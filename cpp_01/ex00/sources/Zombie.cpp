/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:17:16 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/04 00:31:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/*
 *	setName()
 *
 * Accessor to set the value of Zombie class private member Name
 */
// void Zombie::setName(const std::string &name) {

//     this->name = name;

// }

/*
 *	announce()
 *
 * The zombie announces itself displaying the required message
 * Notice the function doesn't receive any parameters, but since it's a member
 * of the Zombie class, it has direct access to the private name member of the
 * object it's being called on.
 */
void Zombie::announce(void) {

	std::cout << std::endl << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
	
}

/*
 *  Zombie()
 *
 * The constructor. Assigns the parameter 'name' to the member variable 'name'.
 */
Zombie::Zombie(const std::string &name) {

    this->name = name;

}

/*
 *	~Zombie()
 *
 * A destructor. It is an specific member function that's automatically called
 * when the object goes out of scope or is explicitily deleted using 'delete'.
 * But its main purpose is to clean up any resources associated with the object
 * assuming they don't involve deallocating the object's own memory(for instance
 * releasing dinamically allocated memory other than the object itself, closing 
 * open files, performing any other necessary cleanup tasks, ...)
 * In this specific case, it simply prints a message related to the object to be 
 * destroyed that might be helpful for debugging purposes to track object lifetime.
 * The 'delete' operator is called in the 'main()' function.
 */
Zombie::~Zombie() {

	std::cout << "Destructor called for " << name << "!" << std::endl << std::endl;

}
