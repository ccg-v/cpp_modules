/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:22:32 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/11 20:05:29 by ccarrace         ###   ########.fr       */
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
			  << std::endl << std::endl;
			  
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
	
	std::cout << std::endl;

	/* --- Double-ended queue ----------------------------------------- */
	
	std::cout << "/* --- Container is a double-ended queue ------------ */"
			  << std::endl << std::endl;

    std::deque<int> deq;
    deq.push_back(2);
    deq.push_back(4);
    deq.push_back(6);
    deq.push_back(8);
    deq.push_back(10);
    
	printContainer(deq);

	num = 2;

    try {

        std::deque<int>::const_iterator result = easyfind(deq, num);
        std::deque<int>::const_iterator begin = deq.begin();
		
        std::cout << "Value '" << num << "': Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }

	num = 42;
	try {

        std::deque<int>::const_iterator result = easyfind(deq, num);
        std::deque<int>::const_iterator begin = deq.begin();
		
        std::cout << "Value '" << num << ": Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }
	
	std::cout << std::endl;

	/* --- Double linked list ----------------------------------------- */
	
	std::cout << "/* --- Container is a double linked list ------------ */"
			  << std::endl << std::endl;

    std::list<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(7);
    
	printContainer(lst);

	num = 7;

    try {

        std::list<int>::const_iterator result = easyfind(lst, num);
        std::list<int>::const_iterator begin = lst.begin();
		
        std::cout << "Value '" << num << "': Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }

	num = 42;
	try {

        std::list<int>::const_iterator result = easyfind(lst, num);
        std::list<int>::const_iterator begin = lst.begin();
		
        std::cout << "Value '" << num << ": Found at position " 
				  << std::distance(begin, result) << std::endl;
    } catch (const std::runtime_error & e) {
        std::cerr << e.what() << std::endl;
    }
	
	std::cout << std::endl;

	/* --- C-style Array ---------------------------------------------- */
	
	std::cout << "/* --- C-style Array -------------------------------- */"
			  << std::endl << std::endl;

    int arr[] = {100, 200, 300, 400, 500};

	printContainer(arr);

	num = 300;
    try {
        // Use easyfind with C-style array
        int* result = easyfind(arr, num);
        std::cout << "Value '" << num << ": Found at position "
				  << (result - arr) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
    }

	num = 42;
	try {
       // Use easyfind with C-style array
        int* result = easyfind(arr, num);
        std::cout << "Value '" << num << ": Found at position "
				  << (result - arr) << std::endl;
    } catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
	}
	
    return 0;
}
