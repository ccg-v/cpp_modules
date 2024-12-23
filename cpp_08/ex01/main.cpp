/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 19:18:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/18 13:06:28 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <ctime>   // std::time()

int	main(void) {

/* --- Testing empty Span --------------------------------------------------- */

	std::cout << "/* --- Testing empty span --------------------------------- */" 
			  << std::endl;
	
	Span emptySpan;
	try {		
		std::cout << emptySpan << std::endl;	// print the Span object

		unsigned int	shortSpan = emptySpan.shortestSpan();
		unsigned int	longSpan = emptySpan.longestSpan();

		std::cout << "\tShortest span = " << shortSpan << std::endl;
		std::cout << "\tLongest span  = " << longSpan << std::endl;
	} catch (const Span::SpanTooSmallException &e) {
		std::cerr << e.what() << std::endl;
	} catch (const Span::SpanIsEmptyException &e) {
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
/* --- Testing single element Span ------------------------------------------ */

	std::cout << "/* --- Testing single element span ------------------------ */" 
			  << std::endl;
	
	Span singleSpan(1);
	try {
		singleSpan.addNumber(6);

		std::cout << singleSpan << std::endl;	// print the Span object
	} catch (const Span::SpanIsEmptyException &e) {	
		std::cerr << e.what() << std::endl;
	} catch (const Span::SpanIsFullException &e) {
		std::cerr << e.what() << std::endl;
		std::cout << singleSpan << std::endl;	// print the Span object
	}

	try {		
		unsigned int	shortSpan = singleSpan.shortestSpan();
		unsigned int	longSpan = singleSpan.longestSpan();

		std::cout << "\tShortest span = " << shortSpan << std::endl;
		std::cout << "\tLongest span  = " << longSpan << std::endl;
	} catch (const Span::SpanTooSmallException &e) {
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

/* --- Adding random numbers one by one ------------------------------------- */

	std::cout << "/* --- Adding random numbers one by one ------------------- */" 
			  << std::endl;

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
	
	std::cout << std::endl;

/* --- Adding random numbers in one call ------------------------------------ */

	std::cout << "/* --- Adding random numbers in one call ------------------ */" 
			  << std::endl;
			  
	unsigned int capacity = 10;
	unsigned int randNumAmount = 10000;
	Span sp2 = Span(capacity);
	
	try {
		std::srand(std::time(0));  // Seed for randomness

		// Generate a range of random numbers in a temporary vector
		std::vector<int> randomVec(randNumAmount);
		for (std::vector<int>::iterator it = randomVec.begin(); it != randomVec.end(); ++it) {
			*it = std::rand() % INT_MAX;
		}

		// Add the range of random numbers to the Span using iterators
		sp2.addRange(randomVec.begin(), randomVec.end());
		std::cout << sp2 << std::endl;	// print the Span object		
	} catch (const Span::SpanIsFullException &e) {
		std::cerr << e.what() << std::endl;
		std::cout << sp2 << std::endl;	// print the Span object
	}

	try {		
		unsigned int	shortSpan = sp2.shortestSpan();
		unsigned int	longSpan = sp2.longestSpan();

		std::cout << "\tShortest span = " << shortSpan << std::endl;
		std::cout << "\tLongest span  = " << longSpan << std::endl;
	} catch (const Span::SpanTooSmallException &e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
