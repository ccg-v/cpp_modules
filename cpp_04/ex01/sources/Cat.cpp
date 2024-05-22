/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 00:52:28 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor	
Cat::Cat( void ) {	//	(1)
	_type = "Cat";
	_brain = new Brain;
	std::cout << "\t[Cat default constructor called]" << std::endl;
}

//	Copy constructor
Cat::Cat( const Cat &source) : Animal(source) {
	*this = source;
	std::cout << "\t[Cat copy constructor called]" << std::endl;
}

//	Operator assignment overload
Cat &Cat::operator=( const Cat &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	_brain = new Brain(*source._brain);
	return *this;
}

//	Default destructor
Cat::~Cat( void ) {
	delete _brain;
	std::cout << "\t[Cat default destructor called] " 
			  << getType() << " has been destructed"
			  << std::endl;
}

/* --- Accessors ------------------------------------------------------------ */

Brain	*Cat::getBrain( void ) const {
	return _brain;
}

/* --- Member methods ------------------------------------------------------- */

void	Cat::makeSound( void ) const {
	std::cout << "\t" << getType () << " meows: 'Meeeeeow!'" << std::endl;
}

/*
 *	(1) More concise implementation of the constructor:
 *
 *		Cat::Cat( void ) : Animal("Cat"), _brain(new Brain) {
 *			std::cout << "\t[Cat default constructor called]" << std::endl;
 *		}
 */