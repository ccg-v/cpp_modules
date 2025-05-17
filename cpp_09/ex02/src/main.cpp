/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2025/05/17 01:00:53 by ccarrace         ###   ########.fr       */
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

int main(int argc, char** argv)
{
	try
	{
		if (argc > 1)
		{
			PmergeMe pmergeme;
			
			pmergeme.checkInputAndSetContainers(argc, argv);
			DEBUG_PRINT(printContainer("\nInput sequence = ", 1, pmergeme.getInput()));

			// Vector container sorting
			size_t	recursionDepth = 0;
			clock_t	timerStart = clock();
			pmergeme.mergeInsertionSort_vector(recursionDepth);
			clock_t	timerStop = clock();
			double vectorElapsedTime = static_cast<double>(timerStop - timerStart) * 1000 / CLOCKS_PER_SEC;

			// Deque container sorting
			recursionDepth = 0;
			timerStart = clock();
			pmergeme.mergeInsertionSort_deque(recursionDepth);
			timerStop = clock();
			double dequeElapsedTime = static_cast<double>(timerStop - timerStart) * 1000 / CLOCKS_PER_SEC;

			printContainer("\nBefore: ", 1, pmergeme.getInput());
			printContainer("After : ", 1, pmergeme.getVectorMain());

			// Display results
			if  (isSorted(pmergeme.getVectorMain())) 
				std::cout << BRIGHTGREEN << "✔ The sequence is sorted" << RESET << std::endl;
			else
				std::cout << (RED) << "✘ The sequence is not sorted" << RESET << std::endl;

			if (pmergeme.getInput().size() != pmergeme.getVectorMain().size())
				std::cout << RED << "✘ The length of input and output sequences do not match" << RESET << std::endl;

			DEBUG_PRINT(std::cout << "Total comparisons = " << BOLDYELLOW << pmergeme._comparisons << RESET << std::endl);

			std::cout << "Time to process a range of " << pmergeme.getVectorMain().size() 
					  << " elements with std::vector<int> : " << vectorElapsedTime << " ms." << std::endl;
			std::cout << "Time to process a range of " << pmergeme.getDequeMain().size()
					  << " elements with std::deque<int>  : " << dequeElapsedTime << " ms." << std::endl;
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
