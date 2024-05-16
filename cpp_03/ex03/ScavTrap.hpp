/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:59:45 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/16 23:35:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : virtual public ClapTrap	// (1)
{
	
public:
	/* --- Orthodox Canonical Form ------------------------------------------ */
	
	ScavTrap( void );								//	Default constructor
	ScavTrap( const ScavTrap &source );				//	Copy constructor
	ScavTrap &operator=( const ScavTrap &source );	//	Copy assignment operator
	~ScavTrap( void );									//	Default destructor
	
	/* --- Constructor overload --------------------------------------------- */

	ScavTrap( const std::string &name );

	/* --- Member functions ------------------------------------------------- */

	void 	attack( const std::string &target );
	void 	guardGate( void );	
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
 * 		In our ScavTrap class, the access specifier for inheritance must be
 * 		'public' because we want to access to the public members of the base 
 * 		class ClapTrap, such as the accessors and the member functions.
 */