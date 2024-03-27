/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:50:48 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/27 20:33:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

// int main() {
//     PhoneBook phonebook;

//     char choice;
// 	std::string input;
// 	int	flag = 0;
	
//     while(true) {
// 		if (flag == 0)
//         	std::cout << std::endl << "Welcome to Phonebook!" << std::endl;
// 		flag = 1;
// 		std::cout << std::endl;
//         std::cout << " > Press A to (A)dd a new contact" << std::endl;
//         std::cout << " > Press S to (S)earch an existing contact" << std::endl;
//         std::cout << " > Press E to (E)xit phonebook" << std::endl;

//         std::cin >> input;
		
//         if (input.length() != 1) {
//             std::cout << std::endl << "Invalid choice. Please try again." << std::endl;
//             continue; // Skip rest of the loop and start from the beginning
//         }
//         choice = std::toupper(input[0]); // Convert to lowercase for comparison

//         switch (choice) {
//             case 'A':
//                 phonebook.addContact();
//                 break;
//             case 'S':
//                 phonebook.searchContact();
//                 break;
//             case 'E':
//                 std::cout << std::endl << "Exiting Phonebook. Goodbye!" << std::endl;
//                 return 0;
//             default:
//                 std::cout << std::endl << "Invalid choice. Please try again." << std::endl;
//         }
//     }
	
//     return 0;
// }

// int main() {
//     PhoneBook phonebook;

// 	std::string input;
	
// 	std::cout << std::endl << "Welcome to Phonebook!" << std::endl;
//     while(true) {
// 		std::cout << std::endl;
//         std::cout << " > Press A to (A)dd a new contact" << std::endl;
//         std::cout << " > Press S to (S)earch an existing contact" << std::endl;
//         std::cout << " > Press E to (E)xit phonebook" << std::endl;

//         // if (!(std::cin >> input)) {
// 		std::getline(std::cin, input);
//         if (input.empty()) {
// 			std::cout << "WARNING!!! EMPTY INPUT" << std::endl;
//             if (std::cin.eof()) {
//                 std::cout << std::endl << "EOF received. Exiting Phonebook. Goodbye!" << std::endl;
//                 break;
//             }
//         }

// 		// Convert input to uppercase for case-insensitive comparison
// 		for (size_t i = 0; i < input.length(); ++i) {
// 			input[i] = std::toupper(input[i]);
//     	}
	
// 		if(input.length() == 1) {
// 			switch (input[0]) {
// 				case 'A':
// 					phonebook.addContact();
// 					break;
// 				case 'S':
// 					phonebook.searchContact();
// 					break;
// 				case 'E':
//                 	std::cout << std::endl << "Exiting Phonebook. Goodbye!" << std::endl;
//                 	return 0;
// 				default:
// 					std::cout << "Invalid command." << std::endl;
// 					break;
// 				}
// 		} else {
// 			if (input == "ADD") {
// 				phonebook.addContact();
// 			} else if (input == "SEARCH") {
// 				phonebook.searchContact();
// 			} else if (input == "EXIT") {
//                 std::cout << std::endl << "Exiting Phonebook. Goodbye!" << std::endl;
// 				return 0;
// 			} else {
// 				std::cout << "Invalid command." << std::endl;
// 			}
// 		}
// 	}
	
//     return 0;
// }

int main() {
    PhoneBook phonebook;

	std::string input;
	
	std::cout << std::endl << "Welcome to Phonebook!" << std::endl;
    while(true) {
		std::cout << std::endl;
        std::cout << " > Press A to (A)dd a new contact" << std::endl;
        std::cout << " > Press S to (S)earch an existing contact" << std::endl;
        std::cout << " > Press E to (E)xit phonebook" << std::endl;

		std::getline(std::cin, input);
        if (input.empty()) {
            if (std::cin.eof()) {
                std::cout << std::endl << "EOF received. Exiting Phonebook. Goodbye!" << std::endl;
                break;
            }
        }

		// Convert input to uppercase for case-insensitive comparison
		for (size_t i = 0; i < input.length(); ++i) {
			input[i] = std::toupper(input[i]);
    	}
	
		if (input == "ADD" || input == "A")
			phonebook.addContact();
		else if (input == "SEARCH" || input == "S")
			phonebook.searchContact();
		else if (input == "EXIT" || input == "E") {
            std::cout << std::endl << "Exiting Phonebook. Goodbye!" << std::endl;
            return 0;
		} else {
			std::cout << "Invalid command. Please try again." << std::endl;
			continue;
		}
	}
    return 0;
}