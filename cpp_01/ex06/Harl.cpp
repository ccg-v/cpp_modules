/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:50:07 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/16 21:37:56 by ccarrace         ###   ########.fr       */
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
 *	-	In a 'for' loop find the place (index) of the level in the array of levels 
 *	-	In a 'switch' loop find and run the function associated to the level's index
 */

void	Harl::complain( std::string level) {
	
	void	(Harl::*complaintFunctions[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	const	std::string complaintLevels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};
	
	int	levelIndex = -1;
	for (int i = 0; i < 4; i++) {
		if (level == complaintLevels[i]) {
			levelIndex = i;
		}
	}

	switch(levelIndex) {
		case 0 :
			(this->*complaintFunctions[0])();	
		case 1 :
			(this->*complaintFunctions[1])();
		case 2 :
			(this->*complaintFunctions[2])();	
		case 3 :
			(this->*complaintFunctions[3])();
			break;
		default :
			std::cout << "Invalid level (must be DEBUG/INFO/WARNING/ERROR)" << std::endl;
	}

};