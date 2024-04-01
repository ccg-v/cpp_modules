/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:08:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/01 22:43:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype> 	// for toupper(), isdigit() in PhoneBook.cpp
#include <string>
#include <cstdlib>
#include "Contact.hpp"

class PhoneBook {

private:
	// Array to hold the contacts
	static const int MAX_CONTACTS = 8;
	int	currentIndex;
	int	replaceIndex;

public:
    // Constructor
	Contact	contacts[MAX_CONTACTS];
    PhoneBook() : currentIndex(0), replaceIndex(0) {} // Initialize currentIndex to 0

    void addContact();
    void searchContact();

};

#endif