/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/22 20:11:46 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER_OF_ANIMALS 4

void AnimalArray_test() {

    Animal* Shelter[NUMBER_OF_ANIMALS]; // Create array of animal pointers
    Shelter[NUMBER_OF_ANIMALS - 1] = NULL;	// Set thelast pointer to NULL

    std::cout << std::endl << "Filling the shelter with " << NUMBER_OF_ANIMALS 
			  << " animals..." << std::endl << std::endl;

    for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
        if (i < (NUMBER_OF_ANIMALS / 2))
            Shelter[i] = new Cat; // Create and assign a new Cat object
        else
            Shelter[i] = new Dog; // Create and assign a new Dog object
		Shelter[i]->makeSound();
		std::cout << std::endl;
	}
    std::cout << "The shelter is now full. Let's start emptying it..." << std::endl;

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
		std::cout << std::endl;
		delete Shelter[i];
	}
    std::cout << std::endl << "The shelter is now empty" << std::endl;	
}

int	main( void ) {
	AnimalArray_test();
}

// int	main( void ) {
// 	std::cout << std::endl << "Creating Animal objects:" << std::endl << std::endl;
// 	const Animal *Undefined = new Animal(); 
// 	const Animal *Sun = new Dog();
// 	Cat *Moon = new Cat();
	

// 	std::cout << std::endl << "Testing Animal objects:" << std::endl << std::endl;
// 	Undefined->makeSound();	// will output the default animal sound
// 	Moon->makeSound();	// will output the dog sound
// 	Sun->makeSound();	// will output the cat sound

// 	std::cout << Moon->getType() << " Moon's first idea is " << Moon->getBrain()->getIdea(0)
// 			  << std::endl;
// 	std::cout << dynamic_cast<const Dog *>(Sun)->getType() << " Sun's first idea is " 
// 			  << dynamic_cast<const Dog *>(Sun)->getBrain()->getIdea(0)
// 			  << std::endl;

// 	std::cout << std::endl << "Deleting Animal objects:" << std::endl << std::endl;
// 	delete Sun;	//	(1)
// 	delete Moon;
// 	delete Undefined;

// 	return 0;
// }

/*
 *	(1)	The best practice is to delete objects in the reverse order of their 
 *		creation:
 *
 *		- Dependency Management: If objects have dependencies (e.g., one object
 *			holds a pointer to another), deleting in reverse order ensures that
 *			dependent objects are deleted before the objects they depend on, 
 *			preventing access to invalid memory.
 *
 *		- Avoiding Dangling Pointers: By deleting in reverse order, you reduce 
 *			the risk of having pointers that reference already-deleted objects.
 */

