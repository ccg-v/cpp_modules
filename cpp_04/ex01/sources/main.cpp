/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 00:54:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

#define NUMBER_OF_ANIMALS 4

void	AnimalArrayTest() {

    Animal* Shelter[NUMBER_OF_ANIMALS]; // Create array of animal pointers
    Shelter[NUMBER_OF_ANIMALS - 1] = NULL;	// Set thelast pointer to NULL

	std::cout << std::endl 
			  << "/* --- Animal array test ------------------------------------------ */"
			  << std::endl;

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

void	BrainTest() {

	std::cout << std::endl 
			  << "/* --- Brain test ------------------------------------------------- */"
			  << std::endl << std::endl;;

	Dog *Tapon = new Dog();

	std::cout << std::endl << Tapon->getType() << " Tapon has " << Tapon->getBrain()->nbr_ideas 
			<< " ideas:" << std::endl << std::endl;
	for (int i = 0; i < Tapon->getBrain()->nbr_ideas; i++) {
		std::cout << Tapon->getBrain()->getIdea(i) << "\t"; 
	}
	std::cout << std::endl;
	std::cout << std::endl << "Let's teach him a bit..." << std::endl;
	Tapon->getBrain()->setIdea(0, "have to be a good boy if I want a treat");
	Tapon->getBrain()->setIdea(1, "don't have to ask for food when humans are eating");
	Tapon->getBrain()->setIdea(2, "must not eat everything I find on the ground");
	std::cout << "See if he learned something." << std::endl;
	std::cout << "I " << Tapon->getBrain()->getIdea(0) << std::endl;
	std::cout << "I "  << Tapon->getBrain()->getIdea(1) << std::endl;
	std::cout << "I "  << Tapon->getBrain()->getIdea(2) << std::endl;
}

void testCopyCat(void)
{
	std::cout <<  "-------------------------------" << std::endl
		<< "\tCOPY CAT TEST" << std::endl
		<<  "-------------------------------" << std::endl << std::endl
		<< "-- Creating \"Norminet\" cat." << std::endl;
	Cat * norminet = new Cat();

	std::cout << std::endl << "-- Putting ideas in Norminet's brain..." << std::endl;
	norminet->getBrain()->setIdea(0, "I think I have a hairball...");
	norminet->getBrain()->setIdea(1, "I need to cough the hairball up...");
	norminet->getBrain()->setIdea(2, "Human, clean that up, will you?");

	std::cout << "Norminet idea 0: \"" << norminet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Norminet idea 1: \"" << norminet->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Norminet idea 2: \"" << norminet->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Creating a copy of \"Norminet\" cat" << std::endl;
	Cat * copyCat = new Cat(*norminet);

	std::cout << std::endl << "-- CopyCat should have the same ideas as Norminet." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Putting new ideas in Norminet's brain..." << std::endl;
	norminet->getBrain()->setIdea(0, "Where is that mouse??");
	norminet->getBrain()->setIdea(1, "I'm hungry.");
	norminet->getBrain()->setIdea(2, "I shall outsmart that mouse!");

	std::cout << "Norminet idea 0: \"" << norminet->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "Norminet idea 1: \"" << norminet->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "Norminet idea 2: \"" << norminet->getBrain()->getIdea(2) << "\"" << std::endl;
	
	std::cout << std::endl << "-- CopyCat's ideas should not have changed." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;

	std::cout << std::endl << "-- Setting CopyCat = Norminet." << std::endl;
	*copyCat = *norminet;

	std::cout << std::endl << "-- CopyCat's ideas should have changed to Norminet's." << std::endl;
	std::cout << "CopyCat idea0: \"" << copyCat->getBrain()->getIdea(0) << "\"" << std::endl;
	std::cout << "CopyCat idea1: \"" << copyCat->getBrain()->getIdea(1) << "\"" << std::endl;
	std::cout << "CopyCat idea2: \"" << copyCat->getBrain()->getIdea(2) << "\"" << std::endl;


	std::cout << std::endl << "-- Deleting Norminet and CopyCat." << std::endl;
	delete norminet;
	delete copyCat;
	std::cout << std::endl;
}

int	main( void ) {
	AnimalArrayTest();
	BrainTest();
	// testCopyCat();
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

