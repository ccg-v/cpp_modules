/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:21:09 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/04 12:50:10 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include "DateUtils.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
BitcoinExchange::BitcoinExchange() {}

//	Copy constructor
BitcoinExchange::BitcoinExchange(const BitcoinExchange & source) 
	: _exchangeRates(source._exchangeRates) {}

//	Copy assignment operator
BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange & source) {
	
	if (this != &source) {
		this->_exchangeRates = source._exchangeRates;
	}
	return *this;
}

//	Default destructor
BitcoinExchange::~BitcoinExchange() {}

/* --- Member methods ------------------------------------------------------- */

void	BitcoinExchange::checkInputFile(const std::string & argv)
{
    struct stat path_stat;

    // Check if the path is a directory	(4)
    if (stat(argv.c_str(), &path_stat) == 0 && S_ISDIR(path_stat.st_mode))
	{
        throw std::runtime_error("Error: '" + argv + "' is a directory, not a file.");
    }

    // Check if the path is an executable (4)
    if (stat(argv.c_str(), &path_stat) == 0 && (path_stat.st_mode & S_IXUSR))
	{
        throw std::runtime_error("Error: '" + argv + "' is an executable.");
    }

    std::ifstream inputFile(argv.c_str());	// (3)

    // Check if file is opened successfully
    if (!inputFile.is_open())
	{
		throw std::runtime_error("Error: could not open '" + argv + "'.");
    }

    // Check if file is empty
    if (inputFile.peek() == std::ifstream::traits_type::eof())
	{
		throw std::runtime_error("Error: '" + argv + "' is empty.");
    }
}

void	BitcoinExchange::fillMap(const std::string & dataBase) // (2)
{	
    std::ifstream dbFile(dataBase.c_str());	// (3)

    if (!dbFile.is_open())
	{
		throw std::runtime_error("Error: could not open database '" + dataBase + "'.");
    }

	std::string	line;

    while (std::getline(dbFile, line))
	{
        std::stringstream	ss(line);
        std::string 		rateDate;
        float				rate;

        std::getline(ss, rateDate, ','); 	// Extract the date
        ss >> rate;                  		// Extract the value
		_exchangeRates[rateDate] = rate;	// Store date and value in the map (1)
    }

    dbFile.close();
}

void BitcoinExchange::validateValue(float &value)
{
	if (value < 0)
	{
		throw std::runtime_error("Error: not a positive number.");
	}
	if (value > 1000)
	{
		throw std::runtime_error("Error: too large a number.");		
	}
}

float BitcoinExchange::findExchangeRate(const std::string &valueDate)
{
    std::map<std::string, float>::iterator it = _exchangeRates.find(valueDate);

    // If an exact match is found, return it
    if (it != _exchangeRates.end())
	{
        return it->second;
    }

    // If no exact match, find the closest earlier date (5)
    it = _exchangeRates.lower_bound(valueDate);
    if (it == _exchangeRates.begin())
	{
        throw std::runtime_error("Error: no exchange rate available for " + valueDate);
    }
    
    --it; // Move to the closest earlier date (5)
    return it->second;
}

void BitcoinExchange::calculateExchanges(const std::string &argv)
{
    std::ifstream inputFile(argv.c_str());  // Open the file
    std::string line;

    // Check and skip the header if it exists
    while (std::getline(inputFile, line))
    {
        if (line == "date | value")
            continue ;

        std::stringstream ss(line);
        std::string date;
        float value;

        std::getline(ss, date, '|'); // Moves chars from 'ss' to 'date' till '|' is found (and removed)
		ss >> value;				 // Moves remaining characters from ss to value ()
		
        try
        {
            if (!validateDate(date))
            {
                throw std::runtime_error("Error: bad input => " + date);
            }

            if (ss.fail() || !(ss.eof())) // Check for valid rate (must be a float) (6)
            {
                throw std::runtime_error("Error: Not a decimal number");
            }

            validateValue(value);
            float exchangeRate = findExchangeRate(date);
            float result = value * exchangeRate;
            std::cout << date << " => " << value << " = " << result << std::endl;
        }
        catch (const std::runtime_error &e)
        {
            std::cerr << e.what() << std::endl;
        }

    }

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
 *	(4) stat():
 *
 *	-	'stat(const char *path, struct stat *buf)' is a system call that
 *		retrieves information about the file specified by path and stores
 *		it in the 'buf' structure (of type struct stat).
 *
 *		This structure contains various details about the file, such as 
 *		its size, permissions, file type (whether it's a directory, regular
 *		file, or executable), and other metadata.
 *
 * 		'if (stat(argv.c_str(), &path_stat) == 0)' checks whether the stat 
 * 		system call was able to retrieve information about the file or path
 * 		referenced by argv
 *
 *	-	S_ISDIR(path_stat.st_mode):
 *
 *		Checks if the file is a directory.
 *
 *	-	S_IXUSR:
 *
 *		This constant checks if the file has execute permissions for the
 *		owner (user).There are also S_IXGRP and S_IXOTH to check execute
 *		permissions for group and others, respectively.
 *
 *		(path_stat.st_mode & S_IXUSR) checks if the file has user (owner)
 *		execute permissions.
 */

/*
 *	(5)	'lower_bound()' and 'upper_bound()'
 *
 *		'lower_bound(key)' returns an iterator pointing to:
 *			- The key itself if it exists.
 *			- The next key if the key does not exist (the first element
 *				that is greater).
 *
 *		'upper_bound(key)' always returns an iterator pointing to:
 *			- The first element that is strictly greater than the key.
 *		
 *		The standard library does not include a direct function to find
 *		the closest lesser value. Finding it involves a two-step process:
 *
 *			1.	Use lower_bound() to find the first element that is not 
 *				less than the key (i.e., the smallest element that is 
 *				greater than or equal to the key).
 *			2.	Check if you need to move back one position to get the 
 *				closest lesser value.
 */

/*
 *	(6) if (ss.fail() || !(ss.eof()))
 *
 * 	- ss.fail() checks if extraction from 'ss' to 'rate' failed. It will 
 * 		happen when 'ss' contains a string (e.g. 'abc') and not a float
 * 		as we want 'rate' to be.
 * 
 *  - ss.eof() checks if there are leftover characters, ensuring that 
 *		invalid inputs like 12.34.56 or 12a34 are correctly detected and
 *		refused.
 */