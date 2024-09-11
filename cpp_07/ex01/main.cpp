/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 21:07:46 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/11 21:00:40 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <cctype>   // for std::toupper
#include <string>   // for std::string

int main() {

    /* --- Test 1: Increment each element ---------------------------------- */

    std::cout << "/* ---- Test 1: Add 42 to each element ------------------ */"
              << std::endl << std::endl;

    //  Int array
    int intArr[] = {1, 2, 3, 4, 5};
    size_t length = sizeof(intArr) / sizeof(intArr[0]);
    
    std::cout << "\t// Int array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(intArr, length, printElement<int>);
    std::cout << std::endl;
    iter(intArr, length, incrementElement<int>);
    std::cout << "\tResulting : ";
    iter(intArr, length, printElement<int>);  
    std::cout << "\n" << std::endl;

    // Float array
    float floatArr[] = {1.1f, 2.2f, 3.3f, 4.4f, 5.5f};
    length = sizeof(floatArr) / sizeof(floatArr[0]);
    
    std::cout << "\t// Float array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(floatArr, length, printElement<float>);
    std::cout << std::endl;
    iter(floatArr, length, incrementElement<float>);
    std::cout << "\tResulting : ";   
    iter(floatArr, length, printElement<float>);  
    std::cout << "\n" << std::endl;

    // Double array
    double doubleArr[] = {1.5, 2.5, 3.5, 4.5, 5.5};
    length = sizeof(doubleArr) / sizeof(doubleArr[0]);

    std::cout << "\t// Double array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(doubleArr, length, printElement<double>);
    std::cout << std::endl;
    iter(doubleArr, length, incrementElement<double>);
    std::cout << "\tResulting : ";  
    iter(doubleArr, length, printElement<double>);   
    std::cout << "\n" << std::endl;

    // Char array
    char charArr[] = {'A', 'B', 'C', 'D', 'E'};
    length = sizeof(charArr) / sizeof(charArr[0]);

    std::cout << "\t// Char array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(charArr, length, printElement<char>);
    std::cout << std::endl;
    iter(charArr, length, incrementElement<char>);
    std::cout << "\tResulting : ";  
    iter(charArr, length, printElement<char>); 
    std::cout << "\n" << std::endl;

	// Function template specializations
    // String array
    std::string strArr[] = {"Goodbye", "Cruel", "World"};
    length = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "\t// Function template full specializations\n" << std::endl;
    std::cout << "\t// String array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(strArr, length, printElement<std::string>);
    std::cout << std::endl;
    iter(strArr, length, incrementElement<std::string>);
    std::cout << "\tResulting : "; 
    iter(strArr, length, printElement<std::string>);
    std::cout << "\n" << std::endl;

    // Struct array
    Point pointArr[] = {{1, 2}, {3, 4}, {5, 6}};
    length = sizeof(pointArr) / sizeof(pointArr[0]);
    
    std::cout << "\t// Struct array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(pointArr, length, printElement<Point>);
    std::cout << std::endl;
    iter(pointArr, length, incrementElement<Point>);
    std::cout << "\tResulting : "; 
    iter(pointArr, length, printElement<Point>);
    std::cout << "\n" << std::endl;

    // Pointer array
    int a = 1, b = 2, c = 3;
    int* ptrArr[] = {&a, &b, &c};
    length = sizeof(ptrArr) / sizeof(ptrArr[0]);

    std::cout << "\t// Pointer array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(ptrArr, length, printPointerElement);
    std::cout << std::endl;
    iter(ptrArr, length, incrementElement<int*>);
    std::cout << "\tResulting : ";
    iter(ptrArr, length, printPointerElement);
    std::cout << "\n" << std::endl;

    /* --- Test 2 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 2: Convert to uppercase --------------------- */"
              << std::endl << std::endl;

    // String array
    length = sizeof(strArr) / sizeof(strArr[0]);

    std::cout << "\t// String array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(strArr, length, printElement<std::string>);
    std::cout << std::endl;
    iter(strArr, length, toUpperCase<std::string>);
    std::cout << "\tResulting : ";
    iter(strArr, length, printElement<std::string>);
    std::cout << "\n" << std::endl;

    // Char array (I use the array of chars defined and transformed in Test 1)
    length = sizeof(charArr) / sizeof(charArr[0]);
    
    std::cout << "\t// Char array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(charArr, length, printElement<char>);
    std::cout << std::endl;
    iter(charArr, length, toUpperCase<char>);
    std::cout << "\tResulting : ";  
    iter(charArr, length, printElement<char>); 
    std::cout << "\n" << std::endl;

    /* --- Test 3 ---------------------------------------------------------- */

    std::cout << "/* ---- Test 3: Edge cases ------------------------------- */"
              << std::endl << std::endl;
    int emptyArr[] = {};
    length = sizeof(emptyArr) / sizeof(emptyArr[0]);

    std::cout << "\t// Empty array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(emptyArr, length, printElement<int>);
    std::cout << std::endl;
    iter(emptyArr, length, incrementElement<int>);
    std::cout << "\tResulting : "; 
    iter(emptyArr, length, printElement<int>);
    std::cout << std::endl;
	std::cout << "\tArray size: " << length << std::endl;
    std::cout << std::endl;

    int singleElemArr[] = {42};
    length = sizeof(singleElemArr) / sizeof(singleElemArr[0]);

    std::cout << "\t// Single element array" << std::endl;
    std::cout << "\tOriginal  : ";
    iter(singleElemArr, length, printElement<int>);
    std::cout << std::endl;
    iter(singleElemArr, length, incrementElement<int>);
    std::cout << "\tResulting : "; 
    iter(singleElemArr, length, printElement<int>);
    std::cout << std::endl;
	std::cout << "\tArray size: " << length << std::endl;
    std::cout << std::endl;

    return 0;
}
