/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/14 23:26:35 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
FragTrap::FragTrap( void ) : ClapTrap() {
	_hitPoints = 444;
	_energyPoints = 555;
	_attackDamage = 666;
	std::cout << "[FragTrap constructor called] Default FragTrap constructor has been called." 
			  << std::endl;
}

//	Copy constructor
FragTrap::FragTrap( const FragTrap &source ) : ClapTrap(source) {
	*this = source;
	std::cout << "\tA new FragTrapp called '" << getName() << "' has been created" 
			  << std::endl;
}

//	Default destructor
FragTrap::~FragTrap( void ) {
	std::cout << "\t[FragTrap destructor called] The FragTrap unit called '" 
			  << getName() << "' has been destroyed." 
			  << std::endl;
}

//	Copy assignment operator
FragTrap &FragTrap::operator=( const FragTrap &source ) {
	if (this == &source)
		return *this;
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return *this;
}

/* --- Constructor overload ------------------------------------------------- */

FragTrap::FragTrap( const std::string &name ) : ClapTrap(name) {
	_hitPoints = 777;
	_energyPoints = 888;
	_attackDamage = 999;
	std::cout << "\t[FragTrap constructor overload called] A FragTrap unit called '" 
			  << _name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

//	To follow the subject and keep the FragTrap attackDamage value constant, 
//	set 'attackDamage' to 30.
//	To simulate a battle, assign to 'attackDamage' the result returned by
//	'dice()' function, that is, a random integer from 0 to 6
void 	FragTrap::attack( const std::string& target ) {

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

void	FragTrap::highFivesGuys(void) {
		std::cout << getName() << " says: Give me five, guys!" << std::endl;
}