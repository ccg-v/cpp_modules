/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 19:55:56 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/28 19:58:39 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>	// For std::toupper
 
int main(int argc, char **argv) {
    int i = 1;

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        while (i < argc) {
            int j = 0;
            while (argv[i][j] != '\0') {
                char c = argv[i][j];
				c = std::toupper(c);
                std::cout << c;
                j++;
            }
            i++;
        }
		std::cout << std::endl;
    }
    return 0;
}
