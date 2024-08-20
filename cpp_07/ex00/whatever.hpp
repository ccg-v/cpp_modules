/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:41:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/20 02:26:33 by ccarrace         ###   ########.fr       */
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

// template <typename T>
// void swap(T *a, T *b)
// {	
// 	T tmp;

// 	tmp = *a;
// 	*a = *b;
// 	*b = tmp;
// }

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
 *	(1) Notice that this implementation would not work in C because C does not 
 *		support references (`T &a`, `T & b`) like C++ does.
 */