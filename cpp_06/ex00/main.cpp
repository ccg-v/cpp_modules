/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:02:29 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/08 13:02:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

// int main(int argc, char **argv)
// {
// 	if (argc == 2)
// 	{
// 		ScalarConverter	converter;
// 		ScalarConverter::eType type;
		
// 		type = converter.detectType(argv[1]);
// 		converter.displayConversions(argv[1]);
// 	}
// 	else
// 		std::cout << "Invalid arguments (usage: './convert.out parameter')"
// 				  << std::endl;
// 	return 0;
// }

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out parameter')"
				  << std::endl;
        return 1;
    }
    ScalarConverter::displayConversions(argv[1]);

    return 0;
}
