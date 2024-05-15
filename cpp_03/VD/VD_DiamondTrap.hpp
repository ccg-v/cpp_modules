#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "VD_ScavTrap.hpp"
#include "VD_FragTrap.hpp"

class DiamondTrap : public FragTrap, ScavTrap{

	private: 
		std::string _name;

	public:
		DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap &copy);
		virtual ~DiamondTrap();
		void attack(std::string object);
		void whoAmI();
		DiamondTrap &operator=(const DiamondTrap &src);	
};

#endif
