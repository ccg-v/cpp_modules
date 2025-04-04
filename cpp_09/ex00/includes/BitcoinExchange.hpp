/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/04 19:08:28 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>			// for std::map
# include <exception>	// for std::exceptions
# include <sys/stat.h>	// for stat() (in checkInputFile())

class	BitcoinExchange {

	private:
		std::map<std::string, float> _exchangeRates;	// (1)

	public:
	
		/* --- Orthodox Canonical Form -------------------------------------- */

		BitcoinExchange();												// Default constructor
		BitcoinExchange(const BitcoinExchange & source);				// Copy constructor
		BitcoinExchange & operator=(const BitcoinExchange & source);	// Copy assignment operator
		~BitcoinExchange();												// Default destructor

		/* --- Member methods ---------------------------------------------- */		

		void	checkInputFile(const std::string & argv);
		void	fillMap(const std::string & dataBase);
		void	calculateExchanges(const std::string & argv);
		void	trimAndvalidateDate(std::string & valueDate);
		void	validateValue(float &value);
		float	findExchangeRate(const std::string & valueDate);
};

#endif

/*
 *	(1)	If the exchange rate data never changes during the execution of the 
 *		program (i.e., the exchange rates are static), it can be beneficial to
 *		load the data once and share it across all instances of BitcoinExchange.
 *		In this case, the exchange rates could be stored as a static member of 
 *		the class. This way, all instances of BitcoinExchange share the same map
 *		of exchange rates:
 *
 *			class BitcoinExchange {
 *				private:
 *					static std::map<std::string, float> _exchangeRates;
 *					static bool _initialized;
 *			};
 *			
 *			BitcoinExchange() {
 *				if (!_initialized) {
 *					FillMap("data.csv");
 *					_initialized = true; // Ensure it's only loaded once
 *				}
 *			}
 *
 *		But our program does not work with several instances of BitcoinExchange
 *		at the same execution so declaring the container as static is not really
 *		needed in this exercise.
 */