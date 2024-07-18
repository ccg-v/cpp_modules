/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:18:40 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/19 00:31:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Form::Form () : _formName("Default"), _isSigned(false), _gradeToSign(100),
				_gradeToExecute(50) {
	std::cout << "Default form constructor called" << std::endl;
}

//	Copy constructor
Form::Form ( const Form& source ) {
	*this = source;
}

//	Copy assignment operator
Form &Form::operator=( const Form& source ) {
	if (this != &source)
	{
		// this->_formName = source._formName;
		this->_isSigned = source._isSigned;
		// this->_gradeToSign = source._gradeToSign;
		// this->_gradeToExecute = source._gradeToExecute;
	}
	return (*this);
}

//	Default destructor
Form::~Form () {
	std::cout << "Form " << getFormName() << " destroyed by default destructor"
			  << std::endl;
}

//	Parameterized constructor
Form::Form ( const std::string& formName, const int gradeToSign,
			const int gradeToExecute) : _formName = formName {
	std::cout << "Form parameterized constructor called" << std::endl;
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	_gradeToSign = gradeToSign;
	_gradeToExecute = gradeToExecute;
	_isSigned = false;
}

/* --- Getters ------------------------------------------------------------- */

const std::string	&Form::getFormName () const {
	return _formName;
}
int	Form::getGradeToSign () const {
	return _gradeToSign;
}

int	Form::getGradeToExecute() const {
	return _gradeToExecute;
}

/* --- Member functions --------------------------------------------- */	

void	Form::beSigned ( Bureaucrat bureaucrat ) {

}

void	Form::signForm () {

}

//	Exceptions
const char* Form::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Bureaucrat& b, const Form& f) {
    os << b.getName() << " couldn't sign form " << f.getFormName << ": () ";
    return os;
}