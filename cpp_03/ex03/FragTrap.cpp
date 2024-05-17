/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 23:23:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/17 20:09:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
FragTrap::FragTrap( void ) : ClapTrap() {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\t[FragTrap constructor called] Default FragTrap constructor has been called." 
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
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "\t[FragTrap constructor overload called] A FragTrap unit called '" 
			  << _name << "' has been constructed."
			  << std::endl;
}

/* --- Member functions ----------------------------------------------------- */

void 	FragTrap::attack( const std::string& target ) {
	ClapTrap::attack( target );
}

void	FragTrap::highFivesGuys(void) {
		std::cout << getName() << " says: Give me five, guys!" << std::endl;
}