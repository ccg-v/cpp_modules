#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap
{
public:
    ScavTrap( void ) : ClapTrap() {
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
    }
    ScavTrap( const ScavTrap &source ) : ClapTrap(source) {}
    ScavTrap &operator=( const ScavTrap &source ) {
        ClapTrap::operator=(source);
        return *this;
    }
    ~ScavTrap( void ) {}

    ScavTrap( const std::string &name ) : ClapTrap(name) {
        _hitPoints = 100;
        _energyPoints = 50;
        _attackDamage = 20;
    }

    void attack( const std::string &target ) { std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl; }
    void guardGate( void ) { std::cout << "ScavTrap " << _name << " is now in Gatekeeper mode." << std::endl; }
};

#endif

