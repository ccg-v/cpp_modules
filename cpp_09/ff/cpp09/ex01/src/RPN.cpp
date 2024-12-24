/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:29 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/06 20:57:53 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

void	RPN( std::string str ) {
	std::vector<node>	chain;

	checkInput( str );
	tokenizer( str, chain );

	if (chain.size() == 1 ) {
		node	tmp = *(chain.begin());
		if (tmp.type == DIGIT )
			std::cout << tmp.content << std::endl;
		else
			throw std::runtime_error("Not enough operators");
		return ;
	}

	std::vector<long double>	numbers;
	long double	result = 0;
	for ( std::vector<node>::iterator it = chain.begin(); it != chain.end(); it++ ) {
		node	tmp = *it;
		if ( tmp.type == DIGIT ) {
			numbers.push_back(tmp.content - '0');
		} else {
			if (numbers.size() < 2)
				throw std::runtime_error("Not enough operators");
			else {
				long double	i = numbers.back();
				numbers.pop_back();
				long double	j = numbers.back();
				numbers.pop_back();
				if (!calculate(result, j, i, tmp.content))
					return ;
				numbers.push_back(result);
			}
		}
	}
	if ( numbers.size() != 1 )
		throw std::runtime_error("Not enough operators");
	std::cout << std::fixed << result << std::endl;
}
