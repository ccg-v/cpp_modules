/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:59:45 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/13 22:30:00 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public virtual ScavTrap, public virtual FragTrap	// (1)
{
private:
	std::string	_name;
	
public:
	/* --- Orthodox Canonical Form ------------------------------------------ */
	
	DiamondTrap( void );								//	Default constructor
	DiamondTrap( const DiamondTrap &source );			//	Copy constructor
	DiamondTrap &operator=( const DiamondTrap &source );	//	Copy assignment operator
	~DiamondTrap( void );								//	Default destructor
	
	/* --- Constructor overload --------------------------------------------- */

	DiamondTrap( const std::string &name );

	/* --- Member functions ------------------------------------------------- */

	void 	attack( const std::string &target );
	void 	whoAmI( void );	
};

#endif

/*
 *	(1)	The syntax of a derived class is as follows:
 *
 *			class DerivedClass : [access-specifier] BaseClass {};
 *
 * 		C++ supports three access specifiers:
 * 
 * 			- public: in public inheritance, public members of the base class
 * 					become public members of the derived class, protected
 * 					members of the base class become protected members of the
 * 					derived class, and private members of the base class remain
 * 					remain inaccessible in the derived class.
 * 			- protected: both public and protected members of the base class
 * 					become protected members of the derived class.
 * 			- private: both public and protected members of the base class
 * 					become private members of the derived class.
 * 
 * 		Derived classes can override base class methods by providing a new
 * 		implementation with the same function signature. This allows to
 * 		POLYMORPHIC BEHAVIOR, where the appropiate method is called based on the
 * 		object's actual type. In C++, polymorphism is tipically achieved through
 * 		VIRTUAL functions and inheritance.
 * 
 * 		In our DiamondTrap class, the access specifier for inheritance must be
 * 		'public' because we want to access to the public members of the base 
 * 		classes ScavTrap and FragTrap.
 */