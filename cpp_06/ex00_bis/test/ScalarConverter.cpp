/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/14 23:03:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>	// isprint(), isdigit()
#include <cerrno>	// errno
#include <cstdlib>	// strtol()
#include <climits>	// INT_MIN, INT_MAX
#include <cfloat>	// FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX
#include <limits>	// std::numeric_limits
#include <iomanip>	// std::fixed, std::setprecision
#include <cmath>	// HUGE_VAL

/* --- Orthodox Canonical Form implementation ------------------------------- */

// Default constructor
ScalarConverter::ScalarConverter() {
	std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Copy constructor
ScalarConverter::ScalarConverter(const ScalarConverter & source) {
	std::cout << "ScalarConverter copy constructor called" << std::endl;
	// Currently, there's no instance-specific data to copy
	(void)source;	// To avoid unused parameter warning
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter & source) {
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	// Currently, there's nothing to copy
	(void)source;
	return (*this);
}

// Default destructor
ScalarConverter::~ScalarConverter() {
	std::cout << "ScalarConverter default destructor called" << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

bool ScalarConverter::isInteger(const std::string & literal) {
    char* end;
    long value = std::strtol(literal.c_str(), &end, 10);
    
    // Check if the entire string was consumed and the value is within int range
    if (*end == '\0' && 
        value >= std::numeric_limits<int>::min() && 
        value <= std::numeric_limits<int>::max()) {
        return true;
    }
    return false;
}

bool ScalarConverter::isFloat(const std::string & literal) {
    if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
        return true;
    }

    // Check if the last character is 'f'
    if (literal.empty() || literal[literal.length() - 1] != 'f') {
        return false;
    }

    // Remove the 'f' suffix
    std::string trimmed = literal.substr(0, literal.length() - 1);

    // We'll just check if it can be parsed as a number here
    char* end;
    double value = std::strtod(trimmed.c_str(), &end);
    
    // Check if the entire string (except 'f') was consumed
    return (*end == '\0' && std::isfinite(value));
}

bool ScalarConverter::isDouble(const std::string & literal) {
    if (literal == "+inf" || literal == "-inf" || literal == "nan") {
        return true;
    }
    char* end;
    double value = std::strtod(literal.c_str(), &end);
    // Check if the entire string was consumed
    if (*end == '\0') {
        // Check if the value is a valid double (including infinity)
        if (!std::isnan(value) || std::isinf(value)) {
            return true;
        }
    }
    return false;
}

bool	ScalarConverter::isChar(const std::string & literal) {
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

/*	
 *	Step 1: Detect the type of the literal
 */
ScalarConverter::eType ScalarConverter::detectType(const std::string & literal) {

    if (isChar(literal))
        return CHAR;
    if (isInteger(literal))
        return INT;
    if (isFloat(literal))
        return FLOAT;
    if (isDouble(literal))
        return DOUBLE;
		
    return UNKNOWN;
}

/*
 *	Step 2: Implement the conversion methods
 */
int	ScalarConverter::toInteger(const std::string & literal) {

	char	*end;
	errno = 0;
	long value = std::strtol(literal.c_str(), &end, 10);
	
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX) 
		throw ImpossibleConversionException();
	return static_cast<int>(value);
}

float ScalarConverter::toFloat(const std::string & literal) {
    if (literal == "+inff") return std::numeric_limits<float>::infinity();
    if (literal == "-inff") return -std::numeric_limits<float>::infinity();
    if (literal == "nanf") return std::numeric_limits<float>::quiet_NaN();

    std::string numPart = literal.substr(0, literal.length() - 1);

    // Parse as a double to check the range more precisely
    char* end;
    double d_value = std::strtod(numPart.c_str(), &end);	

    // Check if the entire string was parsed
    // if (*end != '\0') {
    //     throw ImpossibleConversionException();
    // }

    // Check if the value is within float range
    if (d_value < -std::numeric_limits<float>::max() || 
        d_value > std::numeric_limits<float>::max()) {
		if (d_value > 0)
			throw PositiveInffException();
		else
			throw NegativeInffException();
    }
    return static_cast<float>(d_value);
}

double ScalarConverter::toDouble(const std::string & literal) {
    char* end;
    if (literal == "+inf") 
        return std::numeric_limits<double>::infinity();
    if (literal == "-inf") 
        return -std::numeric_limits<double>::infinity();
    if (literal == "nan")
        return std::numeric_limits<double>::quiet_NaN();
    double value = std::strtod(literal.c_str(), &end);

    // Instead of throwing an exception, return infinity for out-of-range values
    if (value == HUGE_VAL) {
        return std::numeric_limits<double>::infinity();
    }
    if (value == -HUGE_VAL) {
        return -std::numeric_limits<double>::infinity();
    }
    return value;
}

char	ScalarConverter::toChar(const std::string & literal) {

	char value = literal[0];
	return value;
}


/*
 *	Step 3: Implement the display method
 */
void ScalarConverter::displayConversions(const std::string &literal) {
    eType type = detectType(literal);
    displayType(type);

    if (type == UNKNOWN) {
        displayUnknownConversions();
        return;
    }

    displayCharConversion(literal, type);
    displayIntConversion(literal, type);
    displayFloatConversion(literal, type);
    displayDoubleConversion(literal, type);
}

// Helper functions

void ScalarConverter::displayType(eType type) {
    switch (type) {
        case CHAR: std::cout << "Char type" << std::endl; break;
        case INT: std::cout << "Integer type" << std::endl; break;
        case FLOAT: std::cout << "Float type" << std::endl; break;
        case DOUBLE: std::cout << "Double type" << std::endl; break;
        default: std::cout << "Unknown type" << std::endl;
    }
}

void ScalarConverter::displayUnknownConversions() {
    std::cout << "char:\timpossible" << std::endl;
    std::cout << "int:\timpossible" << std::endl;
    std::cout << "float:\timpossible" << std::endl;
    std::cout << "double:\timpossible" << std::endl;
}

void ScalarConverter::displayCharConversion(const std::string &literal, eType type) {
    try {
        char value;
        if (type == CHAR) {
            value = toChar(literal);
        } else if (type == INT) {
            int intValue = toInteger(literal);
            if (intValue < 0 || intValue > 127) throw ImpossibleConversionException();
            value = static_cast<char>(intValue);
        } else if (type == FLOAT) {
            float floatValue = toFloat(literal);
            if (floatValue < 0 || floatValue > 127 || std::isnan(floatValue) || std::isinf(floatValue)) 
                throw ImpossibleConversionException();
            value = static_cast<char>(floatValue);
        } else if (type == DOUBLE) {
            double doubleValue = toDouble(literal);
            if (doubleValue < 0 || doubleValue > 127 || std::isnan(doubleValue) || std::isinf(doubleValue)) 
                throw ImpossibleConversionException();
            value = static_cast<char>(doubleValue);
        } else {
            throw ImpossibleConversionException();
        }
        if (value < 32 || value > 126) {
            throw NonDisplayableException();
        }
        std::cout << "char:\t'" << value << "'" << std::endl;
    } catch (const NonDisplayableException & e) {
        std::cout << "char:\t" << e.what() << std::endl;
    } catch (const std::exception & e) {
        std::cout << "char:\t" << e.what() << std::endl;
    }
}

void ScalarConverter::displayIntConversion(const std::string &literal, eType type) {
    try {
        int value;
        if (type == CHAR) {
            value = static_cast<int>(toChar(literal));
        } else if (type == INT) {
            value = toInteger(literal);
        } else if (type == FLOAT) {
            float floatValue = toFloat(literal);
            if (floatValue > std::numeric_limits<int>::max()|| floatValue < std::numeric_limits<int>::min() 
                || std::isnan(floatValue) || std::isinf(floatValue)) 
                throw ImpossibleConversionException();
            value = static_cast<int>(floatValue);
        } else if (type == DOUBLE) {
            double doubleValue = toDouble(literal);
            if (doubleValue > std::numeric_limits<int>::max() || doubleValue < std::numeric_limits<int>::min() 
                || std::isnan(doubleValue) || std::isinf(doubleValue)) 
                throw ImpossibleConversionException();
            value = static_cast<int>(doubleValue);
        } else {
            throw ImpossibleConversionException();
        }
        std::cout << "int:\t" << value << std::endl;
    } catch (const std::exception & e) {
        std::cout << "int:\t" << e.what() << std::endl;
    }
}

void ScalarConverter::displayFloatConversion(const std::string &literal, eType type) {
    try {
        float value;
        if (type == CHAR) {
            value = static_cast<float>(toChar(literal));
        } else if (type == INT) {
            value = static_cast<float>(toInteger(literal));
        } else if (type == FLOAT) {
            try {
                value = toFloat(literal);
            } catch (const PositiveInffException & e) {
                std::cout << "float:\t" << e.what() << std::endl;
                return;
            } catch (const NegativeInffException & e) {
                std::cout << "float:\t" << e.what()  << std::endl;
                return;
            }
        } else if (type == DOUBLE) {
            double doubleValue = toDouble(literal);
            if (std::isinf(doubleValue)) {
                std::cout << "float:\t" << (doubleValue > 0 ? "+inff" : "-inff") << std::endl;
                return;
            }
            value = static_cast<float>(doubleValue);
        } else {
            throw ImpossibleConversionException();
        }
        
        if (std::isinf(value)) {
			if (value > 0)
				std::cout << "float:\t+inff" << std::endl;
			else
            	std::cout << "float:\t-inff" << std::endl;
        } else {
            std::cout << "float:\t" 
			<< std::fixed << std::setprecision(1) // comment/uncomment to switch between scientific/decimal notation (1)
			<< value << "f" << std::endl;
        }
    } catch (const ImpossibleConversionException & e) {
        std::cout << "float:\t" << e.what() << std::endl;
    }
}

void ScalarConverter::displayDoubleConversion(const std::string &literal, eType type) {
    try {
        double value;
        if (type == CHAR) {
            value = static_cast<double>(toChar(literal));
        } else if (type == INT) {
            value = static_cast<double>(toInteger(literal));
        } else if (type == FLOAT) {
            std::string floatStr = literal.substr(0, literal.length() - 1);
            value = std::strtod(floatStr.c_str(), NULL);
            if (value == HUGE_VAL || value == -HUGE_VAL) {
                throw ImpossibleConversionException();
            }
        } else if (type == DOUBLE) {
            value = toDouble(literal);
        } else {
            throw ImpossibleConversionException();
        }
        
        if (std::isinf(value)) {
			if (value > 0)
				std::cout << "double:\t+inf" << std::endl;
			else
            	std::cout << "double:\t-inf" << std::endl;
        } else {
            std::cout << "double:\t"
			<< std::fixed << std::setprecision(1) // comment/uncomment to switch between scientific/decimal notation (1)
			<< value << std::endl;
        }
    } catch (const ImpossibleConversionException & e) {
        std::cout << "double:\t" << e.what() << std::endl;
    }
}

//	Exceptions

const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return "non displayable";
}

