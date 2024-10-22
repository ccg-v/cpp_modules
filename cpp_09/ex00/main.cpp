/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 20:47:31 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/22 13:01:54 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// int	main(int argc, char **argv) {

// 	if (argc == 2) {

// 		std::string dbFile = "data/data.csv";
// 		BitcoinExchange btc;

// 		btc.fillMap(dbFile);
// 		btc.calculateExchanges(argv[1]);
// 		return 0;
// 	}
// 	std::cerr << "Error: Wrong number of arguments" << std::endl;
// 	return 1;
// }

// int	main(int argc, char **argv) {

// 	try {
// 		if (argc == 2) {

// 			std::string dbFile = "data/data.csv";
// 			BitcoinExchange btc;

// 			btc.fillMap(dbFile);
// 			btc.calculateExchanges(argv[1]);
// 			return 0;
// 		} else {
// 			throw BitcoinExchange::WrongArgsException();
// 		}
// 	} catch (const BitcoinExchange::WrongArgsException & e) {
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	} catch (const BitcoinExchange::DbFileOpenException & e) {
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	} catch (const BitcoinExchange::InputFileOpenException & e) {
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	} catch (const BitcoinExchange::BadDateException & e) {
// 		std::cerr << e.what() << std::endl;
// 		return 1;
// 	}
// }

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
			// throw BitcoinExchange::WrongArgsException();
			// std::ostringstream oss;
			// oss << "Error: arguments! (Runtime exception)";
			// throw std::runtime_error(oss.str());
			throw std::runtime_error("Error: Wrong number of arguments");
		}
	// } catch (const BitcoinExchange::WrongArgsException & e) {
	// 	std::cerr << e.what() << std::endl;
	// 	return 1;
	// } catch (const BitcoinExchange::DbFileOpenException & e) {
	// 	std::cerr << e.what() << std::endl;
	// 	return 1;
	// } catch (const BitcoinExchange::InputFileOpenException & e) {
	// 	std::cerr << e.what() << std::endl;
	// 	return 1;
	// } catch (const BitcoinExchange::BadDateException & e) {
	// 	std::cerr << e.what() << std::endl;
	// 	return 1;
	} catch (const std::runtime_error& e) {
        std::cerr << e.what() << std::endl;
	}
}