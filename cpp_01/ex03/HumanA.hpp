/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:03:26 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/07 23:23:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Class	HumanA {

	private:
		std::string	name;
		Weapon	currentWeapon;

	public:
		// member function that displays the attacker's name and the weapon used
		std::string attack(std::string attackerName, std::string weaponType);

};