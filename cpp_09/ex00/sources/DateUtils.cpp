/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateUtils.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:50:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/03 23:12:13 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateUtils.hpp"

/*
 *	isValidDateFormat()
 *
 *	Checks:
 *	-	Date length must be 10 characters
 *	-	Hyphens must be in positions 4 and 7 of the string
 *	-	The characters (except hyphens) must be digits
 */
bool isValidDateFormat(const std::string& date)
{
    if (date.length() != 10)
        return false;

    if (date[4] != '-' || date[7] != '-')
        return false;

    for (int i = 0; i < 10; ++i)
	{
        if (i == 4 || i == 7)
		{
            continue; // Skip the hyphens
        }
        if (!std::isdigit(date[i]))
		{
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
bool isLeapYear(int year)
{
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/*
 *	isValidDate()
 *
 *	-	Set an array with each month's number of days (note the leading
 *		zero value to match array indexes with month's numbers: Jan = [1], 
 *		Feb = [2], etc. )
 *	-	Adjust February days if it's a leap year
 *	-	Check if the month is valid
 *	-	Check if the day is valid for the given month
 */
bool isValidDate(int year, int month, int day)
{
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
        daysInMonth[2] = 29;

    if (month < 1 || month > 12)
        return false;

    if (day < 1 || day > daysInMonth[month])
        return false;

    return true;
}

/*
 *	validateDate()
 *
 *	- Checks if the date format ('Year-Month-Day') is correct
 *	- Extracts year, month, and day from the string
 *	- Validates  the extracted year, month, and day
 */
bool validateDate(std::string& date)
{
	// Trim whitespaces
	date.erase(date.find_last_not_of(" \n\r\t") + 1);
	
    if (!isValidDateFormat(date))
        return false;

    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());

    return isValidDate(year, month, day);
}
