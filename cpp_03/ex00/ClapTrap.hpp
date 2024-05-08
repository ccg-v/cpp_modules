/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 10:27:42 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/09 00:41:10 by ccarrace         ###   ########.fr       */
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

	ClapTrap( std::string& name );	

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
