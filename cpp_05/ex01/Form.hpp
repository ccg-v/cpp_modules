/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:21:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/19 23:55:56 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
// # include "Bureaucrat.hpp"	//	(1)

class	Bureaucrat;

class	Form {

	private:

		const std::string	_formName;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		/* --- Orthodox Canonical Form -------------------------------------- */

		Form ( );								//	Default constructor
		Form ( const Form& source );			//	Copy constructor
		Form &operator=( const Form& source );	//	Copy assignment operator
		~Form ( );								//	Default destructor

		Form ( const std::string& formName, const int gradeToSign,
			const int gradeToExecute );			//	Parameterized constructor

		/* --- Accessors ---------------------------------------------------- */

		//	Getters
		const std::string&	getFormName () const;
		bool				getIsSigned () const;
		int					getGradeToSign () const;
		int					getGradeToExecute() const;

		/* --- Member functions --------------------------------------------- */	

		void	beSigned ( Bureaucrat bureaucrat );

		//	Exceptions (3)
    	class GradeTooHighException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};

    	class GradeTooLowException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};				
};

/* --- Non-member functions ------------------------------------------------- */

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

/*
 *	(1) Unlike Bureaucrat.hpp, where adding a forward declaration of Form.hpp
 *		was enough, here we need to include the full definition of the class
 *		because the forward declaration only tells the compiler that Bureaucrat
 *		is a class but it doesn't provide the full definition needed to use its
 *		methods. 
 */