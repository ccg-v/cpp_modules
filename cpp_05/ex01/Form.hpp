/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:21:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/29 00:10:19 by ccarrace         ###   ########.fr       */
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

		//	Exceptions (2)
    	class GradeTooHighException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};

    	class GradeTooLowException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};

    	class IsAlreadySignedException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};			
};

/* --- Non-member functions ------------------------------------------------- */

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const Form& f);

#endif

/*
 *	(1) Including the Form.hpp header file in Bureaucrat.hpp is an alternative
 *		to adding a forward declaration, and it would indeed make the Form class 
 *		known to Bureaucrat. However, this approach can lead to circular 
 *		dependencies if Form.hpp also includes Bureaucrat.hpp. To avoid this 
 *		issue, the best practice is to use a forward declaration where possible,
 *		especially when you only need to declare a pointer or reference to a class.
 *
 *		Here's the rationale:
 *
 *		Forward Declaration:
 *			Use a forward declaration if you only need to refer to the class in
 *			your header file (e.g., for method parameters, return types, or member
 *			pointers/references). This avoids circular dependencies and can reduce
 *			compile times because it prevents unnecessary inclusion of headers.
 *
 *		Including Headers:
 *			Include the header file if you need the full definition of the class
 *			in the header file (e.g., for member variables that are objects of
 *			that class).
 *
 *		Given that signForm only needs a reference to Form, a forward declaration 
 *		is sufficient and preferable. However, if you include Form.hpp, you need
 *		to ensure it does not lead to circular dependencies.
 *
 * 		See opposite case in 'Bureaucrat.hpp' footnote (1).
 */

/*
 *	(2) All custom exceptions should be derived from std::exception or a class
 *		that itself derives from std::exception. This ensures that these exception
 *		can be caught using a catch block for std::exception.
 *
 *			try {
 *				// Some code that might throw your custom exceptions
 *			} catch (const std::exception& e) {
 *				// This will catch any exception derived from std::exception,
 *				// including custom ones
 *				std::cerr << "Exception caught: " << e.what() << std::endl;
 *			}
 *
 *		Custom exceptions  inherit from std::exception, which means they can be
 *		caught as std::exception& e, and they override the what() method to 
 *		provide custom error messages.
 */