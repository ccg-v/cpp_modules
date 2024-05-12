/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/12 19:58:55 by ccarrace         ###   ########.fr       */
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

//	To follow the subject and keep the ClapTrap attackDamage value constant, 
//	set 'attackDamage' to 20.
//	To simulate a battle, assign to 'attackDamage' the result returned by
//	'dice()' function, that is, a random integer from 0 to 6
void 	ScavTrap::attack( const std::string& target ) {

	if (getEnergyPoints() <= 0) {
		std::cout << getName() << " ran out of energy, he can't either attack or repair himself!"
				  << std::endl;
		guardGate();
		display_score(getName(), getHitPoints(), getEnergyPoints());
	} else {
	
		int	attackDamage = 20;	//	<- replace HERE!!!
		std::cout << "Turn for " << getName() <<", attackDamage is " << attackDamage
				  << std::endl;

		if(attackDamage == 6) {
			beRepaired(100);
			setAttackDamage(0);
		} else {
			setAttackDamage(attackDamage);
			setEnergyPoints(getEnergyPoints() - 1);
			std::cout << getName() << " attacks " << target << ", causing " 
					<< getAttackDamage() << " points of damage!"
					<< std::endl;
			display_score(getName(), getHitPoints(), getEnergyPoints());Gate	
		}
	}
}

void	ScavTrap::guardGate(void) {
		std::cout << getName() << " is now in Gate keeper mode." << std::endl;
}