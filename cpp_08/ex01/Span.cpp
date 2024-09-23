/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:43:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/23 21:51:17 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default Constructor (1)
Span::Span {
	std::cout << "Span Default Constructor called" << std::enl;
	std::vector<int> vec;
}

// Copy constructor
Span::Span(const Span & source) {
	std::cout << "Span Copy Constructor called"  << std::endl;
	std::vector<int> vec;
	for (unsigned int i = 0; i < source.N; i++)
		vec[i] = source[i];
}

// Copy constructor
Span::Span(const Span & source) {
	std::cout << "Span Copy Constructor called"  << std::endl;
	std::vector<int> vec;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		vec[i] = source[i];
}

/* --- Parameterized constructor -------------------------------------------- */

Span::Span(unsigned int N) {
	std::cout << "Span Parameterized Constructor called" << std::endl;
	std::vector<int> vec(N);
}

/*
 *	(1) When creating a std::vector, if you don't provide an initial size you
 *		are indeed creating an empty vector that dynamically grows as you add
 *		elements.
 */