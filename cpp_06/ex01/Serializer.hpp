/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 20:54:34 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 11:52:38 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <stdint.h>	// uintptr_t
# include "Data.hpp"

class	Serializer
{

private:

	/* --- Orthodox Canonical Form ------------------------------------------ */

	Serializer();										// Default constructor
	Serializer(const Serializer & source);				// Copy constructor
	Serializer & operator=(const Serializer & source);	// Copy assignment operator
	~Serializer();

public:
	/* --- Public member methods ------------------------------------------- */

	static uintptr_t	serialize(Data* ptr);
	static Data*		deserialize(uintptr_t raw);
};

//	Operator assignment overload (1)
std::ostream & operator<<(std::ostream & stream, const Data & obj); 

#endif

/*
 *	(1)	In C++, overloading the insertion operator (<<) allows you to define 
 *		how a custom data type (like your Data struct) should be output when
 *		used with an output stream (like std::cout). It gives you control 
 *		over how the object’s data is printed.
 */