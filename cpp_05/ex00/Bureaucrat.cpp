/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:11:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/18 00:22:57 by ccarrace         ###   ########.fr       */
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
Bureaucrat::Bureaucrat () : _name("Default"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
Bureaucrat::Bureaucrat ( const Bureaucrat& source ) {
	*this = source;
}

//	Copy assignment operator
Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& source ) {
	if (this == &source)
		return (*this);
	// this->_name = source._name; // No name assignment because it is const
	this->_grade = source._grade;
	return (*this);
}

//	Default destructor
Bureaucrat::~Bureaucrat ( void ) {
	std::cout << "Bureaucrat " << getName() << " destroyed by default destructor"
			  << std::endl;
}

//	Parameterized constructor
Bureaucrat::Bureaucrat ( const std::string& name, int grade )
	: _name(name), _grade(grade) {
	std::cout << "Parameterized constructor called" << std::endl;
}

/* --- Getters -------------------------------------------------------------- */

const std::string &Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

/* --- Member functions ----------------------------------------------------- */

void	Bureaucrat::incrementGrade (int grade) {
	if ((_grade - grade) > 1)
		this->_grade -= grade;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade (int grade) {
	if ((_grade + grade) < 150)
		this->_grade += grade;
	else
		throw GradeTooLowException();
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}
