/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:08:11 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/19 01:09:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <list>

static void	updateValues( size_t& groupSize, size_t& size, bool flag );
static void	sortPairs( std::deque< int >& src, size_t groupSize );
static void	sortPairs( std::list< int >& src, size_t groupSize );

void	mergeInsertionSort( std::deque< int >& src ) {
	static size_t	groupSize = 1;
	static size_t	size = src.size();
	if ( groupSize == 1 )
		std::cout << std::endl;
	if ( size > 1 ) {
		sortPairs( src, groupSize );
		updateValues( groupSize, size, INCREMENT );
		std::cout << ">>> Recalling mergeInsertionSort:\n" << std::endl;
		mergeInsertionSort( src );
		std::cout << ">>> Inserting with binarySearch:\n" << std::endl;
			updateValues( groupSize, size, DECREMENT );
		binarySearchInsertion( src, groupSize );
	}
	// updateValues( groupSize, size, DECREMENT );
	return ;
}

static void	sortPairs( std::deque< int >& src, size_t groupSize ) {
	size_t	tail = groupSize - 1;
	std::cout << "\tBefore swap pairs:\t";
	printGroups( src, groupSize );
	while ( tail + groupSize < src.size() ) {
		std::deque< int >::iterator	first = src.begin();
		std::advance( first, tail );
		std::deque< int >::iterator	second = src.begin();
		std::advance( second, tail + groupSize );
		if ( *first > *second ) {
			std::deque< int >::iterator	trueFirst = src.begin();
			std::advance( trueFirst, tail - groupSize + 1 );
			std::deque< int >::iterator	trueSecond = src.begin();
			std::advance( trueSecond, tail + 1 );
			std::advance( first, 1 );
			std::swap_ranges( trueFirst, first, trueSecond ); 
		}
		tail += groupSize * 2;
	}
	std::cout << "\tAfter swap pairs:\t";
	printGroups( src, groupSize );
	std::cout << std::endl;
}

void	mergeInsertionSort( std::list< int >& src ) {
	static size_t	groupSize = 1;
	static size_t	size = src.size();

	if ( size > 1 ) {
		sortPairs( src, groupSize );
		updateValues( groupSize, size, INCREMENT );
		mergeInsertionSort( src );
		binarySearchInsertion( src, groupSize );
	}
	updateValues( groupSize, size, DECREMENT );
	return ;
}

static void	sortPairs( std::list< int >& src, size_t groupSize ) {
	size_t	tail = groupSize - 1;
//	size_t	count = 0;
	while ( tail + groupSize < src.size() ) {
		std::list< int >::iterator	first = src.begin();
		std::advance( first, tail );

		std::list< int >::iterator	second = src.begin();
		std::advance( second, tail + groupSize );
//		count++;
		if ( *first > *second ) {
			std::list< int >::iterator	trueFirst = src.begin();
			std::advance( trueFirst, tail - groupSize + 1 );
			std::list< int >::iterator	trueSecond = src.begin();
			std::advance( trueSecond, tail + 1 );
			std::advance( first, 1 );
			std::swap_ranges( trueFirst, first, trueSecond ); 
		}
		tail += groupSize * 2;
	}
//	std::cout << "COUNT IN PAIRS: " << count << std::endl;
}

static void	updateValues( size_t& groupSize, size_t& size, bool flag ) {
	if ( flag == INCREMENT ) {
		std::cout << ">>> Updating values: INCREMENTING groups\n" << std::endl;
		groupSize *= 2;
		size /= 2;
	} else {
		std::cout << ">>> Updating values: DECREMENTING groups\n" << std::endl;
		groupSize /= 2;
		size *= 2;
	}
}
