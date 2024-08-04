/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 20:58:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/04 22:27:42 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
{
	/* --- Orthodox Canonical Form implementation --------------------------- */

	// Default constructor
	ScalarConverter::ScalarConverter() {
		std::cout << "ScalarConverter default constructor called" << std::endl;
	}

	// Copy constructor
	ScalarConverter::ScalarConverter(const ScalarConverter & source) {
		std::cout << "ScalarConverter copy constructor called" << std::endl;
	}

	// Copy assignment operator
	ScalarConverter &ScalarConverter::operator=(const ScalarConverter & source)

}