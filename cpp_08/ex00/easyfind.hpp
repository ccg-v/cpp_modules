/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:15:05 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/08 22:20:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>	// for std::find
# include <vector>		// for std:vector
# include <stdexcept>   // for std::runtime_error
# include <iostream>	// for std::ostream and std::cout
# include <sstream> 	// For std::ostringstream

template <typename T>
typename T::const_iterator easyfind(const T& container, int value); 

// Specialization for C-style arrays
template <typename T, size_t N>
T* easyfind(T (&array)[N], int value);

// Generic function to print container contents
template <typename T>
void printContainer(const T& container);

// Exception
class NoOccurrenceFoundException : public std::exception {
	public:
		const char *what() const throw();
};

#include "easyfind.tpp"

#endif