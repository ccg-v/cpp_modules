/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:02:02 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/27 22:34:06 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Utils.hpp"

void PhoneBook::addContact() {

    Contact newContact;
    std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    if (currentIndex == MAX_CONTACTS) {
        // Overwrite the oldest contact based on currentIndex
        std::cout << "Phonebook is full. The oldest contact (index " \
			<< replaceIndex << ") will be replaced." << std::endl;
        getContactDetails(newContact);
        contacts[replaceIndex] = newContact;  // Overwrite the oldest contact
		replaceIndex = (replaceIndex + 1) % MAX_CONTACTS;
    } else {
        // Existing logic to store new contact in the next available slot
        getContactDetails(newContact);
        contacts[currentIndex++] = newContact;
    }
    std::cout << std::endl << "Contact added successfully!" << std::endl;
}

void getContactDetails(Contact &newContact) {
    std::string firstName, lastName, nickname, darkestSecret;
    std::string phoneNumber;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, firstName);
	            if (std::cin.eof()) {
                std::cout << std::endl << "EOF received. Exiting Phonebook. Goodbye!" << std::endl;
                exit(1);
            }
    while (firstName.empty() || hasOnlyBlankSpaces(firstName) == true) {
        std::cout << "First Name cannot be empty. Please enter again: ";
        std::getline(std::cin, firstName);
    }
    newContact.setFirstName(trimBlankSpaces(firstName));

    std::cout << "Enter Last Name: ";	
    std::getline(std::cin, lastName);
    while (lastName.empty() || hasOnlyBlankSpaces(lastName) == true) {
        std::cout << "Last Name cannot be empty. Please enter again: ";
        std::getline(std::cin, lastName);
    }
    newContact.setLastName(trimBlankSpaces(lastName));

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, nickname);
    while (nickname.empty() || hasOnlyBlankSpaces(nickname) == true) {
        std::cout << "Nickname cannot be empty. Please enter again: ";
        std::getline(std::cin, nickname);
    }
    newContact.setNickname(trimBlankSpaces(nickname));

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, phoneNumber);
    while (phoneNumber.empty() || hasOnlyBlankSpaces(phoneNumber) == true) {
        std::cout << "Phone Number cannot be empty. Please enter again: ";
        std::getline(std::cin, phoneNumber);
    }
	while (!areAllDigits(phoneNumber)) {
		std::cout << "Phone Number must contain only digits. Please enter again: ";
		std::getline(std::cin, phoneNumber);
	}
    newContact.setPhoneNumber(trimBlankSpaces(phoneNumber));

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, darkestSecret);
    while (darkestSecret.empty() || hasOnlyBlankSpaces(darkestSecret) == true) {
        std::cout << "Darkest Secret cannot be empty. Please enter again: ";
        std::getline(std::cin, darkestSecret);
    }
    newContact.setDarkestSecret(trimBlankSpaces(darkestSecret));
}

/*
 *	searchContact()
 *
 *	1. Warn if search is not possible because there no contacts were added yet
 *	2. If possible, display the list of contacts formatted as subject demands:
 * 		- a list header separated by pipes
 *		- each contact in a new line
 *		- the width of each columnn must be 10 characters, if the field value is
 *			longer it must be shown truncated and last character replaced by '.'
 *	3. Prompt the user for the index of the contact to display
 *		- check if the input is valid (from 0 to 7)
 *	4. Display the information of the selected contact
 */

void PhoneBook::searchContact() {
	
    if (currentIndex == 0) {
        std::cout << "Phonebook is empty. No contacts to search." << std::endl;
        return ;
    }

    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << "|" << std::endl;

    for (int i = 0; i < currentIndex; ++i) {
        std::cout << std::setw(10) << i << "|"
                  << std::setw(10) << formatAndTruncate(contacts[i].getFirstName()) << "|"
                  << std::setw(10) << formatAndTruncate(contacts[i].getLastName()) << "|"
                  << std::setw(10) << formatAndTruncate(contacts[i].getNickname()) << "|" << std::endl;
    }

	int index;
    bool validIndex = false;
    do {
        std::cout << "Enter the index of the contact to display: ";
		// std::cin >> index; // Getting index value here causes strange behavior

        if (!(std::cin >> index) || index < 0 || index >= currentIndex) {
            // Clear the error state and discard invalid input (see note below)
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid index. Please try again." << std::endl;
            validIndex = false;
        } else {
            validIndex = true;
        }
    } while (!validIndex);

    std::cout << std::endl << "Contact number " << index << " information:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
	std::cin.ignore(); // Consume leftover newline (see note below)

}
/* About std::cin.ignore() in line 148:
 *   -	When the user enters the index in 'searchContact' a newline character is left
 * 		in the input buffer after pressing Enter
 *   -	After displayin the contact's info the program returns to the main menu's
 * 		'std::getline(std::cin, input)
 *   -	'getline' immediately captures the newline, resulting in an empty input string
 *   -	The 'if (input.empty())' condition in the main menu evaluates to true, leading
 * 		to the prompt 'Invalid command. Please try again'.
 */
