/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/09 02:03:41 by ccarrace         ###   ########.fr       */
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

// bool ScalarConverter::isInteger(const std::string & literal) {
//     char* end;
//     long value = std::strtol(literal.c_str(), &end, 10);
    
//     // Check if the entire string was consumed and the value is within int range
//     if (*end == '\0' && 
//         value >= std::numeric_limits<int>::min() && 
//         value <= std::numeric_limits<int>::max()) {
//         return true;
//     }
//     return false;
// }

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
    if (isFloat(literal) || literal == "+inff" || literal == "-inff" || literal == "nanf")
        return FLOAT;
    if (isDouble(literal) || literal == "+inf" || literal == "-inf" || literal == "nan")
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
		// throw std::range_error("out of float range");
		throw OutOfRangeException();
	}
	return value;
}

double	ScalarConverter::toDouble(const std::string & literal) {
	
	char	*end;
	errno = 0;
	double value = std::strtod(literal.c_str(), &end);

	if (errno == ERANGE || value < -DBL_MAX || value > DBL_MAX) {
		// throw std::range_error("out of double range");
		throw OutOfRangeException();
	}
	return value;
}

char	ScalarConverter::toChar(const std::string & literal) {

	char value = literal[0];

	if (!std::isprint(static_cast<unsigned char>(value))) {
		throw std::runtime_error("non printable character");
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
			std::cout << "Char type" << std::endl;
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

// case INT:
//     std::cout << "Integer type" << std::endl;
//     try {
//         int value = toInteger(literal);

//         // Handle char conversion
//         try {
//             if (value >= 0 && value <= 127) {
//                 if (value >= 32 && value <= 126) {
//                     std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
//                 } else {
//                     throw NonDisplayableException();
//                 }
//             } else {
//                 throw OutOfRangeException();
//             }
//         } catch (const OutOfRangeException &e) {
//             std::cout << "char:\t" << e.what() << std::endl;
//         } catch (const NonDisplayableException &e) {
//             std::cout << "char:\t" << e.what() << std::endl;
//         }

//         // Display other conversions
//         std::cout << "int:\t" << value << std::endl;
//         std::cout << "float:\t" << std::fixed << std::setprecision(1)
//                   << static_cast<float>(value) << "f" << std::endl;
//         std::cout << "double:\t" << static_cast<double>(value) << std::endl;

//     } catch (const OutOfRangeException &e) {
//         std::cout << "char:\timpossible" << std::endl;
//         std::cout << "int:\t" << e.what() << std::endl;
        
//         // For float and double, we need to use C++98 compatible conversion
//         char* end;
//         double d_value = std::strtod(literal.c_str(), &end);
//         std::cout << "float:\t" << std::fixed << std::setprecision(1)
//                   << static_cast<float>(d_value) << "f" << std::endl;
//         std::cout << "double:\t" << d_value << std::endl;
//     } catch (const std::exception &e) {
//         std::cout << "Error: " << e.what() << std::endl;
//     }
//     break;

		case INT:
			std::cout << "Integer type" << std::endl;
			try {
				int value = toInteger(literal);

				//	Handle char conversion in its own try-catch block to throw exceptions
				try {
					if (value >= 32 && value <= 126) {
						std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
					} else if (value > 127 || value < 0) {
						throw OutOfRangeException(); // This will be caught by the outer block
					} else {
						throw NonDisplayableException(); // This will be caught by the inner block
					}
				} catch (const NonDisplayableException &e) {
					std::cout << "char:\t" << e.what() << std::endl;
				}

				// Proceed with the remaining conversions
				std::cout << "int:\t" << value << std::endl;
				std::cout << "float:\t" << std::fixed << std::setprecision(1)
						<< static_cast<float>(value) << "f" << std::endl;
				std::cout << "double:\t" << static_cast<double>(value) << std::endl;

			} catch (const OutOfRangeException &e) {
				// If 'OutOfRangeException' is thrown, we catch it here
				std::cout << "char:\t" << e.what() << std::endl;

				// The char conversion failed, but we still want to show float and double conversions
				std::cout << "int:\t" << toInteger(literal) << std::endl;
				std::cout << "float:\t" << std::fixed << std::setprecision(1)
						<< static_cast<float>(toInteger(literal)) << "f" << std::endl;
				std::cout << "double:\t" << static_cast<double>(toInteger(literal)) << std::endl;
			} catch (const std::exception &e) { 
				std::cout << "int:\t" << e.what() << std::endl;
			}
			break;

case FLOAT:
    std::cout << "Float type" << std::endl;
    try {
        float value;
        if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
            std::cout << "char:\timpossible" << std::endl;
            std::cout << "int:\timpossible" << std::endl;
            std::cout << "float:\t" << literal << std::endl;
            std::cout << "double:\t" << literal.substr(0, literal.size() - 1) << std::endl;
        } else {
            value = toFloat(literal);

            // Handle char conversion
            try {
                if (value < 0 || value > 127) {
                    throw OutOfRangeException();
                } else if (value >= 32 && value <= 126) {
                    std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
                } else {
                    throw NonDisplayableException();
                }
            } catch (const OutOfRangeException &e) {
                std::cout << "char:\t" << e.what() << std::endl;
            } catch (const NonDisplayableException &e) {
                std::cout << "char:\t" << e.what() << std::endl;
            }

            // Handle int conversion
			try {
				if (value > static_cast<float>(std::numeric_limits<int>::max()) || 
					value < static_cast<float>(std::numeric_limits<int>::min()) || 
					std::isnan(value)) {
					throw OutOfRangeException();
				}
				std::cout << "int:\t" << static_cast<int>(value) << std::endl;
			} catch (const OutOfRangeException &e) {
				std::cout << "int:\t" << e.what() << std::endl;
			}

            // Display float and double
            std::cout << "float:\t" << std::fixed << std::setprecision(1) << value << "f" << std::endl;
            std::cout << "double:\t" << static_cast<double>(value) << std::endl;
        }
    } catch (const OutOfRangeException &e) {
        std::cout << "char:\timpossible" << std::endl;
        std::cout << "int:\timpossible" << std::endl;
        std::cout << "float:\t" << e.what() << std::endl;
        std::cout << "double:\t" << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    break;

        // case FLOAT:
		// 	std::cout << "Float type" << std::endl;
        //     try {
        //         float value;
		// 		if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
		// 			std::cout << "char:\timpossible" << std::endl;
		// 			std::cout << "int:\timpossible" << std::endl;
		// 			std::cout << "float:\t" << literal << std::endl;
		// 			std::cout << "double:\t" << literal.substr(0, literal.size() - 1) << std::endl;
        //         } else {
        //             value = toFloat(literal);

		// 			//	Handle char conversion in its own try-catch block to throw exceptions
		// 			try {
		// 				if (value < 0 || value > 127) {
		// 					throw OutOfRangeException(); 
		// 				} else if (value >= 32 && value <= 126) {
		// 					std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
		// 				} else {
		// 					throw NonDisplayableException();
		// 				}
		// 			} catch (const ScalarConverter::NonDisplayableException &e) {
		// 				std::cout << "char:\t" << e.what() << std::endl;
		// 			} catch (const ScalarConverter::OutOfRangeException &e) {
		// 				std::cout << "char:\t" << e.what() << std::endl;
		// 			}

		// 			//	 Proceed with the remaining conversions
		// 			std::cout << "int:\t" << static_cast<int>(value) << std::endl;
		// 			std::cout << "float:\t" << std::fixed << std::setprecision(1)
		// 					  << value << "f" << std::endl;
		// 			std::cout << "double:\t" << static_cast<double>(value) << std::endl;
		// 		}

		// 	} catch (const OutOfRangeException &e) {
		// 		// If 'OutOfRangeException' is thrown, we catch it here
		// 		std::cout << "char:\t" << e.what() << std::endl;

		// 		// The char conversion failed, but we still want to show float and double conversions
		// 		std::cout << "int:\t" << toInteger(literal) << std::endl;
		// 		std::cout << "float:\t" << std::fixed << std::setprecision(1)
		// 				<< static_cast<float>(toInteger(literal)) << "f" << std::endl;
		// 		std::cout << "double:\t" << static_cast<double>(toInteger(literal)) << std::endl;

        //     } catch (const std::exception &e) {
        //         std::cout << "float:\t" << e.what() << std::endl;
        //     }
        //     break;

        // case FLOAT:
		// 	std::cout << "Float type" << std::endl;
        //     try {
        //         float value;
		// 		if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
		// 			std::cout << "char:\timpossible" << std::endl;
		// 			std::cout << "int:\timpossible" << std::endl;
		// 			std::cout << "float:\t" << literal << std::endl;
		// 			std::cout << "double:\t" << literal.substr(0, literal.size() - 1) << std::endl;
        //         } else {
        //             value = toFloat(literal);

		// 			//	Handle char conversion in its own try-catch block to throw exceptions
		// 			try {
		// 				if (value < 0 || value > 127) {
		// 					throw OutOfRangeException(); 
		// 				} else if (value >= 32 && value <= 126) {
		// 					std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
		// 				} else {
		// 					throw NonDisplayableException();
		// 				}
		// 			} catch (const ScalarConverter::OutOfRangeException &e) {
		// 				std::cout << "char:\t" << e.what() << std::endl;
		// 			} catch (const ScalarConverter::NonDisplayableException &e) {
		// 				std::cout << "char:\t" << e.what() << std::endl;
		// 			}

		// 			//	 Proceed with the remaining conversions
		// 			std::cout << "int:\t" << static_cast<int>(value) << std::endl;
		// 			std::cout << "float:\t" << std::fixed << std::setprecision(1)
		// 					  << value << "f" << std::endl;
		// 			std::cout << "double:\t" << static_cast<double>(value) << std::endl;
		// 		}
        //     } catch (const std::exception &e) {
        //         std::cout << "float:\t" << e.what() << std::endl;
        //     }
        //     break;

        case DOUBLE:
			std::cout << "Double type" << std::endl;
            try {
                double value;
				if (literal == "+inf" || literal == "-inf" || literal == "nan") {
					std::cout << "char:\timpossible" << std::endl;
					std::cout << "int:\timpossible" << std::endl;
					std::cout << "float:\t" << literal + "f" << std::endl;
					std::cout << "double:\t" << literal << std::endl;
                } else {
					value = toDouble(literal);

					//	Handle char conversion in its own try-catch block to throw exceptions
					try {
						if (value < 0 || value > 127) {
							throw OutOfRangeException(); 
						} else if (value >= 32 && value <= 126) {
							std::cout << "char:\t'" << static_cast<char>(value) << "'" << std::endl;
						} else {
							throw NonDisplayableException();
						}
					} catch (const ScalarConverter::OutOfRangeException &e) {
						std::cout << "char:\t" << e.what() << std::endl;
					} catch (const ScalarConverter::NonDisplayableException &e) {
						std::cout << "char:\t" << e.what() << std::endl;
					}

					//	 Proceed with the remaining conversions
					std::cout << "int:\t" << static_cast<int>(value) << std::endl;
					std::cout << "float:\t" << std::fixed << std::setprecision(1)
							  << static_cast<float>(value) << "f" << std::endl;
					std::cout << "double:\t" << value << std::endl;
				}
            } catch (const std::exception &e) {
                std::cout << "double:\t" << e.what() << std::endl;
            }
            break;
        case UNKNOWN:
        default:
            std::cout << "Unknown type" << std::endl;
            break;
    }
}

//	Exceptions
const char *ScalarConverter::OutOfRangeException::what() const throw() {
    return "out of range";
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return "non printable";
}

const char *ScalarConverter::ImpossibleConversionException::what() const throw() {
    return "impossible to convert";
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
 *	A number larger than the maximum representable float:
 *	340282350000000000000000000000000000000.0f
 * 
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