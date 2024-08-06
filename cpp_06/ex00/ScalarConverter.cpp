/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/06 21:24:32 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <cctype>	// isprint(), isdigit()
#include <climits>	// INT_MIN, INT_MAX
#include <cerrno>	// errno
#include <cstdlib>	// strtol()

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

int	toInteger(const std::string & literal) {

	char	*end;
	errno = 0;
	long value = std::strtol(literal.c_str(), &end, 10);

	if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
		throw std::range_error("Value out of range");
		// std::cout << "Value out of range" << std::endl;
	}
	return static_cast<int>(value);
}

void	ScalarConverter::detectType(const std::string & literal) {

	if (isInteger(literal)) {
		std::cout << "Type has integer format" << std::endl;
		try {
			int value = toInteger(literal);
			std::cout << "Converted value is " << value << std::endl;
		} catch (const std::runtime_error & e) {
			std::cout << "Exception caught: " << e.what() << std::endl;
		}

	}
	if (isFloat(literal)) {
		std::cout << "Type has float format" << std::endl;
	}
	if (isDouble(literal)) {
		std::cout << "Type has double format" << std::endl;
	}
	if (isChar(literal)) {
		std::cout << "Type is char" << std::endl; 
		// try {
			
		// } catch (const std::exception & e) {

		// }
	}
}

const char *ScalarConverter::OutofRange::what() const throw()
{
    return "Out of range";
}