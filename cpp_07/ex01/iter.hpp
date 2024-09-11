/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 19:05:01 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/11 20:25:50 by ccarrace         ###   ########.fr       */
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

// Primary template for iterating over an array with a function that does not modify elements
template <typename T, typename F>   // (1)
// void iter(T* array, size_t length, void (*f)(T const &)) {
void iter(T* array, size_t length, F f) {
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

// Primary template for incrementing an element
template <typename T>
void incrementElement(T& element) {
    element += 42;
}

// Full specialization for incrementing the Point struct (3)
template <>
void incrementElement(Point & p) {
    p.x += 42;
    p.y += 42;
}

// Full specialization for incrementing/appending a string
template <>
void incrementElement(std::string & str) {
    str += "!!!";
}

// Wrapper function for incrementing a pointer value (4)
void incrementPointerElement(int* p) {
    incrementElement(*p);
}

/* --- CONVERSION TO UPPERCASE FUNCTIONS ------------------------------------ */

// Primary template to convert string to uppercase
template <typename T>
void toUpperCase(T & str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

// Full specialization of toUpperCase for single chars
template <>
void toUpperCase(char & c) {
    c = std::toupper(static_cast<unsigned char>(c));
}

/* --- PRINTING FUNCTIONS --------------------------------------------------- */

// Primary template for printing an element
template <typename T>
void printElement(const T& element) {
    std::cout << std::fixed << std::setprecision(1) << "[" << element << "] ";
}

// Wrapper function for printing a pointer value (4)
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

/*
 *	(3) Template Specializations:
 *		
 *		https://github.com/ccg-v/cpp_modules/tree/master/cpp_07/ex01#-primary-templates-and-specializations-
 */

/* 
 *  (4) Wrapper functions to dereference the pointer and call 
 *      'incrementElement()'/'printElement()' with the dereferenced value.
 *
 *      Overloading 'incrementElement()'/'printElement()' doesn't work 
 *      because the compiler can't deduce which version to use when passing
 *      it as a template argument and returns the "couldn't deduce template 
 *      parameter 'F'" errors.
 *
 *      Template specialization in this case doesn't solve the underlying 
 *      issue of needing to dereference the pointers before applying the 
 *      operation
 */