/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 12:31:19 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 00:19:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal {

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	Cat( void );						//	Default constructor
	Cat( const Cat &source);			//	Copy constructor
	Cat &operator=( const Cat &source);	//	Operator assignment overload
	~Cat( void );						//	Default destructor

	/* --- Constructor overload --------------------------------------------- */

	// Cat( const std::string &type );

	/* --- Methods ---------------------------------------------------------- */
	void	makeSound( void ) const;

};

#endif