/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:25:43 by ffornes-          #+#    #+#             */
/*   Updated: 2024/11/26 16:10:17 by ffornes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <map>
#include <stdexcept>

static char	detectDelimiter( std::string& filename ) {
	std::ifstream	file( filename.c_str() );

	std::string	header;
	if ( std::getline( file, header ) ) {
		if ( header.find( ',' ) != std::string::npos )
			return ',';
		else if ( header.find( '|' ) != std::string::npos )
			return '|';
	}
	return '\0';
}

// Removes spaces from line which makes it easier to print everything with the same
//	identation. Also prevents errors when header contains spaces.
static std::string	removeSpace( const std::string& line ) {
    std::string result;

	if ( !line.empty() || line.size() > 0 ) {
		result.reserve( line.size() );
		for ( std::string::const_iterator it = line.begin(); it != line.end(); ++it )
			if ( !std::isspace( static_cast< unsigned char >( *it ) ) )
				result += *it;
	}
    return result;
}

static std::multimap< std::string, float >	readFile( std::string filename ) {
	std::multimap< std::string, float >	data;
	std::ifstream	file( filename.c_str() );

	if ( !file )
		throw std::runtime_error( "Error: unable to read " + filename );
	
	std::string	line;
	char		c;

	c = detectDelimiter( filename );
	if ( !c )
		throw std::runtime_error( "Error: invalid format, no delimiter in " + filename );
	else if ( c != '|' && filename != "data.csv" )
		throw std::runtime_error( "Error: invalid format, wrong delimiter in " + filename );
	while ( std::getline( file, line ) ) {
		std::string			date;
		float				value;
		std::string			tmp;

		tmp = removeSpace( line );
		if ( !tmp.empty() ) {
			std::istringstream	ss( tmp );
			std::getline( ss , date, c );
			if ( ss >> value )
				data.insert( std::make_pair< std::string, float >( date, value ) );
			else if ( date != "date" )
				throw std::runtime_error( "Error: invalid format in " + filename + ", in line: " + line );
			else
				ss.clear();
		}
	}
	file.close();
	return data;
}

static bool	badInput( const std::string& str ) {
	std::cout << "Error: Bad input => " + str << std::endl;
	return false;
}

static bool	validateDate( const std::string& str ) {
	int					date[3];
	std::stringstream	ss( str );
	std::string			aux;

// Check there are no other characters besides digits and the valid '-'
	int	c = 0;
	for ( int j = 0; j < static_cast< int >( str.size() ); j++ ) {
		if ( !isdigit( str[ j ] ) && str[ j ] != '-' )
			return badInput( str );
		else if ( str[ j ] == '-' )
			c++;
		if ( c > 2 )
			return badInput( str );
	}

// Save the year - month - day values inside the date array
	int	i = 0;
	while ( getline( ss, aux, '-' ) && i < 3 )
		date[i++] = atoi( aux.c_str() );

// Basic checks for year-month-day
	if ( date[0] < 2009 || date[1] > 12 || date[1] < 1 || date[2] < 1 )
		return badInput( str );
// Check limit case for data.csv
	if ( date[0] == 2009 && date[1] == 1 && date[2] < 2 )
		return badInput( str );
// Check the day is a valid input depending on the month
	switch ( date[1] ) {
		case 2:
			if ( date[2] > 29 )
				return badInput( str );
			if ( date[2] > 28 ) {
				if ( date[0] % 4 != 0 )
					return badInput( str );
				else if ( date[0] % 100 == 0 && date[0] % 400 != 0 )
					return badInput( str );
			}
			break ;
		case 4:
		case 6:
		case 9:
		case 11:
			if ( date[2] > 30 )
				return badInput( str );
			break ;
		default:
			if ( date[2] > 31 )
				return badInput( str );
			break ;
	}
	return true;
}

static bool	validateValue( const float f ) {
	if ( f < 0 )
		std::cout << "Error: not a positive number." << std::endl;
	else if ( f > 1000 )
		std::cout << "Error: too large a number." << std::endl;
	else
		return true;
	return false;
}

// Prints the output of a valid date and value
//	It uses std::fixed and std::setprecision to print the float values with certain
//	precision.
//	In order to prevent the floats to be printed showing unnecessary zeroes after the
//	comma, it will search for the dot character and check where is the last non_zero.
//	Then it simply erases everything before the non_zero and if that value is a dot
//	it erases it too.
static void	printOutput( std::multimap< std::string, float >::iterator it, std::multimap< std::string, float >::iterator ite ) {
	std::ostringstream	out;
	std::string			result;

	out << std::fixed << std::setprecision( 6 ) << ( it->second * ite->second );
	result = out.str();

	size_t	dotPos = result.find( '.' );
	if ( dotPos != std::string::npos ) {
		size_t	lastNonZero = result.find_last_not_of( '0' );
		if ( lastNonZero != std::string::npos )
			result.erase( lastNonZero + 1 );
		else
			result.erase( dotPos );
		if ( !result.empty() && result[ result.size() - 1 ] == '.' )
			result.erase( result.size() - 1 );
	}
	std::cout << it->first << " => " << it->second << " = " << result << std::endl;
}

// Gets both multimaps, the one containing the database and the file we have to process
//	Using an iterator, goes through the file we have to process
//	First validates the date and the value
//	If the database contains that date, calls printOutput.
//	If it doesn't, searches for the closest result using data.lower_bound
//	To get the previous key, access the previous iterator value using foundIt--;
static void	processFile( std::multimap< std::string, float > data, std::multimap< std::string, float > file ) {
	for ( std::multimap< std::string, float >::iterator it = file.begin(); it != file.end(); ++it ) {
		if ( validateDate( it->first ) && validateValue( it->second ) ) {
			std::multimap< std::string, float >::iterator dataIt;
			dataIt = data.find( it->first );
			if ( dataIt != data.end() )
				printOutput( it, dataIt );
			else {
				std::multimap< std::string, float >::iterator foundIt = data.lower_bound( it->first );
				foundIt--;
				printOutput( it, foundIt );
			}
		}
	}
}

void	btc( const char *filename ) {
	std::multimap< std::string, float > data;
	std::multimap< std::string, float > file;

	try {
		data = readFile( "data.csv" );
		file = readFile( filename );
		processFile( data, file );
	}
	catch ( std::runtime_error& e ) {
		std::cout << e.what() << std::endl;
	}
	catch ( std::bad_alloc& e ) {
		std::cout << "Error: not enough memory." << std::endl;
	}
	return ;
}
