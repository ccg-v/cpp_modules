/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:38:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/16 00:20:03 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <random>

class Bureaucrat {

	private:

		std::string const	_name;
		int					_grade;

	public:
		/* --- Orthodox Canonical Form -------------------------------------- */

		Bureaucrat ( void );								// Default constructor
		Bureaucrat ( const Bureaucrat& source );			// Copy constructor
		Bureaucrat& operator=( const Bureaucrat& source );	// Copy assignment operator
		~Bureaucrat ( void );								// Destructor

		/* --- Constructor overload ----------------------------------------- */
		

		/* --- Accessors ---------------------------------------------------- */
		
		//	Getters
		std::string	getName ( void ) const;	// (1)
		int			getGrade ( void ) const;

		//	Setters
		void		setName ( std::string name );
		void		setGrade ( int grade );

		/* --- Member functions --------------------------------------------- */
		
		void 	incrementGrade ( Bureaucrat _Bureaucrat );
		void	decrementGrade ( Bureaucrat _Bureaucrat );

		/* --- Exceptions --------------------------------------------------- */
		
		class	GradeTooHighException;
		class 	GradeTooLowException;
		
};

/* Non-member functions */

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif

/*
 *	(1)	The 'const' after the function declaration doesn't refer to whether the
 *		value can change or not.
 *
 * 			std::string	getName ( void ) const;
 *
 * 		- this declares a const member function that returns a string by value.
 * 		- the const means this function doesn't modify the object's state.
 * 		- this is the most common and generally correct way to declare a getter.
 *		
 *			std::string	const getName ( void );
 *
 *		- this declares a function that returns a const string by value.
 *		- the function itself is not const (it could potentially modify the 
 *			object's state).
 *		- the const here applies to the return value, making it a constant string.
 *
 *			const std::string getName ( void );
 *
 *		- this is functionally identical to #2. The placement of const before or
 *			after the return type doesn't change its meaning.
 *
 * 		For the Bureaucrat class we should use either
 * 
 * 			std::string getName() const;
 * 			const std::string& getName() const;
 * 
 * 		This ensures that:
 * 		1. The function doesn't modify the Bureaucrat object.
 * 		2. It properly reflects that getName is just accessing data, not changing 
 * 			anything.
 */