/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:03:26 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/08 23:46:06 by ccarrace         ###   ########.fr       */
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

Class	HumanA {

	private:
		std::string	attackerName;
		Weapon		currentWeapon;

	public:
		//	Constructor declaration (new instances must have name and weapon)
		HumanA(const std::string &attackerName, Weapon &currentWeapon);

		//	Destructor declaration
		~HumanA();

		//	Getter for attacker's name
		std::string getAttackerName() const;

		//	Getter for current weapon
		std::string	getCurrentWeapon() const;

		//	Member function that displays attacker's name and weapon used
		void attack(void);

};

#endif