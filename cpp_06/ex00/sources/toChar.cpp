/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:11:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 20:46:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarExceptions.hpp"

void	ScalarConverter::toChar(const std::string & literal) {

    // Check if the input is exactly one character (non-numeric)
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c_value = literal[0];
        if (std::isprint(c_value))
            std::cout << "char:\t'" << c_value << "'" << std::endl;
        else
            throw NonDisplayableException();
        return;
    }
	
	const char	*c_str = literal.c_str();
	char	*end;
	double d_value = std::strtod(c_str, &end);

    if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {	// (1)
        	throw ImpossibleConversionException();
    }
    
    // Additional check for negative values that are not within the printable range
    if (d_value < 0) {
        throw ImpossibleConversionException();
    }

	if (d_value >= CHAR_MIN && d_value <= CHAR_MAX)
	{
		char c_value = static_cast<char>(d_value);
		if (std::isprint(c_value))
			std::cout << "char:\t'" << c_value << "'" << std::endl;
		else if (c_value >= 0 && c_value <= 127) // is ascii but not printable
			throw NonDisplayableException();
	}
	else
		throw ImpossibleConversionException();
}

void	ScalarConverter::convertToChar (const std::string & literal) {
	try {
		toChar(literal);
	} catch (const NonDisplayableException & e) {
		std::cout << "char:\t" << e.what() << std::endl;
	} catch (const ImpossibleConversionException & e) {
		std::cout << "char:\t" << e.what() << std::endl;
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
