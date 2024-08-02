/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/02 12:20:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

    std::cout << std::endl
			  << "/* --- Invalid bureaucrat instance ----------------------- /*"
    		  << std::endl;
	try {
		Bureaucrat b1("Bob", 200);
		std::cout << b1 << std::endl;
		Form f1("F-100", 100, 50);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

    std::cout << std::endl
			  << "/* --- Invalid form instance ----------------------------- /*"
    		  << std::endl;
	try {
		Bureaucrat b1("Bob", 1);
		std::cout << b1 << std::endl;
		try {
			Form f1("F-200", 200, 50);
			std::cout << f1 << std::endl;
			b1.signForm(f1);
		} catch (const std::exception & e) {
			std::cout << "\tError: " << e.what() << std::endl;
		}	
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

    std::cout << std::endl
			  << "/* --- Valid bureaucrat signature ------------------------ /*"
    		  << std::endl;
	try {
		Bureaucrat b1("Bob", 1);
		std::cout << b1 << std::endl;
		Form f1("F-100", 100, 50);
		std::cout << f1 << std::endl;
		b1.signForm(f1);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}
    
    std::cout << std::endl
			  << "/* --- Invalid bureaucrat signature attempt -------------- /*"
    		  << std::endl;

	try {
		Bureaucrat b2("Carol", 120);
		std::cout << b2 << std::endl;
		Form f2("F-90", 90, 50);
		std::cout << f2 << std::endl;
		b2.signForm(f2);		
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

    std::cout << std::endl
			  << "/* --- Default bureaucrat signature attempt -------------- /*"
    		  << std::endl;

	try {
	Bureaucrat b3;
	std::cout << b3 << std::endl;
	Form f3("F-80", 80, 50);
	std::cout << f3 << std::endl;
	b3.signForm(f3);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "/* --- Default form signature attempt -------------------- /*"
    		  << std::endl;

	try {
		Bureaucrat b4("Gregor", 100);
		std::cout << b4 << std::endl;
		Form f4;
		std::cout << f4 << std::endl;
		b4.signForm(f4);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "/* --- Form signed by several officers ------------------- /*"
    		  << std::endl;

	try {
		Bureaucrat b5("Ted", 50);
		std::cout << b5 << std::endl;
		Bureaucrat b6("Alice",10);
		std::cout << b6 << std::endl;
		Form f5("F-70", 70, 50);
		std::cout << f5 << std::endl;
		b5.signForm(f5);
		b6.signForm(f5);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

	std::cout << std::endl
			  << "/* --- Officer signs several forms------------------------ /*"
    		  << std::endl;
	
	try {
		Bureaucrat b7("Paul", 50);
		std::cout << b7 << std::endl;
		Form f6("F-60", 60, 50);
		std::cout << f6 << std::endl;
		Form f7("F-50", 50, 40);
		std::cout << f7 << std::endl;
		b7.signForm(f6);
		b7.signForm(f7);
	} catch (const std::exception & e) {
		std::cout << "\tError: " << e.what() << std::endl;
	}

    return 0;
}
	