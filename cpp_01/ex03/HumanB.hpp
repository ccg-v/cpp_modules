/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:05:27 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/08 23:46:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 * Human B:
 *	-	must have a name.
 *	-	must have a weapon.
 *	-	must have a member function 'attack' to display who attack and how.
 *	-	unlike Human A, Human B may not always have a weapon (initially, but
 *		can be equiped with a weapon later)
 *			->	no initialization of weapon in the constructor
 *			--> in this case, a POINTER to 'Weapon' is more suitable because
 *				'Human B' instances  it can be initialized to nullptr initially
 *				and then set to point to a Weapon object later. 
 */

#ifndef HUMANB_HPP
# define HUMANB_HPP

Class	HumanB {

	private:
		std::string	attackerName;
		Weapon		currentWeapon;

	public:
		//	Constructor declaration (new instances must have name but not weapon)
		Weapon(std::string const *attackerName);

		//	Destructor declaration
		~Weapon();

		//	Getter for attacker's name
		std::string getAttackerName() const;

		//	Getter for current weapon
		std::string	getCurrentWeapon() const;
			
		// member function that displays attacker's name and weapon used
		std::string attack(std::string name, std::string type);
		
};

#endif