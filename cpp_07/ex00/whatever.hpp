/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:41:33 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/20 00:29:16 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template <typename T>
void Swap(T *a, T *b)
{	
	T tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

template <typename T>
T Min(T a, T b)
{
	return (a < b ? a : b);
}

template <typename T>
T Max(T a, T b)
{
	return (a > b ? a : b);
}

#endif