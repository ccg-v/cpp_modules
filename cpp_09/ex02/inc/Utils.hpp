/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:17:08 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/12 18:19:02 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

# include <climits>		// For INT_MAX
# include <cerrno>    	// For errno
# include <cstdlib>   	// For std::strtol
# include <string>		// For std::string

bool	onlyWhitespace(std::string input);
bool	isInteger(std::string element);
bool	isValidNumber(std::string & element);

#endif