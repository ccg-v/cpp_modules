/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/13 00:35:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap() {
	_name = "Default_DiamondTrap";
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
	std::cout << "\t[DiamondTrap destructor called] The DiamnodTrap unit called '" 
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
	_attackDamage = source._attackDamage;
	return *this;
}

/* --- Constructor overload ------------------------------------------------- */

DiamondTrap::DiamondTrap( const std::string &name ) : ClapTrap(name), ScavTrap(name), FragTrap(name) {
	_name = name;
	// ClapTrap::_name = name + "_clap_name";
	std::cout << "\t[DiamondTrap constructor overload called] A DiamondTrap unit called '" 
			  << _name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

//	To follow the subject and keep the FragTrap attackDamage value constant, 
//	set 'attackDamage' to 30.
//	To simulate a battle, assign to 'attackDamage' the result returned by
//	'dice()' function, that is, a random integer from 0 to 6
void 	DiamondTrap::attack( const std::string& target ) {

	if (getEnergyPoints() <= 0) {
		std::cout << getName() 
				  << " ran out of energy, he can't either attack or repair himself!"
				  << std::endl;
		highFivesGuys();
		display_score(getName(), getHitPoints(), getEnergyPoints());
	} else {
	
		int	attackDamage = 30;	//	<- replace HERE!!!
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
			display_score(getName(), getHitPoints(), getEnergyPoints());	
		}
	}
}

void	DiamondTrap::whoAmI(void) {
	std::cout <<  getName() << " says: Listen to me! I am " << _name 
			  << ", I belong to " << ClapTrap::_name << " and I beat you all!!!!!" 
			  << std::endl;
}