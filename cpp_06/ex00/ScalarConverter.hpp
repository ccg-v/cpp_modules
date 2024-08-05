/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/05 23:24:55 by ccarrace         ###   ########.fr       */
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

	/* --- Private nember methods ------------------------------------------- */

	static bool	isChar(const std::string & literal);
	static bool	isInteger(const std::string & literal);
	static bool	isFloat(const std::string & literal);
	static bool	isDouble(const std::string & literal);

public:

	/* --- Public nember methods -------------------------------------------- */

	static void	detectType (const std::string & literal);

	/* --- Exceptions ------------------------------------------------------- */

	class OutofRange : public std::exception
	{
		public:
			const char *what() const throw();
	};
};

#endif
