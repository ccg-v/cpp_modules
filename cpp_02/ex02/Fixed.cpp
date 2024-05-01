/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 23:13:14 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/01 20:43:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* --- Orthodox Canonical Form functions ------------------------------------ */

//	Default constructor implementation
Fixed::Fixed( void ) : _raw(0) {}

//	Copy constructor implementation 
Fixed::Fixed(const Fixed& source) : _raw(source._raw) {
	*this = source;
}

//	Copy assignment operator constructor
Fixed& Fixed::operator=(const Fixed& source) {
  if (this != &source) {	// Prevent self-assignment
	this->_raw = source.getRawBits();
  }
  return *this;
}

//	Destructor implementation				
Fixed::~Fixed( void ) {}

/* --- Constructor overloads ------------------------------------------------ */

//	Integer to Fixed constructor
Fixed::Fixed( const int _raw ) {
	int scaleFactor = 1 << this->_fractionalBits;
	this->_raw = _raw * scaleFactor;
}

//	Float to Fixed constructor
Fixed::Fixed( const float _raw ) {
	int scaleFactor = 1 << this->_fractionalBits;
	this->_raw = roundf(_raw * scaleFactor);
}

/* --- Operator overloads --------------------------------------------------- */

//	Comparison operators
bool	Fixed::operator>( const Fixed& source ) {
	return (this->getRawBits() > source.getRawBits());
}

bool	Fixed::operator<( const Fixed& source ) {
	return (this->getRawBits() < source.getRawBits());
}

bool	Fixed::operator>=( const Fixed& source ) {
	return (this->getRawBits() >= source.getRawBits());
}

bool	Fixed::operator<=( const Fixed& source ) {
	return (this->getRawBits() <= source.getRawBits());
}

bool	Fixed::operator==( const Fixed& source ) {
	return (this->getRawBits() == source.getRawBits());
}

bool	Fixed::operator!=( const Fixed& source ) {
	return (this->getRawBits() != source.getRawBits());
}

//	Arithmetic operators
//
//		(Fixed-point values must be converted to float-point values to use the
//		standard addition operators (+, -, * and /) defined for float-point
//		numbers in C++.
//
Fixed Fixed::operator+(const Fixed &source) {
	return (Fixed(toFloat() + source.toFloat()));
}

Fixed Fixed::operator-(const Fixed &source) {
	return (Fixed(toFloat() - source.toFloat()));	
}

Fixed Fixed::operator*(const Fixed &source) {
	return (Fixed(toFloat() * source.toFloat()));
}

Fixed Fixed::operator/(const Fixed &source) {
	return (Fixed(toFloat() / source.toFloat()));
}

//	Increment and decrement operators
Fixed &Fixed::operator++( void ) {	// Implementation of the prefix increment operator (++x)
	this->_raw++;
	return (*this);
}

Fixed Fixed::operator++( int ) {	// Implementation of the postfix increment operator (x++) (1)
    Fixed temp(*this); 				// 	- create a copy of the current object
    operator++();           		// 	- increment the _raw member variable
    return temp;      				// 	- return the copy of the original object
}

/* --- Class public methods ------------------------------------------------- */

int	Fixed::getRawBits( void ) const {
	return this->_raw;
}

void	Fixed::setRawBits( int const raw) {
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

/*
 *	(1)	In the postfix increment operator (operator++(int)), the 'int' parameter 
 *		serves as a dummy parameter. It's a convention in C++ for distinguishing
 *		the postfix increment operator from the prefix increment operator 
 *		(operator++())
 */