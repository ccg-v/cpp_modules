/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:07:46 by carlos            #+#    #+#             */
/*   Updated: 2024/09/01 23:33:29 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>   // for std::toupper
#include <string>   // for std::string
#include <iomanip>  // for std::precision

// // Function to double a number
// template <typename T>
// void doubleElement(T & num) {
//     num *= 2;
// }

// // Function to square a number
// template <typename T>
// void squareElement(T & num) {
//     num *= num;
// }

// Function to convert string to uppercase
void toUpperCase(std::string & str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

// // Function to print an element
// template <typename T>
// void printElement(const T& element) {
//     std::cout << element << " ";
// }

// Function to increment
template <typename T>
void incrementElement(T & element) {
    element += 42;
}

// Specialization for the Point struct
template <>
void incrementElement(Point& p) {
    p.x += 42;
    p.y += 42;
}

// Function to print an element
template <typename T>
void printElement(const T& element) {
    std::cout << std::fixed << std::setprecision(1) << "[" << element << "] ";
}

// template <typename T>
// void	printArray(std::string str, T & array, size_t length)
// {
//     std::cout << "\t" << str;
// 	for (size_t i = 0; i < length; i++) {
// 		std::cout << array[i];
//         if (i < (length - 1))
//             std::cout << ", ";
//         if (i == (length - 1))
//             std::cout << "}";
//     }
// 	std::cout << std::endl;
// }

int main() {

    /* --- Test 1: Double each element ------------------------------------- */

    std::cout << "/* ---- Test 1: Increment each element ------------------- */"
              << std::endl << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(intArr) / sizeof(intArr[0]);
    
    // printArray("Original   : {", intArr, length);
    std::cout << "\tInitial int array  : ";
    iter(intArr, length, printElement<int>);
    std::cout << std::endl;
    iter(intArr, length, incrementElement<int>);
    std::cout << "\tResulting int array: ";
    iter(intArr, length, printElement<int>);
    // printArray("Transformed: {", intArr, length);    
    std::cout << "\n" << std::endl;

    // std::cout << "/* ---- Test 2: Double each element - Float array -------- */"
    //           << std::endl << std::endl;
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    length = sizeof(floatArr) / sizeof(floatArr[0]);
    
    // printArray("Original   : {", floatArr, length);
    std::cout << "\tInitial float array  : ";
    iter(floatArr, length, printElement<float>);
    std::cout << std::endl;
    iter(floatArr, length, incrementElement<float>);
    std::cout << "\tResulting float array: ";    
    iter(floatArr, length, printElement<float>);
    // printArray("Transformed: {", floatArr, length);    
    std::cout << "\n" << std::endl;

    // /* --- Test 3 ---------------------------------------------------------- */

    // std::cout << "/* ---- Test 3: Double each element - Double array ------- */" 
    //           << std::endl << std::endl;
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    length = sizeof(doubleArr) / sizeof(doubleArr[0]);

    // printArray("Original   : {", doubleArr, length);
    std::cout << "\tInitial double array  : ";
    iter(doubleArr, length, printElement<double>);
    std::cout << std::endl;
    iter(doubleArr, length, incrementElement<double>);
    std::cout << "\tResulting double array: "; 
    iter(doubleArr, length, printElement<double>);
    // printArray("Transformed: {", doubleArr, length);    
    std::cout << "\n" << std::endl;

    // /* --- Test 4 ---------------------------------------------------------- */

    // std::cout << "/* ---- Test 4: Increment each element - Char array ------ */" 
    //           << std::endl << std::endl;
    int charArr[] = {'A', 'B', 'C', 'D', 'E'};
    length = sizeof(charArr) / sizeof(charArr[0]);

    // printArray("Original   : {", doubleArr, length);
    std::cout << "\tInitial char array  : ";
    iter(charArr, length, printElement<char>);
    std::cout << std::endl;
    iter(charArr, length, incrementElement<int>);
    std::cout << "\tResulting char array: "; 
    iter(charArr, length, printElement<char>);
    // printArray("Transformed: {", doubleArr, length);    
    std::cout << "\n" << std::endl;

    // /* --- Test 6 ---------------------------------------------------------- */

    // std::cout << "/* ---- Test 6: Increment elements - Struct array -------- */"
    //           << std::endl << std::endl;
    Point pointArr[] = {{1, 2}, {3, 4}, {5, 6}};
    length = sizeof(pointArr) / sizeof(pointArr[0]);
    
    std::cout << "\tInitial struct array  : ";
    iter(pointArr, length, printElement<Point>);
    std::cout << std::endl;
    iter(pointArr, length, incrementElement<Point>);
    std::cout << "\tResulting struct array: "; 
    iter(pointArr, length, printElement<Point>);
    // printArray("Transformed: {", pointArr, length);
    std::cout << "\n" << std::endl;

    /* --- Test 2 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 2: Convert to uppercase - String array ------ */"
              << std::endl << std::endl;
    std::string strArr[] = {"cpp module 07", "exercise 01", "testing"};
    length = sizeof(strArr) / sizeof(strArr[0]);

    // printArray("Original   : {", strArr, length);
    std::cout << "\tOriginal   : ";
    iter(strArr, length, printElement<std::string>);
    std::cout << std::endl;
    iter(strArr, length, toUpperCase);
    std::cout << "\tTransformed: "; 
    iter(strArr, length, printElement<std::string>);
    // printArray("Transformed: {", strArr, length);
    std::cout << "\n" << std::endl;

    /* --- Test 3 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 3: Empty Array ------------------------------ */"
              << std::endl << std::endl;
    int emptyArr[] = {};
    length = sizeof(emptyArr) / sizeof(emptyArr[0]);

    std::cout << "\tOriginal   : ";
    iter(emptyArr, length, printElement<int>);
    std::cout << std::endl;
    iter(emptyArr, length, incrementElement<int>);
    std::cout << "\tResulting  : "; 
    iter(emptyArr, length, printElement<int>);
    std::cout << "\n" << std::endl;
    
    // /* --- Test 8 ---------------------------------------------------------- */

    // std::cout << "/* ---- Test 8: Double elements - Large Array ------------ */"
    //           << std::endl << std::endl;
    // int largeArr[100];
    // for (int i = 0; i < 100; ++i) {
    //     largeArr[i] = i;
    // }

    // std::cout << "\tOriginal   : ";  
    // iter(largeArr, 100, printElement<int>);
    // std::cout << std::endl;
    // iter(largeArr, 100, doubleElement<int>);
    // std::cout << "\tTransformed: ";    
    // iter(largeArr, 100, printElement<int>);
    // std::cout << "\n" << std::endl;

    return 0;
}
