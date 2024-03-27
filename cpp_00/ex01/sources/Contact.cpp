/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 20:02:02 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/27 21:04:22 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

static bool hasOnlyBlankSpaces(const std::string &str);
static bool areAllDigits(const std::string &str);
static std::string trimBlankSpaces(const std::string &str);
static void getContactDetails(Contact &newContact);
static std::string formatAndTruncate(const std::string &str);

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
    std::cout << "Contact added successfully!" << std::endl;
}

void getContactDetails(Contact &newContact) {
    std::string firstName, lastName, nickname, darkestSecret;
    std::string phoneNumber;

    std::cout << "Enter First Name: ";
    // std::cin.ignore(); // Clear input buffer
    std::getline(std::cin, firstName);
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

/*
 * hasOnlyBlankSpaces()
 *
 * Returns true if the input has only blank spaces.
 * 
 * After writing my function, I discovered there is an specific method of the
 * 'std::string' class in C++ called 'find_first_not_of()' that is used to find
 * the position of the first character in the string that is not equal to a 
 * specified character or a set of characters:
 * 
 * 		bool hasOnlyBlankSpaces(const std::string &str) {
 * 			return str.find_first_not_of(' ') == std::string::npos;
 *		}
 */
bool hasOnlyBlankSpaces(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] != ' ')
			return false;
	}
	return true;
}

/* 
 * areAllDigits()
 * 
 * Checks if all characters in a string are digits.
 * 
 * A more concise solution using 'find_if_not()' function from <algorithm> library.
 * 
 * 		#include <algorithm>
 * 
 * 		bool areAllDigits(const std::string &str) {
 * 			return std::find_if_not(str.begin(), str.end(), ::isdigit) == str.end();
 * 		}
 * 
 * It takes a 'start iterator' and an 'end iterator' (the beginning and end of the
 * range), and a 'unary predicate function' that is used to evaluate whether an 
 * element meets a certain condition. In this context it is searching for the first
 * character in the string that is not a digit:
 * 		- If it does not find any character, the function returns an iterator pointing 
 * 			to the end of the string. 
 * 		- If it finds a non-digit character, it returns an iterator pointing to that
 * 			character.
 * The iterator returned by 'find_if_not()' is compared to the end of the string. If 
 * they are equal it means that all characters in the string are digits.
 */
bool areAllDigits(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

/*
 * trimBlankSpaces()
 *
 * Trims leading and trailing blank spaces in the fields values
 */
std::string trimBlankSpaces(const std::string &str) {
    int start = 0, end = str.length() - 1;

    while (start <= end && str[start] == ' ')
        start++;
    while (end >= start && str[end] == ' ')
        end--;
    return str.substr(start, end - start + 1);
}

/*
 * formatAndTruncate()
 *
 * Truncate and format the string if it is longer than the column width
 */ 
std::string formatAndTruncate(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}