const char *ScalarConverter::ImpossibleConversionException::what() const throw() {
    return "impossible";
}

const char *ScalarConverter::PositiveInffException::what() const throw() {
    return "+inff";
}

const char *ScalarConverter::NegativeInffException::what() const throw() {
    return "-inff";
}
/*
 *	(1) 'std::fixed'  and  'std::precision' are manipulators in C++ used
 *		with streams  (like 'std::cout')  to control  the formatting  of
 *		floating-point numbers.
 *		When used together,  'std::fixed'  and  'std::precision' control
 *		the number of decimal places displayed in floating-point numbers
 *		Without 'std::fixed', 'std::setprecision'  sets the total number
 *		of significant digits displayed, which may include digits before
 *		and after the decimal point
 */

/*
 *	INT_MAX:	2147483647
 *	INT_MIN:	-2147483648
 *
 *	FLOAT_MAX:	340282346638528859811704183484516925440.0000000000000000
 *	FLOAT_MIN:	-340282346638528859811704183484516925440.0000000000000000
 * 
 *	
 *
 *	To test a smaller number that the minimum representable double, just
 *	change the sign of the previous number
 *
 *	~
 *  Shell expansion to the current user home directory. If we print the
 * 	literal in 'isChar()':
 * 		std::cout << "Literal: [" << literal << "]" << std::endl;
 * 	the user home directory is printed
 * 		literal: [/home/ccarrace]
 * 
 * 	&
 * 	In Shell it is used to run processes in the background. The command 
 * 	preceding the & will be ran in the background. If we print the literal
 * 	in 'isChar()':
 * 		[1] 43662
 * 	the output indicates that the command was launched in the background
 * 	with the job number [1] and process ID 43662. The shell then displays
 * 	the prompt again because it is ready for more commands.
 */