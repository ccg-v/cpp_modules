/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 20:28:46 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/01 02:21:05 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// int	main( void ) {

// 	Fixed a;
// 	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

// 	std::cout << a << std::endl;
// 	std::cout << ++a << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << a++ << std::endl;
// 	std::cout << a << std::endl;
// 	std::cout << b << std::endl;
// 	std::cout << Fixed::max( a, b ) << std::endl;

// 	return 0;
// }

int main() {
    Fixed a(5.23f);
    Fixed b(3.45f);
    Fixed c(a);

    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "c: " << c << std::endl
			  << std::endl;
			  
	std::cout << "a > b : " << (a > b ? "true" : "false") << std::endl;
    std::cout << "a < b : " << (a < b ? "true" : "false") << std::endl;
    std::cout << "a >= c: " << (a >= c ? "true" : "false") << std::endl;
    std::cout << "a <= c: " << (a <= c ? "true" : "false") << std::endl;
    std::cout << "a == c: " << (a == c ? "true" : "false") << std::endl;
    std::cout << "a != b: " << (a != b ? "true" : "false") << std::endl
			  << std::endl;
			  
	std::cout << "a + b = " << (a + b) << std::endl;
	std::cout << "a - b = " << (a - b) << std::endl;
	std::cout << "a * b = " << (a * b) << std::endl;
	std::cout << "a / b = " << (a / b) << std::endl;
    return 0;
}