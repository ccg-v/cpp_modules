/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:51:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 11:52:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
Serializer::Serializer() {}

//	Copy constructor
Serializer::Serializer(const Serializer & source) {
	(void)source;	// To avoid unused parameter warning
}

//	Copy assignment operator
Serializer &Serializer::operator=(const Serializer & source) {
	(void)source;
	return (*this);
}

//	Default destructor
Serializer::~Serializer() {}

/* --- Public member methods ------------------------------------------------ */

uintptr_t Serializer::serialize(Data* ptr) {
	
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return raw;
}

Data* Serializer::deserialize(uintptr_t raw) {

	Data* ptr = reinterpret_cast<Data *>(raw);
	return ptr;
}

/* --- Free-standing (non member) functions --------------------------------- */

//	Operator assignment overload (1)
std::ostream & operator<<(std::ostream & os, const Data & obj) {
	os << "\tPointer to data is " << &obj << "\n"
	   << "\tValues stored in data and their addresses are:\n" 
	   << "\t - " << obj.num << " | " << &obj.num << "\n" 
	   << "\t - " << obj.str << " | " << &obj.str << "\n"
	   << std::endl;
	return os;
}

/*
 *	(1)	In C++, overloading the insertion operator (<<) allows you to define 
 *		how a custom data type (like your Data struct) should be output when
 *		used with an output stream (like std::cout). It gives you control 
 *		over how the object’s data is printed.
 */