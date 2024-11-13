/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/13 21:26:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <sstream>	// For std::istringstream()
#include <ctime>	// For clock()

int	fillContainers(PmergeMe & pmergeme, int argc, char **argv) {
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
	return 0;
}

int main(int argc, char* argv[]) {
    PmergeMe pmergeme;

	fillContainers(pmergeme, argc, argv);

	printContainer("Before:  ", pmergeme.getVector());
	clock_t	vecStart = clock();
    pmergeme.fordJohnsonSort(pmergeme.getVector());
	clock_t vecEnd = clock();
    printContainer("After :  ", pmergeme.getVector());

	// std::cout << "\n===========================================\n" << std::endl;

	// clock_t	deqStart = clock();
	// pmergeme.fordJohnsonSort(pmergeme.getDeque());
	// clock_t	deqEnd = clock();
    // // printContainer("\nSorted deque: ", pmergeme.getDeque());

	double vecTime = (static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC) * 1000000;
	// double deqTime = (static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC) * 1000000;	

	std::cout << "Time to process a range of " << pmergeme.getVector().size() << " elements with std::vector : " << vecTime << std::endl;
	// std::cout << "Time to process a range of " << pmergeme.getDeque().size() << " elements with std::deque  : " << deqTime << std::endl;



    return 0;
}
