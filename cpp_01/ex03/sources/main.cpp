/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 20:33:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/17 14:44:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);

		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		
		jim.setWeapon(club);
		
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}

	// {
	// 	Weapon knife = Weapon("cutter");
	// 	HumanA bob("Bob", knife);

	// 	bob.attack();
	// 	knife.setType("swiss pocket knife");
	// 	bob.attack();	
	// }
	// {
	// 	HumanB jim("Jim");
		
	// 	jim.attack();
	// }	
	return 0;

}