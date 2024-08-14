/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/14 18:49:07 by ccarrace         ###   ########.fr       */
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

	/* --- Type definitions ------------------------------------------------- */

	enum eType {
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNKNOWN
	};

	/* --- Private member variables ----------------------------------------- */

	// enum eType	currentType;

	/* --- Private member methods ------------------------------------------- */

	static bool		isInteger(const std::string & literal);
	static bool		isFloat(const std::string & literal);
	static bool		isDouble(const std::string & literal);
	static bool		isChar(const std::string & literal);
	
	static int		toInteger(const std::string & literal);
	static float	toFloat(const std::string & literal);
	static double	toDouble(const std::string & literal);
	static char		toChar(const std::string & literal);

	static eType	detectType(const std::string & literal);

	static void 	displayType	(eType type);
	static void 	displayUnknownConversions();
	static void 	displayCharConversion(const std::string &literal, eType type);
	static void 	displayIntConversion(const std::string &literal, eType type);
	static void 	displayFloatConversion(const std::string &literal, eType type);
	static void 	displayDoubleConversion(const std::string &literal, eType type);

public:

	/* --- Public member methods -------------------------------------------- */

	static void		displayConversions(const std::string &literal);

	/* --- Exceptions ------------------------------------------------------- */

    class ImpossibleConversionException : public std::exception {
        public:
            const char *what() const throw();
    };

    class NonDisplayableException : public std::exception {
        public:
            const char *what() const throw();
    };

	class PositiveInffException : public std:: exception {
		public: 
			const char *what() const throw();
	};

	class NegativeInffException : public std:: exception {
	public: 
		const char *what() const throw();
	};
};

#endif
