/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/24 00:53:06 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>	// for std::cout, std::cerr
#include <sstream>	// for std::istringstream()
#include "Utils.hpp"

typedef struct s_pair {
	int	_smaller;
	int _larger;
} t_pair;

class PmergeMe {

	private:
		std::vector<int>	_intsVector;
		std::vector<t_pair>	_pairsVector;
		t_pair				_vecPairStraggler;
		bool				_hasStraggler;

		/* --- Private methods ---------------------------------------------- */

		void				sortAdjacentPairs(std::vector<t_pair> & pairedSeq);
		void 				divideSequence(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending, std::vector<t_pair> & mainChain);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		size_t				binarySearch(const std::vector<t_pair> & seq, t_pair value, size_t end);
		size_t				intBinarySearch(const std::vector<int> & seq, int value, size_t end);
		std::vector<int>	getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int> & getIntsVector();
		std::vector<t_pair> & getPairsVector();

		/* --- Setters ------------------------------------------------------ */

		void	setIntsVector(int value);
		void	setPairsVector(void);

	/* --- Public methods --------------------------------------------------- */

		void	checkInputAndSetContainers(int argc, char** argv);
		void	fordJohnsonSort(std::vector<t_pair> & seq);
		void	extractPendingAndMainChain(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<int> & mainChain);
	
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

std::ostream& operator<<(std::ostream& os, const t_pair& pair);

#endif