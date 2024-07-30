/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/30 19:03:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	Bureaucrat 				low_officer("assistant Bob", 150);
	Bureaucrat				medium_officer("executive Carol", 70);
	Bureaucrat				high_officer("head Boss", 3);
	ShrubberyCreationForm	shrubbery_form("Garden");
	RobotomyRequestForm		robotomy_form("Marvin the Paranoid Android");	
	PresidentialPardonForm	pardon_form("Vogon poet");

/* --- Instances ------------------------------------------------------------ */

    std::cout << std::endl
		<< "/* --- Instances --------------------------------------------- /*\n"
		<< std::endl;

    std::cout << low_officer << std::endl;
	std::cout << medium_officer << std::endl;
	std::cout << high_officer << std::endl;
	std::cout << std::endl;
    std::cout << shrubbery_form << std::endl;
    std::cout << robotomy_form << std::endl;
    std::cout << pardon_form << std::endl;

/* --- ShrubberyCreationForm process ---------------------------------------- */

    std::cout << std::endl
		<< "/* --- ShrubberyCreationForm process (145, 137) -------------- /*\n"
		<< std::endl;

	low_officer.signForm(shrubbery_form);
	medium_officer.signForm(shrubbery_form);
	low_officer.executeForm(shrubbery_form);
	medium_officer.executeForm(shrubbery_form);

/* --- RobotomyRequestForm process ------------------------------------------ */

    std::cout << std::endl
		<< "/* --- RobotomyRequestForm process (72, 45) ------------------ /*\n"
		<< std::endl;

	low_officer.signForm(robotomy_form);
	medium_officer.signForm(robotomy_form);
	high_officer.signForm(robotomy_form);
	low_officer.executeForm(robotomy_form);
	medium_officer.executeForm(robotomy_form);
	high_officer.executeForm(robotomy_form);

/* --- PresidentialPardonForm process --------------------------------------- */

    std::cout << std::endl
		<< "/* --- PresidentialPardonForm process (25, 5) ---------------- /*\n"
		<< std::endl;

	low_officer.signForm(pardon_form);
	medium_officer.signForm(pardon_form);
	high_officer.signForm(pardon_form);
	low_officer.executeForm(pardon_form);
	medium_officer.executeForm(pardon_form);
	high_officer.executeForm(pardon_form);

    std::cout << std::endl;
    return 0;
}
