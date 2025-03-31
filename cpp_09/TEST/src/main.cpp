/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2025/03/31 22:39:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include "debug.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <ctime>	// For clock()

/*
 *	Bash command to generate random sequences of integers:
 *
 *	./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
 */

/*
 *	Program steps:
 *
 *	1. Fill the containers and check input element's validity
 *	2. If sequence has odd number of elements, save last element as straggler 
 *		and remove it from sequence
 *	3. Pair adjacent elements in the vector of integers and load them in a 
 *		vector of pairs
 *	4. Recursively sort main chain
 *	5. Divide sequence of pairs into main chain (storing larger values, sorted)
 *		and pending
 *	6. Insert pending values in the main chain
 *	7. Insert straggler saved in step 2 if it exists
 */

int main(int argc, char** argv)
{
	try
	{
		if (argc > 1)
		{
			PmergeMe pmergeme;
			
			pmergeme.checkInputAndSetContainers(argc, argv);

			// Vector container sorting
	

			size_t	recursionDepth = 0;
			clock_t	timerStart = clock();
			pmergeme.mergeInsertionSort_vector(recursionDepth);
			// pmergeme.mergeInsertionSort_deque(recursionDepth);
			clock_t	timerStop = clock();
			double vectorElapsedTime = static_cast<double>(timerStop - timerStart) * 1000 / CLOCKS_PER_SEC; // * 1000000.0;

			DEBUG_PRINT(std::cout << (isSorted(pmergeme.getVectorMain()) ? "The sequence is sorted" : "Error: The sequence is NOT sorted") << std::endl);
			DEBUG_PRINT(std::cout << "Total comparisons = " << BOLDYELLOW << pmergeme._comparisons << RESET << std::endl);

			// Deque container sorting
			recursionDepth = 0;
			timerStart = clock();
			pmergeme.mergeInsertionSort_deque(recursionDepth);
			timerStop = clock();
			double dequeElapsedTime = static_cast<double>(timerStop - timerStart) * 1000 / CLOCKS_PER_SEC; // * 1000000.0;

			printContainer("Before: ", 1, pmergeme.getInput());
			printContainer("After: ", 1, pmergeme.getVectorMain());
			std::cout << "Time to process a range of " << pmergeme.getVectorMain().size() << " elements with std::vector<int> : " << vectorElapsedTime << " ms." << std::endl;
			std::cout << "Time to process a range of " << pmergeme.getDequeMain().size() << " elements with std::deque<int> : " << dequeElapsedTime << " ms." << std::endl;

		}
		else
		{
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	}
	catch (const std::runtime_error & e)
	{
		std::cerr << e.what() << std::endl;
		return 1;
	}
    return 0;
}

// int main(int argc, char** argv)
// {
// 	try
// 	{
// 		if (argc > 1)
// 		{
// 			PmergeMe pmergeme;
			
// 			pmergeme.checkInputAndSetContainers(argc, argv);
// 			printContainer("****************************************** Input sequence = ", 1, pmergeme.getInput());
// 			// pmergeme.recursiveSort(pmergeme.getPairsVector());

// 			// std::vector<int> pending;
// 			// std::vector<int> mainChain;

// 			// pmergeme.extractPendingAndMainChain(pmergeme.getPairsVector(), pending, mainChain);
// 			// pmergeme.intMergeInsertion(pending, mainChain);
// 			// pmergeme.intMergeInsertion(pmergeme.getIntStraggler(), mainChain);
// 			size_t	recursionDepth = 0;
// 			pmergeme.mergeInsertionSort_vector(recursionDepth);
			
// 			printContainer("Input  sequence = ", 1, pmergeme.getInput());
// 			printContainer("Sorted sequence = ", 1, pmergeme.getVectorMain());
// 			std::cout << "Sequence length = " << pmergeme.getVectorMain().size() << std::endl;
// 			DEBUG_PRINT(std::cout << (isSorted(pmergeme.getVectorMain()) ? "The sequence is sorted" : "Error: The sequence is NOT sorted") << std::endl);
// 			DEBUG_PRINT(std::cout << "Total comparisons = " << BOLDYELLOW << pmergeme._comparisons << RESET << std::endl);
// 		}
// 		else
// 		{
// 			throw std::runtime_error("Error: Wrong number of arguments");			
// 		}
// 	}
// 	catch (const std::runtime_error & e)
// 	{
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	}
//     return 0;
// }
