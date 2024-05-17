/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 21:35:50 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/18 01:24:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string _type;

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Animal( void );								//	Default constructor
	Animal( const Animal &source);				//	Copy constructor
	Animal &operator=( const Animal &source);	//	Operator assignment overload
	~Animal( void );							//	Default destructor

	/* --- Constructor overload --------------------------------------------- */

	Animal( const std::string &type );

	/* --- Accessors -------------------------------------------------------- */

	std::string	getType( void );
};

#endif