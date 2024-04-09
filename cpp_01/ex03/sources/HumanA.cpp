/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:37:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/10 00:35:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

//	Constructor
HumanA::HumanA(std::string const &attackerName, Weapon &weapon) 
		: attackerName(attackerName), weapon(weapon) {}
// 	attackerName = attackerName;
// 	weapon = weapon;
// 	std::cout << attackerName << " enters the ring" << std::endl;
// }

//	Destructor
HumanA::~HumanA() {}

//	Method
void	HumanA::attack() {
	std::cout << attackerName << " attacks with his " << weapon.getType() << std::endl;
}
