/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 14:30:15 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER_OF_ANIMALS 4

void	AnimalArrayTest() {

    Animal* animalsArray[NUMBER_OF_ANIMALS]; // Create array of animal pointers
    animalsArray[NUMBER_OF_ANIMALS - 1] = NULL;	// Set thelast pointer to NULL

	std::cout << std::endl 
			  << "/* --- Animal array test ------------------------------------------ */"
			  << std::endl;

    std::cout << std::endl << "Filling the array with " << NUMBER_OF_ANIMALS 
			  << " animals..." << std::endl << std::endl;

    for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
        if (i < (NUMBER_OF_ANIMALS / 2))
            animalsArray[i] = new Cat; // Create and assign a new Cat object
        else
            animalsArray[i] = new Dog; // Create and assign a new Dog object
		animalsArray[i]->makeSound();
		std::cout << std::endl;
	}
    std::cout << "The array of animals is now full. Let's start emptying it..." << std::endl;

	for (int i = 0; i < NUMBER_OF_ANIMALS; i++) {
		std::cout << std::endl;
		delete animalsArray[i];
	}
    std::cout << std::endl << "The array is now empty" << std::endl;	
}

void	displayIdeas( Dog *animalName ) {
	std::cout << std::endl;
	for (int i = 0; i < animalName->getBrain()->nbr_ideas; i++) {
		std::cout << animalName->getBrain()->getIdea(i) << "\t"; 
	}
	std::cout << std::endl;	
}

void	BrainTest() {

	std::cout << std::endl 
			  << "/* --- Brain test ------------------------------------------------- */"
			  << std::endl << std::endl;;

	Dog *Snoopy = new Dog();

	std::cout << std::endl << Snoopy->getType() << " Snoopy has " << Snoopy->getBrain()->nbr_ideas 
			<< " ideas in his brain:" << std::endl << std::endl;
	for (int i = 0; i < Snoopy->getBrain()->nbr_ideas; i++) {
		std::cout << Snoopy->getBrain()->getIdea(i) << "\t"; 
	}
	std::cout << std::endl;
	std::cout << std::endl << "Let's train him a bit and see what he learned: " << std::endl;
	Snoopy->getBrain()->setIdea(0, "Sit? Why should I?.");
	Snoopy->getBrain()->setIdea(1, "Away, away? What do you mean?.");
	Snoopy->getBrain()->setIdea(2, "Leave it? It's mine! I found it!!.");
	displayIdeas( Snoopy );

	std::cout << std::endl << "Make a copy of Snoopy to check that the ideas are inherited: "
			  << std::endl << std::endl;
	Dog *SnoopyCopy = new Dog(*Snoopy);
	displayIdeas( SnoopyCopy );

	std::cout << std::endl;
	std::cout << std::endl << "Some more training for Snoopy and see if he improves: " << std::endl;
	Snoopy->getBrain()->setIdea(0, "I have to obey if I want that treat.");
	Snoopy->getBrain()->setIdea(1, "I don't have to disturb humans when they are eating.");
	Snoopy->getBrain()->setIdea(2, "I must not take everything I find on the ground.");	
	displayIdeas( Snoopy );

	std::cout << std::endl;
	std::cout << std::endl << "Check that the ideas of the copy haven't changed: " << std::endl;
	displayIdeas( SnoopyCopy );
	
}

int	main( void ) {
	AnimalArrayTest();
	BrainTest();
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

