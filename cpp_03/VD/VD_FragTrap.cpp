#include "VD_FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("John Doe"){
	std::cout << "The default FragTrap constructor is has been called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	// this->_robotType = "FragTrap";
}

FragTrap::FragTrap(const std::string &name) : ClapTrap(name) {
	std::cout << "The name constructor for FragTrap has been called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	// this->_robotType = "FragTrap";
}

FragTrap::FragTrap(const FragTrap &copy){
	*this = copy;
}

FragTrap::~FragTrap(){
	std::cout << "The destructor for FragTrap has been called" << std::endl;
}

void FragTrap::highFivesGuys(void){
	std::cout << "Gimme highfive guys!" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &src){
	std::cout << "Assignation operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}
