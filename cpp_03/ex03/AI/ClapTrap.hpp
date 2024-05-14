#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>

class ClapTrap
{
protected:
    std::string _name;
    int _hitPoints;
    int _energyPoints;
    int _attackDamage;

public:
    ClapTrap( void ) : _name("ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}
    ClapTrap( const ClapTrap& source)
        : _name(source._name), _hitPoints(source._hitPoints), _energyPoints(source._energyPoints), _attackDamage(source._attackDamage) {}
    ClapTrap& operator=( const ClapTrap& source ) {
        if (this != &source) {
            _name = source._name;
            _hitPoints = source._hitPoints;
            _energyPoints = source._energyPoints;
            _attackDamage = source._attackDamage;
        }
        return *this;
    }
    ~ClapTrap( void ) {}

    ClapTrap( const std::string& name )
        : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {}

    void setName( std::string name ) { _name = name; }
    void setHitPoints( int hitPoints) { _hitPoints = hitPoints; }
    void setEnergyPoints( int energyPoints) { _energyPoints = energyPoints; }
    void setAttackDamage( int attackDamage ) { _attackDamage = attackDamage; }

    std::string getName( void ) const { return _name; }
    int getHitPoints( void ) const { return _hitPoints; }
    int getEnergyPoints( void ) const { return _energyPoints; }
    int getAttackDamage( void ) const { return _attackDamage; }

    void attack( const std::string& target ) { std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl; }
    void takeDamage( unsigned int amount ) { _hitPoints -= amount; }
    void beRepaired( unsigned int amount ) { _hitPoints += amount; }
};

#endif

