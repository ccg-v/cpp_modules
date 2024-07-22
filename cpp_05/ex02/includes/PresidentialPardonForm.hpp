/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:24:59 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/22 22:51:43 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class	PresidentialPardonForm : public AForm {

	private:

		std::string	_target;

	private:

		/* --- Orthodox Canonical Form -------------------------------------- */

		//	Default constructor
		PresidentialPardonForm();
		//	Copy constructor
		PresidentialPardonForm(const PresidentialPardonForm& source);
		//	Copy assignment operator
		PresidentialPardonForm& operator=(const PresidentialPardonForm& source);
		//	Default destructor
		~PresidentialPardonForm();

		//	Parameterized constructor
		PresidentialPardonForm( const std::string & target);

		/* --- Member functions --------------------------------------------- */

		void	execute(Bureaucrat const & executor) const;
};

#endif
