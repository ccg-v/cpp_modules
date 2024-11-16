/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:08 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/16 12:57:51 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <climits>		// for INT_MAX
# include <cerrno>    	// for errno
# include <cstdlib>   	// for std::strtol
# include <string>		// for std::string
# include <algorithm>	// for std::adjacent_find
# include <vector>

bool	onlyWhitespace(std::string input);
bool	isPositiveNumber(std::string & element);
bool	isIntegerRange(std::string element);
bool	isSorted(const std::vector<int> & vec);

#endif