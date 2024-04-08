/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:48:56 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/08 23:54:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

//	Constructor implementation
Weapon::Weapon(std::string const &newType) : type(newType) {}

std::string const &Weapon::getType() const {
	return type;
}

void Weapon::setType(std::string const &newType) {
	type = newType;
}