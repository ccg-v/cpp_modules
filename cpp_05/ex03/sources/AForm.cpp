/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 23:18:40 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/21 13:29:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* --- Orthodox Canonical AForm --------------------------------------------- */

//	Default constructor
AForm::AForm () : _formName("Default"), _isSigned(false), _gradeToSign(100),
				_gradeToExecute(50) {
	std::cout << "Default AForm constructor called" << std::endl;
}

//	Copy constructor
AForm::AForm ( const AForm& source ) : _formName(source._formName),
	_isSigned(source._isSigned), _gradeToSign(source._gradeToSign),
	_gradeToExecute(source._gradeToExecute) {
	*this = source;
}

//	Copy assignment operator
AForm &AForm::operator=( const AForm& source ) {
	if (this != &source)
		this->_isSigned = source._isSigned;
	return (*this);
}

//	Default destructor
AForm::~AForm () {
	std::cout << "AForm " << getFormName() << " destroyed by default destructor"
			  << std::endl;
}

// Parameterized constructor
AForm::AForm(const std::string& AFormName, const int gradeToSign, const int gradeToExecute)
    : _formName(AFormName), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
    std::cout << "AForm parameterized constructor called" << std::endl;
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    else if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}


/* --- Getters ------------------------------------------------------------- */

const std::string	&AForm::getFormName () const {
	return _formName;
}

bool	AForm::getIsSigned () const {
	return _isSigned;
}

int	AForm::getGradeToSign () const {
	return _gradeToSign;
}

int	AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

/* --- Member functions ---------------------------------------------------- */	

void	AForm::beSigned ( Bureaucrat bureaucrat ) {
	if (_isSigned == true)
		throw IsAlreadySignedException();
	if (bureaucrat.getGrade() > getGradeToSign())
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(Bureaucrat const & executor) const {
	try {
		if (!this->getIsSigned())
		{
			std::cout << "\t" << getFormName() << " couldn't be executed: ";
			throw IsNotSignedException();
		}
		if (executor.getGrade() > this->getGradeToExecute())
		{
			std::cout << "\t" << executor.getName() << " (grade " << executor.getGrade()
				  << ") couldn't execute form " << getFormName()
				  << " (grade " << getGradeToExecute() << " needed)" << ": ";		
			throw GradeTooLowException();
		} 
		std::cout << "\t" << executor.getName() <<  " (grade " << executor.getGrade()
				  << ") executed form " << getFormName()
				  << " (grade " << getGradeToExecute() << " needed)" << std::endl;
		this->performAction();
    // } catch (const AForm::GradeTooLowException &e) {
    //     std::cerr << e.what() << std::endl;
    // } catch (const AForm::IsNotSignedException &e) {
    //     std::cerr << "Caught exception: " << e.what() << std::endl;
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}

//	Exceptions
const char* AForm::GradeTooHighException::what() const throw() {
    return "Grade is too high";
}

const char* AForm::GradeTooLowException::what() const throw() {
    return "Grade is too low";
}

const char* AForm::IsAlreadySignedException::what() const throw() {
    return "Form is already signed";
}

const char* AForm::IsNotSignedException::what() const throw() {
    return "Form is not signed";
}

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const AForm& f) {
    os << "\tAForm " << f.getFormName() << ", Signed: " << f.getIsSigned()
       << ", Grade to Sign: " << f.getGradeToSign()
       << ", Grade to Execute: " << f.getGradeToExecute();
    return os;
}