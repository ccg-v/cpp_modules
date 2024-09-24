/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:43:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/24 22:21:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default Constructor
Span::Span : _N(0) {
	std::cout << "Span Default Constructor called" << std::enl;
}

// Copy constructor
Span::Span(const Span & source) : _N(source._N){
	std::cout << "Span Copy Constructor called"  << std::endl;
	for (unsigned int i = 0; i < source._N; i++)
		vec[i] = source[i];
}

// Copy constructor
Span::Span(const Span & source) : _N(source._N) {
	std::cout << "Span Copy Constructor called"  << std::endl;
	for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it)
		vec[*it] = source[*it];
}

/* --- Parameterized constructor -------------------------------------------- */

Span::Span(unsigned int N) {
	std::cout << "Span Parameterized Constructor called" << std::endl;
	vec.reserve(N);  // Preallocate space for N elements (optional)
}
