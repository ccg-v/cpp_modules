/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:13:00 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/16 12:11:04 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <map>		// for std::map
# include <cstdlib>	// for std::atoi

class	BitcoinExchange {

	private:
		std::map<std::string, float> _exchangeRates;

	public:
	
		/* --- Orthodox Canonical Form -------------------------------------- */

		BitCoinExchange();												// Default constructor
		BitcoinExchange(const & BitCoinExchange source);				// Copy constructor
		BitCoinExchange & operator=(const & BitCoinExchange source);	// Copy assignment operator
		~BitcoinExchange();												// Default destructor

};

#endif