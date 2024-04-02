/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:15:13 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/02 23:17:03 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 *	randomChump()
 *
 * - Creates a zombie, name it and the zombie announces itself.
 * - Since the zombie doesn't need to exist outside the function, stack
 * 		allocation is efficient. 
 * - The object is automatically cleaned up when the function goes out of scope.
 */
void randomChump(std::string name) {

	Zombie newZombie;

	newZombie.setName(name);
	newZombie.announce();

}