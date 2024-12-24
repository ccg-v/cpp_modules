/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listBinarySearchInsertion.cpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:31:06 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/21 16:32:19 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const int	jacobsthalNumbers[15] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461 }; 

static void		fillChain( std::list< int >& dst, std::list< int > src, size_t groupSize, size_t& groups );
static void		handleLeftovers( std::list< int >& src, std::list< int >& leftovers, std::list< int >::iterator& it );
static void		jacobsthalInsertion( std::list< int >& mainChain, std::list< int > src, size_t groupSize, size_t groups );
static size_t	binarySearch( std::list< int > src, size_t groupSize, int value, int limitValue );
static int		getIndex( double index, size_t groupSize );
static size_t	getLastIndex( std::list< int > src, size_t groupSize, int limitValue );

void	binarySearchInsertion( std::list< int >& src, size_t groupSize ) {
	std::list< int >			mainChain;
	std::list< int >			leftovers;
	std::list< int >::iterator	leftoversIt = src.begin();
	size_t						groups = src.size() / groupSize;

	std::advance( leftoversIt, groups * groupSize );
	fillChain( mainChain, src, groupSize, groups );
	handleLeftovers( src, leftovers, leftoversIt );
	jacobsthalInsertion( mainChain, src, groupSize, groups );
	
	src = mainChain;
	//
	if ( leftovers.size() > 0 )
		src.insert( src.end(), leftovers.begin(), leftovers.end() );

	// DEBUG
	/*
	if ( groupSize > 1 ) {
		std::cout << YELLOW << "FINISH\t\t" << DEFAULT;
		printGroups( mainChain, groupSize );
	}
	*/
}

//	Fills deque 'dst' with all the values already sorted ( the odd numbers ) found in src
static void	fillChain( std::list< int >& dst, std::list< int > src, size_t groupSize, size_t& groups ) {
	std::list< int >::iterator	pos = src.begin();
	std::advance( pos, groupSize );
	
	std::list< int >::iterator	postPos = src.begin();
	std::advance( postPos, groupSize * 2 );

	for ( size_t count = groups * 0.5f; count > 0; count-- ) {
		dst.insert( dst.end(), pos, postPos );
		std::advance( pos, groupSize * 2 );
		std::advance( postPos, groupSize * 2 );
		groups--;
	}
} 

static void	handleLeftovers( std::list< int >& src, std::list< int >& leftovers, std::list< int >::iterator& it ) {
	if ( it != src.end() ) {
		leftovers.insert( leftovers.begin(), it, src.end() );
		src.erase( it, src.end() );
	}
}

static void	jacobsthalInsertion( std::list< int >& mainChain, std::list< int > src, size_t groupSize, size_t groups ) {
 	size_t	n = 0;
	int		jacob = jacobsthalNumbers[ n ] * 2;
	int		previousJacob = 0;
	while ( groups ) {
		if ( jacob == 0 ) {
			std::list< int >::iterator	end = src.begin();
			std::advance( end, groupSize );
			mainChain.insert( mainChain.begin(), src.begin(), end );
			groups--;
			// DEBUG
//			printInfo( src, mainChain, groupSize );
		}
		while ( jacob > previousJacob ) {
			if ( ( groupSize * jacob * 2 ) < src.size() ) {
				std::list< int >::iterator	first = src.begin();
				std::advance( first, groupSize * jacob * 2 );

				std::list< int >::iterator	second = src.begin();
				// We subtract 1 so we can access the value before the iterator in which we'll insert
				std::advance( second, groupSize * jacob * 2 + groupSize - 1 );
				
				int	valueOfPair = ( groupSize * jacob * 2 ) + groupSize - 1 + groupSize;
				if ( valueOfPair > static_cast< int >( src.size() ) )
					valueOfPair = -1;
				else {
					std::list< int >::iterator	tmp = src.begin();
					std::advance( tmp, valueOfPair );
					valueOfPair = *tmp;
				}
				int	posIndex = binarySearch( mainChain, groupSize, *second, valueOfPair );
				std::advance( second, 1 );
				std::list< int >::iterator	pos = mainChain.begin();
				std::advance( pos, posIndex );
				mainChain.insert( pos, first, second );
				// DEBUG
//				printInfo( src, mainChain, groupSize );
				groups--;
			}
			jacob--;
		}
		if ( groups ) {
			previousJacob += jacobsthalNumbers[ n++ ] * 2;
			jacob = previousJacob + jacobsthalNumbers[ n ] * 2;
		}
	} 
}

static size_t	binarySearch( std::list< int > src, size_t groupSize, int value, int limitValue ) {
	size_t	low = 1;
	size_t	high = getLastIndex( src, groupSize, limitValue );

//	size_t	count = 0;
	while ( low < high ) {
//		count++;
		size_t	mid = ( high - low ) / 2 + low;
// 		std::cout << "LOW: " << low << " MID: " << mid << " HIGH: " << high << std::endl;
		
		std::list< int >::iterator	tmp = src.begin();
		std::advance( tmp, getIndex( mid, groupSize ) );
		if ( value > *tmp ) {
			if ( mid < high )
				low = mid + 1;
		}
		else {
			if ( mid > low )
				high = mid - 1;
			else
				high = low;
		}
	}
	size_t	index = 0;
//	count++;	
	std::list< int >::iterator	tmp = src.begin();
	std::advance( tmp, getIndex( low, groupSize ) );
	if ( value < *tmp )
		index = getIndex( low, groupSize ) - groupSize + 1;
	else
		index = getIndex( high, groupSize ) + 1;
//	std::cout << "CHECK COUNT: " << count << std::endl;
	return index;
}

static int	getIndex( double index, size_t groupSize ) {
	return ( index - 1 ) * groupSize + groupSize - 1;
}

static size_t	getLastIndex( std::list< int > src, size_t groupSize, int limitValue ) {
	if ( limitValue >= 0 ) {
 		for ( size_t i = 0; i < src.size(); i++ ) {
			std::list< int >::iterator	tmp = src.begin();
			std::advance( tmp, i );
			if ( *tmp == limitValue )
				return i / groupSize;
		}
	}
	return src.size() / groupSize;
}
