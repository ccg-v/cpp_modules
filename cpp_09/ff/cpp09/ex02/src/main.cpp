/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:07:05 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/26 20:01:31 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <ctime>
#include <algorithm>

static bool	isSorted( std::deque< int > myDeque, std::deque< int > & ogDeque )
{
	std::sort(ogDeque.begin(), ogDeque.end());
	std::deque< int >::iterator ogIt = ogDeque.begin();
	for (std::deque< int >::iterator it = myDeque.begin(); it != myDeque.end(); ++it)
	{
		if (*it != *ogIt)
			return false;
		++ogIt;
	}
	return true;
}

static bool	isSorted( std::list< int > & myDeque, std::list< int > & ogDeque )
{
	ogDeque.sort();
	std::list< int >::iterator ogIt = ogDeque.begin();
	for (std::list< int >::iterator it = myDeque.begin(); it != myDeque.end(); ++it)
	{
		if (*it != *ogIt)
			return false;
		++ogIt;
	}
	return true;
}

static void	printTime( int range, double dequeTime, double listTime ) {
	bool	tooBig = false;

	if ( dequeTime >= 1000 )
		tooBig = true;
	std::cout << "Time to process a range of " << range << " elements with std::[deque] :\t";
	if ( tooBig )
		std::cout << dequeTime / 1000 << " ms" << std::endl;
	else
		std::cout << dequeTime << " us" << std::endl;
	std::cout << "Time to process a range of " << range << " elements wit std::[list] :\t";
	if ( tooBig )
		std::cout << listTime / 1000 << " ms" << std::endl;
	else
		std::cout << listTime << " us" << std::endl;
}

int	main( int argc, char *argv[] ) {
	if ( argc < 3 || argc > 10001 ) {
		std::cout << "Error: run program with a positive integer sequence of any size between 2 & 10000 numbers as argument." << std::endl;
		return 1;
	}
	checkInput( argv + 1 );

	std::deque< int >	myDeque( argc - 1 );
	std::list< int >	myList( argc - 1 );
	std::deque< int >::iterator	dequeIt = myDeque.begin();
	std::list< int >::iterator	listIt = myList.begin();

	for ( int i = 1; argv[ i ] != NULL; i++ ) {
		int	n = atoi( argv[ i ] );
		*dequeIt = n;
		*listIt = n;
		std::advance( dequeIt, 1 );
		std::advance( listIt, 1 );
	}

	std::deque< int >	ogDeque( myDeque );
	std::list< int >	ogList( myList );
	
	clock_t	start;
	clock_t	end;

	std::cout << "Before:\t";
	printContent( myDeque );

	start = std::clock();
	mergeInsertionSort( myDeque );
	end = std::clock();

	double	dequeTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;
	
	start = std::clock();
	mergeInsertionSort( myList );
	end = std::clock();

	double	listTime = static_cast< double >( end - start ) * 1000000 / CLOCKS_PER_SEC;

	std::cout << "After:\t";
	printContent( myDeque );
	printTime( argc - 1, dequeTime, listTime );

	if ( !isSorted( myDeque, ogDeque ) )
		std::cout << YELLOW << "DEQUE NOT SORTED" << DEFAULT<< std::endl;
	else
		std::cout << "DEQUE SORTED" << std::endl;
	if	( !isSorted( myList, ogList ) )
		std::cout << YELLOW << "LIST NOT SORTED" << DEFAULT << std::endl;
	else
		std::cout << "LIST SORTED" << std::endl;
	return 0;
}
