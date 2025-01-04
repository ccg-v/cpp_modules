/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2025/01/04 19:32:14 by ccarrace         ###   ########.fr       */
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
		std::vector<int>	_vecSequence;
		int					_straggler;
		size_t				_comparisons;

		/* --- Private methods ---------------------------------------------- */

		// methods for a vector container
		size_t 				calculateGroupSize(size_t depth);
		void				sortAdjacentPairs(std::vector<int> & sequence, size_t groupSize);
		void				divideSequence(std::vector<int> & sequence, std::vector<int> & mainChain, 
                    			std::vector<int> & pending, size_t groupSize);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		std::vector<int>	getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);
		size_t 				binarySearch(const std::vector<int> & mainChain, int value, size_t end, size_t groupSize);
		void 				binaryInsertion(std::vector<int> & sequence, size_t groupSize);
		
		// overloaded methods for a deque container

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int>	& getVector();
		int					getStraggler();

		/* --- Setters ------------------------------------------------------ */

		void	setVector(int value);
		void	setStraggler();

		/* --- Public methods ----------------------------------------------- */

		void	checkInputAndSetContainers(int argc, char** argv);
		void 	mergeInsertionSort(std::vector<int>& sequence, size_t depth);
		
		// overloading for a list container

};

// Generic function to print container contents
template <typename T>
void printContainer(std::string msg, int groupSize, T & sequence) {

    size_t numberOfGroups = sequence.size() / groupSize;
    size_t remainder = sequence.size() % groupSize;

    size_t index = 0;
	std::cout << msg;
    for (size_t group = 0; group < numberOfGroups; ++group) {
        std::cout << "[ ";
        for (size_t i = 0; i < static_cast<size_t>(groupSize); ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
        std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0) {
        for (size_t i = 0; i < remainder; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
    }
    std::cout << std::endl;
}

#endif