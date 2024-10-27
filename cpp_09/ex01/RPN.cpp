/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 11:33:34 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/28 00:10:11 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <iostream>
// #include <stack>
// #include <sstream>
// #include <string>
// #include <cstdlib>	//for std::atoi

// int evaluateRPN(const std::string& expression) {
//     std::stack<int> stack;
//     std::istringstream input(expression);
//     std::string token;

// 	while (input >> token) {
// 		if (isdigit(token[0]))
// 			std::cout << token << " is an operand" << std::endl;
// 		else
// 			std::cout << token << " is an operator" << std::endl;
// 	}

//     while (input >> token) {	// Evaluate tokens one by one skipping whitespaces (1)
//         if (isdigit(token[0])) {
//             // If the token is a number, push it to the stack
//             stack.push(std::atoi(token.c_str()));
//         } else {
//             // Otherwise, the token is an operator; pop two operands
//             int operand2 = stack.top();	// Retrieve the next operand
// 			stack.pop();				// Remove it from the stack
//             int operand1 = stack.top(); 
// 			stack.pop();
//             if (token == "+") stack.push(operand1 + operand2);
//             else if (token == "-") stack.push(operand1 - operand2);
//             else if (token == "*") stack.push(operand1 * operand2);
//             else if (token == "/") stack.push(operand1 / operand2);
//         }
//     }
//     return stack.top(); // The result is on the top of the stack
// }

#include <iostream>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <string>
#include <cctype>
#include <cstdlib>	//for std::atoi

int evaluateRPN(const std::string& expression) {
    if (expression.empty()) {
        throw std::runtime_error("Expression cannot be empty.");
    }

    std::istringstream input(expression);
    std::string token;
    std::stack<int> stack;
    int operandCount = 0;

    while (input >> token) {
        // Check if token is a number
        if (isdigit(token[0])) {
            stack.push(std::atoi(token.c_str()));
            operandCount++;
            // Reset the count for consecutive operands
            if (operandCount > 2) {
                throw std::runtime_error("Invalid RPN expression: more than two consecutive operands.");
            }
        } else if (token == "+" || token == "-" || token == "*" || token == "/") {
            // Check if there are at least two operands in the stack
            if (stack.size() < 2) {
                throw std::runtime_error("Invalid RPN expression: not enough operands for operator.");
            }
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            // Perform the operation
            if (token == "+") stack.push(operand1 + operand2);
            else if (token == "-") stack.push(operand1 - operand2);
            else if (token == "*") stack.push(operand1 * operand2);
            else if (token == "/") {
                if (operand2 == 0) {
                    throw std::runtime_error("Invalid RPN expression: division by zero.");
                }
                stack.push(operand1 / operand2);
            }

            // Reset operand count after processing an operator
            operandCount = 0;  
        } else {
            throw std::runtime_error("Invalid RPN expression: unknown token.");
        }
    }

    // Final validation: there must be exactly one result on the stack
    if (stack.size() != 1) {
        throw std::runtime_error("Invalid RPN expression: too many operands.");
    }

    return stack.top();
}


int main() {
	// std::string expression = " 1 2 * 3 4	 * 5 6  * * * ";
    // int result = evaluateRPN(expression);
    // std::cout << "Result: " << result << std::endl; // Expected output: 720
	// expression = "8 9 * 9 - 9 - 9 - 4 - 1 +";
	// std::cout << "Result: " << evaluateRPN(expression) << std::endl; // Expected output: 42
	// expression = "7 7 * 7 -";
	// std::cout << "Result: " << evaluateRPN(expression) << std::endl; // Expected output: 42	
	// expression = "1 2 * 2 / 2 * 2 4 - +";
	// std::cout << "Result: " << evaluateRPN(expression) << std::endl; // Expected output: 0

	std::string expression = "(1 + 1)";
	std::cout << "Result: " << evaluateRPN(expression) << std::endl; // Expected output: ERROR

	// std::string 	expression = "7 * 7 -";
	// std::cout << "Result: " << evaluateRPN(expression) << std::endl; // Expected output: 42
    return 0;
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