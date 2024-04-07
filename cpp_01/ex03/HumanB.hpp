/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 21:05:27 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/07 22:32:38 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Class	HumanB {

	private:
		std::string name;
		Weapon	weapon;

	public:
		// member function that displays attacker's name and weapon used
		std::string attack(std::string name, std::string type);
		
};