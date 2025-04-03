/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/04 01:04:16 by ccarrace         ###   ########.fr       */
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
		std::map<std::string, float> _exchangeRates;	// (2)

	public:
	
		/* --- Orthodox Canonical Form -------------------------------------- */

		BitcoinExchange();												// Default constructor
		BitcoinExchange(const BitcoinExchange & source);				// Copy constructor
		BitcoinExchange & operator=(const BitcoinExchange & source);	// Copy assignment operator
		~BitcoinExchange();												// Default destructor

		/* --- Member methods ---------------------------------------------- */		

		void	checkInputFile(const std::string & argv);
		void	fillMap(const std::string & dataBase);	// (1)
		void	calculateExchanges(const std::string & argv);	// (1)
		void	trimAndvalidateDate(std::string & valueDate);
		void	validateValue(float &value);
		float	findExchangeRate(const std::string & valueDate);
};

#endif

/*
 *	(1)	Passing just the name of the database file (likely a short string) and
 *		not a large string—it might seem that passing by reference is overkill. 
 *		However, using const std::string & is still a good habit, even if the 
 *		string is small:
 *
 *		-	Using const std::string & as a general practice ensures consistency 
 *			across your codebase. It's easier to follow one pattern for all 
 *			std::string parameters than switching between passing by value and  
 *			passing by reference based on string size. This consistency reduces 
 *			the chance of errors and confusion.
 *		-	If the program changes in the future (e.g., if you pass longer paths,
 *			URLs, or more complex strings), passing by reference becomes more
 *			efficient.
 *		-	Even though the performance difference in passing a small string
 *			value vs. by reference is minimal, passing by reference still saves
 *			on the potential overhead of copying the string.
 *
 *		In modern C++, it's common to pass strings by const reference for the
 *		reasons above, and it helps in writing idiomatic C++ code. If you're
 *		trying to stick to best practices, passing the file name as a  
 *		const std::string& is the more idiomatic approach.
 */

/*
 *	(2)	If the exchange rate data never changes during the execution of the 
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