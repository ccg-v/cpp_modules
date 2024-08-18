/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 20:01:59 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

// Default constructor
ScalarConverter::ScalarConverter() {}

// Copy constructor (currently there's no instance-specific data to copy)
ScalarConverter::ScalarConverter(const ScalarConverter & source) {
	(void) source;	// To avoid unused parameter warning
}

// Copy assignment operator
ScalarConverter &ScalarConverter::operator=(const ScalarConverter & source) {
	(void) source;
	return (*this);
}

// Default destructor
ScalarConverter::~ScalarConverter() {}

/* --- Member methods ------------------------------------------------------- */

void ScalarConverter::convert(const std::string & literal) {

	ScalarConverter::convertToChar(literal);
	ScalarConverter::convertToInt(literal);
	ScalarConverter::convertToFloat(literal);
	ScalarConverter::convertToDouble(literal);
}

/*
 *	(1) 'std::fixed'  and  'std::precision' are manipulators in C++ used
 *		with streams  (like 'std::cout')  to control  the formatting  of
 *		floating-point numbers.
 *		When used together,  'std::fixed'  and  'std::precision' control
 *		the number of decimal places displayed in floating-point numbers
 *		Without 'std::fixed', 'std::setprecision'  sets the total number
 *		of significant digits displayed, which may include digits before
 *		and after the decimal point
 */

/*
 *	INT_MAX:	2147483647
 *	INT_MIN:	-2147483648
 *
 *	FLOAT_MAX:	340282346638528859811704183484516925440.0000000000000000
 *	FLOAT_MIN:	-340282346638528859811704183484516925440.0000000000000000
 * 
 *	
 *
 *	To test a smaller number that the minimum representable double, just
 *	change the sign of the previous number
 *
 *	~
 *  Shell expansion to the current user home directory. If we print the
 * 	literal in 'isChar()':
 * 		std::cout << "Literal: [" << literal << "]" << std::endl;
 * 	the user home directory is printed
 * 		literal: [/home/ccarrace]
 * 
 * 	&
 * 	In Shell it is used to run processes in the background. The command 
 * 	preceding the & will be ran in the background. If we print the literal
 * 	in 'isChar()':
 * 		[1] 43662
 * 	the output indicates that the command was launched in the background
 * 	with the job number [1] and process ID 43662. The shell then displays
 * 	the prompt again because it is ready for more commands.
 */