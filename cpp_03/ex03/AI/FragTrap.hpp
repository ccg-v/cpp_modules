#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class FragTrap : virtual public ClapTrap
{
public:
    FragTrap( void ) : ClapTrap() {
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
    }
    FragTrap( const FragTrap &source ) : ClapTrap(source) {}
    FragTrap &operator=( const FragTrap &source ) {
        ClapTrap::operator=(source);
        return *this;
    }
    ~FragTrap( void ) {}

    FragTrap( const std::string &name ) : ClapTrap(name) {
        _hitPoints = 100;
        _energyPoints = 100;
        _attackDamage = 30;
    }

    void attack( const std::string &target ) { std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl; }
    void highFivesGuys( void ) { std::cout << "FragTrap " << _name << " is asking for a high five!" << std::endl; }
};

#endif

