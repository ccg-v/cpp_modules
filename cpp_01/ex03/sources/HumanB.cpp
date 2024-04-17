/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:37:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/17 14:44:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

//	Constructor implementation
HumanB::HumanB(std::string const &attackerName) 
		: _attackerName(attackerName), _currentWeapon(NULL) {}

//	Destructor implementation
HumanB::~HumanB() {}

//	Method
void	HumanB::attack ( void ) {
	if (!_currentWeapon)
		std::cout << _attackerName 
				  << " is unarmed!" 
				  << std::endl;
	else
		std::cout << _attackerName 
				  << " attacks with his " 
				  << _currentWeapon->getType() 
				  <<std::endl;
}

void	HumanB::setWeapon(Weapon &weapon) {
	_currentWeapon = &weapon;
}




