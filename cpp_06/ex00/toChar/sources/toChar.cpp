/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toChar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 22:11:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/17 01:05:47 by ccarrace         ###   ########.fr       */
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

    // Check if the conversion was successful and the input is within char range
    if (*end != '\0') {
        // If *end is not '\0', the input contains invalid characters
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
