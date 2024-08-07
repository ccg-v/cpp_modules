/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 20:11:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/02 00:31:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
Bureaucrat::Bureaucrat () : _name("Default"), _grade(150) {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& source)
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
Bureaucrat::~Bureaucrat ( void ) {
	std::cout << "Bureaucrat " << this->getName() << " destroyed by default destructor"
			  << std::endl;
}

/* --- Parameterized constructor -------------------------------------------- */

Bureaucrat::Bureaucrat ( const std::string& name, int grade )
	: _name(name) {
	std::cout << "Bureaucrat " << _name << " parameterized constructor called"
			  << std::endl;
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

//	VERSION WITH TRY-CATCH BLOCK
void	Bureaucrat::signForm(AForm& form) {
    try {
        form.beSigned(*this);
		std::cout << "\t" << _name << " (grade " << _grade << ") signed "
				  << form.getFormName() << " (grade " << form.getGradeToSign()
				  << " needed)" << std::endl;
    } catch (const std::exception& e) {
		std::cout << "\t" << _name << " (grade " << _grade
				  << ") couldn't sign " << form.getFormName()
				  << " (grade " << form.getGradeToSign() << " needed)" << ": "
				  << e.what() << std::endl;
    }
}

//	// VERSION WITHOUT TRY-CATCH BLOCK
// void Bureaucrat::signForm(AForm& form) {
// 	form.beSigned(*this);
// 	if (form.getIsSigned() == true) {
// 		std::cout << "\t" << _name << " (grade " << _grade << ") signed form "
// 				<< form.getFormName() << " (grade " << form.getGradeToSign()
// 				<< " needed)" << std::endl;
// 	} else {
// 		std::cout << "\t" << _name << " (grade " << _grade
// 				<< ") couldn't sign form " << form.getFormName()
// 				<< " (grade " << form.getGradeToSign() << " needed)" << ": " 
// 				<< GradeTooLowException().what() << std::endl;
// 		// throw GradeTooLowException();
//     }
// }

void	Bureaucrat::executeForm(AForm const & form) {
	try {
		form.execute(*this);
	} catch (const std::exception & e) {
		std::cout << "\t" << _name << " (grade " << _grade
				  << ") couldn't execute " << form.getFormName()
				  << " (grade " << form.getGradeToExecute() << " needed)" << ": "
				  << e.what() << std::endl;
	}
}

// Exceptions
const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Bureaucrat's grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return "Bureaucrat's grade is too low";
}

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << "\t" << b.getName() << ", bureaucrat grade: " << b.getGrade();
    return os;
}
