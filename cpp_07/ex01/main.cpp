/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carlos <carlos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:07:46 by carlos            #+#    #+#             */
/*   Updated: 2024/08/30 01:08:16 by carlos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>
#include <cctype> // for std::toupper
#include <string> // for std::string

// // Function to double an integer
// void doubleElement(const int& element) {
//     std::cout << element * 2 << " ";
// }

// Function to double a number
template <typename T>
void doubleElement(T & num) {
    num *= 2;
}

// Function to increment a float
void incrementElement(const float& element) {
    std::cout << element + 1.0f << " ";
}

// // Function to square a double
// void squareElement(const double& element) {
//     std::cout << element * element << " ";
// }

// Function to square a number
template <typename T>
void squareElement(T & num) {
    num *= num;
}

// // Function to convert string to uppercase in C++98 style
// void toUpperCase(const std::string& str) {
//     std::string upperStr = str;
//     for (size_t i = 0; i < upperStr.length(); ++i) {
//         upperStr[i] = std::toupper(static_cast<unsigned char>(upperStr[i]));
//     }
//     std::cout << upperStr << " ";
// }

// Function to convert string to uppercase
void toUpperCase(std::string & str) {
    for (size_t i = 0; i < str.length(); ++i) {
        str[i] = std::toupper(static_cast<unsigned char>(str[i]));
    }
}

// Function to print an element
template <typename T>
void printElement(const T& element) {
    std::cout << element << " ";
}

// Example of a custom struct
struct Point {
    int x, y;
};

// Function to increment point coordinates
void incrementPoint(const Point& p) {
    std::cout << "(" << p.x + 1 << ", " << p.y + 1 << ") ";
}

template <typename T>
void	printArray(std::string str, T & array, size_t length)
{
    std::cout << str;
	for (size_t i = 0; i < length; i++) {
		std::cout << array[i];
        if (i < (length - 1))
            std::cout << ", ";
        if (i == (length - 1))
            std::cout << "}";
    }
	std::cout << std::endl;
}

int main() {

    // Test 1
    std::cout << "/* --- Test 1: Double each element - Int array ----------- */"
              << std::endl;
    int intArr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(intArr) / sizeof(intArr[0]);
    
    printArray("Original   : {", intArr, length);
    iter(intArr, length, doubleElement<int>);
    printArray("Transformed: {", intArr, length);    
    std::cout << std::endl;

    // Test 2
    std::cout << "/* --- Test 2: Double each element - Float array --------- */"
              << std::endl;
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    length = sizeof(floatArr) / sizeof(floatArr[0]);
    
    printArray("Original   : {", floatArr, length);
    iter(floatArr, length, doubleElement<float>);
    printArray("Transformed: {", floatArr, length);    
    std::cout << std::endl;

    // // Test 2: Float Array
    // std::cout << "Test 2: Float Array - Increment each element" << std::endl;
    // float floatArr[] = {1.1f, 2.2f, 3.3f};
    // iter(floatArr, 3, incrementElement);
    // std::cout << std::endl;

    // Test 3
    std::cout << "/* --- Test 3: Square each element - Double array -------- /*" 
              << std::endl;
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    length = sizeof(doubleArr) / sizeof(doubleArr[0]);

    printArray("Original   : {", doubleArr, length);
    iter(doubleArr, length, squareElement<double>);
    printArray("Transformed: {", doubleArr, length);    
    std::cout << std::endl;

    // Test 4
    std::cout << "/* --- Test 4: Convert to uppercase - String array ------- /*"
              << std::endl;
    std::string strArr[] = {"cpp module 07", "exercise 01", "testing"};
    length = sizeof(strArr) / sizeof(strArr[0]);

    printArray("Original   : {", strArr, length);
    iter(strArr, length, toUpperCase);
    printArray("Transformed: {", strArr, length);

    // Test 5: Custom Object (Point) Array
    std::cout << "Test 5: Point Array - Increment coordinates" << std::endl;
    Point pointArr[] = {{1, 2}, {3, 4}, {5, 6}};
    iter(pointArr, 3, incrementPoint);
    std::cout << std::endl;

    // Test 6: Empty Array
    std::cout << "Test 6: Empty Array" << std::endl;
    int emptyArr[] = {};
    iter(emptyArr, 0, doubleElement<int>);
    std::cout << "Empty array processed without errors." << std::endl;

    // Test 7: Single Element Array
    std::cout << "Test 7: Single Element Array - Double the element" << std::endl;
    int singleArr[] = {42};
    iter(singleArr, 1, doubleElement<int>);
    std::cout << std::endl;

    // Test 8: Large Array
    std::cout << "Test 8: Large Array - Print elements" << std::endl;
    int largeArr[10];
    for (int i = 0; i < 10; ++i) {
        largeArr[i] = i;
    }
    iter(largeArr, 10, printElement<int>);
    std::cout << std::endl;

    return 0;
}


// /* --- Basic scalar types test ---------------------------------------------- */

// template <typename T>
// void doubleElement(T & x) {
//     x *= 2;
// }

// // template <typename T>
// // void printElement(T & x) {
// //     std::cout << x;
// // }

// template <typename T>
// void	printArray(T & array, size_t length)
// {
// 	for (size_t i = 0; i < length; i++) {
// 		std::cout << array[i];
//         if (i < (length - 1))
//             std::cout << ", ";
//         if (i == (length - 1))
//             std::cout << "}";
//     }
// 	std::cout << std::endl;
// }

// int main(void) {

//     int intArray[] = {1, 2, 3, 4};
//     size_t length = sizeof(intArray) / sizeof(intArray[0]);

//     std::cout << "Array of integers\t: {";
//     printArray(intArray, length);

//     iter(intArray, length, doubleElement<int>);

//     std::cout << "Array of integers x2\t: {";
//     printArray(intArray, length);
//     std::cout << std::endl;

//     float floatArray[] = {1.1f, 2.2f, 3.3f, 4.4f};
//     length = sizeof(floatArray) / sizeof(floatArray[0]);

//     std::cout << "Array of floats \t: {";
//     printArray(floatArray, length);

//     iter(floatArray, length, doubleElement<float>);

//     std::cout << "Array of floats x2\t: {";
//     printArray(floatArray, length);
//     std::cout << std::endl;

//     return 0;
// }