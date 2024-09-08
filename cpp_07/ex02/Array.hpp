/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 19:28:34 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/08 23:32:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>	// For std::cout and std::endl
# include <stdexcept>	// For std::out_of_range

template <typename T>
class   Array {

	private:

		T*  array;
		unsigned int    size;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Array();                                    // Default constructor
		Array(const Array & source);                // Copy constructor
		Array & operator=(const Array & source);    // Copy assignment operator
		~Array();                                   // Default destructor

		/* --- Parameterized constructor ------------------------------------ */

		Array(const unsigned int n);

		/* --- Getters ------------------------------------------------------ */

		unsigned int getSize(void) const;

		/* --- Subscript Operator overloads --------------------------------- */

		// Non const version (allows modifying the array elements)
		T& operator[](unsigned int index);

		// Const version (allows accessing array elements only in read-only mode)
		const T& operator[](unsigned int index) const;

};

#include "Array.tpp"  // Include template definitions

#endif