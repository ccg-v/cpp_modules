/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 12:35:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor
Cat::Cat( void ) : Animal("Cat") {
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
	return *this;
}

//	Default destructor
Cat::~Cat( void ) {
	std::cout << "\t[Cat default destructor called] " 
			  << getType() << " has been destructed"
			  << std::endl;
}

/* --- Constructor overload ------------------------------------------------- */

// Cat::Cat( const std::string &type) : Animal(type) {
// 	std::cout << "[Cat overload constructor called]" 
// 			  << getType() << " has been constructed"
// 			  << std::endl;
// }

/* --- Member methods ------------------------------------------------------- */

void	Cat::makeSound( void ) const {
	std::cout << "\t" << getType () << " meows: 'Meeeeeow!'" << std::endl;
}