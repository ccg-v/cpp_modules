/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 22:21:03 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/30 19:23:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	AForm class must be abstract. This means that:
 *
 *		- 	It cannot be instantiated directly.
 *		- 	It is designed to be a base class.
 *		-	It typically contains at least one pure virtual function.
 *
 * 	Virtual Function:
 * 
 *		-	Declared with the keyword virtual.
 *		-	CAN BE OVERRIDEN IN DERIVED CLASSES.
 *		-	Enables polymorphism.
 *
 *	Pure Virtual Function:
 *
 *		-	Declared with virtual and assigned = 0.	<--- !!!
 *		-	MUST BE OVERRIDEN IN DERIVED CLASSES.
 *		-	Makes the class abstract.
 *
 *	Virtual Destructor in Base Class:
 *
 *		By declaring the destructor in the base class as virtual, it ensures that
 *		when delete is called on a pointer to the base class, the destructor of
 *		the derived class is also invoked. This allows for proper cleanup of
 *		resources allocated by the derived class.
 *		With a virtual destructor, the destructors are called in the correct order:
 *		first the derived class's destructor, then the base class's destructor.
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
		virtual ~AForm ( );							//	Default destructor

		AForm ( const std::string& formName, const int gradeToSign,
			const int gradeToExecute );			//	Parameterized constructor

		/* --- Accessors ---------------------------------------------------- */

		//	Getters
		const std::string&	getFormName () const;
		bool				getIsSigned () const;
		int					getGradeToSign () const;
		int					getGradeToExecute() const;

		/* --- Member functions --------------------------------------------- */	

		void	beSigned ( Bureaucrat & bureaucrat );
		void	execute ( Bureaucrat const & executor ) const;	// (2)

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

    	class IsNotSignedException : public std::exception {
    		public:
        		virtual const char* what() const throw();
    	};

	protected:

		virtual void performAction() const = 0;	//	(3)
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

/*
 *	(2)	virtual void	execute ( Bureaucrat const & executor ) const = 0;
 *		
 *		The first 'const' ensures that the executor object passed to the execute 
 *		method cannot be modified, providing safety and clarity that the function
 *		will not alter the state of the executor.
 *
 * 		The final 'const' indicates that the execute method does not modify the 
 * 		object (or any of its member variables) on which it is called.
 */

/*
 *	(3)	protected:
 *			virtual void performAction() const = 0;
 *
 * 		- 'protected' to ensure that the function is only accessible within the
 * 			class itself, its derived classes, and friends.
 * 		- 'virtual' so that the function CAN be overriden in the derived classes
 * 		- 'pure virtual' (' = 0') so that the function MUST be overriden in the 
 * 			derived classes
 */