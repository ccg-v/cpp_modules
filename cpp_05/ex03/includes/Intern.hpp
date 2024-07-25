/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 21:35:18 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/25 23:25:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"

class Intern
{
	private:

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		Intern();											//	Default constructor
		Intern(const Intern & source);						//	Copy constructor
		Intern &operator=(const Intern & source);	//	Copy assignment operator
		~Intern();											//	Default destructor

		/* --- Member methods ----------------------------------------------- */

		AForm* makeForm(const std::string & formType, const std::string & target);
};

#endif
