/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 22:47:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/28 14:28:50 by ccarrace         ###   ########.fr       */
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

		//	Copy assignment operator
		Fixed& operator=(const Fixed& source);

		//	Destructor
		~Fixed( void );

	/*	---	Constructor overloads -----	*/
		Fixed( int const intNbr );
		Fixed( float const floatNbr );

		friend std::ostream& operator<<(std::ostream& os, const Fixed& fixed_nbr);

	/*	--- Methods -------------------	*/
		int		getRawBits( void ) const;
		void	setRawBits( int const raw);

		float	toFloat( void ) const;
		int		toInt( void ) const;

};

// Output stream operator overload (needed for outputting 'Fixed' objects to a stream)
// std::ostream& operator<<( std::ostream& os, const Fixed& fixed_nbr ); // (2)

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
 *
 * (2)	The Output Stream Operator (operator<<) is part of the C++ language and it is
 * 		used in many output operations, e.g:
 * 			int x = 5;
 * 			std::cout << x; // Default implementation of operator << for integers
 * 
 * 		But this default implementation does not know how to handle my 'Fixed' class
 * 		so I need to implement my own implementation defining a specific function. 
 * 		Since the function needs access to the private members of the 'Fixed' class
 * 		to output its state, it is often declared as 'friend' function inside the 
 * 		class.
 * 
 * 		However, the subject does not allow to use the 'friend' keyword so I have to 
 * 		declare the prototype of the function outside the class, and the function 
 * 		must access to class members through the 'getRawBits()' accessor.
 */