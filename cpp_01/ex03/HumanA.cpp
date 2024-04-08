/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 22:37:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/08 23:46:15 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

//	Constructor implementation
HumanA::HumanA(const std::string &attackerName, Weapon &currentWeapon) {
	attackerName = attackerName;
	currentWeapon = currentWeapon;
}

//	Destructor implementation
HumanA::~HumanA() {}
