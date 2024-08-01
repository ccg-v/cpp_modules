/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:25:04 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/30 23:29:50 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private:
	
		std::string _target;

		//	Static member variables for tree designs (1)
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

/*
 *	(1)	Making the tree designs static ensures that these large, constant strings
 *		are stored efficiently and shared across all instances of the class, 
 *		maintaining data integrity and reducing memory usage.
 *
 *		Static member variables in a class are initialized before any objects of 
 *		the class are created and are stored in a fixed location in memory. This
 *		means that the tree designs are stored in their static variables when the 
 *		program is compiled, and they are available before any instance of
 *		ShrubberyCreationForm is created.
 */