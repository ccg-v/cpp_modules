/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 19:47:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/02 14:03:11 by ccarrace         ###   ########.fr       */
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
		
	public:

	/* --- Orthodox Canonical Form ---------------------------------------------- */

	PmergeMe();										// Default constructor
	PmergeMe(const PmergeMe & source);				// Copy constructor
	PmergeMe & operator=(const PmergeMe & source);	// Copy assignment operator
	~PmergeMe();									// Default destructor

	/* --- Getters -------------------------------------------------------------- */

	std::vector<int> & getVector();
	std::list<int> & getList();
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