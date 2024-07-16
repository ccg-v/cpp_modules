/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:11:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/17 00:20:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	1. If class is written in OCF, do I have to define a default constructor 
//		although it is not needed?
//	2. Exception functions are classes or void functions?
//	3. Correct name is 'copy assignment operator' or 'operator assignment overload'?
//	4. Why copy assignment operator is different? Bureaucrat &Bureaucrat::(...) instead
//		of Bureaucrat::Bureaucrat ()
//	5. Semicolon trailing all OCF functions?

#include "Bureaucrat.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
Bureaucrat::Bureaucrat ( std::string& name, int grade )
	: _name("Unknown"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
Bureaucrat::Bureaucrat ( const Bureaucrat& source ) {
	*this = source;
}

//	Copy assignment operator
Bureaucrat	&Bureaucrat::operator= ( const Bureaucrat& source ) {
	if (this == &source)
		return (*this);
	this->_name = source._name;
	this->_grade = source._grade;
	return (*this);
}

//	Default destructor
Bureaucrat::~Bureaucrat ( void ) {
	std::cout << "Bureaucrat " << getName() << " destroyed by default destructor"
			  << std::endl;
}

/* --- Getters -------------------------------------------------------------- */

const std::string &Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

/* --- Member functions ----------------------------------------------------- */

void	Bureaucrat::incrementGrade () {
	if (this->_grade <= 150 && this->_grade > 1)
		this->_grade++;
	else
		throw GradeTooLowException();
}

void	Bureaucrat::decrementGrade () {
	if (this->_grade >= 1 && this->_grade < 150)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void	GradeTooHighException () {

}

void Bureaucrat::safeIncrement() {
    try {
        this->incrementGrade();
    } catch (const GradeTooHighException& e) {
        std::cerr << "Cannot increment: " << e.what() << std::endl;
    }
}

