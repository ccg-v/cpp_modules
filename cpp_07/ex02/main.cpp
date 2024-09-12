/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 21:57:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/12 23:54:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void) {
		
	std::cout << "/* ---- Test default constructor ------------------------- */"
			  << std::endl;
	Array<int> defaultArray;
	std::cout << "\tDefault array size: " << defaultArray.getSize() << std::endl;

	std::cout << std::endl;


	std::cout << "/* ---- Test parameterized constructor ------------------- */"
			 << std::endl;

	unsigned int n = 5;
	Array<int> intArray(n);

	std::cout << "\tintArray size: " << intArray.getSize() << std::endl;

	std::cout << std::endl;


	std::cout << "/* ----  Set/get values with subscript operator ---------- */"
			  << std::endl << std::endl;
			  
	// Fill the array with n integers
	for (unsigned int i = 0; i < n; i++)
		intArray[i] = (i + 1) * 10;
	// Print the array
	for (unsigned int i = 0; i < n; i++)
		std::cout << "\tintArray[" << i << "] = " << intArray[i] << std::endl;	

	Array<std::string> strArray(3);

	// Fill the array with 3 strings
	strArray[0] = "Hello ";
	strArray[1] = "World ";
	strArray[2] = "!";
	// Print the array
	for (unsigned int i = 0; i < strArray.getSize(); i++)
		std::cout << "\tstrArray[" << i << "] = " << strArray[i] << std::endl;
	std::cout << std::endl;


	std::cout << "/* ----  Test subscript operator's const overload --------- */"
			  << std::endl;

	// You can initialize a const array by copying or assigning from an 
	// already-filled non-const array
	const Array<int> constArray = intArray;
	// Print the array
	for (unsigned int i = 0; i < n; i++)
		std::cout << "\tconstArray[" << i << "] = " << constArray[i] << std::endl;	
	// If we try to modify an element the program won't compile because the Array
	// object that we have instantiated is const
	// constArray[0] = 999;
	std::cout << std::endl;
	

	std::cout << "/* ---- Accessing out of bounds (throw exception) -------- */"
			  << std::endl;
	try {
		std::cout << intArray[10] << std::endl;
	} catch (const std::out_of_range& e) {
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	

	std::cout << "/* ---- Test copy constructor ---------------------------- */"
			 << std::endl;

	Array<std::string>copiedArray(strArray);

	// Print the size of copied array
	std::cout << "\tcopiedArray size: " << copiedArray.getSize() << std::endl;
	// Print the values of copied array
	for (unsigned int i = 0; i < copiedArray.getSize(); i++)
		std::cout << "\tcopiedArray[" << i << "] = " << copiedArray[i] << std::endl;
	std::cout << std::endl;


	std::cout << "/* ---- Modify copied array (check deep copy) ------------ */"
			 << std::endl << std::endl;

	copiedArray[0] = "Goodbye ";
	copiedArray[1] = "Cruel ";
	copiedArray[2] = "World";
	// Print the copied array
	for (unsigned int i = 0; i < copiedArray.getSize(); i++)
		std::cout << "\tcopiedArray[" << i << "] = " << copiedArray[i] << std::endl;
	std::cout << std::endl;
	// Print the source array
	for (unsigned int i = 0; i < strArray.getSize(); i++)
		std::cout << "\tstrArray[" << i << "] = " << strArray[i] << std::endl;
	std::cout << std::endl;


	std::cout << "/* ---- Test copy assignment operator -------------------- */"
			 << std::endl;

	copiedArray = strArray;
	// Print the copied array
	for (unsigned int i = 0; i < copiedArray.getSize(); i++)
		std::cout << "\tcopiedArray[" << i << "] = " << copiedArray[i] << std::endl;
	std::cout << std::endl;
	// Print the source array
	for (unsigned int i = 0; i < strArray.getSize(); i++)
		std::cout << "\tstrArray[" << i << "] = " << strArray[i] << std::endl;
	std::cout << std::endl;


	std::cout << "/* ---- Test empty array assignment ---------------------- */"
			 << std::endl;
	
	Array<int> emptyArray;

	std::cout << "\tEmpty array size: " << emptyArray.getSize() << std::endl;
	
	emptyArray = intArray;
	std::cout << "\tEmpty array size after assignment: " << emptyArray.getSize()
			  << std::endl;
	// Print the assigned array
	for (unsigned int i = 0; i < emptyArray.getSize(); i++)
		std::cout << "\temptyArray[" << i << "] = " << emptyArray[i] << std::endl;
	std::cout << std::endl;

	return 0;
}