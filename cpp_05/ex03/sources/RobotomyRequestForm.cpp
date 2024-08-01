/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:22:20 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/02 00:39:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <cstdlib>	//	std::rand()
#include <ctime>    // For std::time

/* --- Orthodox Canonical Form implementation ------------------------------- */

//	Default constructor
RobotomyRequestForm::RobotomyRequestForm()
	: AForm("Default RobotomyRequestForm", 72, 45), _target("Unknown") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

//	Copy constructor
RobotomyRequestForm::RobotomyRequestForm (const RobotomyRequestForm & source)
	: AForm(source), _target(source._target) {
		std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

//	Copy assignment operator
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm & source) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this == &source)
		return (*this);
	AForm::operator=(source);
	_target = source._target;
	return (*this);
}

//	Default destructor
RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm default destructor called" << std::endl;
}

/* --- Parameterized constructor -------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm( const std::string & target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void	RobotomyRequestForm::performAction() const {
	std::srand(std::time(0));
	int	robotomyResult = std::rand() % 2;
	std::cout << "\n\t(((buzzzZZZZ...hummmMMM...rrRROOoBotoMMizzZZinnng...CLONK... ping!)))"
			  << std::endl;
	if (robotomyResult == 0)
		std::cout << "\t" << _target << " robotomy process finished succesfully" 
				  << std::endl;
	else
		std::cout << "\t" << _target << " robotomy process failed" 
				  << std::endl;
}
