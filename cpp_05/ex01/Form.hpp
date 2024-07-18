/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:21:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/19 00:18:11 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

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

		Form ( const std::string formName, const int gradeToSign,
			const int gradeToExecute );			//	Parameterized constructor

		/* --- Accessors ---------------------------------------------------- */

		//	Getters
		const std::string	getFormName () const;
		int					getGradeToSign () const;
		int					getGradeToExecute() const;

		/* --- Member functions --------------------------------------------- */	

		void	beSigned ( Bureaucrat bureaucrat );
		void	signForm ();

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
std::ostream& operator<<(std::ostream& os, const Bureaucrat&b, const Form& f);

#endif