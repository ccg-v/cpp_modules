/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 22:50:48 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/19 00:18:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phonebook;

    char choice;
	std::string input;
	int	flag = 0;
	
    while(true) {
		if (flag == 0)
        	std::cout << std::endl << "Welcome to Phonebook!" << std::endl;
		flag = 1;
		std::cout << std::endl;
        std::cout << " > Press A to (A)dd a new contact" << std::endl;
        std::cout << " > Press S to (S)earch an existing contact" << std::endl;
        std::cout << " > Press E to (E)xit phonebook" << std::endl;

        std::cin >> input;
        if (input.length() != 1) {
            std::cout << std::endl << "Invalid choice. Please try again." << std::endl;
            continue; // Skip rest of the loop and start from the beginning
        }
        choice = std::toupper(input[0]); // Convert to lowercase for comparison

        switch (choice) {
            case 'A':
                phonebook.addContact();
                break;
            case 'S':
                phonebook.searchContact();
                break;
            case 'E':
                std::cout << std::endl << "Exiting Phonebook. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << std::endl << "Invalid choice. Please try again." << std::endl;
        }
    }
	
    return 0;
}

