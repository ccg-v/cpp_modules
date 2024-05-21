/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/22 01:02:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int	countIdeas( std::string ideas_arr) {
	return sizeof(ideas_arr) / sizeof(ideas_arr[0]);
}


int	main( void ) {
	std::cout << std::endl << "Creating Animal objects:" << std::endl << std::endl;
	const Animal *a = new Animal(); 
	const Animal *b = new Dog();
	const Animal *c = new Cat();
	Cat *moon = new Cat();

	std::cout << std::endl << "Testing Animal objects:" << std::endl << std::endl;
	a->makeSound();	// will output the default animal sound
	b->makeSound();	// will output the dog sound
	c->makeSound();	// will output the cat sound

	std::cout << moon->getType() << " moon's first idea is " << moon->getBrain()->getIdea(0)
			  << std::endl;
	const Cat *cCat = dynamic_cast<const Cat *>(c);
	std::cout << cCat->getType() << " c's first idea is " << cCat->getBrain()->getIdea(1)
			  << std::endl;
	// std::cout << c->getType() << " c first idea is " << c->getBrain()->getIdea(0) << std::endl;

	std::cout << std::endl << "Deleting Animal objects:" << std::endl << std::endl;
	delete c;	//	(1)
	delete b;
	delete a;

	return 0;
}

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

