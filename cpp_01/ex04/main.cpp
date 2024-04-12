/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:58:32 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/13 00:50:52 by ccarrace         ###   ########.fr       */
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
		return -1;
	}

	std::ifstream inputFile(argv[1]);
	// inputFile.open(argv[1], std::ifstream::in);
	if (!inputFile.is_open()) {
		std::cout << "Error opening input file" << std::endl;
		return -1;
	}

	std::string	fileName = argv[1];
	std::string str1 = argv[2];
	std::string	str2 = argv[3];

	//	Build the name of the new file (extension must be replaced)
	std::string newFileName;

	std::size_t found = fileName.find(".");
	if (found == std::string::npos)
		newFileName = (fileName + ".replace");
	else
		newFileName = fileName.substr(0, found) + ".replace";

	//	Declares an output file stream object named outputFile 
	//	and attempts to open a file named newFileName for writing
	// 	When you create an instance of std::ofstream, like in the line 
	//			std::ofstream outputFile(newFileName);
	//	it doesn't directly create a new file. Instead, it prepares an 
	//	output stream object (outputFile in this case) that is associated 
	//	with a file, which in this case is specified by the newFileName.
	//	The file is created when you actually write data to the stream 
	//	(using outputFile << data;), or in the case of std::ofstream, if 
	//	the file doesn't exist, it will be created when you try to open 
	//	it for writing.
	//	So, in short, that line prepares an output stream object associated 
	//	with a file (newFileName), but it doesn't actually create the file 
	//	until you perform some output operation on the stream or explicitly 
	//	call outputFile.open(newFileName);.
	//
	//	When you create an 'std:ofstream' object with a file as an argument
	//	it automatically opens the file associated with that filename

	std::ofstream outputFile(newFileName);
	// outputFile.open(newFileName);
	if (!outputFile.is_open()) {
		std::cout << "Error opening output file" << std::endl;
		return 1;
	}

	//	Copies the content of inputFile in outputFile, replacing str1 occurences
	//	with str2
	//	std::string::size_type is specifically defined by the std::string class 
	//	and is tailored to represent sizes or positions within strings. On most
	//	platforms ando with most compilers 'size_t' and 'std::string::size_type'
	//	are likely to be the same. using std::string::size_type provides a clear
	//	indication that the variable is intended for use with std::string objects.
	std::string	line;
	while (std::getline(inputFile, line)) {
		std::string::size_type	pos = 0;
		while ((pos = line.find(str1, pos)) != std::string::npos) {
			line = line.substr(0, pos) + str2 + line.substr(pos + str1.length());
			pos += str2.length();
		}
		outputFile << line << std::endl;
	}
	
	inputFile.close();
	outputFile.close();
	return 0;
}