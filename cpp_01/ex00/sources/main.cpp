/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:22:20 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/03 20:47:55 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void) {

	// Create a Zombie object dynamically on the heap using 'newZombie()' and
	// assign it to a pointer 'heapZombie'
	Zombie *heapZombie = newZombie("heap_zombie");
	
	// Call the 'announce()' member function on the 'heapZombie' object 
	heapZombie->announce();
	// Deallocate heap memory. Deleting 'heapZombie' implicitily calls the
	// object's destructor, thus message 'Destructor called...' will be printed
	delete heapZombie;
	
	// Create a temporary Zombie object on the stack using randomChump()
	randomChump("stack_zombie");
	
	return 0;
	
}