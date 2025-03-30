/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2025/03/30 11:10:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>	// for std::cout, std::cerr
#include <sstream>	// for std::istringstream()
#include "Utils.hpp"

class PmergeMe {

	private:
		std::vector<int>	_inputSequence;
		std::vector<int>	_vecSequence;
		std::vector<int>	_mainChain;
		std::vector<int>	_pending;
		int					_straggler;

		/* --- Private methods ---------------------------------------------- */

		// methods for a vector container
		size_t 				calculateGroupSize(size_t depth);
		void				sortAdjacentPairs(size_t groupSize);
		void				divideSequence(size_t groupSize);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		std::vector<int>	getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);
		size_t 				binarySearch(int value, size_t end, size_t groupSize);
		void 				binaryInsertion(size_t groupSize);
		
		// overloaded methods for a deque container

	public:

		size_t				_comparisons;
		
		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int>	& getInput();
		std::vector<int>	& getVector();
		std::vector<int>	& getMainChain();
		int					getStraggler();

		/* --- Setters ------------------------------------------------------ */

		void	setInput(int value);
		void	setVector(int value);
		void	setStraggler();

		/* --- Public methods ----------------------------------------------- */

		void	checkInputAndSetContainers(int argc, char** argv);
		void 	mergeInsertionSort(size_t depth);
		
		// overloading for a list container

};

// // Generic function to print container contents
// template <typename T>
// void printContainer(std::string msg, int groupSize, T & sequence) {

//     size_t numberOfGroups = sequence.size() / groupSize;
//     size_t remainder = sequence.size() % groupSize;

//     size_t index = 0;
// 	std::cout << msg;
//     for (size_t group = 0; group < numberOfGroups; ++group) {
//         if (groupSize > 1)
// 			std::cout << "[ ";
//         for (size_t i = 0; i < static_cast<size_t>(groupSize); ++i, ++index) {
//             std::cout << sequence[index] << " ";
//         }
// 		if (groupSize > 1)
//         	std::cout << "] ";
//     }

//     // Print remaining elements (not part of a full group)
//     if (remainder > 0) {
//         for (size_t i = 0; i < remainder; ++i, ++index) {
//             std::cout << sequence[index] << " ";
//         }
//     }
//     std::cout << std::endl;
// }

// #include <iostream>
// #include <string>

// Define ANSI color codes
const std::string RESET = "\033[0m";  // Reset to default color
const std::string GREEN = "\033[92m";  // Green color for highlighting

template <typename T>
void printContainer(std::string msg, int groupSize, T &sequence) {
    size_t numberOfGroups = sequence.size() / groupSize;
    size_t remainder = sequence.size() % groupSize;

    size_t index = 0;
    std::cout << msg;
    for (size_t group = 0; group < numberOfGroups; ++group) {
        if (groupSize > 1)
            std::cout << "[ ";
        for (size_t i = 0; i < static_cast<size_t>(groupSize); ++i, ++index) {
            if (i == static_cast<size_t>(groupSize - 1)) {  // Last element in the group
                std::cout << GREEN << sequence[index] << RESET << " ";
            } else {
                std::cout << sequence[index] << " ";
            }
        }
        if (groupSize > 1)
            std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0) {
        for (size_t i = 0; i < remainder; ++i, ++index) {
            if (i == remainder - 1) {  // Last remaining element
                std::cout << GREEN << sequence[index] << RESET << " ";
            } else {
                std::cout << sequence[index] << " ";
            }
        }
    }

    std::cout << std::endl;
}


#endif