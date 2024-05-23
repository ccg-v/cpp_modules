/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:31:19 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 19:27:01 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {

private:
	Brain	*_brain;	//	(1)

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Dog( void );						//	Default constructor
	Dog( const Dog &source);			//	Copy constructor
	Dog &operator=( const Dog &source);	//	Operator assignment overload
	virtual ~Dog( void );						//	Default destructor

	/* --- Accessors -------------------------------------------------------- */

	Brain	*getBrain( void ) const;

	/* --- Methods ---------------------------------------------------------- */
	
	void	makeSound( void ) const;

};

#endif

/*
 *	(1)	A pointer to 'Brain' to provide the dog his own brain when constructed.
 *		The pointer will allow for dynamic memory allocation when a 'Dog' object
 *		is constructed.
 *
 *		It's also possible to declare '_brain' as a non-pointer member of the 'Dog'
 *		class. However, in this case, each 'Dog' object would contain its own Brain
 *		object directly within its memory footprint, rather than just a pointer to 
 *		a Brain object.
 *
 *		This approach has some implications:
 *
 *			1. Memory Usage: Each Dog object will have its own Brain object, which
 *				could potentially increase the memory usage if the Brain object is 
 *				large or if there are many Dog objects.
 *
 * 			2. Object Lifetime: The Brain object will be constructed and destroyed 
 * 				along with each Dog object. This means that the lifetime of the 
 * 				Brain object is tied to the lifetime of the Dog object. If you copy 
 * 				or destroy a Dog object, its Brain object will also be copied or 
 * 				destroyed.
 * 
 * 			3. Initialization: The Brain object will be initialized using its 
 * 				default constructor when a Dog object is constructed. If you need 
 * 				to initialize the Brain object with specific values or behavior, 
 * 				you'll need to provide appropriate constructors or initialization 
 * 				methods in the Brain class.
 * 
 *		So, while it's possible to declare _brain as a non-pointer member of the Dog
 *		class, you should carefully consider the implications in terms of memory
 *		usage, object lifetime, and initialization requirements. Using a pointer to 
 *		Brain allows for more flexibility in managing the lifetime and behavior of 
 *		the Brain object.
 */