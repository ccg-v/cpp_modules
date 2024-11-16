/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/16 14:09:08 by ccarrace         ###   ########.fr       */
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

		std::vector<int>	_vec;
		std::deque<int>		_deq;

		/* --- Private methods ---------------------------------------------- */

		// for a vector container
		void 				sortPairs(std::vector<int> & seq);
		void 				divideSequence(std::vector<int> & seq, std::vector<int> & smaller);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		size_t				binarySearch(const std::vector<int> & seq, int value, size_t end);
		std::vector<int>	getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);

		// overloading for a deque container
		void				sortPairs(std::deque<int> & seq);
		void				divideSequence(std::deque<int> & seq, std::deque<int> & smaller);
		std::deque<int> 	buildJacobsthalDeq(size_t len);
		size_t				binarySearch(const std::deque<int> & seq, int value, size_t end);
		std::deque<int>		getInsertionOrder(const std::deque<int> & jacobsthalSeq, size_t size);

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int> & getVector();
		std::deque<int> & getDeque();

	/* --- Public methods --------------------------------------------------- */

		void	fillContainers(int argc, char** argv);
		void	fordJohnsonSort(std::vector<int> & seq);

		// overloading for a list container
		void	fordJohnsonSort(std::deque<int> & seq);		
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

#endif