/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:18:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/04 12:57:03 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int	main(void) {

	unsigned int N = 5;
	Span sp = Span(N);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp << std::endl;	// print the Span object
	} catch (const Span::SpanIsEmptyException &e) {	
		std::cerr << e.what() << std::endl;
	} catch (const Span::SpanIsFullException &e) {
		std::cerr << e.what() << std::endl;
		std::cout << sp << std::endl;	// print the Span object
	}
	
	try {		
		unsigned int	shortSpan = sp.shortestSpan();
		unsigned int	longSpan = sp.longestSpan();

		std::cout << "\tShortest span = " << shortSpan << std::endl;
		std::cout << "\tLongest span  = " << longSpan << std::endl;
	} catch (const Span::SpanTooSmallException &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
