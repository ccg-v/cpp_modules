/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/28 20:02:23 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {

	int	grade;
	int	increment;
	int	decrement;

//	Object creation
	
	std::cout << std::endl
	<< "/* --- Creating a bureaucrat --------------------------------------- */"
	<< std::endl << std::endl;

	grade = 100;
	Bureaucrat a("Bob", grade);
	
	std::cout << a << std::endl;

//	Object upgrading

	std::cout << std::endl
	<< "/* --- Upgrading a bureaucrat -------------------------------------- */"
	<< std::endl << std::endl;

	grade = 100;
	increment = 25;
	Bureaucrat b("Carol", grade);

	std::cout << b << std::endl;
	std::cout << "\t" << b.getName() << " has just been upgraded!" << std::endl;
	a.incrementGrade(increment);
	std::cout << b << std::endl;

//	Object downgrading

	std::cout << std::endl
	<< "/* --- Downgrading a bureaucrat ------------------------------------ */"
	<< std::endl << std::endl;

	grade = 100;
	decrement = 25;
	Bureaucrat c("Ted", grade);

	std::cout << c << std::endl;
	std::cout << "\t" << c.getName() << " has just been downgraded!" << std::endl;
	a.decrementGrade(decrement);
	std::cout << c << std::endl;

//	Object instantiated with wrong grade (should throw an exception)

	std::cout << std::endl
	<< "/* --- Creating a wrong bureaucrat  -------------------------------- */"
	<< std::endl << std::endl;
	grade = 200;	
	Bureaucrat d("Alice", grade);
	std::cout << d << std::endl;

	grade = 0;
	Bureaucrat e("Alice", grade);
	std::cout << d << std::endl;

//	Object with no parameters (should be initialized with default values)

	std::cout << "/* --- Creating a default bureaucrat  ------------------------------ */"
	<< std::endl << std::endl;

	Bureaucrat f;
	std::cout << f << std::endl;

	std::cout << std::endl;
    return 0;
}