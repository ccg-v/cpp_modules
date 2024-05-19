/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 00:45:23 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/19 14:27:34 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"

// int	main( void ) {
	
// 	Animal	defaultAnimal;
// 	Animal a("Tapon");
// 	std::string bark;	

// 	bark = "Bup bup";
// 	std::cout << "Default animal name is " << defaultAnimal.getType() << std::endl;
// 	std::cout << "Dog's name is " << a.getType() << std::endl;
// 	a.makeSound(bark);
// 	return 0;
// }

int	main( void ) {
	const Animal* meta = new Animal(); 
	const Animal* j = new Dog();
	// const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl; 
	// std::cout << i->getType() << " " << std::endl; 
	j->makeSound("Cri cri cri"); //will output the cat sound! j->makeSound();
	meta->makeSound("Oink oink");

	return 0;
}