/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/30 23:38:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	Bureaucrat 	low_officer("assistant Bob", 145);
	Bureaucrat	medium_officer("executive Carol", 70);
	Bureaucrat	high_officer("head Boss", 3);
	Intern		intern_guy;

	AForm*		newRobotomyForm;
	AForm*		newShrubberyForm;
	AForm*		newPardonForm;
	AForm*		wrongForm;

/* --- Instances ------------------------------------------------------------ */

    std::cout << std::endl;
	std::cout << "/* --- Instances ----------------------------------------- /*"
			  << std::endl;

	std::cout << std::endl;
    std::cout << low_officer << std::endl;
	std::cout << medium_officer << std::endl;
	std::cout << high_officer << std::endl;
	std::cout << intern_guy << std::endl;
	std::cout << std::endl;

/* --- ShrubberyCreationForm process ---------------------------------------- */

	std::cout << "/* --- ShrubberyCreationForm process (145, 137) ---------- /*"
			  << std::endl << std::endl;

	newShrubberyForm = intern_guy.makeForm("ShrubberyCreationForm", "Forest");
	low_officer.signForm(*newShrubberyForm);
	low_officer.executeForm(*newShrubberyForm);
	medium_officer.executeForm(*newShrubberyForm);
	delete newShrubberyForm;
    std::cout << std::endl;

/* --- RobotomyRequestForm process ------------------------------------------ */

	std::cout << "/* --- RobotomyRequestForm process (72, 45) -------------- /*"
		<< std::endl << std::endl;

	newRobotomyForm = intern_guy.makeForm("RobotomyRequestForm", "Marvin the Paranoid Android");
	low_officer.signForm(*newRobotomyForm);
	medium_officer.signForm(*newRobotomyForm);
	low_officer.executeForm(*newRobotomyForm);
	medium_officer.executeForm(*newRobotomyForm);
	high_officer.executeForm(*newRobotomyForm);
	delete newRobotomyForm;
    std::cout << std::endl;

/* --- PresidentialPardonForm process --------------------------------------- */

	std::cout << "/* --- PresidentialPardonForm process (25, 5) ------------ /*"
	<< std::endl << std::endl;

	newPardonForm = intern_guy.makeForm("PresidentialPardonForm", "Vogon poet");
	low_officer.signForm(*newPardonForm);
	medium_officer.signForm(*newPardonForm);
	high_officer.signForm(*newPardonForm);
	low_officer.executeForm(*newPardonForm);
	medium_officer.executeForm(*newPardonForm);
	high_officer.executeForm(*newPardonForm);
	delete newPardonForm;
    std::cout << std::endl;

/* --- wrongForm process ---------------------------------------------------- */	

	std::cout << "/* --- wrongForm process --------------------------------- /*"
	<< std::endl << std::endl;

	wrongForm = intern_guy.makeForm("wrongForm", "anyone");
	delete wrongForm;

	std::cout << std::endl;
    return 0;
}
