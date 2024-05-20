/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 12:51:58 by ccarrace          #+#    #+#             */
/*   Updated: 2024/05/20 13:41:45 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>

class Brain {

public:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	//	Default constructor
	Brain( void );							//	Default constructor
	Brain( const Brain &source);			//	Copy constructor
	Brain &operator=( const Brain &source)	//	Operator assignment overload
	~Brain( void );							//	Default destructor

	/* --- Constructor overload -------------------------------------------- */
	
	// Brain( )

private:
	std::string	_ideas[100];

};

#endif