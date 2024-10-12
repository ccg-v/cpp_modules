/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:26:36 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/12 22:33:47 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	Default constructor
template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & source) : _innerStack(source._innerStack) {
    std::cout << "Copy constructor called" << std::endl;
}

// Copy assignment operator
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & source) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) {
        this->_innerStack = source._innerStack;		
	}
	return *this;
}

// Default destructor
template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Default destructor called" << std::endl;
}