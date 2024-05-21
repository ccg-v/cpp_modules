/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:29:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/21 21:38:24 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"
#include <sstream>

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Brain::Brain( void ) {
	std::cout << "\t[Brain Default Constructor called]" << std::endl;
	std::stringstream ss;
	for (int i = 0; i < 100; i++) {
		ss << i;	//	Append 'i' to the streamstring (but still remains as integer)
		_ideas[i] = "idea_" + ss.str();	// Here stringstream is converted to string
	}
};

//	Copy constructor
Brain::Brain( const Brain &source) {
	std::cout << "\t[Brain Copy Constructor called]" << std::endl;
	*this = source;
}

//	Assignment operator overload
Brain &Brain::operator=( const Brain &source ) {
	std::cout << "\t[Brain Assignment Operator Overload called]" << std::endl;
	if (this == &source)
		return *this;
	for (int i = 0; i < 100; i++) {
		_ideas[i] = source._ideas[i];
	}
	return *this;
};

//	Copy destructor
Brain::~Brain( void ) {
	std::cout << "\t[Brain Destructor called]" << std::endl;
};

/* --- Accessors ------------------------------------------------------------ */

std::string	const &Brain::getIdea( int index ) const {
	return _ideas[index];
}

void	Brain::setIdea( int index, std::string const &idea) {
	_ideas[index] = idea;
}