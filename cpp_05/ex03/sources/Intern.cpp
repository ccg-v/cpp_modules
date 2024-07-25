/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:44:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/26 00:37:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

//	Copy constructor
Intern::Intern(const Intern & source) {
	std::cout << "Intern copy constructor called" << std::endl;
	*this = source;
}

//	Copy assignment operator
Intern &Intern::operator=(const Intern & source) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	return (*this);
}

//	Default destructor
~Intern() {
	std::cout << "Intern default destructor called" << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

AForm* makeForm(const std::string & formType, const std::string & target) {
	
}
