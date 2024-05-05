/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:45:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/06 01:08:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	nbr_generator( void );

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

void	ClapTrap::setAttackDamage( std::string name ) {

    // std::random_device rd;
    // std::mt19937 gen(rd());
    // std::uniform_int_distribution<> dis(0, 9);

    // int random_number = dis(gen);
	// this->_attackDamage = random_number;
    // std::cout << name << " attack dammage is " << getAttackDamage() << std::endl;
	std::cout << "\t" << name << std::endl;
	int amount = nbr_generator();
	takeDamage(amount);
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
	setAttackDamage(target);
	// int amount = nbr_generator();
	// takeDamage(amount);
	std::cout << "\tClapTrap " << getName() << " attacks " << target
			  << ", causing " << getAttackDamage() << " points of damage!"
			  << std::endl;
};

void	ClapTrap::takeDamage( unsigned int amount ) {
	std::cout << "\t" << getName() << " launches an attack level " << amount 
			  << std::endl;
};
// void	beRepaired( unsigned int amount ) {};

/* --- Non-class functions --------*/

int	nbr_generator( void ) {
	
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 9);

    int random_number = dis(gen);
	
	return (random_number);
}