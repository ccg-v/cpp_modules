/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:34:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/09 23:55:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>


class Weapon {

	private:
		std::string	type;

	public:
		//	Constructor initializer list syntax:
		Weapon(std::string const &newType);

		//	Member functions
		std::string const	&getType() const;
		void setType(std::string const &newType);
		
};

#endif

/* 
 * Each time a new Weapon object is instanciated, a type of weapon must be 
 * assigned (e.g. Weapon("sword")). That's the task of the constructor, ensure
 * that the new object's state is automatically initialized.
 * The constructor initializer can be written with a different syntax
 * 		Weapon(std::string const &newType) {
 *			type = newType
 *		}
 * In this case the member variable is initialized in the constructor body. 
 */