/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 19:38:06 by ccarrace          #+#    #+#             */
/*   Updated: 2024/07/18 23:08:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat {

	private:

		const std::string	_name;
		int					_grade;

	public:
		/* --- Orthodox Canonical Form -------------------------------------- */

		Bureaucrat ( );										// Default constructor (2)
		Bureaucrat ( const Bureaucrat& source );			// Copy constructor
		Bureaucrat& operator=( const Bureaucrat& source );	// Copy assignment operator
		~Bureaucrat ( void );								// Destructor

		Bureaucrat ( const std::string& name, int grade );	// Parametrized constructor
		/* --- Accessors ---------------------------------------------------- */
		
		//	Getters
		const std::string&	getName () const;	// (1)
		int					getGrade () const;

		//	Setters not needed, name should be constant and grade should be
		//	modified only through increment()/decrement() 

		/* --- Member functions --------------------------------------------- */
		
		void 	incrementGrade ( int grade );
		void	decrementGrade ( int grade );

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

/*
 *	(2) Take/pass a string by value...?

 *			Bureaucrat ( std::string name, int grade );
 *			const std::string	getName () const;

 *		...or by reference?

 *			Bureaucrat ( std::string& name, int grade );
 *			const std::string&	getName () const;
 *
 * 		By value a copy of the string is created when the function is called. If
 * 		the string is long, copying it can take too much time and memory.
 * 		By reference no copy is made, saving time and memory.
 * 			- Use pass-by-value for small, built-in types (like int, char, etc.).
 *			- Use const reference for larger objects or user-defined types.
 */

/*
 *	(3) Exceptions in C++ are objects, not functions. They are designed to be
 *		thrown and caught, carrying information about the error. Using classes
 *		allows you to inherit from std::exception, which is the standard base
 *		class forexceptions in C++. Classes can hold more information about the
 *		error if needed.
 *
 *		1. public std::exception:
 *			This is not a parameter, it's inheritance syntax.
 *			It means your exception classes inherit from std::exception, which
 *			is the standard base class for exceptions in C++. This inheritance
 *			goes in the class declaration in the header file.
 *
 *		2. virtual keyword:
 *			Used in the header to indicate that this function can be overridden
 *			in derived classes. It's good practice when inheriting from 
 *			std::exception.
 *
 * 		3. const throw():
 *			const means the function doesn't modify the object.
 *			throw() is a deprecated exception specification indicating the
 *			function doesn't throw exceptions itself.
 *
 * 		In the .cpp file we will define the what() function for each exception
 * 		class. In .cpp file the Bureaucrat:: prefix is necessary because these
 * 		are nested classes.
 */