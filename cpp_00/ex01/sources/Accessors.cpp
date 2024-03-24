/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Accessors.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 20:31:22 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/24 21:28:05 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/* getters implementation */

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

/* setters implementation */

void Contact::setFirstName(const std::string &firstName) {
    this->firstName = firstName;
}

void Contact::setLastName(const std::string &lastName) {
    this->lastName = lastName;
}

void Contact::setNickname(const std::string &nickname) {
    this->nickname = nickname;
}

void Contact::setPhoneNumber(const std::string &phoneNumber) {
    this->phoneNumber = phoneNumber;
}
void Contact::setDarkestSecret(const std::string &darkestSecret) {
    this->darkestSecret = darkestSecret;
}