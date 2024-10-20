/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateUtils.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 19:45:56 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/20 19:55:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEUTILS_HPP
# define DATEUTILS_HPP

# include <string>
# include <cstdlib>	// for std::atoi

bool	isValidDateFormat(const std::string& date);
bool	isLeapYear(int year);
bool 	isValidDate(int year, int month, int day);
bool	validateDate(const std::string& date);

#endif