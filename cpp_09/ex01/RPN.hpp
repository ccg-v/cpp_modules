/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:57:30 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/29 18:59:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>		// for std::cout(), std::cerr()
#include <sstream>		// for std::isstringstream()
#include <stack>		// for std::stack() container
#include <stdexcept>	// for std::runtime_error() exception
#include <string>		// for std::string class
#include <cctype>		// for std::isdigit(), std::isspace()
#include <cstdlib>		// for std::atoi()
#include <climits>		// for INT_MAX

class RPN {

	private:
		std::stack<int> _stack; 
}