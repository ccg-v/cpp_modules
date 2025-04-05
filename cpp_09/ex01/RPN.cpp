/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:33:34 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/05 02:37:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
RPN::RPN() {}

// Copy constructor
RPN::RPN(const RPN & source) : _stack(source._stack) {}

// Copy assignment operator
RPN & RPN::operator=(const RPN & source) {
	if (this != &source)
		this->_stack = source._stack;
	return *this;
}

// Default destructor
RPN::~RPN() {}

/* --- Member functions ----------------------------------------------------- */

void	RPN::doOperation(std::stack<int> & stack, int operand1, int operand2, std::string token) {
	if (token == "+")
	{
        // Check for overflow in addition
        if (operand2 > 0 && operand1 > (INT_MAX - operand2))
		{
            throw std::runtime_error("Error: integer overflow in addition.");
        }
		stack.push(operand1 + operand2);
	}
	else if (token == "-")
	{
        // No overflow check needed for subtraction with non-negative single digits
		stack.push(operand1 - operand2);
	}
	else if (token == "*")
	{
        // Check for overflow in multiplication
        if (operand2 > 0 && operand1 > (INT_MAX / operand2))
		{
            throw std::runtime_error("Integer overflow in multiplication.");
        }
		stack.push(operand1 * operand2);
	}
	else if (token == "/")
	{
		if (operand2 == 0)
		{
			throw std::runtime_error("Invalid RPN expression: division by zero.");
		}
		stack.push(operand1 / operand2);
	}	
}

int RPN::evaluateRPN(const std::string & expression) {
    if (expression.empty() || onlyWhitespace(expression)) {
        throw std::runtime_error("Expression cannot be empty.");
    }

    std::istringstream input(expression);
    std::string token;
    std::stack<int> stack;
    int operandCount = 0;
	int	operatorCount = 0;

    while (input >> token)
	{
		// Check if token is a single-digit number
        if (isdigit(token[0]) && token.size() == 1)
		{
            stack.push(std::atoi(token.c_str()));
            operandCount++;
			
            // if (operandCount > 2)
			// {
            //     throw std::runtime_error("Invalid RPN expression: more than two consecutive operands.");
            // }
		}
		else if (token.size() > 1)
		{
			throw std::runtime_error("Invalid RPN expression: operands must be a single digit (0-9)");
        }
		else if (isOperator(token))
		{
            // Check if there are at least two operands in the stack
            if (stack.size() < 2)
			{
                throw std::runtime_error("Invalid RPN expression: not enough operands for operator.");
            }
            int operand2 = stack.top();
			stack.pop();
            int operand1 = stack.top();
			stack.pop();

			doOperation(stack, operand1, operand2, token);
			operatorCount++;
            operandCount = 0;  
        }
		else
		{
            throw std::runtime_error("Invalid RPN expression: unknown token.");
        }
    }
	
    // Final validation: there must be exactly one result on the stack!
    if (stack.size() != 1)
	{
		if (operatorCount == 0)
			throw std::runtime_error("Invalid RPN expression: operator missing.");
		else
        	throw std::runtime_error("Invalid RPN expression: too many operands.");
    }

    return stack.top();
}

/* --- Non-member utility functions ----------------------------------------- */

bool	onlyWhitespace(const std::string & expression)
{
	std::string::const_iterator it;
	for (it = expression.begin(); it != expression.end(); ++it)
	{
		if (!std::isspace(*it))
			return false;
	}
	return true;
}

bool	isOperator(std::string token)
{
	return token == "+" || token == "-" || token == "*" || token == "/";
}

/*
 *	In C++, the extraction operator (>>) for input streams (like
 *	std::istringstream) is designed to skip leading whitespace 
 *	(spaces, tabs, and newlines) by default when reading formatted
 *	data (like int, float, std::string, etc.).
 *	
 *	When input >> token is called, the stream ignores any leading
 *	whitespace, then reads characters until it reaches the next
 *	whitespace, which marks the end of the token.
 *
 *	In short, you don’t need to write extra code to handle 
 *	whitespace. It’s automatically managed by the std::istringstream
 *	extraction behavior.
 */