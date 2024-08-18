/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toInt.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:12:13 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 20:46:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarExceptions.hpp"

void	ScalarConverter::toInt(const std::string & literal) {

    // Handle single-character strings
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c_value = literal[0];
        std::cout << "int:\t" << static_cast<int>(c_value) << std::endl;
        return;
    }

    // Convert string to double
	const char	*c_str = literal.c_str();
	char	*end;
	double d_value = std::strtod(c_str, &end);


    if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {	// (1)
        	throw ImpossibleConversionException();
    }

	if (d_value >= INT_MIN && d_value <= INT_MAX && 
		!(std::isinf(d_value) || std::isnan(d_value)))
		std::cout << "int:\t" << static_cast<int>(d_value) << std::endl;
	else
		throw ImpossibleConversionException();
}

void	ScalarConverter::convertToInt(const std::string & literal) {
	try {
		toInt(literal);
	} catch (const ImpossibleConversionException & e) {
		std::cout << "int:\t" << e.what() << std::endl;
	}
}

/*
 *	(1)	This condition first checks if *end is not '\0', meaning there are extra
 *		characters after parsing the number.
 *
 *		Then, it verifies whether these characters are not exactly an 'f' 
 *		followed by '\0' (to avoid throwing exception if literal has float format)
 *
 *		The overall logic says: "If there are extra characters and they are not 
 *		'f' followed by the end of the string, throw an error."
 */