/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/01 19:19:57 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream> // for std::ostream

// Example of a custom struct
struct Point {
    int x, y;
};

template <typename T, typename F>   // (1)
void iter(T* array, size_t length, F f) {
    for (size_t i = 0; i < length; i++) {
        f(array[i]);
    }
}

std::ostream& operator<<(std::ostream& os, const Point& p) {    // (2)
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

#endif

/*
 *  (1) Implementation with less flexibility:
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

/*  
 *  (2) The operator<< is used by C++ streams (like std::cout) to output data.  For 
 *      built-in types like int, float, and char, the operator<< is already defined
 *      by the standard library. However, for custom types like  'Point' structure,
 *      you must define how this operator should behave.
 *  
 *      The operator<< overload function tells the ostream  (like std::cout) how to 
 *      format and print an object of your custom type.  Without this overload, the 
 *      compiler has no idea how to represent the "Point" structure when you try to 
 *      output it using std::cout.
 */