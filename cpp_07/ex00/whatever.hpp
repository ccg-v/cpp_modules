/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:41:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/20 14:13:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)	// (1)
{	
	T tmp;

	tmp = a;
	a = b;
	b = tmp;
}

template <typename T>
T min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
T max(T a, T b)
{
	return (a > b ? a : b);
}

#endif

/*
 *	(1) Swapping values can also be done using pointers:
 *
 *				template <typename T>
 *				void swap(T *a, T *b)
 *				{	
 *					T tmp;
 *
 *					tmp = *a;
 *					*a = *b;
 *					*b = tmp;
 *				}
 *
 * 		But this implementation is not valid in our exercise. Reading carefully
 * 		the subject, in 'the main()' provided as an example to check the output
 * 		we can see that 'swap()' doesn't receive pointers but values:
 * 				
 * 				int main(void) {
 * 					int a = 2;
 * 					int b = 3;
 * 					
 * 					::swap( a, b ); // Not swap(&a, &b) 
 * 					// ...
 * 				}
 * 
 * 		The pointer's implementation won't work with the previous main. We need
 * 		to implement swapping with C++ references.
 *		
 *		Notice that this implementation would not work in C because C does not 
 *		support references (`T &a`, `T & b`) like C++ does. Remember a reference
 *		in C++ is an alias for an existing variable. Once the reference has been
 *		created, it is tied directly to the original variable and cannot be 
 *		changed to refer to another variable.
 *		When C programmers use the term "pass-by-reference" they really mean 
 *		passing a pointer to a variable.
 *		
 * 		  Feature			  C Pointer							 C++ Reference				
 * 		|===================|===================================|===============================|
 *		| Declaration Syntax| int *ptr = &var;					| int &ref = var;				|
 *		| Usage				| Explicit dereferencing with *		| Automatic dereferencing		|
 *		| Reassignability	| Reassignable to another address	| Not reassigneable 			|
 *		| Nullability		| Can be null (NULL)				| Cannot be null				|
 *		| Memory			| Stores an address (pointer)		| Just an alias, no extra memory|
 *		|___________________|___________________________________|_______________________________|
 */		
