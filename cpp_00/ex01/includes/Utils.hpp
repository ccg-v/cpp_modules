/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 21:21:59 by ccarrace          #+#    #+#             */
/*   Updated: 2024/03/28 00:44:26 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

bool hasOnlyBlankSpaces(const std::string &str);
bool areAllDigits(const std::string &str);
std::string trimBlankSpaces(const std::string &str);
std::string formatAndTruncate(const std::string &str);

#endif