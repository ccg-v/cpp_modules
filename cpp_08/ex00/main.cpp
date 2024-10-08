/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:22:32 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/08 22:25:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

// int	main(void)
// {
// 	// int intArr[] = {1, 3, 5, 7, 11, 13, 17, 19, 21, 23};
// 	std::vector<int> intArr = {1, 3, 5, 7, 11, 13, 17, 19, 21, 23};

//     try {
//         typename std::vector<int>::const_iterator result = easyfind(intArr, 13);
//         std::cout << "Found value at position: " << std::distance(intArr, result) << std::endl;
//     } catch (const std::runtime_error& e) {
//         std::cerr << e.what() << std::endl;
//     }
// }

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int main() {

	/* --- Vector ----------------------------------------------------------- */
	
	std::cout << "/* --- Container is a vector ------------------------------ */"
			  << std::endl;
			  
    std::vector<int> vec;
    vec.push_back(5);
    vec.push_back(10);
    vec.push_back(15);
    vec.push_back(20);
    vec.push_back(25);
    
	printContainer(vec);

	int	num = 20;
    try {

        std::vector<int>::const_iterator result = easyfind(vec, num);
        std::vector<int>::const_iterator begin = vec.begin();
		
        std::cout << "Value '" << num << "': Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }
	// } catch (const NoOccurrenceFoundException &e) {	
	// 	std::cerr << "Value " << num << ": " << e.what() << std::endl;
	// } 

	num = 42;
	try {

        std::vector<int>::const_iterator result = easyfind(vec, num);
        std::vector<int>::const_iterator begin = vec.begin();
		
        std::cout << "Value '" << num << ": Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }

	
    // try {
    //     // Use easyfind with std::vector
    //     std::vector<int>::const_iterator result = easyfind(vec, 10);
    //     // Cast vec.begin() to const_iterator explicitly
    //     std::vector<int>::const_iterator begin = vec.begin();
    //     std::cout << "Found value at position: "
	// 			  << std::distance(begin, result) << std::endl;
    // } catch (const std::runtime_error& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // // C-style array
    // int intArr[] = {5, 10, 15, 20, 25};
    
    // try {
    //     // Use easyfind with C-style array
    //     int* result = easyfind(intArr, 20);
    //     std::cout << "Found value at index: " << (result - intArr) << std::endl;
    // } catch (const std::runtime_error& e) {
    //     std::cerr << e.what() << std::endl;
    // }

    // Initialize std::vector in C++98 style


    return 0;
}
