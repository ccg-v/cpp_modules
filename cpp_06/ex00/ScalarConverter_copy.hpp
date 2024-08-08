/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter_copy.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/08 11:57:00 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <cstring>	// strlen()

class ScalarConverter
{

private:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ScalarConverter();									// Default constructor
	ScalarConverter(const ScalarConverter & source);	// Copy constructor
	ScalarConverter & operator=(const ScalarConverter & source);	// Copy assignment operator
	~ScalarConverter();									// Default destructor

	/* --- Private member methods ------------------------------------------- */

	static bool		isInteger(const std::string & literal);
	static bool		isFloat(const std::string & literal);
	static bool		isDouble(const std::string & literal);
	static bool		isChar(const std::string & literal);
	
	static int		toInteger(const std::string & literal);
	static float	toFloat(const std::string & literal);
	static double	toDouble(const std::string & literal);
	static char		toChar(const std::string & literal);

public:

	/* --- Public member methods -------------------------------------------- */

	static void	detectType (const std::string & literal);

	/* --- Exceptions ------------------------------------------------------- */

	class OutofRange : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
