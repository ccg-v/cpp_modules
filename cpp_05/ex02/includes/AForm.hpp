/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:21:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/21 20:21:12 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	In this exercise, the abstract base class (AForm) ensures that all forms 
 *	(ShrubberyCreationForm, RobotomyRequestForm, and PresidentialPardonForm)
 *	implement the execute method. This provides a clear contract that any 
 *	concrete form must follow, thus enabling polymorphism and ensuring
 *	consistency in how forms are handled.
 */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

class	Bureaucrat;	//	(1)

class	AForm {

	private:

		const std::string	_formName;
		bool 				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public:
		/* --- Orthodox Canonical Form -------------------------------------- */

		AForm ( );									//	Default constructor
		AForm ( const AForm& source );				//	Copy constructor
		AForm &operator=( const AForm& source );	//	Copy assignment operator
		~AForm ( );									//	Default destructor
		AForm ( const std::string& formName, const int gradeToSign,
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

    	class IsAlreadySignedException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};			
};

/* --- Non-member functions ------------------------------------------------- */

//	Insertion operator (<<) overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

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