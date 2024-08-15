/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 13:07:41 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 13:53:42 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
# define BASE_HPP

# include <iostream>

class Base {

public:

	// Default destructor (1)
	virtual ~Base();
	
	/* --- Public methods --------------------------------------------------- */

	Base *	generate(void);
	void	identify(Base * p);
	void	identify(Base & p);
};

#endif

/*
 *	(1)	Since Base is intended to be a base class that other classes derive from,
 *		and pointers of type Base* are expected to delete derived objects, the
 *		destructor must be public and virtual.
 *		This is critical because without a public virtual destructor, when you 
 *		delete a derived object through a Base* pointer, the destructor of the 
 *		derived class might not be called, leading to resource leaks.
 */