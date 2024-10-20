/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:50:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/20 19:51:52 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateUtils.hpp"

bool isValidDateFormat(const std::string& date) {
    // Check the length of the string (YYYY-MM-DD is 10 characters)
    if (date.length() != 10) {
        return false;
    }

    // Check that positions 4 and 7 are hyphens
    if (date[4] != '-' || date[7] != '-') {
        return false;
    }

    // Ensure the rest of the characters are digits
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            continue; // Skip the hyphens
        }
        if (!std::isdigit(date[i])) {
            return false;
        }
    }

    return true;
}

/*
 *	isLeapYear()
 *
 *	Leap year is the year divisible by 4, unless it is a secular year 
 *	(last year of each century, ending in “00”), in which case it must 
 *	also be divisible by 400.
 *
 *	Therefore, a year is leap if:
 *	-	it can be divided by 4
 *	-	it cannot be divided by 100...
 *	-	...except if it can be divided by 400
 */
bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool isValidDate(int year, int month, int day) {
    // Days in month lookup
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Adjust for leap years in February
    if (month == 2 && isLeapYear(year)) {
        daysInMonth[2] = 29;
    }

    // Check if the month is valid
    if (month < 1 || month > 12) {
        return false;
    }

    // Check if the day is valid for the given month
    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }

    return true;
}

bool validateDate(const std::string& date) {
    if (!isValidDateFormat(date)) {
        return false;
    }

    // Extract year, month, and day from the string
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    // Validate the extracted year, month, and day
    return isValidDate(year, month, day);
}
