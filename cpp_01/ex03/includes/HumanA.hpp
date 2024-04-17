/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:03:26 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/17 14:43:08 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * Human A:
 *	-	must have a name.
 *	-	must have a weapon.
 *	-	must have a member function 'attack' to display who attacks and how.
 *	-	must always be armed 
 *			-> the weapon must be initialized in the constructor
 *			--> a REFERENCE is more suitable because HumanA instances is always 
 *				associated with a weapon from the start and can't exist without 
 *				one.
 */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class	HumanA {

	private:
		std::string	_attackerName;
		Weapon		&_currentWeapon;

	public:
		//	Constructor declaration (new instances must have name and weapon)
		HumanA(std::string const &attackerName, Weapon &currentWeapon);

		//	Destructor declaration
		~HumanA();

		//	Member function that displays attacker's name and weapon used
		void	attack();

};

#endif