/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:10:21 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/31 00:08:32 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/*
 * hasOnlyBlankSpaces()
 *
 * Returns true if the input has only blank spaces or tabs.
 * 
 * After writing my function, I discovered there is an specific method of the
 * 'std::string' class in C++ called 'find_first_not_of()' that is used to find
 * the position of the first character in the string that is not equal to a 
 * specified character or a set of characters:
 * 
 * 		bool hasOnlyBlankSpaces(const std::string &str) {
 * 			return str.find_first_not_of(' ') == std::string::npos;
 *		}
 */
bool hasOnlyBlankSpaces(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (str[i] != ' ' && str[i] != '\t')
			return false;
	}
	return true;
}

/* 
 * areAllDigits()
 * 
 * Checks if all characters in a string are digits.
 * 
 * A more concise solution using 'find_if_not()' function from <algorithm> library.
 * 
 * 		#include <algorithm>
 * 
 * 		bool areAllDigits(const std::string &str) {
 * 			return std::find_if_not(str.begin(), str.end(), ::isdigit) == str.end();
 * 		}
 * 
 * It takes a 'start iterator' and an 'end iterator' (the beginning and end of the
 * range), and a 'unary predicate function' that is used to evaluate whether an 
 * element meets a certain condition. In this context it is searching for the first
 * character in the string that is not a digit:
 * 		- If it does not find any character, the function returns an iterator pointing 
 * 			to the end of the string. 
 * 		- If it finds a non-digit character, it returns an iterator pointing to that
 * 			character.
 * The iterator returned by 'find_if_not()' is compared to the end of the string. If 
 * they are equal it means that all characters in the string are digits.
 */
bool areAllDigits(const std::string &str) {
	for (size_t i = 0; i < str.length(); ++i) {
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

/*
 * trimBlankSpaces()
 *
 * Trims leading and trailing blank spaces in the fields values
 */
std::string trimBlankSpaces(const std::string &str) {
    int start = 0, end = str.length() - 1;

    while (start <= end && (str[start] == ' ' || str[start] == '\t'))
        start++;
    while (end >= start && (str[end] == ' ' || str[end] == '\t'))
        end--;
    return str.substr(start, end - start + 1);
}

/*
 * formatAndTruncate()
 *
 * Truncate and format the string if it is longer than the column width
 */ 
std::string formatAndTruncate(const std::string &str) {
    if (str.length() > 10) {
        return str.substr(0, 9) + ".";
    } else {
        return str;
    }
}
 /*
  * exitIfEOF
  *
  * Catches the EOF when the user enters a Ctrl+D and exits the function
  */
void exitIfEOF(std::istream &input) {
    if (input.eof()) {
        std::cout << std::endl << "EOF received. Exiting Phonebook. Goodbye!" << std::endl;
        exit(1);
    }
}
