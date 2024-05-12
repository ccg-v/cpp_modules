/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:27:42 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/12 14:41:42 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <random>

class ClapTrap
{
private:
	std::string	_name;
	int			_hitPoints;		// ClapTrap's health in battle
	int			_energyPoints;	// Energy for repairing/attacking (cost: 1 point/each)
	int			_attackDamage;	// Damage caused to the enemy by the attack 

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ClapTrap( void );								// Default constructor
	ClapTrap( const ClapTrap& source);				// Copy constructor 
	ClapTrap& operator=( const ClapTrap& source ); 	// Copy assignment operator
	~ClapTrap( void );								// Destructor

	/* --- Constructor overload --------------------------------------------- */

	ClapTrap( const std::string& name );	// (1)

	/* --- Accessors -------------------------------------------------------- */
	
	//	Setters
	void		setName ( std::string name );
	void		setAttackDamage( int attackDamage );
	void		setHitPoints( int hitPoints);
	
		//	Getters
	std::string	getName ( void );
	int			getHitPoints( void );
	int			getEnergyPoints( void );
	int			getAttackDamage ( void );

	/* --- Member functions ------------------------------------------------- */

	void 	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );
};

#endif

/*
 *	(1)	In this implementation:
 *			
 *					ClapTrap::ClapTrap(std::string& name)
 *		
 *		the constructor takes a non-const reference to a std::string. Therefore, 
 * 		it cannot accept temporary objects, including string literals like 
 * 		"Attacker". String literals are of type 'const char*', and they cannot 
 * 		be bound to non-const references. This assignment won't compile:
 * 
 * 					ClapTrap		ClapTrap1("Atacker")
 * 
 * 		In case we don't want the constructor to take necessarily a 'const char*' 
 * 		parameter, we declaring a std::string variable 'name' and initialize it 
 * 		with the desired value (e.g "Attacker"), then pass 'name' to the 
 * 		constructor of ClapTrap. This way, we are still initializing ClapTrap with 
 * 		a string value, but indirectly through a std::string object rather than 
 * 		directly using a string literal.
 * 
 * 					std::string 	name = "Attacker";
 * 					Claptrap 		ClapTrap1(name);
 *
 *		Instead, in this implementation:
 *
 *					ClapTrap::Claptrap(const std::string& name)
 *	
 *		the constructor takes a const reference to a std::string. This means it 
 *		can accept both lvalues (like variables) and rvalues (temporary objects). // (2)
 * 		When you pass a string literal to this constructor, it is automatically 
 * 		converted into a temporary std::string object, which can then be bound to 
 * 		the const reference parameter.	
 * 		
 * 		So, the inclusion of the const keyword in the parameter type allows the 
 * 		constructor to accept temporary objects like string literals
 * 
 * 
 * 	(2)	In C++, lvalues and rvalues are expressions categorized based on whether 
 * 		they can appear on the left-hand side (lvalue) or right-hand side (rvalue) 
 * 		of an assignment operation.

    	Lvalue: An lvalue refers to an object that occupies some identifiable 
		location in memory. It represents an object that can be assigned a value. 
		Lvalues are typically variables or references to variables. Examples 
		include variables, array elements, and dereferenced pointers.

		Rvalue: An rvalue refers to a temporary value that does not necessarily 
		have a memory location. Rvalues are typically temporary and cannot appear 
		on the left-hand side of an assignment operation. Examples include literals, 
		temporary variables, and the results of expressions.
 */