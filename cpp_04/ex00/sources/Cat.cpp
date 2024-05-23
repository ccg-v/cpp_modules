/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 21:00:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor
Cat::Cat( void ) : Animal() {
	std::cout << "\t[Cat default constructor called]" << std::endl;
	_type = "Cat";
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
	return *this;
}

//	Default destructor
Cat::~Cat( void ) {
	std::cout << "\t[Cat default destructor called] " 
			  << getType() << " has been destructed"
			  << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

void	Cat::makeSound( void ) const {
	std::cout << "\t" << getType () << " meows: 'Meeeeeow!'" << std::endl;
}