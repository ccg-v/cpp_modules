/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:43:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 20:29:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
AAnimal::AAnimal( void ) : _type("Undefined AAAnimal") {
	std::cout << "\t[AAnimal default constructor called]" << std::endl;
};

//	Copy constructor
AAnimal::AAnimal( const AAnimal &source) {
	*this = source;
	std::cout << "\t[AAnimal copy constructor called] A copy of " 
			  << getType() << " has been constructed"
			  << std::endl;
};

//	Default destructor
AAnimal::~AAnimal( void ) {
	std::cout << "\t[AAnimal default destructor called] "
			  << getType() << " has been destructed" << std::endl;
};

//	Operator assignment overload
AAnimal &AAnimal::operator=( const AAnimal &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	return *this;
};

/* --- Constructor overload ------------------------------------------------- */

AAnimal::AAnimal( const std::string &type ) : _type(type) {
	std::cout << "\t[AAnimal constructor overload called] " 
			  << getType() << " has been constructed"
			  << std::endl;
};

/* --- Accessors ------------------------------------------------------------ */

std::string	AAnimal::getType( void ) const {
	return _type;
};

/* --- Methods -------------------------------------------------------------- */

void AAnimal::makeSound( void ) const {
	std::cout << "\t" << getType() << " says nothing" << std::endl;
}