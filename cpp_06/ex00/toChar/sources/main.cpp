/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:02:29 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/17 00:42:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
        return 1;
    }
	// try {
    // 	ScalarConverter::toChar(argv[1]);
	// } catch (const ScalarConverter::NonDisplayableException & e) {
	// 	std::cout << "char:\t" << e.what() << std::endl;
	// } catch (const ScalarConverter::ImpossibleConversionException & e) {
	// 	std::cout << "char:\t" << e.what() << std::endl;
	// } 
	ScalarConverter::convertToChar(argv[1]);
	ScalarConverter::convertToInt(argv[1]);
	ScalarConverter::convertToFloat(argv[1]);
	
    return 0;
}
