#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>

class ClapTrap{

	protected:
		std::string _name;
		std::string _robotType;
		int _hitPoints;
		int _energyPoints;
		int _attackDamage;

	public:
		ClapTrap();
		ClapTrap(const std::string &name);
		virtual ~ClapTrap();
		ClapTrap(const ClapTrap& copy);
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getType();
		int getAttackDamage();
		int getHitPoints();
		int getEnergyPoints();
		std::string getName();
	ClapTrap &operator=(const ClapTrap &src);
};

#endif
