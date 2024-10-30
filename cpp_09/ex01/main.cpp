/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:51:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/30 21:37:48 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 *	The best container to use for evaluating a Reverse Polish Notation (RPN) 
 *	expression is the 'std::stack' container. The std::stack class in C++ is 
 *	designed specifically for LIFO (Last In, First Out) operations, which is 
 *	exactly what we need for evaluating RPN expressions.
 *
 *	'std::stack' provides efficient 'push()' and 'pop()' operations that will
 *	allow us to add and remove elements only from the top of the stack, which
 *	is how RPN operates.
 */
 
#include "RPN.hpp"

int	main(int argc, char **argv) {

	try {
		if (argc == 2) {
			RPN rpn;
			int result = rpn.evaluateRPN(argv[1]);
			std::cout << "Result: " << result << std::endl;
			return 0;
		} else {
			throw std::runtime_error("Error: Wrong number of arguments");
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}