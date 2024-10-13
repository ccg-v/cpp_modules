/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:15:10 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/13 14:24:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>	// For std::cout and std::endl
# include <stack>		// For std::stack

template <typename T>	// (1)
class MutantStack : public std::stack<T> {	// (2)

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		MutantStack();											// Default constructor
		MutantStack(const MutantStack & source);				// Copy constructor
		MutantStack & operator=(const MutantStack & source);	// Copy assignment operator
		~MutantStack();											// Default destructor

        /* --- Member functions --------------------------------------------- */

		// Creating an alias for the underlying container's iterator type
		typedef typename std::stack<T>::container_type::iterator iterator;	// (3)

        // Expose begin() and end() from the underlying container	// (4)
        iterator begin();
        iterator end();

};

/* --- Non member functions ------------------------------------------------- */

// Insertion operator<< overload
template <typename T>
std::ostream & operator<<(std::ostream & os, MutantStack<T> & mstack);

# include "MutantStack.tpp"

#endif

/*
 *	(1) The class must be a template so that it can handle different data types
 */

 /*
  *	(2) even though std::stack has a protected member c, the compiler cannot
  *		directly access it in C++98, and it does not expose this member directly.
  *		The problem arises because c is protected, and in C++98, this can be
  *		tricky to access through inheritance without more explicit mechanisms.
  *
  *		In C++98, we can still access the underlying container c because it's
  *		protected, but we need to use inheritance carefully and ensure we're
  *		referring to it properly.
  *
  *		Direct Access Through Inheritance: You are inheriting from std::stack,
  *		but the protected member c doesn't become automatically accessible
  *		unless you inherit publicly. Here’s the corrected code:
  */

/*	(3) The typedef creates an alias for the underlying container's iterator 
 *		type in the MutantStack class. This alias allows us to refer to the
 *		container's iterator type directly as iterator within your class.
 *
 *		- std::stack<T>::container_type: This is the type of the underlying 
 *			container (usually std::deque<T> by default).
 *		- ::iterator: This accesses the iterator type defined within that 
 *			container (std::deque<T>::iterator, for instance).
 *
 *		By defining this typedef in your class, you're effectively saying,
 *		"I want my class to have an iterator type that is the same as the
 *		iterator type of the container inside the stack."
 */

 /*
  *	(4)	Why explicitly expose the iterators but not push(), pop(), size()...?
  *
  *		- Methods like push, pop, top, etc. are part of the std::stack interface,
  *			so when you inherit from std::stack, these methods are directly 
  *			accessible without needing to do anything special.
  *
  *		- Iterators (begin(), end(), etc.) are not part of the std::stack interface,
  *			even though the underlying container has them. Since std::stack hides
  *			the iterators, you need to explicitly expose these in the MutantStack
  *			class to make the stack iterable.
  */