/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:23:38 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/25 21:08:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("Default PresidentialPardonForm", 25, 5), _target("Unknown") {
		std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

//	Copy constructor
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & source) 
	: AForm(source), _target(source._target) {
		std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

//	Copy assignment operator
PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm & source) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &source) {
		AForm::operator=(source);
		_target = source._target;
	}
	return (*this);
}

//	Default destructor
PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm default destructor called" << std::endl;
}

/* --- Parameterized constructor -------------------------------------------- */

PresidentialPardonForm::PresidentialPardonForm(const std::string & target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void	PresidentialPardonForm::performAction() const {
	std::cout << "\t" << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}