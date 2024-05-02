/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:28:46 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/02 23:40:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main( void ) {

	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	return 0;
}

// /*	My own tests	*/
// int main() {
	
//     Fixed a(5.23f);
//     Fixed b(3.45f);
//     Fixed c(a);
// 	int d(1);
// 	Fixed e(1);

// 	std::cout << "--- Values -------------------------------------------- " << std::endl;
//     std::cout << "a: " << a << std::endl;
//     std::cout << "b: " << b << std::endl;
//     std::cout << "c: " << c << std::endl;
// 	std::cout << "d: " << d << std::endl;
// 	std::cout << "e: " << e << std::endl
//  			  << std::endl;

// 	std::cout << "--- Comparison operators ------------------------------ " << std::endl;		  
// 	std::cout << "a > b : " << (a > b ? "true" : "false") << std::endl;
//     std::cout << "a < b : " << (a < b ? "true" : "false") << std::endl;
//     std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
//     std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
//     std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
//     std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl
// 			  << std::endl;

// 	std::cout << "--- Arithmetic operators ------------------------------ " << std::endl;			  
// 	std::cout << "a + b = " << (a + b) << std::endl;
// 	std::cout << "a - b = " << (a - b) << std::endl;
// 	std::cout << "a * b = " << (a * b) << std::endl;
// 	std::cout << "a / b = " << (a / b) << std::endl
// 			  << std::endl;

// 	std::cout << "--- Increment/decrement operators --------------------- " << std::endl;
// 	std::cout << "Integer d pre incremented (++d) in 1          : " << ++d << std::endl;
// 	std::cout << "Fixed-point e pre incremented (++e) in 1      : " << ++e << std::endl
// 			  << std::endl;	
// 	std::cout << "Integer d post decremented (d++) in 1         : " << d-- << std::endl;
// 	std::cout << "Integer d after post decrement (d++) in 1     : " << d << std::endl;
// 	std::cout << "Fixed-point e post decremented (e++) in 1     :" << e-- << std::endl;
// 	std::cout << "Fixed-point e after post decrement (e++) in 1 : " << e << std::endl
// 			  << std::endl;	

// 	std::cout << "--- Min/max member functions -------------------------- " << std::endl; 
// 	Fixed minValue = Fixed::min( a, b );
// 	Fixed maxValue = Fixed::max( a, b );
// 	std::cout << "Comparing a and b, min is " << minValue 
// 			  << " and max is " << maxValue << std::endl;

// 	std::cout << "Address of min value is   : " << &Fixed::min( a, b ) << std::endl;
// 	std::cout << "Reference of min value is : " << (void *)&Fixed::min( a, b ) << std::endl;
	
//     return 0;
// }