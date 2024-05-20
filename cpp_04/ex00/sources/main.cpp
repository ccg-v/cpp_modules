/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 02:23:19 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main( void ) {
	std::cout << "Creating Animal objects:" << std::endl;
	const Animal *a = new Animal(); 
	const Animal *b = new Dog();
	const Animal *c = new Cat();

	std::cout << std::endl << "Testing Animal objects:" << std::endl;
	a->makeSound();	// will output the default animal sound
	b->makeSound();	// will output the dog sound
	c->makeSound();	// will output the cat sound

	std::cout << std::endl << "Deleting Animal objects:" << std::endl;
	delete a;
	delete b;
	delete c;

	std::cout << std::endl << "Creating WrongAnimal objects:" << std::endl;
	const WrongAnimal *d = new WrongAnimal();
	const WrongAnimal *e = new WrongCat();

	std::cout << std::endl << "Testing WrongAnimal objects:" << std::endl;
	d->makeSound(); // will output the default wrong animal sound
	e->makeSound();	// won't output the wrong cat sound, but the wrong animal sound!

	std::cout << std::endl << "Deleting WrongAnimal objects:" << std::endl;
	delete d;
	delete e;

	return 0;
}

// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "WrongCat.hpp"

// int	main( void ) {
// 	const	Animal *a = new Animal(); 
// 	const	Animal *b = new Dog();
// 	const	Animal *c = new Cat();
// 	const	WrongAnimal *d = new WrongAnimal();
// 	const	WrongAnimal *e = new WrongCat();

// 	a->makeSound();	// 	will output the default animal sound
// 	b->makeSound();	//	will output the dog sound
// 	c->makeSound();	//	will output the cat sound
// 	std::cout << std::endl;
// 	d->makeSound(); // 	will output the default wrong animal sound
// 	e->makeSound();	//	won't output the wrong cat sound, but the wrong animal sound!

// 	delete e;
// 	delete d;
// 	delete c;
// 	delete b;
// 	delete a;

// 	return 0;
// }

// #include "Dog.hpp"
// #include "Cat.hpp"
// #include "WrongCat.hpp"

// // Color codes
// const std::string RESET = "\033[0m";
// const std::string RED = "\033[31m";
// const std::string GREEN = "\033[32m";
// const std::string YELLOW = "\033[33m";

// int	main(void) {
// 	std::cout << std::endl << YELLOW << "Creating Animal class:" << RESET << std::endl << std::endl;
// 	const	Animal* meta = new Animal();
// 	const	Animal* j = new Dog();
// 	const	Animal* i = new Cat();
	
// 	std::cout << std::endl << YELLOW << "Testing Animal class:" << RESET << std::endl << std::endl;
// 	std::cout << "Animal of type " << j->getType() << " created" << std::endl;
// 	std::cout << "Animal of type " << i->getType() << " created" << std::endl;
// 	i->makeSound(); //will output the cat sound!
// 	j->makeSound(); //will output the dog sound!
// 	meta->makeSound();

// 	std::cout << std::endl << YELLOW << "Cleaning Animal objects:" << RESET << std::endl << std::endl;
// 	delete meta;
// 	delete j;
// 	delete i;

// 	std::cout << std::endl << YELLOW << "Creating WrongAnimal class:" << RESET << std::endl << std::endl;
// 	const	WrongAnimal* gama = new WrongAnimal();
// 	const	WrongAnimal* k = new WrongCat();

// 	std::cout << std::endl << YELLOW << "Testing WrongAnimal class:" << RESET << std::endl << std::endl;
// 	std::cout << "Animal of type " << k->getType() << " created" << std::endl;
// 	k->makeSound(); //will output the wrong cat sound!
// 	gama->makeSound();

// 	std::cout << std::endl << YELLOW << "Cleaning WrongAnimal objects:" << RESET << std::endl << std::endl;

// 	delete gama;
// 	delete k;
// 	return (0);
// }
