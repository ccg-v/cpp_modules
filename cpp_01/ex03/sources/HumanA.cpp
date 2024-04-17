/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:37:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

//	Constructor
HumanA::HumanA(std::string const &attackerName, Weapon &weapon) 
		: _attackerName(attackerName), _currentWeapon(weapon) {}

//	Destructor
HumanA::~HumanA() {}

//	Method
void	HumanA::attack() {
	std::cout << _attackerName 
			  << " attacks with his " 
			  << _currentWeapon.getType() 
			  << std::endl;
}
