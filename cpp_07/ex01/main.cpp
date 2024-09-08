/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:07:46 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/03 19:28:17 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>   // for std::toupper
#include <string>   // for std::string
#include <iomanip>  // for std::precision

/* --- INCREMENTING FUNCTIONS ----------------------------------------------- */

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

/* --- CONVERTING TO UPPERCASE FUNCTIONS ------------------------------------ */

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

int main() {

    /* --- Test 1: Increment each element ---------------------------------- */

    std::cout << "/* ---- Test 1: Increment each element ------------------- */"
              << std::endl << std::endl;

    //  Int array
    int intArr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(intArr) / sizeof(intArr[0]);
    
    std::cout << "\t// Int array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(intArr, length, printElement<int>);
    std::cout << std::endl;
    iter(intArr, length, incrementElement<int>);
    std::cout << "\tTransformed: ";
    iter(intArr, length, printElement<int>);  
    std::cout << "\n" << std::endl;

    // Float array
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    length = sizeof(floatArr) / sizeof(floatArr[0]);
    
    std::cout << "\t// Float array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(floatArr, length, printElement<float>);
    std::cout << std::endl;
    iter(floatArr, length, incrementElement<float>);
    std::cout << "\tTransformed: ";   
    iter(floatArr, length, printElement<float>);  
    std::cout << "\n" << std::endl;

    // Double array
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    length = sizeof(doubleArr) / sizeof(doubleArr[0]);

    std::cout << "\t// Double array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(doubleArr, length, printElement<double>);
    std::cout << std::endl;
    iter(doubleArr, length, incrementElement<double>);
    std::cout << "\tTransformed: ";  
    iter(doubleArr, length, printElement<double>);   
    std::cout << "\n" << std::endl;

    // Char array
    char charArr[] = {'A', 'B', 'C', 'D', 'E'};
    length = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "\t// Char array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(charArr, length, printElement<char>);
    std::cout << std::endl;
    iter(charArr, length, incrementElement<char>);
    std::cout << "\tTransformed: ";  
    iter(charArr, length, printElement<char>); 
    std::cout << "\n" << std::endl;

    // Struct array
    Point pointArr[] = {{1, 2}, {3, 4}, {5, 6}};
    length = sizeof(pointArr) / sizeof(pointArr[0]);
    
    std::cout << "\t// Struct array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(pointArr, length, printElement<Point>);
    std::cout << std::endl;
    iter(pointArr, length, incrementElement<Point>);
    std::cout << "\tTransformed: "; 
    iter(pointArr, length, printElement<Point>);
    std::cout << "\n" << std::endl;

    // Pointer array
    int a = 1, b = 2, c = 3;
    int* ptrArr[] = {&a, &b, &c};
    length = sizeof(ptrArr) / sizeof(ptrArr[0]);

    std::cout << "\t// Pointer array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(ptrArr, length, printPointerElement);
    std::cout << std::endl;
    
    iter(ptrArr, length, incrementPointerElement);
    
    std::cout << "\tTransformed: ";
    iter(ptrArr, length, printPointerElement);
    std::cout << "\n" << std::endl;

    /* --- Test 2 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 2: Convert to uppercase --------------------- */"
              << std::endl << std::endl;

    // String array
    std::string strArr[] = {"cpp module 07", "exercise 01", "testing"};
    length = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "\t// String array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(strArr, length, printElement<std::string>);
    std::cout << std::endl;
    iter(strArr, length, toUpperCase<std::string>);
    std::cout << "\tTransformed: "; 
    iter(strArr, length, printElement<std::string>);
    std::cout << "\n" << std::endl;

    // Char array (I use the array of chars defined and transformed in Test 1)
    length = sizeof(charArr) / sizeof(charArr[0]);
    
    std::cout << "\t// Char array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(charArr, length, printElement<char>);
    std::cout << std::endl;
    iter(charArr, length, toUpperCase<char>);
    std::cout << "\tTransformed: ";  
    iter(charArr, length, printElement<char>); 
    std::cout << "\n" << std::endl;

    /* --- Test 3 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 3: Edge cases ------------------------------- */"
              << std::endl << std::endl;
    int emptyArr[] = {};
    length = sizeof(emptyArr) / sizeof(emptyArr[0]);

    std::cout << "\t// Empty array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(emptyArr, length, printElement<int>);
    std::cout << std::endl;
    iter(emptyArr, length, incrementElement<int>);
    std::cout << "\tResulting  : "; 
    iter(emptyArr, length, printElement<int>);
    std::cout << "\n" << std::endl;

    int singleElemArr[] = {42};
    length = sizeof(singleElemArr) / sizeof(singleElemArr[0]);

    std::cout << "\t// Single element array" << std::endl;
    std::cout << "\tOriginal   : ";
    iter(singleElemArr, length, printElement<int>);
    std::cout << std::endl;
    iter(singleElemArr, length, incrementElement<int>);
    std::cout << "\tResulting  : "; 
    iter(singleElemArr, length, printElement<int>);
    std::cout << "\n" << std::endl;

    return 0;
}

/* 
 *  (1) Wrapper functions to dereference the pointer and call 
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