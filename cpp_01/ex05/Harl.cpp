/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:50:07 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/16 00:03:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ) {
    std::cout << "[ DEBUG ]" << std::endl
			  << "I love having extra bacon "
			  "for my 7XL-double-cheese-triple-pickle-special- ketchup burger. "
			  "I really do!" 
			  << std::endl;
}

void	Harl::info( void ) {
	std::cout << "[ INFO ]" << std::endl
			  << "I cannot believe adding extra bacon costs more money. "
			  "You didn't put enough bacon in my burger! "
			  "If you did, I wouldn't be asking for more!" 
			  << std::endl;
}

void	Harl::warning( void ) {
    std::cout << "[ WARNING ]" << std::endl
			  << "I think I deserve to have some extra bacon for free. "
			  "I've been coming for years whereas "
			  "you started working here since last month."
			  << std::endl;
}

void	Harl::error( void ) {
	std::cout << "[ ERROR ]" << std::endl
			  << "This is unacceptable! I want to speak to the manager now." 
			  << std::endl;
}

/*
 *	Complain()
 *	-	Create an array containing pointers to level functions
 *	-	Create an array containing the names of the levels
 *	-	Start a loop to look in the array of names which one matches
 *		the string received matches, and call the corresponding function
 *		in the array of functions using the index.
 */

void	Harl::complain( std::string level) {
	void	(Harl::*complaintFunctions[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	const	std::string complaintLevels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (int i = 0; i < 4; i++) {
		if (level == complaintLevels[i]) {
			(this->*complaintFunctions[i])();
			return ;
		}
	}
};