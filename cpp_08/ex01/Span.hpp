/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:23:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/23 21:43:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <string>
# include <vector>

class Span {

	private:

		unsigned int N;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Span();									// Default constructor
		Span(const Span &source);				// Copy constructor
		Span & operator=(const Span &source);	// Copy assignment operator
		~Span();								// Default destructor

		/* --- Parameterized constructor ------------------------------------ */

		Span(unsigned int N);

		/* --- Member methods ----------------------------------------------- */

		unsigned int shortestSpan(Span Array);
		unsigned int longestSpan(Span Array)
}

#endif