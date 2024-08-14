/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 22:51:49 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/15 00:42:50 by ccarrace         ###   ########.fr       */
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