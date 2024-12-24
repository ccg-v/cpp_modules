/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:28:56 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/06 21:02:41 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cctype>
#include <iostream>

static int	argError( std::string msg ) {
	std::cout << "Error: " << msg << std::endl;
	return 1;
}

int	main( int argc, char *argv[] ) {
	
	if ( argc < 2 )
		return argError( "Not enough arguments." );
	else if ( argc > 2 )
		return argError( "Too many arguments." );
	std::string	input = argv[ 1 ];
	try {
		RPN( input );
	} catch ( std::runtime_error& e ) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
