/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:45:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/08 01:15:20 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	dice( void );

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
ClapTrap::ClapTrap( void ) 
	: _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default 'CL4P-TP General Purpose Robot' model has been constructed. "
				 "Default score points for future new units have been set."
			  << std::endl;
};

//	Copy constructor
ClapTrap::ClapTrap( const ClapTrap &source ) {
	*this = source;
	std::cout << "A new ClapTrap COPY called " << getName() << " has been constructed." 
			  << std::endl;
}

//	Default destructor
ClapTrap::~ClapTrap( void ) {
	std::cout << "A ClapTrap unit called " << getName() << " has been destroyed." 
			  << std::endl;
}

//	Operator assignment overload
ClapTrap	&ClapTrap::operator=( const ClapTrap &source ) {
	if (this == &source)
		return (*this);
	// _name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return (*this);
}

/* --- Constructor overload ------------------------------------------------- */

ClapTrap::ClapTrap( std::string name )
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "A new ClapTrap unit called " << _name << " has been constructed."
			  << std::endl;
}

/* --- Accessors ------------------------------------------------------------ */

//	Setters
void	ClapTrap::setName( std::string name ) {
	this->_name = name;
};

void	ClapTrap::setAttackDamage( int attackDamage ) {
	this->_attackDamage = attackDamage;
};

void	ClapTrap::setHitPoints( int hitPoints) {
	this->_hitPoints = hitPoints;
};

//	Getters
std::string	ClapTrap::getName ( void ) {
	return (_name);
};

int	ClapTrap::getHitPoints( void ) {
	return (_hitPoints);
};

int	ClapTrap::getEnergyPoints( void ) {
	return (_energyPoints);
};

int	ClapTrap::getAttackDamage ( void ) {
	return (_attackDamage);
};

/* --- Member functions ----------------------------------------------------- */

void 	ClapTrap::attack( const std::string& target ) {

	int	dice_roll = dice();
	std::cout << "\tDice roll is " << dice_roll << std::endl;
	if (dice_roll == 0) {
		std::cout << "\t" << getName() << " quickly repairs himself instead of attacking"
				  << std::endl;
		beRepaired(10);
		std::cout << "\t" << getName() << " now has " << getHitPoints() << " hitpoints"
				  << std::endl;
	}
	else {
		setAttackDamage(dice_roll);
		std::cout << "\t" << getName() << " attacks " << target
			  << ", causing " << getAttackDamage() << " points of damage!"
			  << std::endl;
	}
};

void	ClapTrap::takeDamage( unsigned int amount ) {
	this->_hitPoints = this->_hitPoints - amount;
	if (this->_hitPoints > 0)
		std::cout << "\t" << getName() << " has " << this->_hitPoints << " hitpoints" << std::endl;
	else
		std::cout << "\t" << getName() << " died!!!" << std::endl;
};

void	ClapTrap::beRepaired( unsigned int amount ) {
	this->_hitPoints = amount;
	this->_energyPoints = this->_energyPoints - 1;
};

/* --- Non-class functions --------*/

int	dice( void ) {
	
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);

    int random_number = dis(gen);
	
	return (random_number);
}