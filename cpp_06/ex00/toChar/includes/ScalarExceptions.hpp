/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarExceptions.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 21:19:48 by ccarrace          #+#    #+#             */
/*   Updated: 2024/08/18 13:28:30 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAREXCEPTIONS_HPP
# define SCALAREXCEPTIONS_HPP

#include <exception>

class ImpossibleConversionException : public std::exception {
	public:
		const char *what() const throw();
};

class NonDisplayableException : public std::exception {
	public:
		const char *what() const throw();
};

class PositiveInfException : public std:: exception {
	public: 
		const char *what() const throw();
};

class NegativeInfException : public std:: exception {
public: 
	const char *what() const throw();
};

class PositiveInffException : public std:: exception {
	public: 
		const char *what() const throw();
};

class NegativeInffException : public std:: exception {
	public: 
		const char *what() const throw();
};

class NanfException : public std:: exception {
	public: 
		const char *what() const throw();
};

class NanException : public std:: exception {
	public: 
		const char *what() const throw();
};

#endif