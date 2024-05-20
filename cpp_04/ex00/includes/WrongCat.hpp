/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:31:19 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 01:29:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class	WrongCat : public WrongAnimal {

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	WrongCat( void );								//	Default constructor
	WrongCat( const WrongCat &source);				//	Copy constructor
	WrongCat &operator=( const WrongCat &source);	//	Operator assignment overload
	~WrongCat( void );								//	Default destructor

	/* --- Constructor overload --------------------------------------------- */

	// WrongCat( const std::string &type );

	/* --- Methods ---------------------------------------------------------- */
	void	makeSound( void ) const;

};

#endif