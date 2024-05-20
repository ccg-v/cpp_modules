/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:37:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 01:14:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

/* --- Orthodox Canonical Form --------------------------------------------- */

//	Default constructor
WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
	std::cout << "\t[WrongCat default constructor called]" << std::endl;
}

//	Copy constructor
WrongCat::WrongCat( const WrongCat &source) : WrongAnimal(source) {
	*this = source;
	std::cout << "\t[WrongCat copy constructor called]" << std::endl;
}

//	Operator assignment overload
WrongCat &WrongCat::operator=( const WrongCat &source ) {
	if (this == &source)
		return *this;
	_type = source._type;
	return *this;
}

//	Default destructor
WrongCat::~WrongCat( void ) {
	std::cout << "\t[WrongCat default destructor called]" 
			  << getType() << " has been destructed"
			  << std::endl;
}

/* --- Constructor overload ------------------------------------------------- */

// WrongCat::WrongCat( const std::string &type) : WrongAnimal(type) {
// 	std::cout << "[WrongCat overload constructor called]" 
// 			  << getType() << " has been constructed"
// 			  << std::endl;
// }

/* --- Member methods ------------------------------------------------------- */

void	WrongCat::makeSound( void ) const {
	std::cout << getType () << " meows: 'Meeeeeow!'" << std::endl;
}