/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 19:15:05 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/17 20:24:12 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>	// for std::find
# include <vector>		// for std:vector
# include <stdexcept>   // for std::runtime_error
# include <iostream>

// template<typename T>
// typename T::const_iterator easyfind(const T& container, const int value) {

// 	typename T::const_iterator it = std::find(container.begin(), container.end(), value);
// 	if (it == container.end())
// 		// throw std::runtime_error("No occurrence found");
// 		throw std::exception("No occurrence found");
// 	return it;
// }

template <typename T>
typename T::const_iterator easyfind(const T& container, int value) {
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::runtime_error("No occurrence found");
    }
    return it;
}

// Specialization for C-style arrays
template <typename T, size_t N>
T* easyfind(T (&array)[N], int value) {
    T* it = std::find(array, array + N, value);
    if (it == array + N) {
        throw std::runtime_error("No occurrence found");
    }
    return it;
}

#endif