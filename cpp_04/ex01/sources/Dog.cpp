/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 21:43:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor
Dog::Dog( void ) : Animal("Dog") {
	std::cout << "\t[Dog default constructor called]" << std::endl;
}

//	Copy constructor
Dog::Dog( const Dog &source) : Animal(source) {
	*this = source;
	std::cout << "\t[Dog copy constructor called]" << std::endl;
}

//	Operator assignment overload
Dog &Dog::operator=( const Dog &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	return *this;
}

//	Default destructor
Dog::~Dog( void ) {
	delete _brain;
	std::cout << "\t[Dog default destructor called]" 
			  << getType() << " has been destructed"
			  << std::endl;
}

/* --- Constructor overload ------------------------------------------------- */

// Dog::Dog( const std::string &type) : Animal(type) {
// 	std::cout << "[Dog overload constructor called]" 
// 			  << getType() << " has been constructed"
// 			  << std::endl;
// }

/* --- Member methods ------------------------------------------------------- */

void	Dog::makeSound( void ) const {
	std::cout << "\t" << getType () << " barks: 'Woof, woof!'" << std::endl;
}
