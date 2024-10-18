/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:43:35 by ccarrace          #+#    #+#             */
/*   Updated: 2024/10/18 19:44:05 by ccarrace         ###   ########.fr       */
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

unsigned int Span::getN() {
	return _N;
};

/* --- Member functions ----------------------------------------------------- */

void	Span::addNumber(unsigned int num) {
	if (_N == 0)
		throw SpanIsEmptyException();
	if (_vec.size() >= _N)
		throw SpanIsFullException();	
	else {
		_vec.push_back(num);
		std::cout << "\t" << num << " added" << std::endl;
	}
}

unsigned int Span::longestSpan() {
	if (_vec.size() >= 2)
		return *std::max_element(_vec.begin(), _vec.end()) - *std::min_element(_vec.begin(), _vec.end());
	if (_N == 0)
		throw SpanIsEmptyException();
	else
		throw SpanTooSmallException();
}

/*
 *	shortestSpan()
 *
 *	-	If the vector hasn't at least two elements, throw an exception
 *	- 	Start storing the maximum possible span between two integers (INT_MAX)
 *	- 	Work with a copy to keep the original vector unaltered
 *	- 	Sort the copy with std::sort algorithm
 *	- 	Traverse the copy calculating the difference between adjacent elements
 *			and store it if it's lesser than the stored span
 */
unsigned int Span::shortestSpan() {
	if (_vec.size() >= 2) {	
		unsigned int shortestSpan = INT_MAX;

		std::vector<int> sortedVec = _vec;
		std::sort(sortedVec.begin(), sortedVec.end());

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

/*	
 *	Fills the span with the desired amount of random numbers, but does not use
 *	a range of iterators
 */
// void Span::fillSpan(unsigned int spanSize) {

//     while (_vec.size() < _N) {
//         this->addNumber(std::rand() % spanSize * 2 + 1);  // Add random numbers
//     }
// 	if (spanSize > _vec.size()) {
// 		throw SpanIsFullException();
// 	}
// }

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	
	for (std::vector<int>::iterator it = begin; it != end; ++it) {
		if (_vec.size() < _N) {
			addNumber(*it);
		} else {
			throw SpanIsFullException();
		}
	}
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

/* --- Insertion operator<< overload ---------------------------------------- */

std::ostream & operator<<(std::ostream & os, const Span & sp) {

	const std::vector<int> & vec = sp.getVector();
    if (vec.empty()) {  // If the vector is empty, throw an exception
        throw Span::SpanIsEmptyException();
    } else {	
		os << "\t{ "; 		
		for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); 
				++it) 
			os << (*it) << " ";	
		os << "}";
	}
    return os;	
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