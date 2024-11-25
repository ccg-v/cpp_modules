/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/25 22:24:04 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include "debug.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <ctime>	// For clock()

int main(int argc, char** argv) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;
			// Fill the containers and check input element's validity
			pmergeme.checkInputAndSetContainers(argc, argv);
			printContainer("intsVector = ", pmergeme.getIntsVector());

			// Check if input sequence is already sorted
			if (isSorted(pmergeme.getIntsVector()))
				throw std::runtime_error("Error: The input sequence is already sorted");

			// // If sequence has odd number of elements, save last element as straggler and remove it from sequence
			std::vector<int> intStraggler;
			if (pmergeme.getIntsVector().size() % 2 == 1)
			{
				intStraggler.push_back(pmergeme.getIntsVector().back());
				pmergeme.getIntsVector().pop_back();
				printContainer("intStraggler = ", intStraggler);
				printContainer("intsVector without straggler = ", pmergeme.getIntsVector());
			}

			// Pair adjacent elements in the vector of integers and load them in a vector of pairs
			pmergeme.setPairsVector();
			printContainer("pairsVector = ", pmergeme.getPairsVector());
			
			// Recursively sort main chain
			std::cout << " --- Start recursive sorting of main chain --- " << std::endl;
			pmergeme.recursiveSort(pmergeme.getPairsVector());
			std::cout << " --- End recursive sorting of main chain ----- " << std::endl;
			printContainer("main(): Pairs sequence (pre-sorted by pair's larger values) = ", pmergeme.getPairsVector());
			// std::cout << "_vecPairStraggler = " << pmergeme.getVecPairStraggler() << std::endl;

			std::vector<int> pending;
			std::vector<int> mainChain;

			// Divide sequence of pairs into main chain (storing larger values, sorted) and pending
			pmergeme.extractPendingAndMainChain(pmergeme.getPairsVector(), pending, mainChain);

			std::cout << "intMergeInsertion():" << std::endl;
			pmergeme.intMergeInsertion(pending, mainChain);
			printContainer("intStraggler = ", intStraggler);

			pmergeme.intMergeInsertion(intStraggler, mainChain);
			printContainer("Sorted sequence = ", mainChain);
			std::cout << "Sequence length = " << mainChain.size() << std::endl;
			DEBUG_PRINT((if (isSorted(mainChain))
				std::cout << "The sequence is sorted" << std::endl
			else
				std::cout << "THE SEQUENCE IS NOT SORTED!!!" << std::endl))
			// DEBUG_PRINT((isSorted(mainChain) ? "The sequence is sorted" : "THE SEQUENCE IS NOT SORTED!!!"));

		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

    return 0;
}
