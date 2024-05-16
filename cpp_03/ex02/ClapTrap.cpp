/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:45:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/17 01:19:39 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int		dice( void );
void	display_score( std::string name, int hitPoints, int energyPoints);

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
ClapTrap::ClapTrap( void ) 
	: _name("Default_ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "\t[ClapTrap constructor called] Default ClapTrap constructor has been called."
			  << std::endl;
};

//	Copy constructor
ClapTrap::ClapTrap( const ClapTrap &source ) {
	*this = source;
	std::cout << "\tA new ClapTrap called '" << getName() << "' has been copied." 
			  << std::endl;
}

//	Default destructor
ClapTrap::~ClapTrap( void ) {
	std::cout << "\t[Claptrap destructor called] The ClapTrap unit called '" << getName() 
			  << "' has been destroyed." 
			  << std::endl;
}

//	Operator assignment overload
ClapTrap	&ClapTrap::operator=( const ClapTrap &source ) {
	if (this == &source)
		return (*this);
	_name = source._name;
	_hitPoints = source._hitPoints;
	_energyPoints = source._energyPoints;
	_attackDamage = source._attackDamage;
	return (*this);
}

/* --- Constructor overload ------------------------------------------------- */

ClapTrap::ClapTrap( const std::string& name )
	: _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "\t[ClapTrap constructor overload called] A ClapTrap unit called '" 
			  << _name << "' has been constructed."
			  << std::endl;
}

/* --- Accessors ------------------------------------------------------------ */

//	Setters
void	ClapTrap::setName( std::string name ) {
	this->_name = name;
};

void	ClapTrap::setHitPoints( int hitPoints) {
	this->_hitPoints = hitPoints;
};

void	ClapTrap::setEnergyPoints( int energyPoints) {
	this->_energyPoints = energyPoints;
};

void	ClapTrap::setAttackDamage( int attackDamage ) {
	this->_attackDamage = attackDamage;
};

//	Getters
std::string	ClapTrap::getName ( void ) const {
	return (_name);
};

int	ClapTrap::getHitPoints( void ) const {
	return (_hitPoints);
};

int	ClapTrap::getEnergyPoints( void ) const {
	return (_energyPoints);
};

int	ClapTrap::getAttackDamage ( void ) const {
	return (_attackDamage);
};

/* --- Member functions ----------------------------------------------------- */

//	To follow the subject and keep the ClapTrap attackDamage value constant, 
//	set 'attackDamage' to 0.
//	To simulate a battle, assign to 'attackDamage' the result returned by
//	'dice()' function, that is, a random integer from 0 to 6
void 	ClapTrap::attack( const std::string& target ) {

	if (this->_energyPoints <= 0) {
		std::cout << getName() << " ran out of energy, he can't either attack or repair himself!"
				  << std::endl;
		display_score(getName(), getHitPoints(), getEnergyPoints());
	} else {
	
		int	attackDamage = getAttackDamage();	//	<-- replace HERE!!
		std::cout << "Turn for " << getName() <<", attackDamage is " << attackDamage 
				  << std::endl;

		if(attackDamage == 6) {
			beRepaired(getHitPoints());
			setAttackDamage(0);
		} else {
			setAttackDamage(attackDamage);
			this->_energyPoints = this->_energyPoints - 1;
			std::cout << getName() << " attacks " << target << ", causing " 
					<< getAttackDamage() << " points of damage!"
					<< std::endl;
			display_score(getName(), this->_hitPoints, this->_energyPoints);			
		}
	}
}

void	ClapTrap::takeDamage( unsigned int amount ) {

	this->_hitPoints = this->_hitPoints - amount;
	display_score(getName(), this->_hitPoints, this->_energyPoints);

	if (this->_hitPoints <= 0)
		std::cout << getName() << " died!!!" << std::endl;
};

void	ClapTrap::beRepaired( unsigned int amount ) {
	if (this->_energyPoints > 0) {
	std::cout << getName() << " quickly repairs himself instead of attacking"
			  << std::endl;
	this->_hitPoints = amount;
	this->_energyPoints = this->_energyPoints - 1;
	display_score(getName(), this->_hitPoints, this->_energyPoints);
	} else {
		std::cout << getName() << " can't repair himself because he has no energy points!"
				  << std::endl;
	}
};

/* --- Non-class functions -------------------------------------------------- */

int	ClapTrap::dice( void ) {
	
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 6);

    int random_number = dis(gen);
	
	return random_number;
}

void	ClapTrap::display_score( std::string name, int hitPoints, int energyPoints) {

	if (energyPoints < 0)
		energyPoints = 0;
	if (hitPoints < 0)
		hitPoints = 0;	
	std::cout << name << " score: " 
			  << hitPoints << " hit points / "
			  << energyPoints << " energy points"
			  << std::endl;
}