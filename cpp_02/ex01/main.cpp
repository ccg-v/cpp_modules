/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 21:49:18 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/28 22:58:49 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {

	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;

	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;

}

/*
 *	(1) Appending an 'f' to a numeric literal indicates that the literal 
 *		is a single-precision floating-point constant. Without the 'f',
 *		a floating-point literal would default to double precision.
 *
 *		The term "single-precision float" refers to a floating-point number 
 *		represented in 32 bits. This type is commonly denoted as float in C 
 *		and C++. It provides about 7 decimal digits of precision.
 *
 *		The term "double-precision float" refers to a floating-point number
 *		represented in 64 bits. This type is denoted as double in C and C++.
 *		It provides about 15-16 decimal digits of precision.
 *	
 *		The difference between the two lies primarily in the amount of memory 
 *		they occupy and the precision they offer. Single-precision floats use
 *		32 bits (4 bytes) of memory, while double-precision floats use 64 bits 
 *		(8 bytes). Double precision offers greater precision and a wider range
 *		of representable numbers compared to single precision.
 */