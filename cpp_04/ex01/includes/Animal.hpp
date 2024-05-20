/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:35:50 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 20:57:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal
{
protected:
	std::string _type;

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Animal( void );								//	Default constructor
	Animal( const Animal &source);				//	Copy constructor
	Animal &operator=( const Animal &source );	//	Operator assignment overload
	virtual ~Animal( void );					//	Default destructor	(2)

	
	/* --- Constructor overload --------------------------------------------- */

	Animal( const std::string &type );

	/* --- Accessors -------------------------------------------------------- */

	std::string	getType( void ) const;

	/* --- Methods ---------------------------------------------------------- */

	virtual void	makeSound( void ) const;	//	(1)
};

#endif

/*	(1)	Declaring the function as 'virtual' makes the class an 'abstract class'.
 *		This will require derived classes to provide their own implementation of
 *		the function (derived classes will have to override the virtual methods)
 *
 * 	(2)	Declaring the base class destructor as 'virtual' allows to delete derived
 * 		class objects through base class pointers and do proper clean up. If we
 * 		don't set it as 'virtual', the derived class destructor will not be called,
 * 		thus the object will not be properly cleaned.
 */