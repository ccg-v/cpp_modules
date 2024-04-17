/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/04 19:57:12 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/18 00:19:01 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void) {

	int	numZombies = 10;
	
	std::string name = "Brain Eater";

	Zombie *horde = zombieHorde(numZombies, name);

	for (int i =0; i < numZombies; i++) {
		horde[i].announce();
	}
	
	delete [] horde;
}