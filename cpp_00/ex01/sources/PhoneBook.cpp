/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:50:48 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/27 21:27:20 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

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