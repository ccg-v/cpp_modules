/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:21:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/23 00:47:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("Default ShrubberryCreationForm", 145, 137), _target("Unknown") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

//	Copy constructor (1)
ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm & source)
	: AForm(source), _target(source._target) {
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

//	Copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm & source) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	AForm::operator=(source);  // Call the base class assignment operator to copy its members
	_target = source._target;
	return (*this);
}

//	Default destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm default destructor called" << std::endl;
}

/*
 *	(1) Initialization list vs. Copy assignment (*this = source)
 *
 * 	Copy assignment:
 * 
 * 	ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source)
 *  	: AForm(source) { 	// Initialize base class
 *   		*this = source; // Use assignment operator to copy
 *   		std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
 *	}
 *
 * 	Initialization list;
 * 
 * 	ShrubberyCreationForm::ShrubberyCreationForm (const ShrubberyCreationForm & source)
 *		: AForm(source), _target(source._target) {
 *			std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
 * 
 * 	The copy assignment operator is used to assign values from one already-constructed 
 *	object to another already-constructed object. This process involves:
 *
 *	Existing Object:
 *      The destination object must already be constructed and initialized, but 
 *		potentially with default or previously set values.
 *
 *  Overwriting Values:
 *      The copy assignment operator then overwrites these existing values with the 
 * 		values from the source object. This can lead to intermediate states where
 * 		members are default-initialized or contain old values before they are overwritten.
 * 
 * 	Instead, initialization list initializes members directly when the object is created.
 * 	There’s no intermediate state where members are uninitialized or partially initialized.
 * 
 *	The copy assignment operator is not intended for initializing a new object; instead,
 *	it is designed for reassigning an existing object's state. When used correctly, it is
 *	a safe and essential part of managing objects, especially when dealing with dynamic
 *	resources or complex states. 
 */