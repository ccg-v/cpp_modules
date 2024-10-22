/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:47:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/22 14:24:15 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int argc, char **argv) {

	try {

		if (argc == 2) {
			
			std::string dbFile = "data/data.csv";
			BitcoinExchange btc;

			btc.fillMap(dbFile);
			btc.checkInputFile(argv[1]);
			btc.calculateExchanges(argv[1]);
			
			return 0;
		} else {
			throw std::runtime_error("Error: Wrong number of arguments");
		}

	} catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
		return 1;
	}
}