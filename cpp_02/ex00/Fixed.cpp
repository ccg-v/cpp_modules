/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:07:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/21 19:25:32 by ccarrace         ###   ########.fr       */
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
}

/*	Copy assignment operator constructor	*/
Fixed& Fixed::operator=(const Fixed& source) {
  if (this != &source) {	// Prevent self-assignment
    _fixedPoint = source._fixedPoint;
  }
  std::cout << "Copy assignment operator called" << std::endl;
  return *this;
}

/*	Destructor implementation				*/
Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}