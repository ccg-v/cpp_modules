/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:42:38 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 23:16:12 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
// #include <cstdlib>	// std::rand()

// Default destructor
Base::~Base() {
	std::cout << "Base default destructor called" << std::endl;
}

/* --- Non member methods --------------------------------------------------- */

Base *	generate(void) {
	// std::srand(std::time(0));	// moved to the main,to improve randomness (1)
	int	random_num = std::rand() % 3;
	if (random_num == 0)
		return (new A);
	else if (random_num == 1)
		return (new B);
	else
		return (new C);
}

void 	identify(Base * p) {	// (2)
	
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "\tThe new object is type A\n" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "\tThe new object is type B\n" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "\tThe new object is type C\n" << std::endl;
}

void identify(Base& p) {	// (3)
    try {
        (void) dynamic_cast<A&>(p);
        std::cout << "\tThe new object is type A\n" << std::endl;
    } catch (const std::exception & e) {}

    try {
        (void) dynamic_cast<B&>(p);
        std::cout << "\tThe new object is type B\n" << std::endl;
    } catch (const std::exception & e) {}

    try {
        (void) dynamic_cast<C&>(p);
        std::cout << "\tThe new object is type C\n" << std::endl;
    } catch (const std::exception & e) {}
}

/*
 *	(1)	Calling 'std::srand(std::time(0))' inside the generate() function means 
 *		calling it every time the function is called. This causes the seed to be
 *		reset each time you call the function, leading to poor randomness (often
 *		the same result repeatedly).
 *
 *		It’s better to call 'std::srand(std::time(0))' only once at the start of
 *		the program, typically in main(). Then 'std::rand()' can be called freely
 *		in the generate() function without reseeding every time.
 */

/*
 *	(2) When you use `dynamic_cast` with pointers, 
 *		 -	if the cast is successful, it returns a pointer to the casted type
 *		 -	if the cast fails, it return NULL
 */

/*
 *	(3) When you use `dynamic_cast` with references, 
 *		 -	if the cast is successful, it returs a reference to the casted type
 *		 -	if the cast fails it throws a `std::bad_cast` exception. But
 *			`std::bad_cast` is not explicitly available in C++98 (only C++11
 *			and later) and cannot be caught directly so we must use 
 *			`std::exception`, a base class for all standard exceptions, as a 
 *			fallback to catch the `std::bad_cast` exception.
 */