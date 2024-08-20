/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:57:47 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/20 02:05:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>
#include <limits>	// std::numeric_limits


template <typename T>
void test(T value1, T value2) {

	std::cout << "Before swapping:\tvalue1 = " << value1
			  << "\tvalue2 = " << value2 << std::endl;	
	swap(value1, value2);
	std::cout << "After swapping :\tvalue1 = " << value1
			  << "\tvalue2 = " << value2 << std::endl;

	std::cout << "Min value is " << min(value1, value2) << std::endl; 
	std::cout << "Max value is " << max(value1, value2) << std::endl;
	std::cout << std::endl;
}

int	main(void)
{
	std::cout << "/* --- Test with integer values ------------------------ */\n"
			  << std::endl;

	test(1, 200);
	test(std::numeric_limits<int>::max(), std::numeric_limits<int>::min());

	std::cout << "/* --- Test with float values -------------------------- */\n"
			  << std::endl;

	test(42.0f, 365.99f);
	test(std::numeric_limits<float>::max(), std::numeric_limits<float>::min());


	std::cout << "/* --- Test with char values --------------------------- */\n"
			  << std::endl;

	test('Z', 'a');

	std::cout << "/* --- Test with strings ------------------------------- */\n"
			  << std::endl;

	test("prime", "prize");

	return 0;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;

// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
	
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }