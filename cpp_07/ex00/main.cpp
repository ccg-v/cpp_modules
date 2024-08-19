/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:57:47 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/20 00:53:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"
#include <iostream>

template <typename T>
void test(T value1, T value2) {

	std::cout << "Before swapping:\tvalue1 = " << value1
			  << "\tvalue2 = " << value2 << std::endl;	
	Swap(&value1, &value2);
	std::cout << "After swapping :\tvalue1 = " << value1
			  << "\tvalue2 = " << value2 << std::endl;

	std::cout << "Min value is " << Min(value1, value2) << std::endl; 
	std::cout << "Max value is " << Max(value1, value2) << std::endl;
	std::cout << std::endl;	
}

int	main(void)
{
	std::cout << "/* --- Test with integer values ------------------------ */\n"
			  << std::endl;

	int	int1 = 1;
	int int2 = 200;

	test(int1, int2);

	std::cout << "/* --- Test with float values -------------------------- */\n"
			  << std::endl;

	float float1 = 42.0f;
	float float2 = 365.99f;

	test(float1, float2);

	std::cout << "/* --- Test with char values --------------------------- */\n"
			  << std::endl;

	char char1 = 'Z';
	char char2 = 'a';

	test(char1, char2);

	std::cout << "/* --- Test with strings ------------------------------- */\n"
			  << std::endl;
			  
	std::string str1 = "apple";
	std::string str2 = "banana";

	test(str1, str2);

	return 0;
}