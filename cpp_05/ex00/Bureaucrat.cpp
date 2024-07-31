/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:11:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/31 11:00:36 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
Bureaucrat::Bureaucrat () : _name("Default"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
Bureaucrat::Bureaucrat ( const Bureaucrat& source ) 
	: _name(source._name), _grade(source._grade) {
	std::cout << "Default copy constructor called" << std::endl;
}

//	Copy assignment operator
Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& source ) {
	std::cout << "Default copy assignment operator called" << std::endl;
	if (this != &source) {
		// this->_name = source._name; // No name assignment because it is const
		this->_grade = source._grade;
	}
	return (*this);
}

//	Default destructor
Bureaucrat::~Bureaucrat ( void ) {
	std::cout << "Bureaucrat " << getName() << " destroyed by default destructor"
			  << std::endl;
}

//	Parameterized constructor
Bureaucrat::Bureaucrat ( const std::string& name, int grade )
	: _name(name) {
	std::cout << "Parameterized constructor called" << std::endl;
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

/* --- Getters -------------------------------------------------------------- */

const std::string &Bureaucrat::getName() const {
	return _name;
}

int	Bureaucrat::getGrade() const {
	return _grade;
}

/* --- Member functions ----------------------------------------------------- */

void	Bureaucrat::incrementGrade (int increment) {
	if ((_grade - increment) >= 1)
		_grade = _grade - increment;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade (int decrement) {
	if ((_grade + decrement) <= 150)
		_grade = _grade + decrement;
	else
		throw GradeTooLowException();
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << "\t" << b.getName() << ", bureaucrat grade " << b.getGrade();
    return os;
}
