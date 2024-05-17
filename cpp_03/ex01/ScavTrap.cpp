/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/17 20:00:39 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
ScavTrap::ScavTrap( void ) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "[ScavTrap constructor called] Default ScavTrap constructor has been called." 
			  << std::endl;
}

//	Copy constructor
ScavTrap::ScavTrap( const ScavTrap &source ) : ClapTrap(source) {
	*this = source;
	std::cout << "\tA new ScavTrap called '" << getName() << "' has been created" 
			  << std::endl;
}

//	Default destructor
ScavTrap::~ScavTrap( void ) {
	std::cout << "\t[ScavTrap destructor called] The ScavTrap unit called '" 
			  << getName() << "' has been destroyed." 
			  << std::endl;
}

//	Copy assignment operator
ScavTrap &ScavTrap::operator=( const ScavTrap &source ) {
	if (this == &source)
		return *this;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return *this;
}

/* --- Constructor overload ------------------------------------------------- */

ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << "\t[ScavTrap constructor overload called] A ScavTrap unit called '" 
			  << _name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void 	ScavTrap::attack( const std::string& target ) {
	ClapTrap::attack( target );
}

void	ScavTrap::guardGate(void) {
		std::cout << getName() << " is now in Gate keeper mode." << std::endl;
}