/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/13 23:32:51 by ccarrace         ###   ########.fr       */
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
	(void) source;	// To avoid unused parameter warning
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter & source) {
	std::cout << "ScalarConverter copy assignment operator called" << std::endl;
	if (this == &source) {
		// Currently, there's nothing to copy
	}
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

// bool ScalarConverter::isDouble(const std::string & literal) {
//     if (literal == "+inf" || literal == "-inf" || literal == "nan") {
//         return true;
//     }

//     char* end;
//     // double value = std::strtod(literal.c_str(), &end);
//     std::strtod(literal.c_str(), &end);
	
//     // Check if the entire string was consumed
//     if (*end == '\0') {
//         // Check if the value is within double range
//         // if (value >= -std::numeric_limits<double>::max() && 
//         //     value <= std::numeric_limits<double>::max() &&
//         //     !std::isnan(value)) {
//             return true;
//         // }
//     }
//     return false;
// }

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
	
	if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
		// throw std::range_error("out of integer range");
		// throw OutOfRangeException();
		throw ImpossibleConversionException();
	}
	return static_cast<int>(value);
}

float ScalarConverter::toFloat(const std::string & literal) {
    if (literal == "+inff") return std::numeric_limits<float>::infinity();
    if (literal == "-inff") return -std::numeric_limits<float>::infinity();
    if (literal == "nanf") return std::numeric_limits<float>::quiet_NaN();

    // Remove the 'f' suffix
    std::string numPart = literal.substr(0, literal.length() - 1);

    // Parse as a double to check the range more precisely
    char* end;
    double d_value = std::strtod(numPart.c_str(), &end);	

    // Check if the entire string was parsed
    if (*end != '\0') {
        throw ImpossibleConversionException();
    }

    // Check if the value is within float range
    if (d_value < -std::numeric_limits<float>::max() || 
        d_value > std::numeric_limits<float>::max()) {
        // throw ImpossibleConversionException();
		if (d_value > 0)
			throw PositiveInffException();
		else
			throw NegativeInffException();
    }

    // If it's in range, convert to float
    return static_cast<float>(d_value);
}

// double ScalarConverter::toDouble(const std::string & literal) {
//     char* end;
//     if (literal == "+inf") {
//         return std::numeric_limits<double>::infinity();
//     }
//     if (literal == "-inf") {
//         return -std::numeric_limits<double>::infinity();
// 	}
//     if (literal == "nan") {
//         return std::numeric_limits<double>::quiet_NaN();
//     }
	
//     double value = std::strtod(literal.c_str(), &end);

//     // if (*end != '\0') {
//     //     throw OutOfRangeException();
//     // }

//     if (value == HUGE_VAL || value == -HUGE_VAL) {
// 		std::cout << "Exception thrown from toDouble (double out of range)" << std::endl;
//         throw ImpossibleConversionException();
//     }

//     return value;
// }

