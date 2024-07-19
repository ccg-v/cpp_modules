/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/20 00:33:33 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
// //	Object creation
// 	try {
// 		Bureaucrat a("Gregor", 100);
// 		std::cout << a << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// //	Object upgrade
// 	try {
// 		Bureaucrat a("Gregor", 100);
// 		a.incrementGrade(25);
// 		std::cout << a << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// //	Object downgrade
// 	try {
// 		Bureaucrat a("Gregor", 100);
// 		a.decrementGrade(25);
// 		std::cout << a << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;
	
// //	Object instantiated with wrong grade should throw an exception
// 	try {
// 		Bureaucrat b("Gregor", 200);
// 		std::cout << b << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// 	try {
// 		Bureaucrat b("Gregor", 0);
// 		std::cout << b << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

// //	Object with no parameters should be instantiated with default values
// 	try {
// 		Bureaucrat b;
// 		std::cout << b << std::endl;
// 	} catch (const std::exception& e) {
// 		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
// 	}
// 	std::cout << std::endl;

//	Valid bureaucrat to sign
	try {
		Bureaucrat b("Gregor", 1);
		std::cout << b << std::endl;
		Form f("F-420", 100, 50);
		std::cout << f << std::endl;
		f.beSigned(b);
		b.signForm(f);
	} catch (const std::exception& e) {
		std::cerr << "\tError signing form: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
//	Invalid bureaucrat to sign
	try {
		Bureaucrat b("Gregor", 120);
		std::cout << b << std::endl;
		Form f("F-420", 100, 50);
		f.beSigned(b);
		b.signForm(f);
		std::cout << f << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "\tError signing form: " << e.what() << std::endl;
	}

    return 0;
}