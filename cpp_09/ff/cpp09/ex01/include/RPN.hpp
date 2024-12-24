/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffornes- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:29:41 by ffornes-          #+#    #+#             */
/*   Updated: 2024/12/06 20:53:21 by herz             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
#include <limits>
#include <cfloat>

#ifndef DIGIT
# define DIGIT 0
#endif
#ifndef OPERATOR
# define OPERATOR 1
#endif

std::string	removeSpaces( const std::string& );
bool		validateInput( const std::string str );

struct node {
    char	content;
	bool	type;
};

void	RPN( const std::string );
void	checkInput( const std::string& input );
void	tokenizer( const std::string& input, std::vector<node>& chain );
bool	calculate( long double& r, long double n1, long double n2, char operation );
