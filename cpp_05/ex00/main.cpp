/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/18 14:11:09 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	Bureaucrat b("Gregor", 200);
    // b.incrementGrade(100);
	// Bureaucrat b();
	try {
		// Bureaucrat b();
	 	// Bureaucrat b("Gregor", 100);        
		b.incrementGrade(1); // This will throw an exception
		std::cout << b.getName() << " is grade " << b.getGrade() << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
		std::cout << b.getName() << " is grade " << b.getGrade() << std::endl;
	}
	// std::cout << b.getName() << " is grade " << b.getGrade() << std::endl;
    return 0;
}