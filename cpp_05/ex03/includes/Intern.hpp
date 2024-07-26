/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:35:18 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/26 23:12:15 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:

		static const std::string	formNamesArray[];
		static	AForm*				(*formFunctionsArray[])(const std::string &); // (1)

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Intern();									//	Default constructor
		Intern(const Intern & source);				//	Copy constructor
		Intern &operator=(const Intern & source);	//	Copy assignment operator
		~Intern();									//	Default destructor

		/* --- Member methods ----------------------------------------------- */

		AForm* makeForm(const std::string & formName, const std::string & target);
};


// Form creation functions declarations

AForm*	createShrubberyForm(const std::string& target);
AForm*	createRobotomyForm(const std::string& target);
AForm*	createPardonForm(const std::string& target);

// Insertion operator (<<) overload

std::ostream& operator<<(std::ostream& os, const Intern& intern);

#endif

/*
 *	(1)	- As a static member of the Intern class, it will be initialized once and
 *			shared among all instances fo the class instead of being tied to a
 *			specific instance
 *
 *		- '(const std::string &)' indicates that the functions pointed to by the
 *			elements in the 'formCreators' array take a single parameter of type
 *			'const std::string &)'
 */