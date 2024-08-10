/*============================================================================*/
				HEADER FILE
/*============================================================================*/

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstring>	// strlen()

class ScalarConverter
{

private:
	
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ScalarConverter();									// Default constructor
	ScalarConverter(const ScalarConverter & source);	// Copy constructor
	ScalarConverter & operator=(const ScalarConverter & source);	// Copy assignment operator
	~ScalarConverter();									// Default destructor

	/* --- Type definitions ------------------------------------------------- */

	enum eType {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNKNOWN
	};

	/* --- Private member methods ------------------------------------------- */

	static bool		isInteger(const std::string & literal);
	static bool		isFloat(const std::string & literal);
	static bool		isDouble(const std::string & literal);
	static bool		isChar(const std::string & literal);
	
	static int		toInteger(const std::string & literal);
	static float	toFloat(const std::string & literal);
	static double	toDouble(const std::string & literal);
	static char		toChar(const std::string & literal);

	static eType	detectType(const std::string & literal);

public:

	/* --- Public member methods -------------------------------------------- */

	static void		displayConversions(const std::string &literal);

	/* --- Exceptions ------------------------------------------------------- */

	class OutOfRangeException : public std::exception {
		public:
			const char *what() const throw();
	};

    class ImpossibleConversionException : public std::exception {
        public:
            const char *what() const throw();
    };

    class NonDisplayableException : public std::exception {
        public:
            const char *what() const throw();
    };
};

#endif



/*============================================================================*/
				SOURCE FILE
/*============================================================================*/

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
    std::string numPart = literal.substr(0, literal.length() - 1);

    // We'll just check if it can be parsed as a number here
    char* end;
    std::strtod(numPart.c_str(), &end);
    
    // Check if the entire string (except 'f') was consumed
    return (*end == '\0');
}

bool ScalarConverter::isDouble(const std::string & literal) {
    if (literal == "+inf" || literal == "-inf" || literal == "nan") {
        return true;
    }

    char* end;
    double value = std::strtod(literal.c_str(), &end);
    
    // Check if the entire string was consumed
    if (*end == '\0') {
        // Check if the value is within double range
        if (value >= -std::numeric_limits<double>::max() && 
            value <= std::numeric_limits<double>::max() &&
            !std::isnan(value)) {
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
		throw OutOfRangeException();
	}
	return static_cast<int>(value);
}

float ScalarConverter::toFloat(const std::string & literal) {
    if (literal == "+inff") return std::numeric_limits<float>::infinity();
    if (literal == "-inff") return -std::numeric_limits<float>::infinity();
    if (literal == "nanf") return std::numeric_limits<float>::quiet_NaN();

    // Remove the 'f' suffix
    std::string numPart = literal.substr(0, literal.length() - 1);

    // First, try to parse as a double to check the range
    char* end;
    double d_value = std::strtod(numPart.c_str(), &end);

    if (d_value < -std::numeric_limits<float>::max() || 
        d_value > std::numeric_limits<float>::max()) {
        throw OutOfRangeException();
    }

    // If it's in range, parse directly as float
    float f_value = std::strtof(numPart.c_str(), &end);

    return f_value;
}

double ScalarConverter::toDouble(const std::string & literal) {
    char* end;

    if (literal == "nan") {
        return std::numeric_limits<double>::quiet_NaN();
    }
	
    double value = std::strtod(literal.c_str(), &end);

    if (*end != '\0') {
        throw OutOfRangeException();
    }

    if (value == HUGE_VAL || value == -HUGE_VAL) {
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
				float value = toFloat(literal);
				
				// Handle char conversion
				if (value >= 0 && value <= 127) {
					if (value >= 32 && value <= 126) {
						std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
					} else {
						std::cout << "char: Non displayable" << std::endl;
					}
				} else {
					std::cout << "char: impossible" << std::endl;
				}

				// Handle int conversion
				if (value > static_cast<float>(std::numeric_limits<int>::max()) || 
					value < static_cast<float>(std::numeric_limits<int>::min()) || 
					std::isnan(value)) {
					std::cout << "int: impossible" << std::endl;
				} else {
					std::cout << "int: " << static_cast<int>(value) << std::endl;
				}

				// Display float and double
				std::cout << "float: " << std::fixed << std::setprecision(1) << value << "f" << std::endl;
				std::cout << "double: " << static_cast<double>(value) << std::endl;
			} catch (const OutOfRangeException &) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: out of range" << std::endl;
				
				// For double, we need to use the original literal
				char* end;
				double d_value = std::strtod(literal.c_str(), &end);
				std::cout << "double: " << d_value << std::endl;
			}
			break;

		case DOUBLE:
			std::cout << "Double type" << std::endl;
			try {
				double value = toDouble(literal);
				
				// Handle char conversion
				if (value >= 0 && value <= 127) {
					if (value >= 32 && value <= 126) {
						std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
					} else {
						std::cout << "char: Non displayable" << std::endl;
					}
				} else {
					std::cout << "char: impossible" << std::endl;
				}

				// Handle int conversion
				std::cout << "int: impossible" << std::endl;

				// Handle float conversion
				if (std::isnan(value) || std::isinf(value)) {
					std::cout << "float: " << (std::isnan(value) ? "nanf" : (value > 0 ? "+inff" : "-inff")) << std::endl;
				} else {
					float f_value = static_cast<float>(value);
					if (f_value != value) {
						std::cout << "float: impossible" << std::endl;
					} else {
						std::cout << "float: " << std::fixed << std::setprecision(1) << f_value << "f" << std::endl;
					}
				}

				// Display double
				if (std::isnan(value)) {
					std::cout << "double: nan" << std::endl;
				} else if (std::isinf(value)) {
					std::cout << "double: " << (value > 0 ? "+inf" : "-inf") << std::endl;
				} else {
					std::cout << "double: " << std::fixed << std::setprecision(1) << value << std::endl;
				}
			} catch (const OutOfRangeException &) {
				std::cout << "char: impossible" << std::endl;
				std::cout << "int: impossible" << std::endl;
				std::cout << "float: impossible" << std::endl;
				std::cout << "double: out of range" << std::endl;
			}
			break;

		case UNKNOWN:
			std::cout << "Unknown type" << std::endl;
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: impossible" << std::endl;
			std::cout << "double: impossible" << std::endl;
			break;
		default:
			std::cout << "Error: Unhandled type" << std::endl;
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



/*============================================================================*/
				MAIN FILE
/*============================================================================*/


#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
        return 1;
    }
    ScalarConverter::displayConversions(argv[1]);

    return 0;
}