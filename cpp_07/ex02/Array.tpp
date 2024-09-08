/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 22:54:18 by ccarrace          #+#    #+#             */
/*   Updated: 2024/09/08 23:31:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
template <typename T>
Array<T>::Array() : array(NULL), size(0) {
    std::cout << "Default Array constructor called" << std::endl;
}

// Copy constructor (3)
template <typename T>
Array<T>::Array(const Array & source) : array(NULL), size(source.size) {
	std::cout << "Array copy constructor called" << std::endl;
	array = new T[size];
	for (unsigned int i = 0; i < size; i++)
		array[i] = source.array[i];	// Deep copy of the element (3)
}

// Copy assignment operator
template <typename T>
Array<T>& Array<T>::operator=(const Array & source) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &source)
		return *this;
	if (array.size != source.size) {
		delete[] array;
		size = source.size;
		array = new T[size];
	}
	for (unsigned int i; i < size; i++)
		array[i] = source.array[i];
	return *this;
}

// Default destructor
template <typename T>
Array<T>::~Array() {
	std::cout << "Default Array destructor called" << std::endl;
	delete[] array;
}

/* --- Parameterized constructor -------------------------------------------- */

template <typename T>
Array<T>::Array(const unsigned int n) : array(NULL), size(n) {	// (2)
	std::cout << "Parameterized Array constructor called" << std::endl;
    if (n != 0)
        array = new T[n];
}


/* --- Getters -------------------------------------------------------------- */

template <typename T>   // (1)
unsigned int Array<T>::getSize(void) const {
    return size;
}

/* --- Subscript Operator overloads ----------------------------------------- */

// Non const version (allows modifying the array elements)
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= size)
		throw std::out_of_range("Index is out of array bounds");
	return array[index];
}

// Const version (allows accessing to array elements only in read-only mode)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= size)
		throw std::out_of_range("Index is out of array bounds");
	return array[index];
}

/*  
 *  (1) Even if getSize() returns a fixed type (unsigned int),  it is still a
 *  	member function of the class Array<T>, which is a template class. The
 *  	template  <typename T> syntax  tells the compiler  that this function 
 *  	belongs to a class  that has a template parameter T.  Without it, the 
 *  	compiler would not know that Array is a template class.
 *
 *  	Even if a function inside a class template doesn't depend on the
 *  	template parameter (like getSize()),  you must still include the
 *  	template <typename T> declaration when defining the function 
 *		outside the class.
 */

/*
 *	(2)	If the 'size' passed to the function is a negative value, as unsigned int
 *		it will cause it to be converted into a large positive number, which can
 *		cause unexpected results. This could be avoided by changing the parameter 
 *		type to int, checking for negative values and casting to unsigned int:
 *
 *			template <typename T>
 *			Array<T>::Array(int n) : array(NULL), size(0) {
 *				if (n < 0)
 *					throw std::invalid_argument("Array size cannot be negative.");
 *				else if (n != 0)
 *					size = static_cast<unsigned int>(n);
 *				array = new T[size];
 *			}
 *
 *		But the subject the subject specifically requires the parameter to be an 
 *		unsigned int ("Construction with an unsigned int n as a parameter: Creates
 *		an array of n elements initialized by default."), so we should respect that
 *		requirement.
 */

/*
 *	(3)	The subject specifically says that the implementations of the Copy Constructor
 *		and the Copy Assignment Operator should not affect the original array, and
 *		viceversa. This means that we have to create a deep copy of the original by:
 *		 -	Allocate new memory for the copy.
 *		 -	Copying each element from source.array to the new array so that changes in 
 *			the copied array don't affect the original array.
 *
 *		A shallow copy 
 *
 *    		template <typename T>
 *			Array<T>::Array(const Array & source) : array(source.array), size(source.size) {}
 *
 *		would simply copying the pointer from source.array, meaning both the original
 *		and the copy would share the same memory, which can lead to issues like double
 *		deletion or modifying one affecting the other.
 */

/*
 *	(4)	
 */