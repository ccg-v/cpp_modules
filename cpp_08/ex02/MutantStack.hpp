/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 22:15:10 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/13 00:34:59 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>	// For std::cout and std::endl
# include <stack>		// For std::stack

template <typename T>	// (1)
class MutantStack : public std::stack<T> {	// (2)

	private:
		std::stack<T> _innerStack;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		MutantStack();											// Default constructor
		MutantStack(const MutantStack & source);				// Copy constructor
		MutantStack & operator=(const MutantStack & source);	// Copy assignment operator
		~MutantStack();											// Default destructor

        /* --- Exposing std::stack member functions ------------------------ */

        // Delegate push() to the underlying stack
        void push(const T& value) {
            _innerStack.push(value);
        }

        // Delegate top() to the underlying stack
        T& top() {
            return _innerStack.top();
        }

        void pop() {
            _innerStack.pop();
        }

        bool empty() const {
            return _innerStack.empty();
        }

        size_t size() const {
            return _innerStack.size();
        }

	    /* --- Adding Iterator Support -------------------------------------- */
		
        typedef typename std::deque<T>::iterator iterator;
        typedef typename std::deque<T>::const_iterator const_iterator;
        typedef typename std::deque<T>::reverse_iterator reverse_iterator;
        typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

        // Expose begin() and end() from the underlying container
        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }

        const_iterator begin() const {
            return this->c.begin();
        }

        const_iterator end() const {
            return this->c.end();
        }

        // Expose reverse iterators from the underlying container
        reverse_iterator rbegin() {
            return this->c.rbegin();
        }

        reverse_iterator rend() {
            return this->c.rend();
        }

        const_reverse_iterator rbegin() const {
            return this->c.rbegin();
        }

        const_reverse_iterator rend() const {
            return this->c.rend();
        }
};

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