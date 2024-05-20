/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:43:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 01:07:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
WrongAnimal::WrongAnimal( void ) : _type("Undefined wrong animal") {
	std::cout << "\t[WrongAnimal default constructor called]" << std::endl;
};

//	Copy constructor
WrongAnimal::WrongAnimal( const WrongAnimal &source) {
	*this = source;
	std::cout << "\t[WrongAnimal copy constructor called] A copy of " 
			  << getType() << " has been constructed"
			  << std::endl;
};

//	Default destructor
WrongAnimal::~WrongAnimal( void ) {
	std::cout << "\t[WrongAnimal default destructor called] "
			  << getType() << " has been destructed" << std::endl;
};

//	Operator assignment overload
WrongAnimal &WrongAnimal::operator=( const WrongAnimal &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	return *this;
};

/* --- Constructor overload ------------------------------------------------- */

WrongAnimal::WrongAnimal( const std::string &type ) : _type(type) {
	std::cout << "\t[WrongAnimal constructor overload called] " 
			  << getType() << " has been constructed"
			  << std::endl;
};

/* --- Accessors ------------------------------------------------------------ */

std::string	WrongAnimal::getType( void ) const {
	return _type;
};

/* --- Methods -------------------------------------------------------------- */

void WrongAnimal::makeSound( void ) const {
	std::cout << getType() << " says nothing" << std::endl;
}