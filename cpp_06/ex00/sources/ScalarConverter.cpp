/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 20:26:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor (currently there's no instance-specific data to copy)
ScalarConverter::ScalarConverter(const ScalarConverter & source) {
	(void) source;	// To avoid unused parameter warning
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter & source) {
	(void) source;
	return (*this);
}

// Default destructor
ScalarConverter::~ScalarConverter() {}

/* --- Member methods ------------------------------------------------------- */

void ScalarConverter::convert(const std::string & literal) {

	ScalarConverter::convertToChar(literal);
	ScalarConverter::convertToInt(literal);
	ScalarConverter::convertToFloat(literal);
	ScalarConverter::convertToDouble(literal);
}

