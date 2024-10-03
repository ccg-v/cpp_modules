/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:43:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/03 22:18:11 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default Constructor
Span::Span() : _N(0) {
	std::cout << "Span Default Constructor called" << std::endl;
}

// Copy constructor
Span::Span(const Span & source) : _N(source._N) {
	std::cout << "Span Copy Constructor called"  << std::endl;
	_vec.reserve(source._vec.size());	// (1)

	for (std::vector<int>::const_iterator srcIt = source._vec.begin(); srcIt != source._vec.end(); 
			++srcIt)
		_vec.push_back(*srcIt);
}

// Copy assignment operator
Span &Span::operator=(const Span & source) {
	std::cout << "Span Copy Assignment Operator called" << std::endl;
	if (this == &source)
		return *this;
	
	// delete[] this.vec;	// (2)
	this->_N = source._N;
	this->_vec.resize(source._vec.size());	// (3)
	
	std::vector<int>::const_iterator srcIt = source._vec.begin();	// (4)
	std::vector<int>::iterator dstIt = this->_vec.begin();
	
	while (srcIt != source._vec.end()) {
		*dstIt = *srcIt;
		srcIt++;
		dstIt++;
	}
	return *this;
}

// Default destructor	
Span::~Span() {
	std::cout << "Span Default Destructor called" << std::endl;
}

/* --- Parameterized constructor -------------------------------------------- */

Span::Span(unsigned int N) : _N(N){
	std::cout << "Span Parameterized Constructor called" << std::endl;
	_vec.reserve(N);  // Preallocate space for N elements (optional) (5)
}

/* --- Getters -------------------------------------------------------------- */

const std::vector<int> & Span::getVector() const {
	return _vec;
}

/* --- Member functions ----------------------------------------------------- */

void	Span::addNumber(unsigned int num) {
	std::cout << "_vec.size is " << _vec.size() << std::endl;
	if (_vec.size() == 0)
		throw SpanIsEmptyException();
	if (_vec.size() > _N)
		throw SpanIsFullException();	
	else {
		_vec.push_back(num);
		std::cout << "\t" << num << " added" << std::endl;
	}
}

unsigned int Span::longestSpan() {
	if (_vec.size() >= 2)
		return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
	throw SpanTooSmallException();
}

unsigned int Span::shortestSpan() {
	if (_vec.size() >= 2) {	
		unsigned int shortestSpan = INT_MAX;  // Start with the maximum possible value

		// First, sort the vector to find adjacent differences
		std::vector<int> sortedVec = _vec;  // Copy the original vector
		std::sort(sortedVec.begin(), sortedVec.end());  // Sort the copied vector

		// Calculate the minimum difference between adjacent elements
		for (std::vector<int>::iterator it = sortedVec.begin(); it != sortedVec.end() - 1; ++it) {
			unsigned int diff = *(it + 1) - *it;
			if (diff < shortestSpan) {
				shortestSpan = diff;
			}
		}

		return shortestSpan;
	}
	throw SpanTooSmallException();
}

/* --- Exceptions ----------------------------------------------------------- */

const char* Span::SpanIsEmptyException::what() const throw() {
    return "\tException: The span is empty";
}

const char* Span::SpanIsFullException::what() const throw() {
    return "\tException: No more elements added: the span is full";
}

const char*	Span::SpanTooSmallException::what() const throw() {
	return "\tException: No span calculated: at least two numbers needed";
}

/*
 *	(1)	Why use vec.size() instead of _N?
 *
 * 		- _N represents the maximum capacity
 * 		- vec.size() is the actual number of elements
 * 		
 * 		If _N is greater than the number of elements in source.vec, we would
 * 		attempt to copy elements that don't exist. This could result in
 * 		undefined behavior (segmentation fault or accessing garbage values).
 * 
 * 		Using _N instead of vec.size() is not safe because _N represents the 
 * 		capacity and doesn't necessarily reflect how many elements are actually 
 * 		stored in the vector. It could lead to out-of-bounds access or wasteful
 * 		memory allocation.
 * 
 * 		Always use vec.size() when you need to know the actual number of
 * 		elements stored in the vector, and use _N only for managing capacity
 * 		constraints.
 */

/*
 *	(2)	Attempting to delete this.vec using delete[] is incorrect because vec
 *		is a std::vector, not a dynamically allocated array. Vectors
 *		automatically handle memory management (allocation and deallocation),
 *		so there's no need to manually delete anything.
 */

/*
 *	(3) 'reserve()' or 'resize()' memory?
 *		
 *		Reserve only allocates memory but does not change the size of the
 *		vector.  We must use resize instead if we want to change the size  
 *		to match source.vec.size(). Otherwise, the iterators may be invalid
 *		because the vector may still have a smaller size, even though the 
 *		capacity is sufficient.
 */

/*
 *	(4)	const_iterator
 *
 * 		Since source is a constant reference (const Span&), we must use 
 * 		const_iterator for source.vec.
 */

/*
 *	(5) Why reserving memory is optional, but useful?
 *		
 *		vec.reserve(N) preallocates memory for N elements, but it does not
 *		change the size of the vector. It only ensures that the vector has
 *		enough capacity to hold N elements before a reallocation is needed.
 *
 *		Without reserve,  the vector dynamically reallocates memory as you
 *		add elements (via push_back or similar functions), which can result
 *		in multiple memory allocations as the vector grows.  Each time the 
 *		vector runs out of space, it doubles its capacity (in many
 *		implementations). This can lead to unnecessary allocations and data
 *		copying.
 */