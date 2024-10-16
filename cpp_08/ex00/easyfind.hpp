/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:15:05 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/16 14:26:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>	// for std::find
# include <stdexcept>   // for std::runtime_error
# include <iostream>	// for std::ostream and std::cout
# include <sstream> 	// For std::ostringstream
# include <vector>		// for std:vector
# include <deque>		// for std::deque
# include <list>		// for std::list

/* --- easyfind() function -------------------------------------------------- */

// Generic function
template <typename T>
typename T::const_iterator easyfind(const T& container, int value); 

// Specialization for C-style arrays
template <typename T, size_t N>
T* easyfind(T (&array)[N], int value);

/* --- Printing functions --------------------------------------------------- */

// Generic function to print container contents
template <typename T>
void printContainer(const T& container);

// Specialization to print C-style arrays
template <typename T, size_t N>
void printContainer(T (&array)[N]);

/* --- Exceptions ----------------------------------------------------------- */ // (1)

// class NoOccurrenceFoundException : public std::exception {
// 	public:
// 		const char *what() const throw();
// };

#include "easyfind.tpp"

#endif

/*
 *	(1) I finally decided to throw a standard exception instead of a custom one. 
 *		Read why here:
 *		https://github.com/ccg-v/cpp_modules/tree/master/cpp_08/ex00#-throw-a-standard-or-a-custom-exception-
 */