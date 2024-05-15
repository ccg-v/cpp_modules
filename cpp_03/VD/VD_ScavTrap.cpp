#include "VD_ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("John Doe") {
	std::cout << "The default ScavTrap constructor has been called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	_guardGate = false;
}

ScavTrap::ScavTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "The name constructor for ScavTrap has been called" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	// _robotType = "ScavTrap";
}

ScavTrap::ScavTrap(const ScavTrap &copy){
	*this = copy;
}

ScavTrap::~ScavTrap(){
	std::cout << "The destructor for ScavTrap has been called" << std::endl;
}

void ScavTrap::GuardGate(){
	std::cout << getName() << " is now in Gate keeper mode" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &src){
	std::cout << "Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}
