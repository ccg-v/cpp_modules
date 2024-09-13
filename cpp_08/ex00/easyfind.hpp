/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:15:05 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/14 00:58:04 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

typename T::const_iterator easyfind(const T& container, const int value) {

	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
	if (it == vec.end())
		throw std::runtime_error("No occurrence found");
	return it;
}

#endif