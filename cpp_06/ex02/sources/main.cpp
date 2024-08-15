/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 19:17:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 22:38:33 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <ctime>   // std::time()

int	main(void) {
	Base *	random_obj = NULL;
	
	std::srand(std::time(0));	// (1)
	random_obj = generate();

	/* --- Identifying the Type Using a Pointer (identify(Base * p)) -------- */

	std::cout << "\n/* --- Identifying the Type Using a Pointer "
			  << "(identify(Base * p)) ---------------------- */"
			  << std::endl;

	identify(random_obj);

	/* --- Identifying the Type Using a Reference (identify(Base * p)) ------ */

	std::cout << "/* --- Identifying the Type Using a Reference "
			  << "(identify(Base & p)) -------------------- */"
			  << std::endl;

	identify(*random_obj);

	delete random_obj;
	
	return 0;
}

/*
 *	(1)	I was initially calling 'std::srand(std::time(0))' inside the generate()
 *		function every time the function called. This was causing the seed to be
 *		reset each time you call the function, leading to poor randomness (often
 *		the same result repeatedly).
 *
 *		It’s better to call 'std::srand(std::time(0))' only once at the start of
 *		the program, typically in main(). Then 'std::rand()' can be called freely
 *		in the generate() function without reseeding every time.
 */