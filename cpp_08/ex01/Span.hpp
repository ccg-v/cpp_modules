/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:23:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/04 12:05:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>
# include <iostream>
# include <algorithm>	// for std::min_element and std::max_element
# include <limits.h>	// for INT_MAX

class Span {

	private:

		std::vector<int>	_vec;
		unsigned int		_N;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Span();									// Default constructor
		Span(const Span &source);				// Copy constructor
		Span & operator=(const Span &source);	// Copy assignment operator
		~Span();								// Default destructor

		/* --- Parameterized constructor ------------------------------------ */

		Span(unsigned int N);

		/* --- Getters ------------------------------------------------------ */

		const std::vector<int> & getVector() const;	

		/* --- Member methods ----------------------------------------------- */

		void addNumber(unsigned int num);
		unsigned int shortestSpan();
		unsigned int longestSpan();

		/* --- Exceptions --------------------------------------------------- */

		class SpanIsEmptyException : public std:: exception {
			public: 
				const char *what() const throw();
		};

		class SpanIsFullException : public std:: exception {
			public: 
				const char *what() const throw();
		};

		class SpanTooSmallException : public std::exception {
			public:
				const char *what() const throw();
		};

};


/* --- Non member functions ------------------------------------------------- */

// Insertion operator<< overload
std::ostream & operator<<(std::ostream & os, const Span & sp);

#endif