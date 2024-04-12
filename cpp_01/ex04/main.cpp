/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:58:32 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/12 13:42:07 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	main(int argc, char **argv) {
	
	if (argc != 4) {
		std::cout	<< "Wrong arguments!" << std::endl 
					<< "Usage: "
					<< argv[0] 
					<< " <filename> <string to replace> <new string>" 
					<< std::endl;
		return 1;
	}

	std::ifstream inputFile;
	inputFile.open (argv[1], std::ifstream::in);
	if (!inputFile.is_open()) {
		std::cout << "Error opening file" << std::endl;
		return 1;
	}

	std::string	fileName = argv[1];
	std::string str1 = argv[2];
	std::string	str2 = argv[3];

	std::ofstream outputFile;
	std::size_t found = fileName.find(".");
	if (found == std::string::npos)
		std::string outputFileName = (fileName + ".replace");
	else
		std::string outputFileName = fileName.substr(0, found) + ".replace";
	


	


	// while (!inputFile.eof()) {
	// 	std::cout << getline()

	// }
	
	return 0;
}