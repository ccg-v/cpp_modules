/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:57:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/30 21:12:07 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>	// for std::cout(), std::cerr()
# include <sstream>		// for std::isstringstream()
# include <stack>		// for std::stack() container
# include <stdexcept>	// for std::runtime_error() exception
# include <string>		// for std::string class
# include <cctype>		// for std::isdigit(), std::isspace()
# include <cstdlib>		// for std::atoi()
# include <climits>		// for INT_MAX

class RPN {

	private:
		std::stack<int> _stack;	

		/* --- Private member functions ------------------------------------- */

		void	doOperation(std::stack<int> & stack, int operand1, int operand2, std::string token); // (1)

	public:

		/* --- Orthodox Canonical Form -------------------------------------- */

		RPN();									// Default constructor
		RPN(const RPN & source);				// Copy constructor
		RPN & operator=(const RPN & source);	// Copy assignment operator
		~RPN();									// Default destructor

		/* --- Public member methods ---------------------------------------- */

		int		evaluateRPN(const std::string & expression);
};

/* --- Non-member utility functions ----------------------------------------- */

	bool	onlyWhitespace(const std::string & expression);
	bool	isOperator(std::string token);

	// Insertion operator<< overload
	std::ostream & operator<<(std::ostream & os, RPN & rpn);

#endif

/*
 * (1) Why is 'doOperation()' private?
 *
 *		The main reason to make 'doOperation()' private is to preserve encapsulation 
 *		and prevent misuse. It’s a helper function meant only for the internal use of
 *		'evaluateRPN()', not for external access.
 */