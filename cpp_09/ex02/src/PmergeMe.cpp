/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/14 14:03:58 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) : _vec(source._vec), _deq(source._deq) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_vec = source._vec;
		this->_deq = source._deq;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<int> & PmergeMe::getVector() {
	return this->_vec;
}

std::deque<int> & PmergeMe::getDeque() {
	return this->_deq;
}

/* --- Member methods for a VECTOR container ------------------------------- */

void PmergeMe::sortPairs(std::vector<int> & seq) {
	if (seq.size() <= 1)
		return;
	for (size_t i = 0; i < seq.size() - 1; i += 2) {
		if (seq[i] > seq[i + 1]) {
			std::swap(seq[i], seq[i + 1]);
		}
	}
}

void PmergeMe::divideSequence(std::vector<int> & seq, std::vector<int> & smaller) {
	if (seq.size() <= 1) 
		return;
	
	std::vector<int> larger;
	for (size_t i = 0; i < seq.size() - 1; i += 2) {
		smaller.push_back(seq[i]);
		larger.push_back(seq[i + 1]);
	}
	if (seq.size() % 2 == 1) {
		larger.push_back(seq.back());
	}

	seq = larger;

	printContainer("larger  = ", seq);
	printContainer("smaller = ", smaller);
	std::cout << "--------------------------" << std::endl;
}

std::vector<int> PmergeMe::buildJacobsthalVec(size_t len)
{
	std::vector<int>	JacobsthalSeq;
	size_t				num;

	JacobsthalSeq.push_back(0);
	JacobsthalSeq.push_back(1);
	for (size_t i = 2; i < len; i++) {
		num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		JacobsthalSeq.push_back(num);
	}
	// Remove the first two elements if the sequence has at least two elements
	if (JacobsthalSeq.size() > 2) {
		JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
	}
	return JacobsthalSeq;
}