double ScalarConverter::toDouble(const std::string & literal) {
    char* end;
    if (literal == "+inf") {
        return std::numeric_limits<double>::infinity();
    }
    if (literal == "-inf") {
        return -std::numeric_limits<double>::infinity();
    }
    if (literal == "nan") {
        return std::numeric_limits<double>::quiet_NaN();
    }
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

void	ScalarConverter::HandleCharConversion (int value) {

	//	Handle char conversion in its own try-catch block to throw exceptions
	try {
		if (value >= 32 && value <= 126) {
			std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
		} else if (value > 127 || value < 0)
			throw ImpossibleConversionException();
		else 
			throw NonDisplayableException();
	} catch (const NonDisplayableException &e) {
		std::cout << "char:\t" << e.what() << std::endl;
	}
}

/*
 *	Step 3: Implement the display method
 */
void ScalarConverter::displayConversions(const std::string &literal) {
	
    eType type = detectType(literal);
	
    switch (type) {
		
        case CHAR: {
			std::cout << "Char type" << std::endl;
            char value = toChar(literal);
            std::cout << "char:\t'" << value << "'" << std::endl;
            std::cout << "int:\t" << static_cast<int>(value) << std::endl;
            std::cout << "float:\t" << std::fixed << std::setprecision(1)
					  << static_cast<float>(value) << "f" << std::endl;
            std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            break;
		}

		case INT:
			std::cout << "Integer type" << std::endl;
			try {
				int value = toInteger(literal);
				//	Handle char conversion in its own try-catch block to throw exceptions
				try {
					if (value >= 32 && value <= 126) {
						std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
					} else if (value > 127 || value < 0)
						throw ImpossibleConversionException();
					else 
						throw NonDisplayableException();
				} catch (const NonDisplayableException &e) {
					std::cout << "char:\t" << e.what() << std::endl;
				}
			} catch (const ImpossibleConversionException &e) {
				std::cout << "char:\t" << e.what() << std::endl;
			}		
			// The char conversion failed, but we still want to show float and double conversions
			std::cout << "int:\t" << toInteger(literal) << std::endl;
			std::cout << "float:\t" << std::fixed << std::setprecision(1)
					  << static_cast<float>(toInteger(literal)) << "f" << std::endl;
			std::cout << "double:\t" << static_cast<double>(toInteger(literal))
					  << std::endl;
			break;

		case FLOAT:
			std::cout << "Float type" << std::endl;
			float f_value;
			double d_value;

			// Step 1: Try to convert to float
			try {
				f_value = toFloat(literal);

				// Step 2: Attempt to convert to char
				try {
					if (f_value >= 32 && f_value <= 126) {
						std::cout << "char:\t'" << static_cast<char>(f_value) << "'" << std::endl;
					} else if (f_value > 127 || f_value < 0) {
						throw ImpossibleConversionException();
					} else {
						throw NonDisplayableException();
					}
				} catch (const NonDisplayableException &e) {
					std::cout << "char:\t" << e.what() << std::endl;
				} catch (const ImpossibleConversionException &e) {
					std::cout << "char:\t" << e.what() << std::endl;
				}

				// Step 3: Attempt to convert to int
				try {
					std::string floatStr = literal.substr(0, literal.length() - 1);
					int intValue = toInteger(floatStr);
					std::cout << "int:\t" << intValue << std::endl;
				} catch (const ImpossibleConversionException &e) {
					std::cout << "int:\t" << e.what() << std::endl;
				}

				// Step 4: Display the float value
				if (std::isinf(f_value)) {
					if (f_value > 0)
						std::cout << "float:\t+inff" << std::endl;
					else
						std::cout << "float:\t-inff" << std::endl;
				} else {
					std::cout << "float:\t" << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
				}

			} catch (const ImpossibleConversionException & e) {
				std::cout << "char:\t" << e.what() << std::endl;
				std::cout << "int:\t" << e.what() << std::endl;
			} catch (const PositiveInffException & e) {
				std::cout << "float:\t" << e.what() << std::endl;
			} catch (const NegativeInffException & e) {
				std::cout << "float:\t" << e.what() << std::endl;
			}

			// Step 5: Attempt to convert to double, whether float conversion succeeded or failed
			try {
				std::string doubleStr = literal.substr(0, literal.length() - 1);
				d_value = std::strtod(doubleStr.c_str(), NULL);
				if (d_value == HUGE_VAL || d_value == -HUGE_VAL) {
					throw ImpossibleConversionException();
				}
				std::cout << "double:\t" << std::fixed << std::setprecision(1) << d_value << std::endl;
			} catch (const ImpossibleConversionException &e) {
				std::cout << "double:\t" << e.what() << std::endl;
			}

			break;

        case DOUBLE:
            std::cout << "Double type" << std::endl;
            try {
                double value = toDouble(literal);

                // Handle char conversion
                try {
                    if (value < 0 || value > 127 || std::isnan(value) || std::isinf(value)) {
                        throw ImpossibleConversionException();
                    } else if (value < 32 || value > 126) {
                        throw NonDisplayableException();
                    } else {
                        std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
                    }
                } catch (const NonDisplayableException &e) {
                    std::cout << "char:\t" << e.what() << std::endl;
                } catch (const ImpossibleConversionException &e) {
                    std::cout << "char:\t" << e.what() << std::endl;
                }

                // Handle int conversion
                try {
                    if (value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min() || std::isnan(value) || std::isinf(value)) {
                        throw ImpossibleConversionException();
                    } else {
                        std::cout << "int:\t" << static_cast<int>(value) << std::endl;
                    }
                } catch (const ImpossibleConversionException &e) {
                    std::cout << "int:\t" << e.what() << std::endl;
                }

				// Handle float conversion
				try {
					if (std::isinf(value)) {
						if (value > 0)
							std::cout << "double:\t+inf" << std::endl;
						else
							std::cout << "double:\t-inf" << std::endl;
					} else {
						float f_value = static_cast<float>(value);
						if (std::isinf(f_value)) {
							throw ImpossibleConversionException();
						}
						std::cout << "float:\t" << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
					}
				} catch (const ImpossibleConversionException &e) {
					std::cout << "float:\t" << e.what() << std::endl;
				}
				
				// Display double
				if (std::isinf(value)) {
					if (value > 0)
						std::cout << "double:\t+inf" << std::endl;
					else
						std::cout << "double:\t-inf" << std::endl;
				} else {
					std::cout << "double:\t" << std::fixed << std::setprecision(1) << value << std::endl;
				}
			} catch (const ImpossibleConversionException & e) {
				// This catch block handles errors in initial double conversion
				std::cout << "char:\t" << e.what() << std::endl;
				std::cout << "int:\t" << e.what() << std::endl;
				std::cout << "float:\t" << e.what() << std::endl;
				std::cout << "double:\t" << e.what() << std::endl;
			}
			break;

		case UNKNOWN:
			std::cout << "Unknown type" << std::endl;
			std::cout << "(UNKNOWN)char:\timpossible" << std::endl;
			std::cout << "(UNKNOWN)int:\timpossible" << std::endl;
			std::cout << "(UNKNOWN)float:\timpossible" << std::endl;
			std::cout << "(UNKNOWN)double:\timpossible" << std::endl;
			break;
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