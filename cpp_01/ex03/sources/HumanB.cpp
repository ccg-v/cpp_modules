/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:37:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/09 23:50:05 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

//	Constructor implementation
HumanB::HumanB(std::string const &attackerName) 
		: attackerName(attackerName), currentWeapon(NULL) {}

//	Destructor implementation
HumanB::~HumanB() {}

//	Method
void	HumanB::attack ( void ) {
	if (!currentWeapon)
		std::cout << attackerName << " is unarmed!" << std::endl;
	else
		std::cout << attackerName << " attacks with his " << currentWeapon->getType() <<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	currentWeapon = &weapon;
}




