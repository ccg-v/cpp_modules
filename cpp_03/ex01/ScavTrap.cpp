/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/09 00:28:03 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
ScavTrap::ScavTrap( void ) : ClapTrap(), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
	std::cout << "Default constructor has been called." << std::endl;
};

//	Default destructor
ScavTrap::~ScavTrap( void ) {
	std::cout << "Default destructor has been called." << std::endl;
}

/* --- Constructor overload ------------------------------------------------- */

ScavTrap::ScavTrap( std::string name ) :