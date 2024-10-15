/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 23:21:09 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/14 23:37:31 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <map>  // for std::map

int main() {
    std::ifstream file("data.csv");

    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::map<std::string, float> btcPrices;  // Create a map to store the date and value
    std::string line;

    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string date;
        float value;

        std::getline(ss, date, ',');  // Extract the date
        ss >> value;                  // Extract the value

        btcPrices[date] = value;  // Store the date and value in the map
    }

    file.close();

    // Let's print out the map to check if the data was stored correctly:
    for (typename std::map<std::string, float>::iterator it = btcPrices.begin(); it != btcPrices.end(); it++) {
        std::cout << "Date: " << it->first << ", Value: " << it->second << std::endl;
    }

    return 0;
}
