/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:53 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/18 23:46:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <list>
#include <deque>
#include <cstdlib>
#include <iostream>

#include <iostream>
#include <climits>
#include <cstring>

#ifndef INCREMENT
# define INCREMENT	0
#endif
#ifndef DECREMENT
# define DECREMENT	1
#endif

#ifndef _COLORS_
# define _COLORS_

# define YELLOW	"\033[1;33m"
# define DEFAULT	"\033[1;0m"

#endif

void	checkInput( char *argv[] );

void	mergeInsertionSort( std::deque< int >& );
void	mergeInsertionSort( std::list< int >& );

void	binarySearchInsertion( std::deque< int >&, size_t );
void	binarySearchInsertion( std::list< int >&, size_t );

template< typename T >
void	printContent( T t ) {
	for ( typename T::iterator it = t.begin(); it != t.end(); it++ )
		std::cout << *it << " ";
	std::cout << std::endl;
}

template< typename T >
void	printGroups( T t, size_t size ) {
	size_t	count = 1;

	for ( typename T::iterator it = t.begin(); it != t.end(); it++ ) {
		if ( count == 1 )
			std::cout << YELLOW << "[" << DEFAULT;
		std::cout << *it;
		if ( count == size ) {
			std::cout << YELLOW << "] " << DEFAULT;
			count = 1;
		} else {
			std::cout << " ";
			count++;
		}
	}
	std::cout << std::endl;
}

template< typename T >
void	printInfo( T t1, T t2, size_t size ) {
	std::cout << std::endl << "\tMain chain:\t";
	printGroups( t2, size );
	std::cout << "\tOriginal:\t";
	printGroups( t1, size );
	std::cout << std::endl;
}

/*
		WHAT TO DO?

	call merge-insertion-sort
		groupSize = 1
		size = 9

	5 2 3 1 4 7 6 9 8 

	swap content inside pairs

	[5-2] [3-1] [4-7] [6-9] | 8				
	[2-5] [1-3] [4-7] [6-9] | 8

	call merge-insertion-sort
		groupSize = 2
		size = 4

	swap content inside pairs

	[(2-5) (1-3)] [(4-7) (6-9)]
	[(1-3)-(2-5)] [(4-7)-(6-9)]

	call merge-insertion-sort
		groupSize = 4
		size = 2

	swap content inside pairs

	[((1-3)-(2-5)) ((4-7)-(6-9))] 		since 5 < 9 we do not swap content
	[((1-3)-(2-5))-((4-7)-(6-9))] 

	call merge-insertion-sort
		groupSize = 8
		size = 1 ; then return

	
	call jacobsthal haha xdxd

	when calling jacobsthal we will keep the reference of the paired number using an iterator
	the main difference between deque and list is that list will be able to keep it's iterator
	intact event tho we insert stuff in between, however that's not the case for deque

*/