size_t PmergeMe::binarySearch(const std::vector<int> & seq, int value, size_t end) {
	size_t left = 0;
	size_t right = end;
	while (left < right) {
		size_t mid = (left + right) / 2;
		if (seq[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

// std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t size) {
// 	std::vector<int> insertionOrder;

// 	// Add all Jacobsthal-indexed elements and interleave non-Jacobsthal elements in reverse order
// 	for (size_t i = 0; i < jacobsthalSeq.size(); i++) {
// 		size_t currentJacobIndex = jacobsthalSeq[i];

// 		// Stop if the current Jacobsthal index exceeds the given size
// 		if (currentJacobIndex >= size) break;

// 		// Add current Jacobsthal-indexed element
// 		insertionOrder.push_back(currentJacobIndex);

// 		// If there's a previous Jacobsthal index, add interleaved indices in reverse order
// 		if (i > 0) {
// 			size_t prevJacobIndex = jacobsthalSeq[i - 1];
// 			for (size_t j = currentJacobIndex - 1; j > prevJacobIndex; --j) {
// 				if (j < size) {
// 					insertionOrder.push_back(j);
// 				}
// 			}
// 		}
// 	}

	// // For any remaining values past the last Jacobsthal index, add them in reverse order
	// size_t lastJacobIndex = jacobsthalSeq.back();
	// for (size_t k = size - 1; k > lastJacobIndex; --k) {
	// 	insertionOrder.push_back(k);
	// }

	// // Ensure '0' is included as the first index if it's missing
	// if (!insertionOrder.empty() && insertionOrder[0] != 0) {
	// 	insertionOrder.insert(insertionOrder.begin(), 0);
	// }

// 	return insertionOrder;
// }

std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int> & jacobsthalOrder, size_t numElements) {
    std::vector<int> insertionOrder;
    std::vector<bool> included(numElements, false);  // Track included indices
    size_t jIndex = 0;

    // Add Jacobsthal indices to insertion order, ensuring each is within bounds
    while (jIndex < jacobsthalOrder.size() && static_cast<size_t>(jacobsthalOrder[jIndex]) < numElements) {
        if (!included[jacobsthalOrder[jIndex]]) {
            insertionOrder.push_back(jacobsthalOrder[jIndex]);
            included[jacobsthalOrder[jIndex]] = true;
        }
        ++jIndex;
    }

    // Fill in any remaining indices sequentially
    for (size_t i = 0; i < numElements; ++i) {
        if (!included[i]) {
            insertionOrder.push_back(i);
std::cout << "##### Inserting " << i << std::endl;
printContainer("included = ", included);
            included[i] = true;
        }
std::cout << "[" << i << "] ";
    }

    return insertionOrder;
}


void	PmergeMe::fordJohnsonSort(std::vector<int> & seq) {
	if (seq.size() <= 1)
		return;
	if (seq.size() == 2) {
		if (seq[0] > seq[1])
			std::swap(seq[0], seq[1]);
		return;
	}

	// Step 1: Pair and sort
	std::vector<int> smaller;
	sortPairs(seq);
	divideSequence(seq, smaller);
	fordJohnsonSort(seq);

	// Step 2: Generate insertion order using Jacobsthal sequence
	std::vector<int> jacobsthalOrder = buildJacobsthalVec(smaller.size());
	std::vector<int> insertionOrder = getInsertionOrder(jacobsthalOrder, smaller.size());

	printContainer("\nLarger (main chain)    :\t", seq);		
	printContainer("Smaller (pend elements):\t", smaller);
	printContainer("Jacobsthal numbers     :\t", jacobsthalOrder);
	printContainer("Insertion indexes      :\t", insertionOrder);

	// Step 3: Insert smaller elements into seq based on insertionOrder
	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t insertIndex = insertionOrder[i];
		if (insertIndex < smaller.size()) {
			int valueToInsert = smaller[insertIndex];
			size_t position = binarySearch(seq, valueToInsert, seq.size());
			seq.insert((seq.begin() + position), valueToInsert);
			// debug
			std::cout << "\n   Inserting value " << valueToInsert << " at position " << position << std::endl;
			printContainer("      Updated larger sequence:\t", seq);
		}
	}
}

/* --- Member methods for a DEQUE container ---------------------------------- */

/*
 *	Lists cannot be traversed by indexes because they don't support random
 *	access like vectors do. Lists only support sequential access, so we need
 *	to use iterators for traversal.
 */

void PmergeMe::sortPairs(std::deque<int> & seq) {
	if (seq.size() <= 1)
		return;
	for (size_t i = 0; i < seq.size() - 1; i += 2) {
		if (seq[i] > seq[i + 1]) {
			std::swap(seq[i], seq[i + 1]);
		}
	}
}

void PmergeMe::divideSequence(std::deque<int> & seq, std::deque<int> & smaller) {
	if (seq.size() <= 1) 
		return;
	
	std::deque<int> larger;
	for (size_t i = 0; i < seq.size() - 1; i += 2) {
		smaller.push_back(seq[i]);
		larger.push_back(seq[i + 1]);
	}
	if (seq.size() % 2 == 1) {
		larger.push_back(seq.back());
	}

	seq = larger;

	printContainer("larger  = ", seq);
	printContainer("smaller = ", smaller);
	std::cout << "--------------------------" << std::endl;
}

std::deque<int>	PmergeMe::buildJacobsthalDeq(size_t len)
{
	std::deque<int>	JacobsthalSeq;
	size_t				num;

	JacobsthalSeq.push_back(0);
	JacobsthalSeq.push_back(1);
	for (size_t i = 2; i < len; i++) {
		num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		JacobsthalSeq.push_back(num);
	}
	// Remove the first two elements if the sequence has at least two elements
	if (JacobsthalSeq.size() > 2) {
		JacobsthalSeq.pop_front();
		JacobsthalSeq.pop_front();
	}
	return JacobsthalSeq;
}

size_t PmergeMe::binarySearch(const std::deque<int> & seq, int value, size_t end) {
	size_t left = 0;
	size_t right = end;
	while (left < right) {
		size_t mid = (left + right) / 2;
		if (seq[mid] > value)
			right = mid;
		else
			left = mid + 1;
	}
	return left;
}

std::deque<int> PmergeMe::getInsertionOrder(const std::deque<int> & jacobsthalSeq, size_t size) {
    std::deque<int> insertionOrder;

    // Add all Jacobsthal-indexed elements and interleave non-Jacobsthal elements in reverse order
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        size_t currentJacobIndex = jacobsthalSeq[i];

        // Stop if the current Jacobsthal index exceeds the given size
        if (currentJacobIndex >= size)
			break;

        // Add the current Jacobsthal-indexed element
        insertionOrder.push_back(currentJacobIndex);

        // Interleave non-Jacobsthal elements in reverse order between previous and current Jacobsthal indices
        if (i > 0) {
            size_t prevJacobIndex = jacobsthalSeq[i - 1];
            for (size_t j = currentJacobIndex - 1; j > prevJacobIndex; --j) {
                if (j < size) {
                    insertionOrder.push_back(j);
                }
            }
        }
    }

    // For any remaining values past the last Jacobsthal index, add them in reverse order
    size_t lastJacobIndex = jacobsthalSeq.empty() ? 0 : jacobsthalSeq.back();
    for (size_t k = size - 1; k > lastJacobIndex; --k) {
        insertionOrder.push_back(k);
    }

    // Ensure '0' is included as the first index if it's missing
    if (!insertionOrder.empty() && insertionOrder.front() != 0) {
        insertionOrder.push_front(0);
    }

    return insertionOrder;
}

void	PmergeMe::fordJohnsonSort(std::deque<int> & seq) {
	if (seq.size() <= 1)
		return;
	if (seq.size() == 2) {
		if (seq[0] > seq[1])
			std::swap(seq[0], seq[1]);
		return;
	}

	// Step 1: Pair and sort
	std::deque<int> smaller;
	sortPairs(seq);
	divideSequence(seq, smaller);
	fordJohnsonSort(seq);

	// Step 2: Generate insertion order using Jacobsthal sequence
	std::deque<int> jacobsthalOrder = buildJacobsthalDeq(smaller.size());
	std::deque<int> insertionOrder = getInsertionOrder(jacobsthalOrder, smaller.size());

	printContainer("\nLarger (main chain)    :\t", seq);		
	printContainer("Smaller (pend elements):\t", smaller);
	printContainer("Jacobsthal numbers     :\t", jacobsthalOrder);
	printContainer("Insertion indexes      :\t", insertionOrder);

	// Step 3: Insert smaller elements into seq based on insertionOrder
	for (size_t i = 0; i < insertionOrder.size(); ++i) {
		size_t insertIndex = insertionOrder[i];
		if (insertIndex < smaller.size()) {
			int valueToInsert = smaller[insertIndex];
			size_t position = binarySearch(seq, valueToInsert, seq.size());
			// insertElement(seq, valueToInsert, pos);
			seq.insert((seq.begin() + position), valueToInsert);
			// debug
			std::cout << "\n   Inserting value " << valueToInsert << " at position " << position << std::endl;
			printContainer("      Updated larger sequence:\t", seq);
		}
	}
}