/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:31:19 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/22 18:30:00 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {

private:
	Brain	*_brain;	//	(1)

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Cat( void );						//	Default constructor
	Cat( const Cat &source);			//	Copy constructor
	Cat &operator=( const Cat &source);	//	Operator assignment overload
	~Cat( void );						//	Default destructor

	/* --- Accessors -------------------------------------------------------- */

	Brain	*getBrain( void ) const;

	/* --- Methods ---------------------------------------------------------- */
	
	void	makeSound( void ) const;

};

#endif

/*
 *	(1)	A pointer to 'Brain' to provide the cat his own brain when constructed.
 *		The pointer will allow for dynamic memory allocation when a 'Cat' object
 *		is constructed.
 *		
 *		It's also possible to declare '_brain' as a non-pointer member of the 'Cat'
 *		class. However, in this case, each 'Cat' object would contain its own Brain
 *		object directly within its memory footprint, rather than just a pointer to 
 *		a Brain object.
 *
 *		This approach has some implications:
 *
 *			1. Memory Usage: Each Cat object will have its own Brain object, which
 *				could potentially increase the memory usage if the Brain object is 
 *				large or if there are many Cat objects.
 *
 * 			2. Object Lifetime: The Brain object will be constructed and destroyed 
 * 				along with each Cat object. This means that the lifetime of the 
 * 				Brain object is tied to the lifetime of the Cat object. If you copy 
 * 				or destroy a Cat object, its Brain object will also be copied or 
 * 				destroyed.
 * 
 * 			3. Initialization: The Brain object will be initialized using its 
 * 				default constructor when a Cat object is constructed. If you need 
 * 				to initialize the Brain object with specific values or behavior, 
 * 				you'll need to provide appropriate constructors or initialization 
 * 				methods in the Brain class.
 * 
 *		So, while it's possible to declare _brain as a non-pointer member of the Cat
 *		class, you should carefully consider the implications in terms of memory
 *		usage, object lifetime, and initialization requirements. Using a pointer to 
 *		Brain allows for more flexibility in managing the lifetime and behavior of 
 *		the Brain object.
 */