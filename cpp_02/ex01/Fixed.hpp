/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:47:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/28 13:51:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_raw;	// (1)) 
		static const int	_fractionalBits = 8;

	public:

	/*	--- Orthodox Canonical Form	---	*/
		//	Default constructor			
		Fixed( void );

		//	Copy constructor
		Fixed(const Fixed& source);

		//	Copy assignment orawperator
		Fixed& operator=(const Fixed& source);

		//	Destructor
		~Fixed( void );

	/*	---	Constructor overloads -----	*/
		Fixed( int const intNbr );
		Fixed( float const floatNbr );
	
	/*	---	Operator overloads --------	*/
		// Fixed& operator<


	/*	--- Methods -------------------	*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

std::ostream& operator<<( std::ostream& os, const Fixed& fixed_nbr );

#endif

/*
 * (1) 	Although '_raw' is declared as an integer, it stores indeed the entire 
 *		representation of the fixed-point number after conversion.
 *
 *		In fixed-point arithmetic, a fixed-point number is represented using 
 *		an integer type, where a portion of the integer bits is reserved for 
 *		the integer part of the number, and the remaining bits are used for 
 *		the fractional part.
 *		
 *		So, even though _raw is declared as an integer, it effectively represents 
 *		a fixed-point number. The integer bits of _raw represent the integer part 
 *		of the fixed-point number, and the fractional bits (determined by the 
 *		'_fractionalBits' constant) represent the fractional part.
 */