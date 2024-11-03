/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/03 23:42:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# include <iostream>	// For std::cout(), std::cerr()
# include <sstream>		// For std::isstringstream()
#include <vector>	
#include <climits>		// For INT_MAX
#include <cstdlib>   	// For std::strtol
#include <cerrno>    	// For errno

bool	onlyWhitespace(std::string input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (!isspace(input[i])) {
			return false;
		}
	}
	return true;
}

bool	isInteger(std::string element) {
	// Convert element to an integer with range checking
	char* end;
	errno = 0;
	long value = std::strtol(element.c_str(), &end, 10);

	// Check for errors in conversion
	if (errno == ERANGE || value > INT_MAX) {
		return false;
	}
	return true;
}	

bool	isValidNumber(std::string & element) {
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

int main(int argc, char* argv[]) {
    PmergeMe pmergeme;

    // Populate the containers with the sequence of integers
    for (int i = 1; i < argc; ++i) {
        std::string input = argv[i];

        if (input.empty() || onlyWhitespace(input)) {
            std::cerr << "Error: input is empty." << std::endl;
            return 0;
        }

        std::istringstream argStream(input);
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
            if (!isValidNumber(element)) {
                std::cerr << "Sequence not valid" << std::endl;
                return 0;
            }

            // // Convert element to an integer with range checking
            // char* end;
            // errno = 0;
            // long value = std::strtol(element.c_str(), &end, 10);

            // // Check for errors in conversion
            // if (errno == ERANGE || value > INT_MAX) {
            //     std::cerr << "Value out of integer's range found" << std::endl;
            //     return 0;
            // }

			if (!isInteger(element)) {
				std::cerr << "Value out of integer's range found" << std::endl;
            	return 0;
			}

            // // Add the integer to the containers
            // pmergeme.getVector().push_back(static_cast<int>(element));
            // pmergeme.getList().push_back(static_cast<int>(element));

            // Add the integer to the containers
            pmergeme.getVector().push_back(atoi(element.c_str()));
            pmergeme.getList().push_back(atoi(element.c_str()));
        }
    }

    printContainer(pmergeme.getVector());
    printContainer(pmergeme.getList());

    return 0;
}
