]/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/01 20:16:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PMergeMe::PMergeMe() {}

// Copy constructor
PMergeMe::PMergeMe(const PMergeMe & source) : _vec(source._vec), _lst(source._lst) {}

// Copy assignment operator
PMergeMe & PMergeMe::operator=(const PMergeMe & source) {
	if (this != &source) {
		this->_vec = source._vec;
		this->_lst = source._lst;
	}
	return *this;
}

// Default destructor
PMergeMe::~PMergeMe() {}