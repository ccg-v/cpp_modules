/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/27 13:47:28 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>

template <typename T, typename F>
void iter(T* array, size_t length, F f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

#endif

/*
 *  Implementation with less flexibility:
 *
 *          template <typename T>
 *          void iter (T* array, size_t length, void(*f)(const T&)) {
 *              for (size_t i = 0; i < length; i++) {
 *                  f(array[i]);
 *              }
 *          };
 *
 *  https://github.com/ccg-v/cpp_modules/tree/master/cpp_07/ex01#-the-function-parameter-why-passing-by-reference-and-not-by-value-
 *  https://github.com/ccg-v/cpp_modules/tree/master/cpp_07/ex01#-using-a-more-generalized-template-for-the-callable-parameter-
 */

