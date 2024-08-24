/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/24 20:05:56 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T>
void iter (T* array, size_t length, void(*f)(const T&)) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
};

#endif

