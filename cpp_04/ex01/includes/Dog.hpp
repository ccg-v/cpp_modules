/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:31:19 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/19 21:28:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class	Dog : public Animal {

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Dog( void );						//	Default constructor
	Dog( const Dog &source);			//	Copy constructor
	Dog &operator=( const Dog &source);	//	Operator assignment overload
	~Dog( void );						//	Default destructor

	/* --- Constructor overload --------------------------------------------- */

	// Dog( const std::string &type );

	/* --- Methods ---------------------------------------------------------- */
	void	makeSound( void ) const;

};

#endif