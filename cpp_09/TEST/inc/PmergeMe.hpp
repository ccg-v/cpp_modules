/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2025/01/04 14:39:16 by ccarrace         ###   ########.fr       */
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
		std::vector<int>	_vecStraggler;
		size_t				_comparisons;

		/* --- Private methods ---------------------------------------------- */

		// methods for a vector container
		size_t 				calculateGroupSize(size_t depth);
		void				sortAdjacentPairs(std::vector<int> & sequence, size_t groupSize);
		void				divideSequence(const std::vector<int> & sequence, std::vector<int> & mainChain, 
                    			std::vector<int> & pending, size_t groupSize);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		std::vector<int>	getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);
		size_t 				binarySearch(const std::vector<int> & mainChain, int value, size_t end, size_t groupSize);
		void 				binaryInsertion(std::vector<int> & sequence, size_t groupSize);
		void 				mergeInsertionSort(std::vector<int>& sequence, size_t depth);
		
		// overloaded methods for a deque container

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int> & getVector();
		std::vector<int> & getStraggler();

		/* --- Setters ------------------------------------------------------ */

		void	setVector(int value);
		void	setStraggler(void);

		/* --- Public methods ----------------------------------------------- */

		void	checkInputAndSetContainers(int argc, char** argv);
		
		// overloading for a list container

};

// Generic function to print container contents
template <typename T>
void printContainer(std::string msg, int groupSize, std::vector<int> sequence) {

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

/*
 * The function template 'printContainer()' works for standard containers of
 * primitive types or types that overload the << operator.
 * However, for std::vector<t_pair> and std::deque<t_pair>, we need to define
 * how to print a t_pair since the std::ostream << operator is not defined for
 * custom types like t_pair.
 */
std::ostream& operator<<(std::ostream& os, const t_pair& pair);

#endif