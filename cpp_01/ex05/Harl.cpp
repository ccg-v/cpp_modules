/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/14 22:50:07 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/15 00:28:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void ) {
    std::cout << "I love having extra bacon "
              << "for my 7XL-double-cheese-triple-pickle-special- ketchup burger. "
              << "I really do!" 
			  << std::endl;
}

void	Harl::info( void ) {
	std::cout << "I cannot believe adding extra bacon costs more money. "
			  << "You didn't put enough bacon in my burger! "
			  << "If you did, I wouldn't be asking for more!" 
			  << std::endl;
}

void	Harl::warning( void ) {
    std::cout << "I think I deserve to have some extra bacon for free. "
              << "I've been coming for years whereas "
              << "you started working here since last month."
			  << std::endl;
}

void	Harl::error( void ) {
	std::cout << "This is unacceptable! I want to speak to the manager now." 
			  << std::endl;
}

void	complain( std::string level) {
	
}