/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:21:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/22 14:35:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "DateUtils.hpp"

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
	std::cout << "Copy assignment operator called" << std::endl;
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
		throw std::runtime_error("Error: could not open database '" + dataBase + "'.");
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

void	BitcoinExchange::checkInputFile(const std::string & argv) {

    std::ifstream inputFile(argv.c_str());	// (3)
	std::string	line;
	std::ostringstream oss;

    // Check if file is opened successfully
    if (!inputFile.is_open()) {
		throw std::runtime_error("Error: could not open '" + argv + "'.");
    }

    // Check if file is empty
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
		throw std::runtime_error("Error: '" + argv + "' is not a file or file is empty.");
    }
}

void BitcoinExchange::trimAndvalidateDate(std::string & valueDate) {
    // Trim whitespaces
    valueDate.erase(valueDate.find_last_not_of(" \n\r\t") + 1);

	// Validate the date
	if (validateDate(valueDate) == false) {
		throw std::runtime_error("Error: bad input => " + valueDate);
	}
}

void BitcoinExchange::validateValue(float value) {
	// Validate the value
	if (value < 0) {
		throw std::runtime_error("Error: not a positive number.");
	}
	if (value > 1000) {
		throw std::runtime_error("Error: too large a number.");		
	}
}

float BitcoinExchange::findExchangeRate(const std::string & valueDate) {

    std::map<std::string, float>::iterator it = _exchangeRates.lower_bound(valueDate);
    std::ostringstream oss;

    // No exact match, move to the closest earlier date
    if (it == _exchangeRates.end() || it->first != valueDate) {
        if (it != _exchangeRates.begin()) {
            --it;
        } else {
            oss << "Error: no exchange rate available for " << valueDate;
            throw std::runtime_error(oss.str());
        }
    }

    return it->second;
}

void	BitcoinExchange::calculateExchanges(const std::string & argv) {

    std::ifstream inputFile(argv.c_str());	// (3)
	std::string	line;

	// Check and skip the header if it exists
    if (std::getline(inputFile, line)) {
		if (line == "date | value")
			std::getline(inputFile, line);
    }

	do {	// (4)

        std::stringstream	ss(line);
        std::string 		valueDate;
        float				value;
		
        std::getline(ss, valueDate, '|');	// Extract the date
        ss >> value;                  		// Extract the value

		try {
			
			trimAndvalidateDate(valueDate);
			validateValue(value);
			float exchangeRate = findExchangeRate(valueDate);

			float result = value * exchangeRate;
			std::cout << valueDate << " => " << value << " = " << result << std::endl;

		} catch (const std::runtime_error& e) {
			std::cerr << e.what() << std::endl;
		}
		
	} while (std::getline(inputFile, line));  // Continue reading lines until the end

	inputFile.close();

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

/*
 *	(4) Why a do-while loop?
 *
 *		If I use a simple while loop
 * 
 *			while (std::getline(inputFile, line)) {
 *				...
 *			}
 *
 *		the 
 */