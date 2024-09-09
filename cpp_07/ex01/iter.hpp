/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/10 00:15:44 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <cstddef>
#include <iostream> // for std::ostream
#include <iomanip>  // for std::precision

struct Point {
    int x, y;
};

// Template for iterating over an array with a function that does not modify elements
template <typename T>   // (1)
void iter(T* array, size_t length, void (*f)(T const &)) {
	if (!array || !f)
		return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

// Template for iterating over an array with a function that modifies elements
template <typename T>   // (1)
void iter(T* array, size_t length, void (*f)(T &)) {
	if (!array || !f)
		return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

// Template specialization for arrays of pointers (non-modifying functions)
template <typename T>
void iter(T** array, size_t length, void (*f)(T*)) {
    if (!array || !f)
        return;
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {    // (2)
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

/* --- INCREMENT FUNCTIONS -------------------------------------------------- */

// General template for incrementing an element
template <typename T>
void incrementElement(T& element) {
    element += 42;
}

// Specialization for incrementing the Point struct
template <>
void incrementElement(Point & p) {
    p.x += 42;
    p.y += 42;
}

// Wrapper function for incrementing a pointer value (1)
void incrementPointerElement(int* p) {
    incrementElement(*p);
}

/* --- CONVERSION TO UPPERCASE FUNCTIONS ------------------------------------ */

// Function to convert string to uppercase
template <typename T>
void toUpperCase(T & str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

// Specialization of toUpperCase for single chars
template <>
void toUpperCase(char & c) {
    c = std::toupper(static_cast<unsigned char>(c));
}

/* --- PRINTING FUNCTIONS --------------------------------------------------- */

// General template for printing an element
template <typename T>
void printElement(const T& element) {
    std::cout << std::fixed << std::setprecision(1) << "[" << element << "] ";
}

// Wrapper function for printing a pointer value (1)
void printPointerElement(int* p) {
    printElement(*p);
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