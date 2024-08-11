/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:02:29 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/11 23:03:39 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
        return 1;
    }
	try {
    	ScalarConverter::toChar(argv[1]);
	}
	catch (const ScalarConverter::NonDisplayableException & e) {
		std::cout << "char:\t" << e.what() << std::endl;
	}
    return 0;
}
