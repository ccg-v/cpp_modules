/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:07:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/23 21:45:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*	Default constructor implementation		*/
Fixed::Fixed( void ) : _fixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

/*	Copy constructor implementation 		*/
Fixed::Fixed(const Fixed& source) : _fixedPoint(source._fixedPoint) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

/*	Copy assignment operator constructor	*/
Fixed& Fixed::operator=(const Fixed& source) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &source) {	// Prevent self-assignment
	this->_fixedPoint = source.getRawBits();
  }
  return *this;
}

/*	Destructor implementation				*/
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/*	Class methods							*/
int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_fixedPoint;
}

void	Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_fixedPoint = raw;
}