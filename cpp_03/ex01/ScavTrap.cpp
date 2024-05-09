/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/10 00:38:14 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
// ScavTrap::ScavTrap( void ) : ClapTrap() {
// 	_hitPoints = 100;
// 	_energyPoints = 50;
// 	_attackDamage = 20;
// 	std::cout << "Default ScavTrap constructor has been called." << std::endl;
// }
// ScavTrap::ScavTrap( void ) : ClapTrap() {
// 	setHitPoints(100);
// 	setEnergyPoints(50);
// 	setAttackDamage(20);
// 	std::cout << "\tDefault ScavTrap constructor has been called." << std::endl;
// }
ScavTrap::ScavTrap(void) : ClapTrap(), _hitPoints(100), _energyPoints(50), _attackDamage(20) {
  std::cout << "\tDefault ScavTrap constructor has been called." << std::endl;
}

//	Copy constructor
ScavTrap::ScavTrap( const ScavTrap &source ) : ClapTrap(source) {
	*this = source;
	std::cout << "\tA new ScavTrap called '" << getName() << "' has been created" 
			  << std::endl;
}

//	Default destructor
ScavTrap::~ScavTrap( void ) {
	std::cout << "\tThe ScavTrap unit called '" << getName() << "' has been destroyed." 
			  << std::endl;
}

//	Copy assignment operator
// ScavTrap &ScavTrap::operator=( const ScavTrap &source ) {
// 	if (this == &source)
// 		return *this;
// 	_name = source._name;
// 	_hitPoints = source._hitPoints;
// 	_energyPoints = source._energyPoints;
// 	_attackDamage = source._attackDamage;
// 	return *this;
// }
ScavTrap &ScavTrap::operator=( const ScavTrap &source ) {
	if (this == &source)
		return *this;
	setName(source.getName());
	setHitPoints(source.getHitPoints());
	setEnergyPoints(source.getEnergyPoints());
	setAttackDamage(source.getAttackDamage());
	return *this;
}

/* --- Constructor overload ------------------------------------------------- */

// ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
// 	_hitPoints = 100;
// 	_energyPoints = 50;
// 	_attackDamage = 20;
// 	std::cout << "\tA ScavTrap unit called '" << _name << "' has been constructed."
			//   << std::endl;
// }
ScavTrap::ScavTrap( const std::string &name ) : ClapTrap(name) {
	setHitPoints(100);
	setEnergyPoints(50);
	setAttackDamage(20);
	std::cout << "\tA ScavTrap unit called '" << getName() << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void 	ScavTrap::attack( const std::string& target ) {

	if (getEnergyPoints() <= 0) {
		std::cout << getName() << " [SCAV ATTACK_FT] ran out of energy, he can't either attack or repair himself!"
				  << std::endl;
	} else {

		int	dice_roll = dice();
		std::cout << "[SCAV ATTACK_FT] Turn for " << getName() <<", dice roll is " << dice_roll 
				  << std::endl;

		if(dice_roll == 6) {
			beRepaired(10);
			setAttackDamage(0);
		} else {
			setAttackDamage(dice_roll);
			setEnergyPoints(getEnergyPoints() - 1);
			std::cout << getName() << " [SCAV ATTACK_FT] attacks " << target << ", causing " 
					<< getAttackDamage() << " points of damage!"
					<< std::endl;
			display_score(getName(), getHitPoints(), getEnergyPoints());			
		}
	}
}

// void	ScavTrap::attack(const std::string &target) {
// 	std::cout << "ScavTrap " << getName() << " attacks " << target << ", causing " 
// 			  << getAttackDamage() << " points of damage!" 
// 			  << std::endl;
// }

void	ScavTrap::guardGate(void) {
	std::cout << "ScavTrap " << getName() << " is now in Gate keeper mode." << std::endl;
}