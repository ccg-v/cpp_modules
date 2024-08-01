/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/01 17:49:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	int	grade;
	int	increment;
	int decrement;

//	Object creation

	std::cout << std::endl
			  << "/* --- Creating a bureaucrat ----------------------------- */"
			  << std::endl;
	grade = 100;

	try {
		Bureaucrat a("Gregor", grade);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat with grade " << grade << ": " 
		<< e.what() << std::endl;
	}

//	Object upgrading

	std::cout << std::endl
			  << "/* --- Upgrading a bureaucrat ---------------------------- */"
			  << std::endl;
	grade = 100;
	increment = 99;

	try {
		Bureaucrat a("Gregor", grade);
		std::cout << a << std::endl;
		std::cout << "\t" << a.getName() << " is to be promoted " << increment 
				  << " grades" << std::endl;
		a.incrementGrade(increment);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error upgrading bureaucrat to grade " << grade - increment 
		<< ": " << e.what() << std::endl;
	}

//	Object downgrading

	std::cout << std::endl
			  << "/* --- Downgrading a bureaucrat -------------------------- */"
			  << std::endl;
	grade = 100;
	decrement = 50;

	try {
		Bureaucrat a("Gregor", grade);
		std::cout << a << std::endl;
		std::cout << "\t" << a.getName() << " is to be downgraded " << increment 
				  << " grades" << std::endl;
		a.decrementGrade(decrement);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error downgrading bureaucrat to grade " << grade + decrement
		<< ": " << e.what() << std::endl;
	}
	
//	Object instantiated with wrong grade (should throw an exception)

	std::cout << std::endl
			  << "/* --- Creating a wrong bureaucrat  ---------------------- */"
			  << std::endl;
	grade = 200;	

	try {
		Bureaucrat b("Gregor", grade);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "\tError creating bureaucrat with grade " << grade << ": "
		<< e.what() << std::endl;
	}

	std::cout << std::endl;

	grade = 0;
	try {
		Bureaucrat b("Gregor", grade);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "\tError creating bureaucrat with grade " << grade << ": "
		<< e.what() << std::endl;
	}

//	Object with no parameters (should be initialized with default values)

	std::cout << std::endl
			  << "/* --- Creating a default bureaucrat  -------------------- */"
			  << std::endl;
	
	try {
		Bureaucrat b;
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	
	std::cout << std::endl;

    return 0;
}
