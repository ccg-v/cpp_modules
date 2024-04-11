/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:58:32 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/12 00:28:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	
	if (argc != 4) {
		std::cout	<< "Wrong arguments!" << std::endl 
					<< "Usage: <executable> <filename> <string to replace> <new string>" 
					<< std::endl;
		return 1;
	}

	std::ifstream ifs;
	ifs.open (argv[1], std::ifstream::in);
	if (!ifs.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}
	
	
	return 0;
}