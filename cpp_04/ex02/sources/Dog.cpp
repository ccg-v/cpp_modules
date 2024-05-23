/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 21:14:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor
Dog::Dog( void ) : AAnimal() {	//	(1)
	std::cout << "\t[Dog default constructor called]" << std::endl;
	_type = "Dog";
	_brain = new Brain;
}

//	Copy constructor
Dog::Dog( const Dog &source) : AAnimal(source) {
	std::cout << "\t[Dog copy constructor called]" << std::endl;
	*this = source;
}

//	Operator assignment overload
Dog &Dog::operator=( const Dog &source ) {
	std::cout << "\t[Dog copy assignment operator called]" << std::endl;	
	if (this != &source) {
		this->_type = source._type;
		this->_brain = new Brain(*source._brain);
	}
	return (*this);
}

//	Default destructor
Dog::~Dog( void ) {
	std::cout << "\t[Dog default destructor called] " << getType() 
			  << " has been destructed" << std::endl;
		delete _brain;
}

/* --- Accessors ------------------------------------------------------------ */

Brain	*Dog::getBrain( void ) const {
	return _brain;
}

/* --- Member methods ------------------------------------------------------- */

void	Dog::makeSound( void ) const {
	std::cout << "\t" << getType () << " barks: 'Woof, woof!'" << std::endl;
}

/*
 *	(1) More concise implementation of the constructor:
 *
 *		Dog::Dog( void ) : AAnimal("Dog"), _brain(new Brain) {
 *			std::cout << "\t[Dog default constructor called]" << std::endl;
 *		}
 */