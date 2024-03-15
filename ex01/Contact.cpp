/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 19:55:50 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/15 12:13:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void PhoneBook::addContact() {
    if (currentIndex >= MAX_CONTACTS) {
        std::cout << "Phonebook is full. Cannot add more contacts." << std::endl;
        return;
    }

    Contact newContact;
	std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

    std::cout << "Enter First Name: ";
    std::cin >> firstName;
    newContact.setFirstName(firstName);

    std::cout << "Enter Last Name: ";
    std::cin >> lastName;
    newContact.setLastName(lastName);

    std::cout << "Enter Nickname: ";
    std::cin >> nickname;
    newContact.setNickname(nickname);

    std::cout << "Enter Phone Number: ";
    std::cin >> phoneNumber;
    newContact.setPhoneNumber(phoneNumber);

    std::cout << "Enter Darkest Secret: ";
    std::cin >> darkestSecret;
    newContact.setDarkestSecret(darkestSecret);

	contacts[currentIndex++] = newContact;
    std::cout << "Contact added successfully!" << std::endl;
}

void PhoneBook::searchContact() {
    if (currentIndex == 0) {
        std::cout << "Phonebook is empty. No contacts to search." << std::endl;
        return;
    }

    // Display the saved contacts as a list
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

    // Prompt the user for the index of the contact to display
    int index;
    std::cout << "Enter the index of the contact to display (0-7): ";
    std::cin >> index;

    // Display full information of the selected contact
    if (index >= 0 && index < currentIndex) {
        std::cout << std::endl << "Contact number " << index << " information:" << std::endl;
        std::cout << "-----------------------------" << std::endl;
        std::cout << "First Name: " << contacts[index].getFirstName() << std::endl;
        std::cout << "Last Name: " << contacts[index].getLastName() << std::endl;
        std::cout << "Nickname: " << contacts[index].getNickname() << std::endl;
        std::cout << "Phone Number: " << contacts[index].getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << std::endl;
    } else {
        std::cout << "Invalid index. Please enter a valid index next time." << std::endl;
    }
}

// Truncate and format the string if it is longer than the column width
std::string PhoneBook::formatAndTruncate(const std::string& str) const {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}
