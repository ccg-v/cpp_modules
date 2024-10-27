/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 11:48:20 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/27 01:05:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// for std::cout, std::endl;
#include <vector>
#include <cstring>	// for strlen

// bool	isOperator(char c) {
// 	return c == "+" || c == "-" || c == "*" || c == "/";
// }

void	fillVector(std::vector<char> & vec, char *argv) {

	int i = 0;
	int	nonWhitespaces = 0;

	// Count the number of non-whitespace characters
	while (argv[i] != '\0') {
		if (argv[i] != ' ') {
			nonWhitespaces++;
		}
		i++;
    }

    // Resize the vector to match the length of the input string discarding whitespaces
    vec.resize(nonWhitespaces);
	
	i = 0;
	int j = 0;
    // Copy each character from argv into vec
    while (argv[i] != '\0') {
        if (argv[i] != ' ') {
            vec[j] = argv[i];
            j++;
        }
        i++;
    }
}

int	main(int argc, char **argv) {

	if (argc == 2) {

		// int i = 0;
		// int operands = 0;
		// int res1 = 0;
		// int res2 = 0;
		std::vector<char> vec;

		fillVector(vec, argv[1]);
		
		// // Print vector content
		// std::vector<char>::iterator it = vec.begin();
		// for (it = vec.begin(); it != vec.end(); it++) {
		// 	std::cout << *it ;
		// }
		// std::cout << std::endl;
		
		return 0;
		
	} else {
		std::cout << "Error: Wrong number of arguments" << std::endl;
		return 1;
	}
}

/*
 *	(1)	String literals like "+", "-", "*", and "/" are const char* by default,
 *		and cannot be assigned to char* without violating const-correctness in
 *		ISO C++
 */

/*
 *	(2) Choose C-style array or std::vector here?
 *
 *		In C++, it's generally more consistent and idiomatic to use a C++ 
 *		container instead of a C-style array. Using a C++ container has several
 *		advantages, such as better type safety, easier resizing (for vectors), 
 *		and more flexibility with standard library algorithms.
 *
 *		However, If the array (or vector) is not going to change during the 
 *		program's execution and will only store the four basic operators, using
 *		a C-style array can be a more straightforward and efficient choice for 
 *		several reasons:
 *
 *		- Simplicity: C-style arrays are simple to declare and use.
 *		- Performance: C-style arrays have a fixed size and are allocated on the
 *			stack, so they can be slightly more efficient than std::vector,
 *			which has some overhead for managing dynamic memory and its size.
 *			With a fixed size, there’s no need for additional memory allocations
 *			or deallocations, making C-style arrays very efficient in terms of 
 *			performance.
 *		- Memory Footprint: C-style arrays typically use less memory than vectors 
 *			since there’s no need to store metadata related to size, capacity, or
 *			other vector-specific details.
 *		- No Need for Dynamic Behavior: If you know the operators will never change,
 *			you don’t need the dynamic behavior that comes with a vector. C-style
 *			arrays are often sufficient for fixed collections of data.
 */