/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:21:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/15 10:38:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>  // for std::map

void	FillMap(std::map<std::string, float> & exchangeRates) {

    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return ;
    }

	std::string	line;

    while (std::getline(file, line)) {
        std::stringstream	ss(line);
        std::string 		date;
        float				rate;

        std::getline(ss, date, ',');  // Extract the date
        ss >> rate;                  // Extract the value
		exchangeRates[date] = rate;  // Store the date and value in the map (1)
    }

    file.close();
}

int main(int argc, char **argv) {
	std::map<std::string, float> exchangeRates;  // Create a map to store the date and value
	FillMap(exchangeRates);

    // Let's print out the map to check if the data was stored correctly:
    for (typename std::map<std::string, float>::iterator it = exchangeRates.begin(); it != exchangeRates.end(); it++) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }

}

// int main() {
//     std::ifstream file("data.csv");

//     if (!file.is_open()) {
//         std::cerr << "Error: could not open file." << std::endl;
//         return 1;
//     }

//     std::map<std::string, float> btcPrices;  // Create a map to store the date and value
//     std::string line;

    // while (std::getline(file, line)) {
    //     std::stringstream ss(line);
    //     std::string date;
    //     float value;

    //     std::getline(ss, date, ',');  // Extract the date
    //     ss >> value;                  // Extract the value

    //     btcPrices[date] = value;  // Store the date and value in the map
    // }

//     file.close();

//     // Let's print out the map to check if the data was stored correctly:
//     for (typename std::map<std::string, float>::iterator it = btcPrices.begin(); it != btcPrices.end(); it++) {
//         std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
//     }

//     return 0;
// }

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