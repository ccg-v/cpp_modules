/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 19:29:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/04 00:36:14 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 *	newZombie()
 *
 * - Creates a zombie, name it and returns a pointer so it can be used outside
 * 		of the function scope.
 * - Heap allocation is the only choice here because the object needs to persist 
 * 		beyond the function's execution.
 * 		--> to allocate memory on the heap, the NEW operator must be called.
 *      --> to release memory, the DELETE operator must be called (in main() ).
 */
Zombie *newZombie(std::string name) {

	Zombie *newZombiePtr = new Zombie(name);

	/* 	No need of setter now I defined a constructor that receives the name
		as a parameter */
	// newZombiePtr->setName(name); 
	
	return newZombiePtr;
	
}
