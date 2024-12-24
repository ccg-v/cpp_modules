/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:32:49 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/11 13:14:57 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

static bool	infiniteCheck( long double n );
static bool	additionCheck( long double n1, long double n2 );
static bool	subtractionCheck( long double n1, long double n2 );
static bool	multiplicationCheck( long double n1, long double n2 );
static bool	divisionCheck( long double n1, long double n2 );
static bool	printError( std::string msg );

bool	calculate( long double& r, long double n1, long double n2, char operation ) {
	switch ( operation ) {
		case '+':
			if ( !additionCheck( n1, n2 ) )
				return false;
			r = n1 + n2;
			break ;
		case '-':
			if ( !subtractionCheck( n1, n2 ) )
				return false;
			r = n1 - n2;
			break ;
		case '*':
			if ( !multiplicationCheck( n1, n2 ) )
				return false;
			r = n1 * n2;
			break ;
		case '/':
			if ( !divisionCheck( n1, n2 ) )
				return false;
			r = n1 / n2;
			break ;
	}
	if ( std::isnan( r ) )
		return printError( "NaN" );
	return true;
}

static bool	infiniteCheck( long double n ) {
	if ( std::isinf( n ) ) {
		if ( std::signbit( n ) )
			return printError( "-inff." );
		else
			return printError( "inff." );
    }
	return true;
}

static bool	additionCheck( long double n1, long double n2 ) {
	if ( n1 > 0 && n2 > 0 && n1 > ( std::numeric_limits<int>::max() - n2 ) )
		return printError( "Overflow: addition result is too big." );
	if ( n1 < 0 && n2 < 0 && n1 < ( std::numeric_limits<int>::min() - n2 ) )
		return printError( "Underflow: addition result is too small." );
	return true;
}

static bool	subtractionCheck( long double n1, long double n2 ) {
	if ( n1 > 0 && n2 < 0 && n1 > ( std::numeric_limits<int>::max() + n2 ) )
		return printError( "Overflow: addition result is too big." );
	if ( n1 < 0 && n2 > 0 && n1 < ( std::numeric_limits<int>::min() + n2 ) )
		return printError( "Underflow: addition result is too small." );
	return true;
}

static bool	multiplicationCheck( long double n1, long double n2 ) {
	long double	res = n1 * n2;
	if ( !infiniteCheck( res ) )
		return false;
	if ( n1 > 0 && n2 > 0 && n1 > ( std::numeric_limits<int>::max() / n2 ))
		return printError( "Overflow: multiplication result is too big." );
	else if ( n1 < 0 && n2 < 0 && n1 < ( std::numeric_limits<int>::max() / n2 ))
		return printError( "Overflow: multiplication result is too big." );
	else if ( n1 > 0 && n2 < 0 && n1 < ( std::numeric_limits<int>::min() / 2 ))
		return printError( "Underflow: multiplication result is too small." );
	else if ( n1 < 0 && n2 > 0 && n1 < ( std::numeric_limits<int>::min() / 2 ))
		return printError( "Underflow: multiplication result is too small." );
	return true;
}

static bool	divisionCheck( long double n1, long double n2 ) {
	if ( n2 == 0 )
		return printError( "Can't divide by 0." );
	if ( !infiniteCheck( n1 / n2 ) )
		return false;
	if ( n1 > 0 && n2 > 0 && n1 > ( std::numeric_limits<int>::max() / n2 ) )
		return printError( "Overflow: division result is too big." );
	else if ( n1 < 0 && n2 < 0 && n1 < ( std::numeric_limits<int>::max() / n2 ) )
		return printError( "Overflow: division result is too big." );
	else if ( n1 > 0 && n2 < 0 && n1 < ( std::numeric_limits<int>::min() / n2 ) )
		return printError( "Underflow: divison result is too small." );
	else if ( n1 < 0 && n2 > 0 && n1 < ( std::numeric_limits<int>::min() / n2 ) )
		return printError( "Underflow: divison result is too small." );
	return true;
}

static bool	printError( std::string msg ) {
	std::cout << "Error: " << msg << std::endl;
	return false;
}
