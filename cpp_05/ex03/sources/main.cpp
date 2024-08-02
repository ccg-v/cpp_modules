/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/02 13:56:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {
    try {
        std::cout << std::endl
                  << "/* --- ShrubberyCreationForm process (145, 137) -------------- /*\n"
                  << std::endl;

        Bureaucrat	low_officer("assistant Bob", 150);
        Bureaucrat	medium_officer("executive Carol", 70);
		Intern		intern_guy;
		AForm*		newShrubberyForm;

		std::cout << std::endl;
		std::cout << low_officer << std::endl;
        std::cout << medium_officer << std::endl;
        std::cout << intern_guy << std::endl;
		std::cout << std::endl;

		newShrubberyForm = intern_guy.makeForm("ShrubberyCreationForm", "Forest");
		
		std::cout << std::endl;
        low_officer.signForm(*newShrubberyForm);
        medium_officer.signForm(*newShrubberyForm);
        low_officer.executeForm(*newShrubberyForm);
        medium_officer.executeForm(*newShrubberyForm);
		std::cout << std::endl;

		delete newShrubberyForm;
		
    } catch (const std::exception & e) {
        std::cout << "\tError: " << e.what() << std::endl;
    }

    // RobotomyRequestForm process
    try {
        std::cout << std::endl
                  << "/* --- RobotomyRequestForm process (72, 45) ------------------ /*\n"
                  << std::endl;

        Bureaucrat	low_officer("assistant Bob", 150);
        Bureaucrat	medium_officer("executive Carol", 70);
        Bureaucrat	high_officer("head Boss", 3);
		Intern		intern_guy;
		AForm*		newRobotomyForm;

		std::cout << std::endl;
        std::cout << low_officer << std::endl;
        std::cout << medium_officer << std::endl;
        std::cout << high_officer << std::endl;
        std::cout << intern_guy << std::endl;
		std::cout << std::endl;

		newRobotomyForm = intern_guy.makeForm("RobotomyRequestForm", "Marvin the Paranoid Android");

		std::cout << std::endl;
        low_officer.signForm(*newRobotomyForm);
        medium_officer.signForm(*newRobotomyForm);
        high_officer.signForm(*newRobotomyForm);
        low_officer.executeForm(*newRobotomyForm);
        medium_officer.executeForm(*newRobotomyForm);
        high_officer.executeForm(*newRobotomyForm);
		std::cout << std::endl;

		delete newRobotomyForm;

    } catch (const std::exception & e) {
        std::cout << "\tError: " << e.what() << std::endl;
    }

    // PresidentialPardonForm process
    try {
        std::cout << std::endl
                  << "/* --- PresidentialPardonForm process (25, 5) ---------------- /*\n"
                  << std::endl;


        Bureaucrat	low_officer("assistant Bob", 150);
        Bureaucrat	medium_officer("executive Carol", 70);
        Bureaucrat	high_officer("head Boss", 3);
		Intern		intern_guy;
		AForm*		newPardonForm;

		std::cout << std::endl;
        std::cout << low_officer << std::endl;
        std::cout << medium_officer << std::endl;
        std::cout << high_officer << std::endl;
        std::cout << intern_guy << std::endl;
		std::cout << std::endl;

		newPardonForm = intern_guy.makeForm("PresidentialPardonForm", "Vogon poet");

		std::cout << std::endl;
		low_officer.signForm(*newPardonForm);
		medium_officer.signForm(*newPardonForm);
		high_officer.signForm(*newPardonForm);
		low_officer.executeForm(*newPardonForm);
		medium_officer.executeForm(*newPardonForm);
		high_officer.executeForm(*newPardonForm);
		std::cout << std::endl;
				
		// delete newPardonForm;
		
    } catch (const std::exception & e) {
        std::cout << "\tError: " << e.what() << std::endl;
    }

    return 0;
}
