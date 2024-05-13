/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/13 23:47:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
DiamondTrap::DiamondTrap( void ) : ClapTrap() {
	_name = "Default_DiamondTrap";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "[DiamondTrap constructor called] Default DiamondTrap constructor has been called." 
			  << std::endl;
}

//	Copy constructor
DiamondTrap::DiamondTrap( const DiamondTrap &source ) : ClapTrap(source), ScavTrap(source), FragTrap(source) {
	*this = source;
	std::cout << "\tA new DiamondTrap copy called '" << getName() << "' has been created" 
			  << std::endl;
}

//	Default destructor
DiamondTrap::~DiamondTrap( void ) {
	std::cout << "\t[DiamondTrap destructor called] The DiamondTrap unit called '" 
			  << getName() << "' has been destroyed." 
			  << std::endl;
}

//	Copy assignment operator
DiamondTrap &DiamondTrap::operator=( const DiamondTrap &source ) {
	if (this == &source)
		return *this;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._hitPoints;
	return *this;
}

/* --- Constructor overload ------------------------------------------------- */

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name) {
	ClapTrap::_name = name + "_clap_name";
	_name = name;
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "\t[DiamondTrap constructor overload called] A DiamondTrap unit called '" 
			  << this->_name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void	DiamondTrap::attack( const std::string &target ) {
	FragTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout <<  getName() << " says: Listen to me! I am " << _name 
			  << ", my ClapTrap name is " << ClapTrap::_name << " and I am invincible!!!!!" 
			  << std::endl;
}