/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:23:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/26 22:16:04 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>

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

		void addNumber(Span & spn, unsigned int num);

		/* --- Member methods ----------------------------------------------- */

		unsigned int shortestSpan(Span & spn);
		unsigned int longestSpan(Span & spn);

		/* --- Exceptions --------------------------------------------------- */

		class SpanIsFullException : public std:: exception {
			public: 
				const char *what() const throw();
		};
}

#endif