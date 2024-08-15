/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:07:41 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 22:36:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <cstdlib>	// std::rand() in Base.cpp and main.cpp

class Base {

public:

	// Default destructor (1)
	virtual ~Base();
};

	/* --- Non member methods ---------------------------------------------- */

	Base *	generate(void);		// (2)
	void	identify(Base * p);	// (2)
	void	identify(Base & p);	// (2)

#endif

/*
 *	(1)	Since Base is intended to be a base class that other classes derive from,
 *		and pointers of type Base* are expected to delete derived objects, the
 *		destructor must be public and virtual.
 *		This is critical because without a public virtual destructor, when you 
 *		delete a derived object through a Base* pointer, the destructor of the 
 *		derived class might not be called, leading to resource leaks.
 */

/*
 *	(2)	- If I want these functions to be 'Base' class member methods, an
 * 			instance of 'Base' is needed to call it on. 
 *		- If I want to call these functions without needing an instance, they
 *			should be declared 'static'. 
 *
 *		Conceptually, these functions are more utility functions that don't 
 *		depend on any instance data, so making them 'static' or leaving them
 *		as non-member  functions should be more appropriate.
 *
 *		The best design is moving them outside the class as non-member functions
 *		because they are utility functions related to the class hierarchy, not
 *		specific to any 'Base' object.
 */