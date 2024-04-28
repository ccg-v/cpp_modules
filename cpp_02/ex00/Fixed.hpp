/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:04:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/28 13:41:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_raw;	// (1)
		static const int	_fractionalBits = 8;
	
	public:
	
		/*	Default constructor	*/
		Fixed( void );

		/*	Copy constructor:					
			If called, it creates a NEW object that is a
			a copy of the object passed as a parameter	*/
		Fixed(const Fixed& source);

		/*	Copy assignment operator:
			If called, it assigns 'source' member values 
			to an EXISTING object of the same class	*/
		Fixed& operator=(const Fixed& source);

		/*	Destructor	*/
		~Fixed( void );

		/*	Accessors	*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);

};

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