/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/25 21:27:21 by ccarrace         ###   ########.fr       */
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

    std::cout << std::endl;
	std::cout << "/* --- Instances ----------------------------------------- /*"
			  << std::endl << std::endl;

	std::cout << std::endl;
    std::cout << low_officer << std::endl;
	std::cout << medium_officer << std::endl;
	std::cout << high_officer << std::endl;
	std::cout << std::endl;
    std::cout << shrubbery_form << std::endl;
    std::cout << robotomy_form << std::endl;
    std::cout << pardon_form << std::endl;
	std::cout << std::endl;

/* --- ShrubberyCreationForm process ---------------------------------------- */

    std::cout << std::endl;
	std::cout << "/* --- ShrubberyCreationForm process (145, 137) ---------- /*"
			  << std::endl << std::endl;

	low_officer.signForm(shrubbery_form);
	medium_officer.signForm(shrubbery_form);
	shrubbery_form.execute(low_officer);
	shrubbery_form.execute(medium_officer);

/* --- RobotomyRequestForm process ------------------------------------------ */

    std::cout << std::endl;
	std::cout << "/* --- RobotomyRequestForm process (72, 45) -------------- /*"
	<< std::endl << std::endl;

	low_officer.signForm(robotomy_form);
	medium_officer.signForm(robotomy_form);
	high_officer.signForm(robotomy_form);
	robotomy_form.execute(low_officer);
	robotomy_form.execute(medium_officer);
	robotomy_form.execute(high_officer);

/* --- PresidentialPardonForm process --------------------------------------- */

    std::cout << std::endl;
	std::cout << "/* --- PresidentialPardonForm process (25, 5) ------------ /*"
	<< std::endl << std::endl;

	low_officer.signForm(pardon_form);
	medium_officer.signForm(pardon_form);
	high_officer.signForm(pardon_form);
	pardon_form.execute(low_officer);
	pardon_form.execute(medium_officer);
	pardon_form.execute(high_officer);

    std::cout << std::endl;
    return 0;
}
