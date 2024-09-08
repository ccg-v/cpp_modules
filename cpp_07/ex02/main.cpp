/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:57:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/08 21:59:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void) {
	
	Array<int> myArray(5);  // Array of 5 integers

	// Set values using the subscript operator
	myArray[0] = 10;
	myArray[1] = 20;

	// Access values using the subscript operator
	std::cout << myArray[0] << std::endl;  // Output: 10
	std::cout << myArray[1] << std::endl;  // Output: 20

	// Accessing out of bounds will throw an exception
	try {
		std::cout << myArray[10] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;  // Output: Index is out of bounds
	}
}