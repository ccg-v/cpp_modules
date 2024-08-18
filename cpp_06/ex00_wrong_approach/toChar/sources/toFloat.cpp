/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toFloat.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 00:39:37 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 14:18:20 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarExceptions.hpp"

void	ScalarConverter::toFloat(const std::string & literal) {
	
    // Handle single-character strings
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c_value = literal[0];
        std::cout << "float:\t" 
				  << std::fixed << std::setprecision(1)
				  << static_cast<float>(c_value) << "f" << std::endl;
        return;
    }

	// Convert string to double
	const char	*c_str = literal.c_str();
	char	*end;
	double d_value = std::strtod(c_str, &end);

    // Check if the conversion was successful and the input is within int range
	// DON'T THROW THE EXCEPTION IF STRING HAS FLOAT FORMAT (ENDS WITH 'F')
    if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) { //	(1)
        	throw ImpossibleConversionException();
    }

	if (d_value >= -FLT_MAX && d_value <= FLT_MAX &&	// (2)
		!(std::isinf(d_value) || std::isnan(d_value))) {
			std::cout << "float:\t" 
				  	  << std::fixed << std::setprecision(1) // comment/uncomment for scientific/decimal notation
					  << static_cast<float>(d_value) << "f" << std::endl;
		}
	else if (std::isinf(static_cast<float>(d_value)))
		(d_value) > 0 ? throw PositiveInffException() : throw NegativeInffException();
	else if (std::isnan(d_value))
		throw NanfException();
	else
		throw ImpossibleConversionException();	
}

void	ScalarConverter::convertToFloat(const std::string & literal) {
	try {
		toFloat(literal);
	} catch (const ImpossibleConversionException & e) {
		std::cout << "float:\t" << e.what() << std::endl;
	} catch (const PositiveInffException & e) {
		std::cout << "float:\t" << e.what() << std::endl;
	} catch (const NegativeInffException & e) {
		std::cout << "float:\t" << e.what() << std::endl;
	} catch (const NanfException & e) {
		std::cout << "float:\t" << e.what() << std::endl;
	} catch (const NanException & e) {
		std::cout << "float:\t" << e.what() << std::endl;
	}
}

/*
 *	(1)	This condition first checks if *end is not '\0', meaning there are extra
 *		characters after parsing the number.
 *		Then, it verifies whether these characters are not exactly an 'f' 
 *		followed by '\0'.
 *		The overall logic says: "If there are extra characters and they are not 
 *		'f' followed by the end of the string, throw an error."
 */

/*
 *	(2)	FLT_MIN does not represent the smallest negative value a float can hold,
 *		it represents the smallest positive normalized value for a float
 *		(around 1.175494e-38).
 *		The smallest value a float can hold is actually -FLT_MAX for negative 
 *		values.
 */