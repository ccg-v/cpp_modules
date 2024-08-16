#include <iostream>
#include <string>
// #include <cfloat>
#include <cstdlib>
#include "ScalarConverter.hpp"


char	ScalarConverter::toChar(const std::string & literal) {

	char	*end;
	// long value = std::strtol(literal.c_str(), &end, 10);
	int value = static_cast<int>(literal);

	std::cout << "value is " << value << std::endl;
	std::cout << "length is " << literal.length() << std::endl;
	if (std::isprint(static_cast<int>(value)))
		std::cout << value << " is printable" << std::endl;
	else
		std::cout << value << " is NOT printable" << std::endl;
	if (literal.length() == 1 && std::isprint(static_cast<int>(value)))
		return value;
	else 
		throw NonDisplayableException();
}

const char *ScalarConverter::NonDisplayableException::what() const throw() {
    return "non printable";
}

