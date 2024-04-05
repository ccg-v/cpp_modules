/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 23:15:45 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/05 22:12:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 *	Zombie()
 *
 *	Default constructor. It will be called when a 'Zombie' object is instanciated
 *	without any parameters:
 *		Zombie myZombie();
 *	If there is no constructor at all, the compiler generates one automatically. 
 *	But in this case the compiler won't create a default constructor because there
 *	is already one constructor defined (above), so I need to specify the default
 *	one too.
 */
Zombie::Zombie() {}

/*
 *	Zombie()
 *
 *	Constructor that assigns a name to Zombie class member 'name'
 */
Zombie::Zombie (const std::string &name) {

   this->name = name;
   std::cout << "A zombie called " << name << " is born" << std::endl;
   
} 	

/*
 *	zombieHorde()
 *
 *  -	Allocates memory for an array of zombies of size received as parameter
 *  -	Initializes each zombie with the name received as a parameter
 *  -	Returns a pointer to the firss
 */
Zombie	*zombieHorde( int N, std::string name ) {
	
	Zombie *horde = new Zombie[N];

    for (int i = 0; i < N; ++i) {
		std::string uniqueName = name + " " + std::to_string(i + 1);
        horde[i] = Zombie(uniqueName);
    }

    return horde;
}

/*
 *	announce()
 *
 * The zombie announces itself displaying the required message
 * Notice the function doesn't receive any parameters, but since it's a member
 * of the Zombie class, it has direct access to the private name member of the
 * object it's being called on.
 */
void	Zombie::announce(void) {

	std::cout << this->name << " says: BraiiiiiiinnnzzzZ..." << std::endl;
	
}