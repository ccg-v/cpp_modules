/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/23 00:03:57 by ccarrace         ###   ########.fr       */
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

			pmergeme.setVectorStraggler(pmergeme.getPairSortedVector());

			std::cout << "Straggler = " << pmergeme.getVectorStraggler() << std::endl;

			printContainer("After:  ", pmergeme.getPairSortedVector());
			std::cout << std::endl;

			// printContainer("After:  ", pmergeme.getPairSortedVector());			
			// // clock_t	vecStart = clock();
std::cout << " --- Starting recursion ----------------------------------------------- " << std::endl;
			pmergeme.fordJohnsonSort(pmergeme.getPairSortedVector());
std::cout << " --- End of recursion ------------------------------------------------- " << std::endl;
			std::vector<int> pending;
			std::vector<int> mainChain;
std::cout << "Main: last vecPairStraggler to add = " << pmergeme.getVectorPairStraggler() << std::endl;
std::cout << "Main: last intStraggler to add = " << pmergeme.getVectorStraggler() << std::endl;

// // ERROR:
// // SI DESHABILITO ESTA CONDICION, NO ANADE EL PAR STRAGGLER EN LA SECUENCIA DE 6
// // SI HABILITO ESTA CONDICION, ANADE EL PAR DE STRAGGLER EN LA SECUENCA DE 6 PERO LO DUPLICA EN LA SECUENCIA DE 10
// t_pair pair = pmergeme.getVectorPairStraggler();
// if (pair._smaller != 0 && pair._larger != 0) {
//     // The pair is (0, 0)
// 	pmergeme.getPairSortedVector().push_back(pmergeme.getVectorPairStraggler()); //ERROR: NADA DE PUSHBACK, BINARYINSERT del par
// }

 			if (pmergeme.getVectorStraggler() > 0) {
				pending.push_back(pmergeme.getVectorStraggler());
			}
			
			pmergeme.extractPendingAndMainChain(pmergeme.getPairSortedVector(), pending, mainChain);
			printContainer("Main(): Paired seq = ", pmergeme.getPairSortedVector());
			printContainer("Main(): Main chain = ", mainChain);
			printContainer("Main(): Pending    = ", pending);

			pmergeme.intMergeInsertion(pending, mainChain);
			printContainer("Sorted sequence = ", mainChain);
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
