/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/12/06 11:48:38 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>	// for std::cout, std::cerr
#include <sstream>	// for std::istringstream()
#include "Utils.hpp"

struct t_pair {
    int _larger;
    int _smaller;
    t_pair* _ptrAdjacent; // Pointer to adjacent pair in mainChain

    t_pair(int larger = 0, int smaller = 0, t_pair* ptr = NULL)
        : _larger(larger), _smaller(smaller), _ptrAdjacent(ptr) {}
};


class PmergeMe {

	private:
		std::vector<int>	_intsVector;
		std::vector<t_pair>	_pairsVector;

		std::vector<int>	_intStraggler;

		/* --- Private methods ---------------------------------------------- */

		// methods for a vector container

		void				sortAdjacentPairs(std::vector<t_pair> & pairedSeq);
		void 				divideSequence(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending, std::vector<t_pair> & mainChain);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		size_t				intBinarySearch(const std::vector<int> & mainChain, int value, size_t end, size_t & comparisons);
		size_t				pairBinarySearch(const std::vector<t_pair> & mainChain, t_pair value, size_t end, size_t & comparisons);
		std::vector<int>	getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);
		void				recursiveSort(std::vector<t_pair> &pairedSeq, size_t &comparisons);		
		
		//////////////////// rename as pairPendingInsertion(), pairInsertPending(), insertPendingPairs() ??????
		void	intMergeInsertion(std::vector<int> & pending, std::vector<int> & mainChain, size_t & comparisons);
		void	pairMergeInsertion(std::vector<t_pair> pending, std::vector<t_pair> & mainChain, size_t & comparisons);// size_t & level);	

		void	extractPendingAndMainChain(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<int> & mainChain);

		// overloaded methods for a deque container

		// void				divideSequence(std::deque<t_pair> & seq, std::deque<int> & pending, std::deque<int> & mainChain);
		std::deque<int> 	buildJacobsthalDeq(size_t len);
		std::deque<int>		getPickingOrder(const std::deque<int> & jacobsthalSeq, size_t size);

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int> 	& getIntsVector();
		std::vector<t_pair> & getPairsVector();	

		std::vector<int>	& getIntStraggler();

		/* --- Setters ------------------------------------------------------ */

		void	setIntsVector(int value);
		void	setPairsVector(void);
		void	setPairsUpperBounds(std::vector<t_pair> pairedSeq);
		void	setIntStraggler(void);

		/* --- Public methods ----------------------------------------------- */

		void	checkInputAndSetContainers(int argc, char** argv);

		void	vecFordJohnsonSort();
		
		// overloading for a list container
		// void	fordJohnsonSort(std::deque<t_pair> & seq);		
};

// Generic function to print container contents
template <typename T>
void printContainer(const std::string msg, const T& container) {
	if (container.size() > 0) {
		std::cout << msg << "{ ";
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "}" << std::endl;
	}
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