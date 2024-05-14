#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
    std::string _name;

public:
    DiamondTrap( void ) : ClapTrap("DiamondTrap_clap_name"), ScavTrap(), FragTrap() {
        _name = "DiamondTrap";
        _hitPoints = 777;
        _energyPoints = 888;
        _attackDamage = 999;
    }
    DiamondTrap( const DiamondTrap &source ) : ClapTrap(source), ScavTrap(source), FragTrap(source), _name(source._name) {}
    DiamondTrap &operator=( const DiamondTrap &source ) {
        if (this != &source) {
            ClapTrap::operator=(source);
            ScavTrap::operator=(source);
            FragTrap::operator=(source);
            _name = source._name;
        }
        return *this;
    }
    ~DiamondTrap( void ) {}

    DiamondTrap( const std::string &name ) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name) {
        _name = name;
        _hitPoints = FragTrap::_hitPoints;
        _energyPoints = ScavTrap::_energyPoints;
        _attackDamage = FragTrap::_attackDamage;
    }

    using ScavTrap::attack; // To resolve ambiguity and use ScavTrap's attack method
    void whoAmI( void ) {
        std::cout << "I am " << _name << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
    }

	std::string getDiamondName() const {
        return _name;
    }
};

#endif

