/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:51:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/23 20:28:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include "AAnimal.hpp"

class Brain {
	
public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	//	Default constructor
	Brain( void );							//	Default constructor
	Brain( const Brain &source);			//	Copy constructor
	Brain &operator=( const Brain &source);	//	Operator assignment overload
	~Brain( void );							//	Default destructor

	/* --- Accessors -------------------------------------------------------- */

	std::string	const 	&getIdea( int index ) const;
	void				setIdea( int index, std::string const &idea);

	/* --- Static members --------------------------------------------------- */

	static int const	nbr_ideas = 100;

private:

	std::string	_ideas[nbr_ideas];
};

#endif