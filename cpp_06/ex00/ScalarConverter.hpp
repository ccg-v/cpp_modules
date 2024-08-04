/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 19:44:52 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/04 20:14:46 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>

class ScalarConverter
{

private:
	/* --- Orthodox Canonical Form ------------------------------------------ */

	ScalarConverter();									// Default constructor
	ScalarConverter(const ScalarConverter & source);	// Copy constructor
	ScalarConverter & operator=(const ScalarConverter & source);	// Copy assignment operator
	~ScalarConverter();									// Default destructor

public:

};


#endif