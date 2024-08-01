/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 22:44:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/02 01:00:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>	// for 'std::ostream'

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Intern::Intern() {
	std::cout << "Intern default constructor called" << std::endl;
}

//	Copy constructor
Intern::Intern(const Intern & source) {
	std::cout << "Intern copy constructor called" << std::endl;
	// Currently, there's no instance-specific data to copy
	(void) source;	// To avoid unused parameter warning
}

//	Copy assignment operator
Intern &Intern::operator=(const Intern & source) {
	std::cout << "Intern copy assignment operator called" << std::endl;
	if (this == &source) {
		// Currently, there's nothing to copy
	}
	return (*this);
}

//	Default destructor
Intern::~Intern() {
	std::cout << "Intern default destructor called" << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

AForm* Intern::makeForm(const std::string & formName, const std::string & target) {
	for (int i = 0; i < 3; i++) {
		if (formName == formNamesArray[i]) {
			std::cout << *this << " has created a " << formName << std::endl	// (2)
					  << std::endl; 
			return (formFunctionsArray[i](target));
		}
	}
	std::cout << *this << " couldn't create a " << formName << " (not a valid form)";
	return (NULL);
}

/* --- Non-member functions ---------------------------------------------------- */

AForm* createShrubberyForm(const std::string & target) {
	return (new ShrubberyCreationForm(target));
}

AForm* createRobotomyForm(const std::string & target) {
	return (new RobotomyRequestForm(target));
}

AForm* createPardonForm(const std::string & target) {
	return (new PresidentialPardonForm(target));
}

// Insertion Operator Overload (1)
std::ostream& operator<<(std::ostream& os, const Intern& /*intern*/) {	// (3)
    os << "\tthe intern guy";
    return os;
}

/* --- Private static members initialization -------------------------------- */

const std::string	Intern::formNamesArray[] = { "ShrubberyCreationForm",
	"RobotomyRequestForm", "PresidentialPardonForm" };

AForm* (*Intern::formFunctionsArray[])(const std::string &) = {
	createShrubberyForm, createRobotomyForm, createPardonForm
};

/*
 *	(1)	The primary purpose of overloading the insertion operator (<<) is to
 *		define how an object should be represented when output to a  stream,
 *		typically for printing or logging.
 *
 *		This operator is called whenever you try to output an object of  the 
 *		class (in this case, an Intern object) using the << operator with an
 *		output stream (like std::cout)
 */

/*
 *	(2)	Intern objects have no name. However, in the main every object is 
 *		identified with a name when it is instantiated:
 *
 *			Intern	intern_guy;
 *
 * 		I wanted that identifier to appear when the 'makeForm()' function
 * 		is executed. To do so:
 * 
 * 			1. I use '*this' to refer to the current Intern object
 * 			2. Using the insertion operator '<<' with '*this' will call
 * 				our overloaded 'operator<<' function
 * 			3. This will print "an intern guy" (as defined in my insertion
 * 				operator overload) before the rest of the message.
 */

/*
 *	(3)	By commenting out the parameter name intern in the function definition, 
 *		we tell the compiler that we intentionally don't use this parameter. 
 *		This is a common C++ idiom for avoiding unused parameter warnings.
 *		This change should resolve the compiler error while still maintaining
 *		the functionality of the operator<< for the Intern class.
 */