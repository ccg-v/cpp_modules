/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:18:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/03 22:14:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void	printSpan(Span & sp) {

		const std::vector<int> & vec = sp.getVector();
		
		std::cout << "\t{ "; 		
		for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); 
				++it) 
			std::cout << (*it) << " ";	
		std::cout << "}" << std::endl;	
}

int	main(void) {

	unsigned int size = 4;
	Span sp = Span(size);

	try {
		sp.addNumber(6);
		sp.addNumber(3);
		// sp.addNumber(17);
		// sp.addNumber(9);
		// sp.addNumber(11);

		// const std::vector<int> & vec = sp.getVector();
		
		// std::cout << "{ "; 		
		// for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); 
		// 		++it) 
		// 	std::cout << (*it) << " ";	
		// std::cout << "}" << std::endl;

		printSpan(sp);
	} catch (const Span::SpanIsFullException &e) {
		printSpan(sp);	
		std::cerr << e.what() << std::endl;
	}
	
	try {
		// const std::vector<int> & vec = sp.getVector();
		// std::cout << "{ "; 		
		// for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); 
		// 		++it) 
		// 	std::cout << (*it) << " ";	
		// std::cout << "}" << std::endl;
	
		
		unsigned int	shortSpan = sp.shortestSpan();
		unsigned int	longSpan = sp.longestSpan();
		std::cout << "\tShortest span = " << shortSpan << std::endl;
		std::cout << "\tLongest span  = " << longSpan << std::endl;
	} catch (const Span::SpanTooSmallException &e) {
		std::cerr << e.what() << std::endl;
	}
	
	return 0;
}
