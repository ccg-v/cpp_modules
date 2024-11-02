/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/03 00:11:52 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

#include <iostream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <climits>
#include <cstdlib>   // For strtol
#include <cerrno>    // For errno

// bool	isValid(std::string & element) {

// 	if (element.size() > 1) {
// 		for (size_t i = 0; i < element.size(); i++) {
// 			char token = element[i];
// 			if (!isdigit(token))
// 				return 0;
// 		}
// 		return 1;
// 	} else if (!isdigit(element[0]))
// 			return 0; 
// 	return 1;
// }

bool isValid(std::string & element) {
    // Check if the input contains only digits
    for (size_t i = 0; i < element.size(); ++i) {
        if (!isdigit(element[i])) {
            return false;
        }
    }
	if (std::atoi(element.c_str()) > INT_MAX)
		return false;
    return true;
}


// int main(int argc, char* argv[]) {

//     PmergeMe pmergeme;

// 	// Populate the containers with the sequence of integers
//     for (int i = 1; i < argc; ++i) {
//         std::istringstream argStream(argv[i]);
//         std::string element;
	
//         // Split quoted arguments
//         while (argStream >> element) {
// 			if (!isValid(element)) {
// 				std::cerr << "Sequence not valid" << std::endl;
// 				return 0;
// 			}
//             pmergeme.getVector().push_back(atoi(element.c_str()));
// 			pmergeme.getList().push_back(atoi(element.c_str()));
//         }
//     }

// 	printContainer(pmergeme.getVector());
// 	printContainer(pmergeme.getList());

//     return 0;
// }

int main(int argc, char* argv[]) {
    PmergeMe pmergeme;

    // Populate the containers with the sequence of integers
    for (int i = 1; i < argc; ++i) {
        std::string arg = argv[i];

        // Check if the input is empty or consists only of whitespace
        bool onlyWhitespace = true;
        for (size_t j = 0; j < arg.size(); ++j) {
            if (!isspace(arg[j])) {
                onlyWhitespace = false;
                break;
            }
        }

        if (arg.empty() || onlyWhitespace) {
            std::cerr << "Sequence not valid" << std::endl;
            return 0;
        }

        std::istringstream argStream(arg);
        std::string element;

        // Split quoted arguments
        // while (argStream >> element) {
        //     if (!isValid(element)) {
        //         std::cerr << "Sequence not valid" << std::endl;
        //         return 0;
        //     }
        //     pmergeme.getVector().push_back(atoi(element.c_str()));
        //     pmergeme.getList().push_back(atoi(element.c_str()));
        // }

        while (argStream >> element) {
            if (!isValid(element)) {
                std::cerr << "Sequence not valid" << std::endl;
                return 0;
            }

            // Convert element to an integer with range checking
            char* end;
            errno = 0;
            long value = std::strtol(element.c_str(), &end, 10);

            // Check for errors in conversion
            if (errno == ERANGE || value < INT_MIN || value > INT_MAX) {
                std::cerr << "Value out of integer's range found" << std::endl;
                return 0;
            }

            // Add the integer to the containers
            pmergeme.getVector().push_back(static_cast<int>(value));
            pmergeme.getList().push_back(static_cast<int>(value));
        }
    }

    printContainer(pmergeme.getVector());
    printContainer(pmergeme.getList());

    return 0;
}
