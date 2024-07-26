/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/27 00:18:59 by ccarrace         ###   ########.fr       */
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
	newShrubberyForm->execute(low_officer);
	newShrubberyForm->execute(medium_officer);
	delete newShrubberyForm;
    std::cout << std::endl;

/* --- RobotomyRequestForm process ------------------------------------------ */

	std::cout << "/* --- RobotomyRequestForm process (72, 45) -------------- /*"
		<< std::endl << std::endl;

	newRobotomyForm = intern_guy.makeForm("RobotomyRequestForm", "Marvin the Paranoid Android");
	low_officer.signForm(*newRobotomyForm);
	medium_officer.signForm(*newRobotomyForm);
	newRobotomyForm->execute(medium_officer);
	newRobotomyForm->execute(high_officer);
	delete newRobotomyForm;
    std::cout << std::endl;

/* --- PresidentialPardonForm process --------------------------------------- */

	std::cout << "/* --- PresidentialPardonForm process (25, 5) ------------ /*"
	<< std::endl << std::endl;

	newPardonForm = intern_guy.makeForm("PresidentialPardonForm", "Vogon poet");
	low_officer.signForm(*newPardonForm);
	medium_officer.signForm(*newPardonForm);
	high_officer.signForm(*newPardonForm);
	newPardonForm->execute(low_officer);
	newPardonForm->execute(medium_officer);
	newPardonForm->execute(high_officer);
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
