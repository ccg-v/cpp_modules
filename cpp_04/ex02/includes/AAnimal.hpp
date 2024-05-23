/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:35:50 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 20:26:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class AAnimal
{
protected:
	std::string _type;

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	AAnimal( void );								//	Default constructor
	AAnimal( const AAnimal &source);				//	Copy constructor
	AAnimal &operator=( const AAnimal &source );	//	Operator assignment overload
	virtual ~AAnimal( void );						//	Default destructor

	
	/* --- Constructor overload --------------------------------------------- */

	AAnimal( const std::string &type );

	/* --- Accessors -------------------------------------------------------- */

	std::string	getType( void ) const;

	/* --- Methods ---------------------------------------------------------- */

	virtual void	makeSound( void ) const = 0;	//	(1)
};

#endif

/*	(1)	Marking a method as virtual allows derived classes to override it, but 
 *		it does not force them to provide an implementation. A virtual method 
 *		in a base class can have a default implementation, and derived classes 
 *		can choose to use that implementation or override it with their own.
 
 *		On the other hand, making a method as pure virtual
 *
 *					virtual void method() = 0;
 *		
 *		enforces that all derived classes must provide their own implementation.
 *		This makes the base class abstract and non-instantiable.
 *		
 *		There are many ways to turn a class abstract:
 *			-	Using a pure virtual destructor
 *			-	Deleting the constructor
 *			-	Making the constructor private
 *			-	Using a static assert
 */		