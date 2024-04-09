/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 23:48:56 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/10 00:12:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"

/* --- Constructors and destructors ----------------------------------------- */

//	Default constructor
Weapon::Weapon(std::string const &newType) {
	type = newType;
}

//	Destructor
// Weapon::~Weapon() {}

/* --- Accessors ------------------------------------------------------------ */

//	Setter
void Weapon::setType(std::string const &newType) {
	this->type = newType;
}

//	Getter
std::string const &Weapon::getType() const {
	return this->type;
}