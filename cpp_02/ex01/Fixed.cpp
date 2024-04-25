/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:13:14 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/26 00:50:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* --- Orthodox Canonical Form functions ------------------------------------ */

//	Default constructor implementation
Fixed::Fixed( void ) : _fixedPointNbr(0) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor implementation 
Fixed::Fixed(const Fixed& source) : _fixedPointNbr(source._fixedPointNbr) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

//	Copy assignment operator constructor
Fixed& Fixed::operator=(const Fixed& source) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &source) {	// Prevent self-assignment
	this->_fixedPointNbr = source.getRawBits();
  }
  return *this;
}

//	Destructor implementation				
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* --- Constructor overloads ------------------------------------------------ */

Fixed::Fixed( const int _fixedPointNbr ) {
	std::cout << "Int constructor called" << std::endl;
}