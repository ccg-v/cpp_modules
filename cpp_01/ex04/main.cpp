/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 20:58:32 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/11 19:35:21 by ccarrace         ###   ########.fr       */
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

	std::string	fileName = argv[1];
	std::string str1 = argv[2];
	std::string	str2 = argv[3];

	//	Declare an input file stream object for reading and try to open it
	std::ifstream ifs(fileName.c_str());	// (1)
	if (!ifs.is_open()) {			// (2)
		std::cout << "Error opening input file" << std::endl;
		return -1;
	}

	//	Build the name of the new file (extension must be replaced)
	std::string newFileName;

	std::size_t found = fileName.find(".");
	if (found == std::string::npos)
		newFileName = (fileName + ".replace");
	else
		newFileName = fileName.substr(0, found) + ".replace";

	// Declare an output file stream object for writing and try to open it
	std::ofstream ofs(newFileName.c_str());
	if (!ofs.is_open()) {		// (2)
		std::cout << "Error opening output file" << std::endl;
		return 1;
	}

	//	Copy the content of inputFile in outputFile, replacing str1 occurences
	//	with str2. Only integral occurrences are replaced, those that are part 
	//	of a longer word are ignored.
    std::string line;
    while (std::getline(ifs, line)) {
        std::string::size_type pos = 0;
        while ((pos = line.find(str1, pos)) != std::string::npos) {
			// Check if character next to occurrence found is a newline, a blank space 
			// or a punctuation sign
			if (pos + str1.length() == line.length() 
					|| (line[pos + str1.length()] == ' ' 
					|| std::ispunct(line[pos + str1.length()]))) {
                line = line.substr(0, pos) + str2 + line.substr(pos + str1.length());
                pos += str2.length(); // Increment by the length of the replacement string
            } else {
                pos += str1.length(); // Move past the found occurrence
            }
        }
        ofs << line << std::endl;
    }
	
	ifs.close();
	ofs.close();
	return 0;
}

/*
 *	(1)	std::ifstream 
 *		It's a special class to perform input/output operations on the associated files.
 *		It doesn't directly create a new file. Instead, it prepares a i/o stream object
 *		that will be associated with a existing or new file. 
 *		
 *	(2)	ifstream::open
 *			void open (const char *filename, ios_base::openmode mode = ios_base::in)
 *		Opens 'filename', associating it with the stream object. 
 *		Argument 'mode' specifies the opening mode ('in'/'out' for input/output operations)
 *
 *		Ex:	std::ifstream inputFile();
 *			inputFile.open(fileName, std::ifstream::in);
 *			if(inputFile.isOpen()) {
 *				(...) }
 *
 *		Notice that when a stream object is created with a file as argument, the file is
 *		automatically opened (if it exists) or created (if it doesn't). 
 *		Obviously, in this case calling 'open' function is redundant and will fail.
 *		
 *			std::ifstream inputFile(fileName);
 *			if(inputFile.isOpen()) {
 *				(...) }
 *
 *	(3)	std::string::size_type 
 *		Is a type specifically defined by the 'std::string' class and is tailored to 
 *		represent sizes or positions within strings. On most platforms and with most 
 *		compilers 'size_t' and 'std::string::size_type' are likely to be the same. 
 *		However, using 'std::string::size_type' provides a clear indication that the 
 *		variable is intended for use with std::string objects.
 */