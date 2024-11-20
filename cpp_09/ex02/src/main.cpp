/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/20 22:25:03 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <ctime>	// For clock()

int main(int argc, char* argv[]) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;
			
			pmergeme.checkInputAndSetContainers(argc, argv);
			
			printContainer("Before:  ", pmergeme.getPairSortedVector());

			// pmergeme.setVectorStraggler(pmergeme.getPairSortedVector());

			// std::cout << "Straggler = " << pmergeme.getVectorStraggler() << std::endl;


			
			// printContainer("After:  ", pmergeme.getPairSortedVector());			
			// // clock_t	vecStart = clock();
			pmergeme.fordJohnsonSort(pmergeme.getPairSortedVector());
			std::vector<int> pending;
			std::vector<int> mainChain;
			pmergeme.extractPendingAndMainChain(pmergeme.getPairSortedVector(), pending, mainChain);
			printContainer("Paired seq = ", pmergeme.getPairSortedVector());
			printContainer("Main chain = ", mainChain);
			printContainer("Pending    = ", pending);
			// // clock_t vecEnd = clock();
			// // printContainer("After :  ", pmergeme.getVector());

			// // std::cout << "\n===========================================\n" << std::endl;

			// // clock_t	deqStart = clock();
			// // pmergeme.fordJohnsonSort(pmergeme.getDeque());
			// // clock_t	deqEnd = clock();
			// // // printContainer("\nSorted deque: ", pmergeme.getDeque());

			// double vecTime = (static_cast<double>(vecEnd - vecStart) / CLOCKS_PER_SEC) * 1000000;
			// // double deqTime = (static_cast<double>(deqEnd - deqStart) / CLOCKS_PER_SEC) * 1000000;	

			// std::cout << "Time to process a range of " << pmergeme.getVector().size() << " elements with std::vector : " << vecTime << std::endl;
			// // std::cout << "Time to process a range of " << pmergeme.getDeque().size() << " elements with std::deque  : " << deqTime << std::endl;
		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}


    return 0;
}
