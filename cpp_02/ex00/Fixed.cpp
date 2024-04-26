/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:07:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/26 19:57:11 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor implementation
Fixed::Fixed( void ) : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Copy constructor implementation
Fixed::Fixed(const Fixed& source) : _raw(source._raw) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

// Copy assignment operator constructor
Fixed& Fixed::operator=(const Fixed& source) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &source) {	// Prevent self-assignment
	this->_raw = source.getRawBits();
  }
  return *this;
}

// Destructor implementation
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* --- Class public methods ------------------------------------------------- */

//	The raw value of a fixed-point number is the integer representation
//	of the fixed-point number without considering its fractional part.

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}