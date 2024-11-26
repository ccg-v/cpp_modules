/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/26 20:42:18 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include "debug.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <ctime>	// For clock()

/*
 *	1. Fill the containers and check input element's validity
 *	2. Check if input sequence is already sorted
 *	3. If sequence has odd number of elements, save last element as straggler 
 *		and remove it from sequence
 *	4. Pair adjacent elements in the vector of integers and load them in a 
 *		vector of pairs
 *	5. Recursively sort main chain
 *	6. Divide sequence of pairs into main chain (storing larger values, sorted)
 *		and pending
 *	7. Insert pending values in the main chain
 *	8. Insert first straggler found (last integer in odd input sequence) if it 
 *		exists
 */

int main(int argc, char** argv) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;

			pmergeme.checkInputAndSetContainers(argc, argv);

			if (isSorted(pmergeme.getIntsVector()))
				throw std::runtime_error("Error: The input sequence is already sorted");

			std::vector<int> intStraggler;
			if (pmergeme.getIntsVector().size() % 2 == 1)
			{
				intStraggler.push_back(pmergeme.getIntsVector().back());
				pmergeme.getIntsVector().pop_back();
				DEBUG_PRINT(printContainer("intStraggler = ", intStraggler));
				DEBUG_PRINT(printContainer("intsVector without straggler = ", pmergeme.getIntsVector()));
			}

			pmergeme.setPairsVector();
			pmergeme.recursiveSort(pmergeme.getPairsVector());

			std::vector<int> pending;
			std::vector<int> mainChain;

			pmergeme.extractPendingAndMainChain(pmergeme.getPairsVector(), pending, mainChain);

			pmergeme.intMergeInsertion(pending, mainChain);
			// printContainer("intStraggler = ", intStraggler);

			pmergeme.intMergeInsertion(intStraggler, mainChain);

			printContainer("Sorted sequence = ", mainChain);
			std::cout << "Sequence length = " << mainChain.size() << std::endl;
			DEBUG_PRINT(std::cout << (isSorted(mainChain) ? "The sequence is sorted" : "Error: The sequence is NOT sorted") << std::endl);

		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

    return 0;
}
