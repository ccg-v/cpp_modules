/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:29:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 13:41:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Brain::Brain( void ) {
	std::cout << "[Brain Default Constructor called]" << std::endl;
};

//	Copy constructor
Brain::Brain( const Brain &source) {
	std::cout << "[Brain Copy Constructor called]" << std::endl;
	*this == source;
}

//	Assignment operator overload
Brain &Brain::operator=( const Brain &source ) {
	std::cout << "[Brain Assignment Operator Overload called]"
	if (*this == source)
		return *this;
	

}