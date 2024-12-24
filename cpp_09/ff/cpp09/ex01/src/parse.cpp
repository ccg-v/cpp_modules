/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:29:30 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/06 20:58:24 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	checkInput( const std::string& input ) {
	for (unsigned int i = 0; i < input.size(); i++) {
		if (!isspace(input[i]) && !(input[i] == '+' || input[i] == '-' 
			|| input[i] == '/' || input[i] == '*')) {
			if (!isdigit(input[i])) {
				throw std::runtime_error("Character is neither a number nor a valid operator.");
			}
			if (isdigit(input[i]) && i + 1 < input.size() && isdigit(input[i + 1])) {
				throw std::runtime_error("Only single-digit numbers are allowed.");
			}
		}
	}
}


void	tokenizer( const std::string& input, std::vector<node>& chain ) {
	for ( size_t i = 0; i < input.size(); i++ ) {
		node	tmp;
		if (!isspace(input[i])) {
			tmp.content = input[i];
			if (isdigit(input[i]))
				tmp.type = DIGIT; 
			else
				tmp.type = OPERATOR;
			chain.push_back(tmp);
		}
	}
}
