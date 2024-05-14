/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/14 23:53:21 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
DiamondTrap::DiamondTrap( void ) : ClapTrap("Default"), ScavTrap(), FragTrap() {
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

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name), ScavTrap(), FragTrap() {
	// ClapTrap::_name = name + "_clap_name";
	_name = name;
	_energyPoints = ScavTrap::_energyPoints;
	_hitPoints = FragTrap::_hitPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "\t[DiamondTrap constructor overload called] A DiamondTrap unit called '" 
			  << this->_name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void	DiamondTrap::attack( const std::string &target ) {
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI(void) {
	std::cout <<  getName() << " says: I am " << _name 
			  << "and my ClapTrap name is " << ClapTrap::_name
			  << std::endl;
}