/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 13:04:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/26 19:49:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed {

	private:
		int					_raw;
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