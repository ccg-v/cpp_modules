/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 12:30:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	std::cout << std::endl << "Creating Animal objects:" << std::endl << std::endl;
	const Animal *a = new Animal(); 
	const Animal *b = new Dog();
	const Animal *c = new Cat();

	std::cout << std::endl << "Testing Animal objects:" << std::endl << std::endl;
	a->makeSound();	// will output the default animal sound
	b->makeSound();	// will output the dog sound
	c->makeSound();	// will output the cat sound

	std::cout << std::endl << "Deleting Animal objects:" << std::endl << std::endl;
	delete c;	//	(1)
	delete b;
	delete a;

	std::cout << std::endl << "Creating WrongAnimal objects:" << std::endl << std::endl;
	const WrongAnimal *d = new WrongAnimal();
	const WrongAnimal *e = new WrongCat();

	std::cout << std::endl << "Testing WrongAnimal objects:" << std::endl << std::endl;
	d->makeSound(); // will output the default WrongAnimal sound
	e->makeSound();	// will ALSO output the default WrongAnimal sound
	std::cout << std::endl << "Deleting WrongAnimal objects:" << std::endl << std::endl;
	delete e;
	delete d;

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

