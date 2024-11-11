/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 22:24:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/11 22:26:59 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <climits>		// For INT_MAX

bool	onlyWhitespace(std::string input) {
	for (size_t i = 0; i < input.size(); i++) {
		if (!isspace(input[i])) {
			return false;
		}
	}
	return true;
}

bool	isInteger(std::string element) {
	// Convert element to an integer with range checking
	char* end;
	errno = 0;
	long value = std::strtol(element.c_str(), &end, 10);

	// Check for errors in conversion
	if (errno == ERANGE || value > INT_MAX) {
		return false;
	}
	return true;
}	

bool	isValidNumber(std::string & element) {
    // Check if the input contains only digits
    for (size_t i = 0; i < element.size(); ++i) {
        if (!isdigit(element[i])) {
            return false;
        }
    }
	if (std::atoi(element.c_str()) > INT_MAX)
		return false;
    return true;
}