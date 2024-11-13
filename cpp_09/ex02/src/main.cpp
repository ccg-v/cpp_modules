/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/12 23:00:42 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <sstream>	// For std::istringstream()	

int	fillContainers(PmergeMe & pmergeme, int argc, char **argv) {
    // Populate the containers with the sequence of integers
    for (int i = 1; i < argc; ++i) {
        std::string input = argv[i];

        if (input.empty() || onlyWhitespace(input)) {
            std::cerr << "Error: input is empty." << std::endl;
            return 0;
        }

        std::istringstream argStream(input);
        std::string element;

        while (argStream >> element) {
            if (!isValidNumber(element)) {
                std::cerr << "Sequence not valid" << std::endl;
                return 0;
            }

			if (!isInteger(element)) {
				std::cerr << "Value out of integer's range found" << std::endl;
            	return 0;
			}

            // Add the integer to the containers
            pmergeme.getVector().push_back(atoi(element.c_str()));
            pmergeme.getDeque().push_back(atoi(element.c_str()));
        }
    }

    printContainer(pmergeme.getVector());
    printContainer(pmergeme.getDeque());

	return 0;
}

int main(int argc, char* argv[]) {
    PmergeMe pmergeme;

	fillContainers(pmergeme, argc, argv);

    pmergeme.fordJohnsonSort(pmergeme.getVector());
	std::cout << "\nSorted vector: ";
    printContainer(pmergeme.getVector());

	std::cout << "\n===========================================\n" << std::endl;

	pmergeme.fordJohnsonSort(pmergeme.getDeque());
	std::cout << "\nSorted deque: ";
    printContainer(pmergeme.getDeque());

    return 0;
}
