/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 21:08:57 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/22 20:21:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iomanip> 	// for std::setw

class Contact {

public:
	// Constructor declaration
	/*Contact(const std::string &firstName, \
			const std::string &lastName, \
			const std::string &nickname, \
			const std::string &phoneNumber, \
			const std::string &darkestSecret);*/
	
	// getters declaration
	std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string	getPhoneNumber() const;
    std::string getDarkestSecret() const;
    
	// setters declaration
	void setFirstName(const std::string &firstName);
	void setLastName(const std::string &lastName);
	void setNickname(const std::string &nickname);
	void setPhoneNumber(const std::string &phoneNumber);
	void setDarkestSecret(const std::string &darkestSecret);

private:
	std::string	firstName;
	std::string	lastName;
	std::string	nickname;
	std::string	phoneNumber;
	std::string	darkestSecret;
	
};

#endif