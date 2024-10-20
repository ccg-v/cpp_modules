/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:21:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/20 14:28:41 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
BitcoinExchange::BitcoinExchange() {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange & source) : _exchangeRates(source._exchangeRates) {
	std::cout << "Copy constructor called" << std::endl;
}

//	Copy assignment operator
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & source) {
	std::cout << "Copy assignment operaror called" << std::endl;
	if (this != &source) {
		this->_exchangeRates = source._exchangeRates;
	}
	return *this;
}

//	Default destructor
BitcoinExchange::~BitcoinExchange() {
	std::cout << "Default destructor called" << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

void	BitcoinExchange::fillMap(const std::string & dataBase) {	// (2)

    std::ifstream dbFile(dataBase.c_str());	// (3)

    if (!dbFile.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        return ;
    }

	std::string	line;

    while (std::getline(dbFile, line)) {
        std::stringstream	ss(line);
        std::string 		rateDate;
        float				rate;

        std::getline(ss, rateDate, ','); 	// Extract the date
        ss >> rate;                  		// Extract the value
		_exchangeRates[rateDate] = rate;	// Store date and value in the map (1)
    }

    dbFile.close();
}

void	BitcoinExchange::CalculateExchanges(const std::string & argv) {

    std::ifstream inputFile(argv.c_str());	// (3)
	std::string	line;

    while (std::getline(inputFile, line)) {
        std::stringstream	ss(line);
        std::string 		valueDate;
        float				value;

        std::getline(ss, valueDate, '|');  // Extract the date
        ss >> value;                  // Extract the value

        // Trim whitespaces
        valueDate.erase(valueDate.find_last_not_of(" \n\r\t") + 1);

		// Validate the date
		if (validateDate(valueDate) == false){
            std::cerr << "Error: bad input => " << valueDate << std::endl;
            continue;			
		}
		// Validate the value
        if (value < 0) {
            std::cerr << "Error: not a positive number" << std::endl;
            continue;
        }
		if (value > 1000) {
            std::cerr << "Error: too large a number" << std::endl;
            continue;			
		}

		// Find the closest date in the map
        std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(valueDate);

		// No exact match, move to the closest earlier date
        if (it == _exchangeRates.end() || it->first != valueDate) {
            if (it != _exchangeRates.begin()) {
                --it;
            } else {
                std::cerr << "Error: no exchange rate available for " << valueDate << std::endl;
                continue;
            }
        }

		// Multiply the value by the exchange rate
        float result = value * it->second;
        std::cout << valueDate << " => " << value << " = " << result << std::endl;
    }


	inputFile.close();

}

bool BitcoinExchange::isValidDateFormat(const std::string& date) {
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
bool BitcoinExchange::isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

bool BitcoinExchange::isValidDate(int year, int month, int day) {
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

bool BitcoinExchange::validateDate(const std::string& date) {
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

/*
 *	(1)	This line effectively inserts or updates a key-value pair in the
 *		map, where the key is the date (as a string) and the value is the
 *		corresponding value (a float rate).
 *
 *		In a map, the syntax 'exchangeRates[date]' is used to access the
 *		value associated with the key date.
 *		- If the key (date) already exists in the map, this will access 
 *			its corresponding value.
 *		- If the key does not exist, it will create a new key-value pair 
 *			where date is the key.
 *
 *		'rate' is a float variable that holds the price extracted from the
 *		line. The = operator assigns the value to the key (date) in the map.
 *		If date already exists in 'exchangeRates', the current value will 
 *		be overwritten. If it doesn't exist, a new key-value pair will be
 *		added.
 */

/*
 *	(2)	Is it worth passing 'dataBase' parameter, which is just a file name,
 *		as a const reference and not just be value?
 *
 *			void	BitcoinExchange::fillMap(std::string dataBase)
 *
 *		Read the answer in .hpp file, comment (1)
 */

/*
 *	(3)	In C++98, the constructor for std::ifstream does not accept a 
 *		std::string as a parameter. Instead, it requires a C-style string
 *		(const char*). In C++98, std::string to const char* conversion 
 *		isn't implicit for this specific use case. You need to manually
 *		convert the std::string to a C-style string using the .c_str()
 *		method.
 */