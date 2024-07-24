/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/25 01:06:39 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int main() {

/* --- ShrubberyCreationForm process ---------------------------------------- */

    std::cout << std::endl;
	std::cout << "/* --- ShrubberyCreationForm process (145, 137) ---------- /*"
			  << std::endl << std::endl;
	
	Bureaucrat 				officer1("Bob", 150);
	Bureaucrat				officer2("Carol", 50);
	ShrubberyCreationForm	form1("Garden");

	std::cout << std::endl;
    std::cout << officer1 << std::endl;
	std::cout << officer2 << std::endl;
    std::cout << form1 << std::endl;
	std::cout << std::endl;
	
	officer1.signForm(form1);
	officer2.signForm(form1);
	form1.execute(officer2);

/* --- RobotomyRequestForm process ------------------------------------------ */

    std::cout << std::endl;
	std::cout << "/* --- RobotomyRequestForm process (72, 45) -------------- /*"
	<< std::endl << std::endl;

	Bureaucrat			officer3("Ted", 46);
	Bureaucrat			officer4("Alice", 20);
	RobotomyRequestForm	form2("Marvin the Paranoid Android");

	std::cout << std::endl;
    std::cout << officer3 << std::endl;
    std::cout << form2 << std::endl;
	std::cout << std::endl;

	officer3.signForm(form2);
	officer4.signForm(form2);
	form2.execute(officer3);
	form2.execute(officer4);

    std::cout << std::endl;
    return 0;
}
