/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 14:17:57 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
// # include <cstring>	// strlen()
# include <climits>	// CHAR_MIN, CHAR_MAX, INT_MIN, INT_MAX, 
# include <cfloat>	// FLT_MIN, FLT_MAX, DBL_MIN, DBL_MAX
# include <cmath>	// std::isinf, std::isnan
# include <iomanip>	// std::setprecision
# include <cstdlib>	// std:strtod

class ScalarConverter
{

private:
	
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ScalarConverter();									// Default constructor
	ScalarConverter(const ScalarConverter & source);	// Copy constructor
	ScalarConverter & operator=(const ScalarConverter & source);	// Copy assignment operator
	~ScalarConverter();									// Default destructor
	
public:

	/* --- Public member methods -------------------------------------------- */

	static void		toChar(const std::string & literal);
	static void		toInt(const std::string & literal);
	static void		toFloat(const std::string & literal);
	static void		toDouble(const std::string & literal);

	static void		convertToChar (const std::string & literal);
	static void		convertToInt (const std::string & literal);
	static void		convertToFloat(const std::string & literal);
	static void		convertToDouble(const std::string & literal);
};

#endif
