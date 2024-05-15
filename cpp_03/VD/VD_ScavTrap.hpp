#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "VD_ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap{

	private:
		bool _guardGate;
	
	public:
		ScavTrap();
		ScavTrap(const std::string &name);
		ScavTrap(const ScavTrap& copy);
		virtual ~ScavTrap();
		void GuardGate();
	ScavTrap &operator=(const ScavTrap &src);
};

#endif
