/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:24:33 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/04 19:51:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Utils.hpp"

bool	onlyWhitespace(std::string input)
{
	for (size_t i = 0; i < input.size(); i++)
	{
		if (!isspace(input[i]))
			return false;
	}
	return true;
}

bool	isPositiveNumber(std::string & element)
{
    // Check if the input contains only digits
    for (size_t i = 0; i < element.size(); ++i)
	{
        if (!isdigit(element[i]))
            return false;
    }
	if (std::atoi(element.c_str()) == 0)
		return false;
    return true;
}

bool	isIntegerRange(std::string element)
{
	// Convert element to an integer with range checking
	char* end;
	errno = 0;
	long value = std::strtol(element.c_str(), &end, 10);

	// Check for errors in conversion
	if (errno == ERANGE || value > INT_MAX)
		return false;
	return true;
}

bool isSorted(const std::vector<int> & vec)
{
    return std::adjacent_find(vec.begin(), vec.end(), std::greater<int>()) == vec.end();
}
