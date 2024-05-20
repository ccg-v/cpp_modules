/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:35:50 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 11:44:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
protected:
	std::string _type;

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	WrongAnimal( void );									//	Default constructor
	WrongAnimal( const WrongAnimal &source);				//	Copy constructor
	WrongAnimal &operator=( const WrongAnimal &source );	//	Operator assignment overload
	virtual ~WrongAnimal( void );							//	Default destructor	(2)

	
	/* --- Constructor overload --------------------------------------------- */

	WrongAnimal( const std::string &type );

	/* --- Accessors -------------------------------------------------------- */

	std::string	getType( void ) const;

	/* --- Methods ---------------------------------------------------------- */

	void	makeSound( void ) const;	//	(1)
};

#endif

/*	(1)	In this case the function is 'non-virtual'. This means any derived
 *		class will inherit the base's function implementation, losing any
 *		chance to override it. However,... (read (2))
 *
 * 	(2)	...we still set the class default destructor as 'virtual' to ensure
 * 		proper cleanup of derived class objects when deleted through base 
 * 		class pointers. Thanks to this 'virtual' destructor in the base class,
 * 		the 'delete' statement in the main file will call the derived class
 * 		destructor first, followed by the base clas destructor.
 */