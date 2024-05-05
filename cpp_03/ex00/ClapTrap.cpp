/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:45:55 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/05 14:06:14 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
ClapTrap::ClapTrap( void ) 
	: _name("default_ClapTrap"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "Default 'CL4P-TP General Purpose Robot' model has been constructed. "
				 " Their default score points have been set."
			  << std::endl;
};

//	Copy constructor
ClapTrap::ClapTrap(const ClapTrap &source) {
	*this = source;
	std::cout << _name < " ClapTrap unit has been constructed." << std::endl;
}


//	Default destructor
ClapTrap::~ClapTrap( void ) {
	std::cout << _name << has been destroyed << std::endl;
}
