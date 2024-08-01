/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:11:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/01 11:15:23 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
Bureaucrat::Bureaucrat () : _name("Default"), _grade(150) {
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

//	Copy constructor
Bureaucrat::Bureaucrat ( const Bureaucrat& source )
	: _name(source._name), _grade(source._grade) {
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

//	Copy assignment operator
Bureaucrat	&Bureaucrat::operator=( const Bureaucrat& source ) {
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	// this->_name = source._name; // No name assignment because it is const
	this->_grade = source._grade;
	return (*this);
}

//	Default destructor
Bureaucrat::~Bureaucrat () {
	std::cout << "Bureaucrat " << this->getName() << " destroyed by default destructor"
			  << std::endl;
}

// //	Parameterized constructor
// Bureaucrat::Bureaucrat ( const std::string& name, int grade )
// 	: _name(name) {
// 	std::cout << "Parameterized constructor called" << std::endl;
// 	if (grade < 1)
// 		throw GradeTooHighException();
// 	else if (grade > 150)
// 		throw GradeTooLowException();
// 	_grade = grade;
// }
//	Parameterized constructor

Bureaucrat::Bureaucrat ( const std::string& name, int grade )
	: _name(name) {
	std::cout << "Parameterized constructor called" << std::endl;
	try {
		_grade = grade;
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	} catch (const std::exception& e) {
        std::cerr << "\tError creating bureaucrat " << name << " with grade "
		<< getGrade() << ": " << e.what() << std::endl;
    }
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

void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
		std::cout << "\t" << _name << " (grade " << _grade << ") signed form "
				  << form.getFormName() << " (grade " << form.getGradeToSign()
				  << " needed)" << std::endl;
    } catch (const std::exception& e) {
		if(this->getGrade() >=1 && this->getGrade() <= 150
			&& form.getGradeToSign() >= 1 && form.getGradeToSign() <= 150
			&& form.getGradeToExecute() >= 1 && form.getGradeToExecute() <= 150)
			std::cout << "\t" << _name << " (grade " << _grade
					<< ") couldn't sign form " << form.getFormName()
					<< " (grade " << form.getGradeToSign() << " needed)" << ": "
					<< e.what() << std::endl;
    }
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
	if (b.getGrade() >= 1 && b.getGrade() <= 150)
    	os << "\t" << b.getName() << ", bureaucrat grade: " << b.getGrade();
    return os;
}
