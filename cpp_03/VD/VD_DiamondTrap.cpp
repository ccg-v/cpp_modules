#include "VD_DiamondTrap.hpp"

void DiamondTrap::attack(std::string object){
	FragTrap::attack(object);
}

DiamondTrap::DiamondTrap() : ClapTrap("John_Doe_clap_trap"){
	std::cout << "The default DiamondTrap constructor has been called" << std::endl;
	this->_name = "John_Doe";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	// this->_robotType = "DiamondTrap";
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_trap"){
	std::cout << "DiamondTrap Name Constructor called" << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	// this->_robotType = "DiamondTrap";
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy){
	*this = copy;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "The destructor for "<< getName() << " has been called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &src){
	std::cout << "DiamondTrap Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << _name << std::endl;
	std::cout << "My ClapTrap name is " << ClapTrap::_name << std::endl;
}
