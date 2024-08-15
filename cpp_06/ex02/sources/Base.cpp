/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:42:38 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 14:27:52 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include <cstdlib>	// std::rand()
#include <ctime>    // std::time()

// Default constructor
Base::~Base() {
	std::cout << "Base default constructor called" << std::endl;
}

/* --- Public member methods ------------------------------------------------ */

Base *	Base::generate(void) {
	std::srand(std::time(0));
	int	random_num = std::rand() % 3;
	if (random_num == 0)
		return (new A);
	else if (random_num == 1)
		return (new B);
	else
		return (new C);
}

void 	Base::identify(Base * p) {

}

void	Base::identify(Base & p) {

}