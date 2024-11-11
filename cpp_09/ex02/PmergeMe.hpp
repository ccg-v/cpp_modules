/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/11 21:43:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>	// for std::cout, std::cerr

class PmergeMe {

	private:

		std::vector<int>	_vec;
		std::list<int>		_lst;

		/* --- Private methods ---------------------------------------------- */

		// for a vector container
		void 				sortPairs(std::vector<int>& seq);
		void 				divideSequence(std::vector<int>& seq, std::vector<int>& smaller);
		std::vector<int> 	generateJacobsthalSeq(size_t len);
		size_t				binarySearch(const std::vector<int>& seq, int value, size_t end);
		std::vector<int>	getInsertionOrder(const std::vector<int>& jacobsthalSeq, size_t size);

		// overloading for a list container

		
	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		PmergeMe();										// Default constructor
		PmergeMe(const PmergeMe & source);				// Copy constructor
		PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
		~PmergeMe();									// Default destructor

		/* --- Getters ------------------------------------------------------ */

		std::vector<int> & getVector();
		std::list<int> & getList();

	/* --- Public methods --------------------------------------------------- */

		void	fordJohnsonSort(std::vector<int>& seq);
};

// Generic function to print container contents
template <typename T>
void printContainer(const T& container) {
	if (container.size() > 0) {
		std::cout << "{ ";
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "}" << std::endl;
	}
}

#endif