/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/18 22:17:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
//	Object creation
	try {
		Bureaucrat a("Gregor", 100);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;

//	Object upgrade
	try {
		Bureaucrat a("Gregor", 100);
		a.incrementGrade(25);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;

//	Object downgrade
	try {
		Bureaucrat a("Gregor", 100);
		a.decrementGrade(25);
		std::cout << a << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;
	
//	Object instantiated with wrong grade should throw an exception
	try {
		Bureaucrat b("Gregor", 200);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;

	try {
		Bureaucrat b("Gregor", 0);
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;

//	Object with no parameters should be instantiated with default values
	try {
		Bureaucrat b;
		std::cout << b << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error creating bureaucrat: " << e.what() << std::endl;
	}
	std::cout << std::endl;

    return 0;
}