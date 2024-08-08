/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/08 13:52:23 by ccarrace         ###   ########.fr       */
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

bool	ScalarConverter::isInteger(const std::string & literal) {
	size_t	i = 0;

	if (literal[0] == '-')
		i++;
	while (i < literal.length())
	{
		if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	return true;
}

bool	ScalarConverter::isFloat(const std::string & literal) {
	size_t	i = 0;
	size_t 	dotCount = 0;
	size_t	len = literal.length();

	if (literal[len - 1] != 'f')
		return false;
	if (literal[0] == '-')
		i++;
	while (i < (len - 1))
	{
		if ((literal[i]) == '.')
			dotCount++;
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	if (dotCount != 1)
		return false;
	return true;
}

bool	ScalarConverter::isDouble(const std::string & literal) {
	size_t	i = 0;
	size_t 	dotCount = 0;
	size_t	len = literal.length();

	if (literal[0] == '-')
		i++;
	while (i < len)
	{
		if ((literal[i]) == '.')
			dotCount++;
		else if (!std::isdigit(literal[i]))
			return false;
		i++;
	}
	if (dotCount != 1)
		return false;
	return true;
}

bool	ScalarConverter::isChar(const std::string & literal) {
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return true;
	return false;
}

/*	
 *	Step 1: Detect the type of the literal
 */
ScalarConverter::eType	ScalarConverter::detectType(const std::string & literal) {

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
		throw OutOfRangeException();
	}
	return static_cast<int>(value);
}

float	ScalarConverter::toFloat(const std::string & literal) {

	char	*end;
	errno = 0;
	float value = std::strtof(literal.c_str(), &end);

	if (errno == ERANGE || value < -FLT_MAX || value > FLT_MAX) {
		throw std::range_error("out of float range");
	}
	return value;
}

double	ScalarConverter::toDouble(const std::string & literal) {
	
	char	*end;
	errno = 0;
	double value = std::strtod(literal.c_str(), &end);

	if (errno == ERANGE || value < -DBL_MAX || value > DBL_MAX) {
		throw std::range_error("out of double range");
	}
	return value;
}

char	ScalarConverter::toChar(const std::string & literal) {

	char value = literal[0];

	if (!std::isprint(static_cast<unsigned char>(value))) {
		throw std::runtime_error("non displayable character");
	}
	return value;
}

/*
 *	Step 3: Implement the display method
 */
void ScalarConverter::displayConversions(const std::string &literal) {
	
    eType type = detectType(literal);
    switch (type) {
        case CHAR:
            try {
                char value = toChar(literal);
                std::cout << "char:\t'" << value << "'" << std::endl;
                std::cout << "int:\t" << static_cast<int>(value) << std::endl;
                std::cout << "float:\t" << std::fixed << std::setprecision(1)
						  << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "char: " << e.what() << std::endl;
            }
            break;
        case INT:
            try {
                int value = toInteger(literal);
                std::cout << "char:\t";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int:\t" << value << std::endl;
                std::cout << "float:\t" << std::fixed << std::setprecision(1)
						  << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "int:\t" << e.what() << std::endl;
            }
            break;
        case FLOAT:
            try {
                float value = toFloat(literal);
                std::cout << "char: ";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << value << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "float: " << e.what() << std::endl;
            }
            break;
        case DOUBLE:
            try {
                double value = toDouble(literal);
                std::cout << "char: ";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double: " << value << std::endl;
            } catch (const std::exception &e) {
                std::cout << "double: " << e.what() << std::endl;
            }
            break;
        case UNKNOWN:
        default:
            std::cout << "Impossible to convert" << std::endl;
            break;
    }
}

//	Exceptions
void ScalarConverter::displayConversions(const std::string &literal) {
	
    eType type = detectType(literal);
    switch (type) {
        case CHAR:
            try {
                char value = toChar(literal);
                std::cout << "char:\t'" << value << "'" << std::endl;
                std::cout << "int:\t" << static_cast<int>(value) << std::endl;
                std::cout << "float:\t" << std::fixed << std::setprecision(1)
						  << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "char: " << e.what() << std::endl;
            }
            break;
        case INT:
            try {
                int value = toInteger(literal);
                std::cout << "char:\t";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int:\t" << value << std::endl;
                std::cout << "float:\t" << std::fixed << std::setprecision(1)
						  << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double:\t" << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "int:\t" << e.what() << std::endl;
            }
            break;
        case FLOAT:
            try {
                float value = toFloat(literal);
                std::cout << "char: ";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << value << "f" << std::endl;
                std::cout << "double: " << static_cast<double>(value) << std::endl;
            } catch (const std::exception &e) {
                std::cout << "float: " << e.what() << std::endl;
            }
            break;
        case DOUBLE:
            try {
                double value = toDouble(literal);
                std::cout << "char: ";
                if (value >= 32 && value <= 126) {
                    std::cout << "'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    std::cout << "Non displayable" << std::endl;
                }
                std::cout << "int: " << static_cast<int>(value) << std::endl;
                std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
                std::cout << "double: " << value << std::endl;
            } catch (const std::exception &e) {
                std::cout << "double: " << e.what() << std::endl;
            }
            break;
        case UNKNOWN:
        default:
            std::cout << "Impossible to convert" << std::endl;
            break;
    }
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
 *	A number larger than the maximum representable double:
 *	17976931348623157081452742373170435679807056752584499659891747680315
 	72607800285387605895586327668781715404589535143824642343213268894641
	82768467546703537516986049910576551282076245490090389328944075868508
	45513394230458323690322294816580855933212334827479782620414472316873
	81771809192998812504040261841248583680.0
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