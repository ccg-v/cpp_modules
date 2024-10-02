/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:23:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/02 23:09:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>
# include <iostream>

class Span {

	private:

		std::vector<int>	vec;
		unsigned int		_N;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Span();									// Default constructor
		Span(const Span &source);				// Copy constructor
		Span & operator=(const Span &source);	// Copy assignment operator
		~Span();								// Default destructor

		/* --- Parameterized constructor ------------------------------------ */

		Span(unsigned int N);

		/* --- Member methods ----------------------------------------------- */

		void addNumber(unsigned int num);
		unsigned int shortestSpan(Span & spn);
		unsigned int longestSpan(Span & spn);

		/* --- Exceptions --------------------------------------------------- */

		class SpanIsFullException : public std:: exception {
			public: 
				const char *what() const throw();
		};
};

#endif