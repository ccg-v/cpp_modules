/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/04 19:40:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>	// std::cout, std::cerr
#include <sstream>	// std::istringstream()
#include <time.h>	// clock_t, clock(), CLOCK_PER_SEC
#include "Utils.hpp"

class PmergeMe
{
	public:

		size_t				_comparisons;
		
		/* --- Orthodox Canonical Form -------------------------------------- */
		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */
		std::vector<int>	&getInput();

		// For vector
		std::vector<int>	&getVector();
		std::vector<int>	&getVectorMain();
		int					getVectorStraggler();

		// For deque 
		std::deque<int>		&getDeque();
		std::deque<int>		&getDequeMain();
		int					getDequeStraggler();

		/* --- Setters ------------------------------------------------------ */
		void				setInput(int value);

		// For vector
		void				setVector(int value);
		void				setVectorStraggler();

		// For deque
		void				setDeque(int value);
		void				setDequeStraggler();

		/* --- Public methods ----------------------------------------------- */
		void				checkInputAndSetContainers(int argc, char** argv);
		void 				mergeInsertionSort_vector(size_t depth);
		void 				mergeInsertionSort_deque(size_t depth);

	private:

		std::vector<int>	_inputSeq;

		/* --- Attributes for vector-based sorting -------------------------- */
		std::vector<int>	_vectorSeq;
		std::vector<int>	_vectorMain;
		std::vector<int>	_vectorPending;
		int					_vectorStraggler;

		/* --- Attributes for deque-based sorting --------------------------- */
		std::deque<int>		_dequeSeq;
		std::deque<int>		_dequeMain;
		std::deque<int>		_dequePending;
		int					_dequeStraggler;

		/* --- Private methods ---------------------------------------------- */
		size_t 				calculateGroupSize(size_t depth);
		
		// Vector-based methods
		void				popStraggler();
		void				sortAdjacentPairs(size_t groupSize);
		void				divideSequence(size_t groupSize);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		std::vector<int>	getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);
		size_t 				binarySearch(int value, size_t end, size_t groupSize);
		void 				binaryInsertion(size_t groupSize);
		void				insertStraggler(size_t groupSize);
		
		// Deque-based methods
		void				popStraggler_deque();
		void				sortAdjacentPairs_deque(size_t groupSize);
		void				divideSequence_deque(size_t groupSize);
		std::deque<int> 	buildJacobsthalDeque(size_t len);
		std::deque<int>		getPickingOrder_deque(const std::deque<int> & jacobsthalSeq, size_t smallerSize);
		size_t 				binarySearch_deque(int value, size_t end, size_t groupSize);
		void 				binaryInsertion_deque(size_t groupSize);
		void				insertStraggler_deque(size_t groupSize);
};

// Define ANSI color codes
#define RESET "\033[0m"					// Reset to default color
#define GREEN "\033[92m"				// Green
#define BRIGHTGREEN "\033[38;5;120m"	// Pastel green
#define	RED "\033[38;5;203m"			// Coral red
#define YELLOW "\033[93m"				// Yellow 
#define BOLDYELLOW "\033[1;93m"			// Bold yellow

// Generic function to print container contents
template <typename T>
void printContainer(std::string msg, int groupSize, T &sequence)
{
    size_t numberOfGroups = sequence.size() / groupSize;
    size_t remainder = sequence.size() % groupSize;
    size_t index = 0;

    std::cout << msg;

    for (size_t group = 0; group < numberOfGroups; ++group)
	{
        if (groupSize > 1)
            std::cout << "[ ";

        for (size_t i = 0; i < static_cast<size_t>(groupSize); ++i, ++index)
		{
            if (i == static_cast<size_t>(groupSize - 1)) // Last element in the group
                std::cout << GREEN << sequence[index] << RESET << " ";
            else 
                std::cout << sequence[index] << " ";
        }
        if (groupSize > 1)
            std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0)
	{
        for (size_t i = 0; i < remainder; ++i, ++index)
		{
            if (i == remainder - 1) // Last remaining element
                std::cout << GREEN << sequence[index] << RESET << " ";
            else
                std::cout << sequence[index] << " ";
        }
    }

    std::cout << std::endl;
}

#endif
