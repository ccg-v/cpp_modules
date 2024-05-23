/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 21:24:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

/*	
 * 	The program won't compile because 'AnimalAbstractTest()' function is trying 
 *	to instantiate an abstract class, which is not possible at all.
 *	To compile, comment the 'AnimalAbstractTest()' function and the call to the
 *	function in the main() 
 */

#define NUMBER_OF_ANIMALS 4

void	AnimalArrayTest();
void	DeepCopyTest();
void	AnimalAbstractTest(void);

int	main( void ) {
	AnimalAbstractTest();	//	<- Comment to compile!
	AnimalArrayTest();
	DeepCopyTest();
}

void	AnimalAbstractTest(void)	// <- Comment to compile!
{
	AAnimal * Unknown = new AAnimal();
	Unknown->makeSound();
	delete Unknown;
}

void	AnimalArrayTest() {

    AAnimal* animalsArray[NUMBER_OF_ANIMALS]; // Create array of animal pointers
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

void	DeepCopyTest() {

	std::cout << std::endl 
			  << "/* --- Deep Copy test --------------------------------------------- */"
			  << std::endl << std::endl;;

	std::cout << std::endl << "Creating a new object..." << std::endl << std::endl;	

	Dog *Tapon = new Dog();

	std::cout << std::endl << Tapon->getType() << " Tapon has been created with " 
			<< Tapon->getBrain()->nbr_ideas << " ideas in his brain:" 
			<< std::endl << std::endl;
	for (int i = 0; i < Tapon->getBrain()->nbr_ideas; i++) {
		std::cout << Tapon->getBrain()->getIdea(i) << "\t"; 
	}
	std::cout << std::endl;
	std::cout << std::endl << "Let's train him a bit and see what he learned: " << std::endl;
	Tapon->getBrain()->setIdea(0, "Sit? Why should I?.");
	Tapon->getBrain()->setIdea(1, "Away, away? What do you mean?.");
	Tapon->getBrain()->setIdea(2, "Leave it? It's mine! I found it!!.");
	displayIdeas( Tapon );

	std::cout << std::endl << "Make a copy of Tapon to check that the ideas are inherited: "
			  << std::endl << std::endl;
	Dog *TaponCopy = new Dog(*Tapon);
	displayIdeas( TaponCopy );

	std::cout << std::endl;
	std::cout << std::endl << "Some more training for Tapon and see if he improves: " << std::endl;
	Tapon->getBrain()->setIdea(0, "I have to obey if I want that treat.");
	Tapon->getBrain()->setIdea(1, "I don't have to disturb humans when they are eating.");
	Tapon->getBrain()->setIdea(2, "I must not take everything I find on the ground.");	
	displayIdeas( Tapon );

	std::cout << std::endl;
	std::cout << std::endl << "Check that the ideas of the copy haven't changed: " << std::endl;
	displayIdeas( TaponCopy );

	std::cout << std::endl;
	std::cout << std::endl << "Delete objects: " << std::endl;
	delete Tapon;
	delete TaponCopy;

}

/*
 *	A Dog (or a Cat) can be created as an Animal:
 *
 *		const Animal *Undefined = new Animal(); 
 *		const Animal *Tapon = new Dog();
 *
 *	and it's members have to be called as usual:
 *
 * 		std::cout << Moon->getType() << " Moon's first idea is " << Moon->getBrain()->getIdea(0)
 *			  	  << std::endl;
 *
 * 	But a Dog can also be straigthly instantiated:
 *
 *		Dog *Tapon = new Dog();
 *
 * 	In this case, to access its members we will need to downcast the object to tell the compiler
 * 	which Animal are we talking about:
 * 
 * 		std::cout << dynamic_cast<const Dog *>(Sun)->getType() << " Sun's first idea is " 
 * 				  << dynamic_cast<const Dog *>(Sun)->getBrain()->getIdea(0)
 * 				  << std::endl;
 * 
 * 	Anyway, it's generally preferable to design your classes and interfaces in such a way that 
 * 	you don't need to perform dynamic casts.
 */

