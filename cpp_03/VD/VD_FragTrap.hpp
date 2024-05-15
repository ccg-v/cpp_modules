#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "VD_ClapTrap.hpp"
#include "VD_ScavTrap.hpp"

class FragTrap : virtual public ClapTrap{
	
	public:
		FragTrap();
		FragTrap(const std::string &name);
		FragTrap(const FragTrap& copy);
		virtual ~FragTrap();

		void highFivesGuys(void);
	FragTrap &operator=(const FragTrap &src);	
};

#endif
