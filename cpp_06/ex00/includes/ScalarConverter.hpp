/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 21:15:17 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <climits>	// CHAR_MIN, CHAR_MAX, INT_MIN, INT_MAX, 
# include <cfloat>	// FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX
# include <cmath>	// std::isinf, std::isnan
# include <iomanip>	// std::setprecision
# include <cstdlib>	// std:strtod

class ScalarConverter	// (1)
{

private:
	
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ScalarConverter();									// Default constructor
	ScalarConverter(const ScalarConverter & source);	// Copy constructor
	ScalarConverter & operator=(const ScalarConverter & source);	// Copy assignment operator
	~ScalarConverter();									// Default destructor
	
	/* --- Private member methods -------------------------------------------- */

	static void		toChar(const std::string & literal);
	static void		toInt(const std::string & literal);
	static void		toFloat(const std::string & literal);
	static void		toDouble(const std::string & literal);

	static void		convertToChar (const std::string & literal);
	static void		convertToInt (const std::string & literal);
	static void		convertToFloat(const std::string & literal);
	static void		convertToDouble(const std::string & literal);

public:

	/* --- Public member methods -------------------------------------------- */

	static void		convert(const std::string & literal);
};

#endif

/*
 *	(1) Class design explanation
 *
 * 	1. Static member functions
 * 
 *	The functions in `ScalarConverter` are declared as static, meaning they do
 *	not require an instance of the class to be called. This is logical because 
 *	conversions like these  do not depend on any instance-specific data.  They 
 *	take input and perform operations based purely on that input.
 *
 * 2. Public/private visibility
 * 
 * 	- The individual `toChar()`, `toInt()`, etc., functions are private because
 * 		they are implementation details. Their sole purpose is to serve the main
 * 		convert method.  This improves encapsulation and makes the class easier
 * 		to maintain and extend in the future.
 * 
 * 	- The only public method is `convert()`, which is the main interface for 
 * 		external users. This method internally calls the specific conversion 
 * 		methods and handles exceptions.
 */