/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:43:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 12:34:46 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Animal::Animal( void ) : _type("Undefined animal") {
	std::cout << "\t[Animal default constructor called]" << std::endl;
};

//	Copy constructor
Animal::Animal( const Animal &source) {
	*this = source;
	std::cout << "\t[Animal copy constructor called] A copy of " 
			  << getType() << " has been constructed"
			  << std::endl;
};

//	Default destructor
Animal::~Animal( void ) {
	std::cout << "\t[Animal default destructor called] "
			  << getType() << " has been destructed" << std::endl;
};

//	Operator assignment overload
Animal &Animal::operator=( const Animal &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	return *this;
};

/* --- Constructor overload ------------------------------------------------- */

Animal::Animal( const std::string &type ) : _type(type) {
	std::cout << "\t[Animal constructor overload called] " 
			  << getType() << " has been constructed"
			  << std::endl;
};

/* --- Accessors ------------------------------------------------------------ */

std::string	Animal::getType( void ) const {
	return _type;
};

/* --- Methods -------------------------------------------------------------- */

void Animal::makeSound( void ) const {
	std::cout << "\t" << getType() << " says nothing" << std::endl;
}