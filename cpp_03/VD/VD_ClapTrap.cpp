#include "VD_ClapTrap.hpp"

ClapTrap::ClapTrap(){
	std::cout << "The default ClapTrap constructor has been called" << std::endl;
	_name = "John Doe";
	// _robotType = "ClapTrap";
	_hitPoints = 10;
	_energyPoints = 10;
	_attackDamage = 0;
}

ClapTrap::ClapTrap(const std::string &name) : _name(name), _robotType("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "The name ClapTrap constructor has been called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy){
	*this = copy;
}

ClapTrap::~ClapTrap(){
	std::cout << "The destructor for ClapTrap has been called" << std::endl;
}

int ClapTrap::getAttackDamage(){
	return this->_attackDamage;
}

int ClapTrap::getHitPoints(){
	return this->_hitPoints;
}

int ClapTrap::getEnergyPoints(){
	return this->_energyPoints;
}

std::string ClapTrap::getName(){
	return this->_name;
}

std::string ClapTrap::getType(){
	return this->_robotType;
}

// void ClapTrap::setName(std::string name){
// 	_name = name;
// }

void ClapTrap::attack(const std::string& target){
	if (this->getEnergyPoints() > 0){
		_energyPoints -= 1;
		std::cout << this->getType() << " " << this->getName() << " attacks " << target << ", causing " << this->getAttackDamage() << " points of damage!" << std::endl;
		std::cout << this->getType() << " " << this->getName() << " has " << this->getEnergyPoints() << " points of energy left" << std::endl;
	}
	else
		std::cout << "Can not attack! No energy left"  << std::endl;
}	

void ClapTrap::takeDamage(unsigned int amount){
	if (this->getHitPoints() > 0)
		{
			std::cout << this->getType() << " " << this->getName() <<  " received " << amount << " points of damage" << std::endl;
			_hitPoints -= amount;
			std::cout << this->getType() << " " << this->getName() <<  " has " << this->getHitPoints() << " points of health left" << std::endl;
		}
	else
		std::cout << "The target is long dead";
}
void ClapTrap::beRepaired(unsigned int amount){
	if (this->getHitPoints() > 0 && this->getEnergyPoints() > 0)
		{
			std::cout << this->getType() << " received " << amount << " points of healing" << std::endl;
			_hitPoints += amount;
			_energyPoints -= 1;
			std::cout << this->getType() << " has " << this->getHitPoints() << " points of health left" << std::endl;
		}
	else if (this->getHitPoints() < 0)
		std::cout << "No healing is possible, " << this->getType() << " is dead" << std::endl;
	else 
		std::cout << "There's not enough energy to perform the repair process" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &src){
	std::cout << "Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}
