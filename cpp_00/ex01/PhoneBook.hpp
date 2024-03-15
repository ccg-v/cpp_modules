/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:08:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/14 21:19:28 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype> 	// for std::toupper in PhoneBook.cpp
#include <string>
#include "Contact.hpp"

class PhoneBook {

private:
	// Array to hold the contacts
	static const int MAX_CONTACTS = 8;
	int	currentIndex;

public:
    // Constructor
	Contact	contacts[MAX_CONTACTS];
    PhoneBook() : currentIndex(0) {} // Initialize currentIndex to 0

    void addContact();
    void searchContact();
	std::string formatAndTruncate(const std::string& str) const;

};

#endif