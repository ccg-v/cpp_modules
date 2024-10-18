/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 21:26:36 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/18 19:05:05 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* --- Orthodox Canonical Form ---------------------------------------------- */

//	Default constructor
template <typename T>
MutantStack<T>::MutantStack() {
	std::cout << "Default constructor called" << std::endl;
}

//	Copy constructor
template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> & source) {
    std::cout << "Copy constructor called" << std::endl;
	(void)source;
}

// Copy assignment operator
template <typename T>
MutantStack<T> & MutantStack<T>::operator=(const MutantStack<T> & source) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &source) {
        MutantStack<T>::operator=(source); // Call std::stack's assignment operator		
	}
	return *this;
}

// Default destructor
template <typename T>
MutantStack<T>::~MutantStack() {
	std::cout << "Default destructor called" << std::endl;
}

/* --- Member methods ------------------------------------------------------- */

template <typename T>	// (1)
typename MutantStack<T>::iterator MutantStack<T>::begin( )
{
    return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end( )
{
    return this->c.end();
}

/* --- Non member functions ------------------------------------------------- */

// Insertion operator<< overload
template <typename T>
std::ostream & operator<<(std::ostream & os, MutantStack<T> & mstack) {

    if (mstack.empty()) {
        std::cout << "The stack is empty" << std::endl;
    } else {	
		os << "{ "; 		
		for (typename MutantStack<T>::iterator it = mstack.begin(); it != mstack.end(); 
				++it) 
			os << (*it) << " ";	
		os << "}";
	}
    return os;	
};

/*
 *	(1)	Why do iterators need to be templates?
 *
 *		In a templated class, as MutantStack, iterators must also be templates
 *		because their types depend on the type T of the class.
 *
 *		If the class were tied to a specific type (e.g., int), then the iterators 
 *		wouldn't need to be templates. The iteration process itself is independent
 *		of the type of data the stack is storing. It's a behavior of the class, not
 *		the data.
 */