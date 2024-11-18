/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/17 21:26:08 by ccarrace         ###   ########.fr       */
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
	int	_larger;
	int _smaller;
} t_pair;

class PmergeMe {

	private:
		std::vector<t_pair>	_pairedVector;
		std::deque<t_pair>	_deqPairs;
		int					_vecStraggler;

		/* --- Private methods ---------------------------------------------- */

		// for a vector container

		void 				sortPairs(std::vector<t_pair> & pairedSeq);
		void				sortSeqByPairs(std::vector<t_pair>& pairedSeq);
		void 				divideSequence(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<int> & mainChain);
		std::vector<int> 	buildJacobsthalVec(size_t len);
		size_t				binarySearch(const std::vector<int> & seq, int value, size_t end);
		std::vector<int>	getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize);

		// overloading for a deque container
		void				sortPairs(std::deque<t_pair> & pairedSeq);
		// void				sortSeqByPairs(std::deque<t_pair>& pairedSeq);
		void				divideSequence(std::deque<t_pair> & seq, std::deque<int> & pending, std::deque<int> & mainChain);
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

		std::vector<t_pair> & getPairedVector();
		std::deque<t_pair> & getPairedDeque();
		int		getVectorStraggler();			

		/* --- Setters ------------------------------------------------------ */

		void	setVectorStraggler(std::vector<t_pair> & pairedSeq);

	/* --- Public methods --------------------------------------------------- */

		// int		findStraggler(std::vector<t_pair> & pairedSeq);
		void	fillContainers(int argc, char** argv);
		void	fordJohnsonSort(std::vector<t_pair> & seq);

		// overloading for a list container
		void	fordJohnsonSort(std::deque<t_pair> & seq);		
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