/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/07 12:00:05 by ccarrace          #+#    #+#             */
/*   Updated: 2024/04/07 14:26:37 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void) {

	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout << "MEMORY ADDRESS:" << std::endl;
	std::cout << " - of the string variable:\t" << &string << std::endl;
	std::cout << " - held by 'stringPTR':\t\t" << stringPTR << std::endl;
	std::cout << " - held by 'stringREF':\t\t" << &stringREF << std::endl;
	std::cout << "VALUE:" << std::endl;
	std::cout << " - of the string variable:\t" << string << std::endl;
	std::cout << " - pointed to by 'stringPTR':\t" << *stringPTR << std::endl;
	std::cout << " - pointed to by 'stringREF':\t" << stringREF << std::endl;

	return 0;
}

/* References
 * 
 *	Can be defined as an alias for an existing value or, more accurately, as a
 *	pointer that is constant and can never be unreferenced or null (void).
 *	 -> A reference is always pointing to the same item
 *	 -> Thus, we can't declare an uninitialized reference pointing on nothing
 *	 -> Also because it is constant, it cannot be initialized to null or whatever
 *		expecting that it will be reassigned to point on somewehere else later. 
 *	A reference is like a dereferenced pointer. It does not need to be dereferenced,
 *	it always is.
 */