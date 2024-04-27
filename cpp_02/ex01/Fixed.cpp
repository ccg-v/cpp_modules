/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:13:14 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/27 01:33:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* --- Orthodox Canonical Form functions ------------------------------------ */

//	Default constructor implementation
Fixed::Fixed( void ) : _raw(0) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor implementation 
Fixed::Fixed(const Fixed& source) : _raw(source._raw) {
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

//	Copy assignment operator constructor
Fixed& Fixed::operator=(const Fixed& source) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &source) {	// Prevent self-assignment
	this->_raw = source.getRawBits();
  }
  return *this;
}

//	Destructor implementation				
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

/* --- Constructor overloads ------------------------------------------------ */

//	Integer to Fixed constructor
Fixed::Fixed( const int _raw ) {
	std::cout << "Int constructor called" << std::endl;
	int scaleFactor = 1 << this->_fractionalBits;
	// this->_fixedPointValue = _raw / scaleFactor;
	this->_raw = _raw * scaleFactor;
	std::cout << "\tInteger " << _raw << " = fixed-point number " << this->_raw << std::endl;
}

//	Float to Fixed constructor
Fixed::Fixed( const float _raw ) {
	std::cout << "Float constructor called" << std::endl;
	int scaleFactor = 1 << this->_fractionalBits;
	// this->_fixedPointValue = (_raw * scaleFactor);
	this->_raw = roundf(_raw * scaleFactor);
	std::cout << "\tFloat-point number " << _raw << " = fixed-point number " << this->_raw << std::endl;
}

/* --- Class public methods ------------------------------------------------- */

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

void	Fixed::setRawBits( int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
}

int		Fixed::toInt( void ) const {
	return ( this->_raw >> Fixed::_fractionalBits );	
}

float	Fixed::toFloat( void ) const {
	return ( (float)this->_raw / (1 << _fractionalBits) );
}

// Implement logic to convert Fixed object to a format suitable for output
std::ostream& operator<<( std::ostream& os, const Fixed& fixed_nbr ) {
	os << fixed_nbr.toFloat();
    return os;
}