/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeBinarySearchInsertion.cpp                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:31:06 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/23 19:50:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

const int	jacobsthalNumbers[15] = { 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461 }; 

static void		fillChain( std::deque< int >& dst, std::deque< int > src, size_t groupSize, size_t& groups );
static void		jacobsthalInsertion( std::deque< int >& mainChain, std::deque< int > src, size_t groupSize, size_t groups );
static size_t	binarySearch( std::deque< int > src, size_t groupSize, int value, int limitValue );
static int		getIndex( size_t index, size_t groupSize );
static size_t	getLastIndex( std::deque< int > src, size_t groupSize, int limitValue );

void	binarySearchInsertion( std::deque< int >& src, size_t groupSize ) {
	std::deque< int >			mainChain;
	size_t						groups = src.size() / groupSize;

	if ( groups * groupSize < src.size() ) {
		size_t						size = src.size() - ( groups * groupSize );
		std::deque< int >			leftovers( size );
		std::deque< int >::iterator	leftoversIt;
		std::deque< int >::iterator	copy;

		leftoversIt = src.begin();
		std::advance( leftoversIt, ( groups * groupSize ) );
		copy = leftoversIt;
		for ( std::deque< int >::iterator it = leftovers.begin(); leftoversIt != src.end(); ++it ) {
			*it = *leftoversIt;
			++leftoversIt;
		}
		src.erase( copy, src.end() );
		fillChain( mainChain, src, groupSize, groups );
		jacobsthalInsertion( mainChain, src, groupSize, groups );

		src = mainChain;
		src.insert( src.end(), leftovers.begin(), leftovers.end() );
	} else {
		fillChain( mainChain, src, groupSize, groups );
		jacobsthalInsertion( mainChain, src, groupSize, groups );
		src = mainChain;
	}
}

//	Fills deque 'dst' with all the values already sorted ( the odd numbers ) found in src
static void	fillChain( std::deque< int >& dst, std::deque< int > src, size_t groupSize, size_t& groups ) {

	std::deque< int >::iterator pos = src.begin();
	std::advance( pos, groupSize );
	for ( size_t count = groups / 2 ; count > 0; count-- ) {
		std::deque< int >::iterator	endpos = pos;
		std::advance( endpos, groupSize );
		dst.insert( dst.end(), pos, endpos );
		if ( count > 1 )
			std::advance( pos, groupSize * 2 );
		groups--;
	std::cout << "fillChain: pos = " << *pos << " | endpos = " << *endpos << std::endl;
	}

} 

static void	jacobsthalInsertion( std::deque< int >& mainChain, std::deque< int > src, size_t groupSize, size_t groups ) {
 	size_t	n = 0;
	int		jacob = jacobsthalNumbers[ n ] * 2;
	int		previousJacob = 0;

	while ( groups ) {
		if ( jacob == 0 ) {
			std::cout << "\tJacobsthal: " << jacob;
			std::deque< int >::iterator	tmp = src.begin();
			std::advance( tmp, groupSize );
			mainChain.insert( mainChain.begin(), src.begin(), tmp );
			groups--;
			printInfo( src, mainChain, groupSize );
		}
		while ( jacob > previousJacob ) {
			std::cout << "\tJacobsthal: " << jacob;
			size_t	index = groupSize * jacob * 2;
			if ( index < src.size() ) {
				std::deque< int >::iterator	first = src.begin();
				std::advance( first, index );
				std::deque< int >::iterator	second = src.begin();
				std::advance( second, index + groupSize );
				int	valueOfPair = index + groupSize - 1 + groupSize;
				if ( valueOfPair >= static_cast< int >( src.size() ) )
					valueOfPair = -1;
				else
					valueOfPair = src[ valueOfPair ];

				std::deque< int >::iterator	pos = mainChain.begin();
				std::deque< int >::iterator	tmp = first;
				std::advance( tmp, groupSize - 1 );

				std::cout << "\tValue to insert [" << *tmp << "] | upper bound is [" << valueOfPair << "]";
				std::advance( pos, binarySearch( mainChain, groupSize, *tmp, valueOfPair ) );
				mainChain.insert( pos, first, second );
				printInfo( src, mainChain, groupSize );
				groups--;
			}
			else
				std::cout << std::endl;
			jacob--;
		}
		if ( groups ) {
			previousJacob += jacobsthalNumbers[ n++ ] * 2;
			jacob = previousJacob + jacobsthalNumbers[ n ] * 2;
		}
	} 
}

static size_t	binarySearch( std::deque< int > src, size_t groupSize, int value, int limitValue ) {
	size_t	low = 1;
	size_t	high = getLastIndex( src, groupSize, limitValue );

	size_t	count = 0;
	while ( low < high ) {
		count++;
		size_t	mid = ( high - low ) / 2 + low;
		std::deque< int >::iterator	tmp = src.begin();
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
	count++;
	if ( value < src[ getIndex( low, groupSize ) ] )
		index = getIndex( low, groupSize ) - groupSize + 1;
	else
		index = getIndex( high, groupSize ) + 1;
	std::cout << " | CHECK COUNT: " << count << std::endl;
	return index;
}

static int	getIndex( size_t index, size_t groupSize ) {
	return ( index - 1 ) * groupSize + groupSize - 1;
}

static size_t	getLastIndex( std::deque< int > src, size_t groupSize, int limitValue ) {
	if ( limitValue >= 0 ) {
		for ( std::deque< int >::iterator it = src.begin(); it != src.end(); it++ ) {
			if ( *it == limitValue )
				return std::distance( src.begin(), it ) / groupSize;
		}
	}
	return src.size() / groupSize;
}
