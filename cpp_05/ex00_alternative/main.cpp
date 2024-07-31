/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:05:54 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/31 12:59:28 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * In this version, the forest of try-catch blocks has been removed from the 
 * main and placed within the parameterized constructor. This approach isn't
 * wrong, inefficient, or unsafe per se. It's a valid design choice. However,
 * it might lead to some issues:
 *
 *  - Lack of feedback on failure: 
 * 		When an exception is caught within the constructor, the object is still 
 * 		created, but it might not be in a valid state. This can be confusing as 
 * 		users of the class might expect the object to be either fully valid or 
 * 		not created at all.
 *
 *	- Inconsistent state: 
 *		If the constructor catches an exception and logs an error, the object 
 *		still exists but may not have the intended state. For example, an object 
 *		might be created with a default grade if the provided grade was invalid,
 *		but this can lead to unpredictable behavior.
 *
 *	- Separation of concerns:
 *		It's often clearer to handle exceptions outside the class, where the 
 *		context of object creation is better understood, and appropriate actions
 *		can be taken based on the specific situation.
 *
 *  It's often better to let the exception propagate out of the constructor.
 * 	This way, if object creation fails due to an invalid grade, the calling 
 * 	code can handle it appropriately (e.g., by retrying with a different grade,
 * 	logging the error, or informing the user).
 */

#include "Bureaucrat.hpp"

int main() {

	int	grade;
	int	increment;
	int	decrement;

//	Object creation
	
	std::cout << std::endl
	<< "/* --- Creating a bureaucrat --------------------------------------- */"
	<< std::endl << std::endl;

	grade = 200;
	Bureaucrat a("Bob", grade);
	
	std::cout << a << std::endl;

//	Object upgrading

	std::cout << std::endl
	<< "/* --- Upgrading a bureaucrat -------------------------------------- */"
	<< std::endl << std::endl;

	grade = 100;
	increment = 99;
	Bureaucrat b("Carol", grade);

	std::cout << b << std::endl;
	std::cout << "\t" << b.getName() << " is to be promoted " << increment
			  << " grades" << std::endl;
	b.incrementGrade(increment);
	std::cout << b << std::endl;

//	Object downgrading

	std::cout << std::endl
	<< "/* --- Downgrading a bureaucrat ------------------------------------ */"
	<< std::endl << std::endl;

	grade = 100;
	decrement = 25;
	Bureaucrat c("Ted", grade);

	std::cout << c << std::endl;
	std::cout << "\t" << b.getName() << " is to be downgraded " << decrement
			  << " grades" << std::endl;
	c.decrementGrade(decrement);
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