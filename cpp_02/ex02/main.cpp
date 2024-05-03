/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:28:46 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/03 22:46:18 by ccarrace         ###   ########.fr       */
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

/*	My own tests	*/
// int main() {
	
//     Fixed a(5.23f);
//     Fixed b(3.45f);
//     Fixed c(a);
// 	int d(1);
// 	Fixed e(1);

// 	std::cout << "--- Values -------------------------------------------- " << std::endl;
//     std::cout << "Fixed   a: " << a << std::endl;
//     std::cout << "Fixed   b: " << b << std::endl;
//     std::cout << "Fixed   c: " << c << std::endl;
// 	std::cout << "Integer d: " << d << std::endl;
// 	std::cout << "Fixed   e: " << e << std::endl
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
// 	std::cout << "Integer d post decremented (d--) in 1         : " << d-- << std::endl;
// 	std::cout << "Integer d after post decrement (d--) in 1     : " << d << std::endl;
// 	std::cout << "Fixed-point e post decremented (e--) in 1     : " << e-- << std::endl;
// 	std::cout << "Fixed-point e after post decrement (e--) in 1 : " << e << std::endl
// 			  << std::endl;	

// 	std::cout << "--- Min/max member functions -------------------------- " << std::endl; 
// 	Fixed minValue = Fixed::min( a, b );
// 	Fixed maxValue = Fixed::max( a, b );
// 	std::cout << "Comparing a and b, min is " << minValue 
// 			  << " and max is " << maxValue << std::endl;

// 	// To test whether the const or the non-const min/max function is called, 
// 	//		1. Set 'a' and 'b' to const in main()
// 	//		2. Uncomment the following line in const min() and/or max() implementation:
// 	// 				std::cout << "\n(Const function called)" << std::endl;
// 	//		3. Uncomment the following line in non const min() and/or max() implementation:
// 	// 				std::cout << "\n(Non const function called)" << std::endl;
	
//     return 0;
// }