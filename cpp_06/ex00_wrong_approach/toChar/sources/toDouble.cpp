/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toDouble.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 13:57:39 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 14:23:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "ScalarExceptions.hpp"

void	ScalarConverter::toDouble (const std::string & literal) {

    // Handle single-character strings
    if (literal.length() == 1 && !std::isdigit(literal[0])) {
        char c_value = literal[0];
        std::cout << "double:\t" 
				  << std::fixed << std::setprecision(1)
				  << static_cast<double>(c_value) << std::endl;
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

	if (d_value >= -DBL_MAX && d_value <= DBL_MAX &&	// (2)
		!(std::isinf(d_value) || std::isnan(d_value))) {
			std::cout << "double:\t" 
				  	  << std::fixed << std::setprecision(1) // comment/uncomment for scientific/decimal notation
					  << d_value << std::endl;
		}
	else if (std::isinf(d_value))
		(d_value) > 0 ? throw PositiveInfException() : throw NegativeInfException();
	else if (std::isnan(d_value))
		throw NanException();
	else
		throw ImpossibleConversionException();	
}

void	ScalarConverter::convertToDouble (const std::string & literal) {

	try {
		toDouble(literal);
	} catch (const ImpossibleConversionException & e) {
		std::cout << "double:\t" << e.what() << std::endl;
	} catch (const PositiveInfException & e) {
		std::cout << "double:\t" << e.what() << std::endl;
	} catch (const NegativeInfException & e) {
		std::cout << "double:\t" << e.what() << std::endl;
	} catch (const NanfException & e) {
		std::cout << "double:\t" << e.what() << std::endl;
	} catch (const NanException & e) {
		std::cout << "double:\t" << e.what() << std::endl;
	}
}