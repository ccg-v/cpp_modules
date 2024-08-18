/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:02:29 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 20:26:09 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
        return 1;
    }
	
	ScalarConverter::convert(argv[1]);

    return 0;
}

/*
 *	./convert ~

 *  '~' is Shell expansion to the current user home directory. If we print
 * 	the literal in 'isChar()':
 * 		std::cout << "Literal: [" << literal << "]" << std::endl;
 * 	the user home directory is printed
 * 		literal: [/home/ccarrace]
 */

/* 
 * 	./convert &
 * 
 * 	In Shell '&' is used to run processes in the background. The command 
 * 	preceding the & will be ran in the background. If we print the literal
 * 	in 'isChar()':
 * 		[1] 43662
 * 	the output indicates that the command was launched in the background
 * 	with the job number [1] and process ID 43662. The shell then displays
 * 	the prompt again because it is ready for more commands.
 */