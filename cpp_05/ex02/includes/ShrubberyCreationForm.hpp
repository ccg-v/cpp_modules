/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:25:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/23 21:17:07 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
	
		std::string _target;

		//	Static member variables for tree designs
		static const	std::string _tree1;
		static const	std::string _tree2;
		static const	std::string _tree3;

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		// Default constructor
		ShrubberyCreationForm();
		// Copy constructor
		ShrubberyCreationForm(const ShrubberyCreationForm& source);
		// Copy assignment operator
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& source);
		// Default destructor
		~ShrubberyCreationForm();

		// Parameterized constructor
		ShrubberyCreationForm(const std::string& target);
	
	protected:

		/* --- Member functions --------------------------------------------- */
	
		void	performAction() const;
};

#endif
