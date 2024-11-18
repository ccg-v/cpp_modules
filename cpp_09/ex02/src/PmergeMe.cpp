/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/19 00:14:29 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _vecStraggler(0) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _pairedVector(source._pairedVector), _deqPairs(source._deqPairs), _vecStraggler(source._vecStraggler) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_pairedVector = source._pairedVector;
		this->_deqPairs = source._deqPairs;
		this->_vecStraggler = source._vecStraggler;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<t_pair> & PmergeMe::getPairSortedVector() {
	return this->_pairedVector;
}

std::deque<t_pair> & PmergeMe::getPairSortedDeque() {
	return this->_deqPairs;
}

int	PmergeMe::getVectorStraggler() {
	return this->_vecStraggler;
}

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setPairSortedVector(int value) {
	if (_pairedVector.empty() || _pairedVector.back()._smaller != -1) {
		// Start new pair
		t_pair newPair;
		newPair._larger = value;
		newPair._smaller = -1;  // Mark as incomplete
		_pairedVector.push_back(newPair);
	} else {
		// // Complete existing pair
		// if (value > _pairedVector.back()._larger) {
		// 	_pairedVector.back()._smaller = _pairedVector.back()._larger;
		// 	_pairedVector.back()._larger = value;
		// } else {
			_pairedVector.back()._smaller = value;
		// }
	}
}

void	PmergeMe::setVectorStraggler(std::vector<t_pair> & pairedSeq) {
	// _vecStraggler = 0;
	if (pairedSeq.back()._smaller == -1) {
		_vecStraggler = pairedSeq.back()._larger;
		pairedSeq.pop_back();
	}
}

/* --- Common member methods ------------------------------------------------ */

void PmergeMe::checkInputAndSetContainers(int argc, char** argv) {

	for (int i = 1; i < argc; ++i) {
		// input validation
		std::string input = argv[i];
		
		if (input.empty() || onlyWhitespace(input)) {
			throw std::runtime_error("Error: input is empty.");
		}

		std::istringstream argStream(input);
		std::string element;

		while (argStream >> element) {
			if (!isPositiveNumber(element)) {
				throw std::runtime_error("Error: sequence must be made up of positive integers.");
			}

			if (!isIntegerRange(element)) {
				throw std::runtime_error("Error: value out of integer's range found.");
			}

			int value = atoi(element.c_str());
			setPairSortedVector(value);
			// setDeque(value);
		}
	}
	
	// // Handle odd length (last pair might be incomplete)
	// int	straggler = 0;
	// if (_pairedVector.back()._smaller == -1) {
	// 	_pairedVector.back()._smaller = _pairedVector.back()._larger;
	// }
}

// void	PmergeMe::setStraggler(std::vector<t_pair> & pairedSeq) {

// 	if (pairedSeq.back()._smaller == -1) {
// 		_vecStraggler = pairedSeq.back()._larger;
// 		pairedSeq.pop_back();
// 	}
// 	// return straggler;
// }

/* --- Member methods for a VECTOR container ------------------------------- */

// void	PmergeMe::sortPairs(std::vector<t_pair> & seq) {
// 	if (seq.size() <= 1)
// 		return;
// 	for (size_t i = 0; i < seq.size() - 1; i += 2) {
// 		if (seq[i] > seq[i + 1]) {
// 			std::swap(seq[i], seq[i + 1]);
// 		}
// 	}
// }

void	PmergeMe::sortPairs(std::vector<t_pair> & pairedSeq) {
	if (pairedSeq.size() <= 1)
		return;
	for (size_t i = 0; i < pairedSeq.size(); i++) {
		if (pairedSeq[i]._smaller > pairedSeq[i]._larger) {
			std::cout << "Swapping smaller " << pairedSeq[i]._smaller << " and larger " << pairedSeq[i]._larger << std::endl; 
			std::swap(pairedSeq[i]._smaller, pairedSeq[i]._larger);
		}
	}
}

// void	PmergeMe::sortSeqByPairs(std::vector<t_pair>& pairedSeq) {
// 	// Sort pairs based on larger value
// 	for (size_t i = 0; i < pairedSeq.size() - 1; i++) {
// 		for (size_t j = 0; j < pairedSeq.size() - i - 1; j++) {
// 			if (pairedSeq[j]._larger > pairedSeq[j + 1]._larger) {
// 				// Pair temp = pairedSeq[j];
// 				// pairedSeq[j] = pairedSeq[j + 1];
// 				// pairedSeq[j + 1] = temp;
// 				std::swap(pairedSeq[j]._larger, pairedSeq[j + 1]._larger);
// 			}
// 		}
// 	}
// }

void	PmergeMe::divideSequence(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<t_pair> & mainChain) {
    if (pairedSeq.size() <= 1) 
        return;
std::cout << "pairedSeq.size() = " << pairedSeq.size() << std::endl; 
    for (size_t i = 0; i < pairedSeq.size(); i++) {
std::cout << "inserting pairedSeq[" << i << "]" << std::endl;
        mainChain.push_back(pairedSeq[i]); // In mainChain I keep the pairs because fordJohnsonSort() needs t_pairs for recursion
		pending.push_back(pairedSeq[i]._smaller); // In pending I store the integer values
    }
	// // STRAGGLER (No porque lo que encuentra es un solo par, no un solo numero; el par puede tener uno o dos elementos)
    // if (pairedSeq.size() % 2 == 1) {
    //     mainChain.push_back(pairedSeq.back());
    // }

    // Debugging
    printContainer("Debug main chain = ", mainChain);
    printContainer("Debug pending    = ", pending);
}


std::vector<int> PmergeMe::buildJacobsthalVec(size_t len)
{
    std::vector<int>    JacobsthalSeq;
    size_t                num;

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

std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int>& jacobsthalSeq, size_t smallerSize) {
    std::vector<int> result;
    std::vector<bool> inserted(smallerSize, false); // Track inserted indices

    // Always add index 0 first
    if (smallerSize > 0) {
        result.push_back(0);
        inserted[0] = true;
    }

    size_t current = 1; // Start interleaving from index 1

    // Process each Jacobsthal boundary
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(smallerSize)) {
            break; // Ignore out-of-bounds Jacobsthal indices
        }

        // Add the current boundary
        if (!inserted[boundary]) {
            result.push_back(boundary);
            inserted[boundary] = true;
        }

//         // Insert interleaved indices between `current` and `boundary`
//         for (size_t j = current; j < static_cast<size_t>(boundary); ++j) {
// std::cout << "\t\t\t\tj = " << j << " | current = " << current << " | boundary = " << boundary << std::endl;
//             if (!inserted[j]) {
// std::cout << "\t\t\t\tinserting " << j << std::endl;	
//                 result.push_back(j);
//                 inserted[j] = true;
//             }
//         }

        // Insert interleaved indices between `current` and `boundary` in descending order
        for (size_t j = boundary; j >= static_cast<size_t>(current); --j) {
// std::cout << "\t\t\t\tcurrent = " << current << " | boundary = " << boundary << std::endl;
            if (!inserted[j]) {
// std::cout << "\t\t\t\tinserting " << j << std::endl;				
                result.push_back(j);
                inserted[j] = true;
            }
        }

        current = boundary + 1; // Move to the next range
    }

//     // Add any remaining indices after the last Jacobsthal boundary
//     for (size_t i = current; i < smallerSize; ++i) {
// std::cout << "\t\t\t\tcurrent = " << i << " | smallerSize = " << smallerSize << std::endl;
//         if (!inserted[i]) {
//             result.push_back(i);
//         }
//     }

    for (size_t i = smallerSize; i > current; --i) {
std::cout << "\t\t\t\tcurrent = " << i << " | smallerSize = " << smallerSize << std::endl;
        if (!inserted[i]) {
            result.push_back(i);
        }
    }

    return result;
}

void PmergeMe::fordJohnsonSort(std::vector<t_pair> & pairedSeq) {
    if (pairedSeq.size() <= 1)
        return;
    // if (pairedSeq.size() == 2) {
    //     if (seq[0] > seq[1])
    //         std::swap(seq[0], seq[1]);
    //     return;
    // }

    // Step 1: Pair and sort
	std::vector<t_pair> mainChain;
    std::vector<int> pending;

    sortPairs(pairedSeq);
	// printContainer("\tpaired vector      = ", pairedSeq);
    divideSequence(pairedSeq, pending, mainChain);
    // fordJohnsonSort(pairedSeq);
	printContainer("Main chain = ", mainChain);
	printContainer("Pending    = ", pending);
	std::cout << "Pending size is " << pending.size() << std::endl;

    // Step 2: Generate insertion order using Jacobsthal sequence
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> insertionIndexes = getInsertionOrder(jacobsthalSeq, pending.size());

	// printContainer("\tpaired vector      = ", pairedSeq);
	// printContainer("\tMain chain        = ", mainChain);
	// printContainer("\tPending           = ", pending);
	printContainer("\tJacobthal nums    = ", jacobsthalSeq);
	printContainer("\tInsertion indexes = ", insertionIndexes);

    // // Step 3: Insert smaller elements into seq based on insertionIndexes
    // std::vector<bool> inserted(pending.size(), false); // Track inserted elements
    // for (size_t i = 0; i < insertionIndexes.size(); ++i) {
    //     size_t insertIndex = insertionIndexes[i];
    //     if (insertIndex < pending.size() && !inserted[insertIndex]) {
    //         int valueToInsert = pending[insertIndex];
    //         size_t position = binarySearch(mainChain, valueToInsert, mainChain.size());

    //         // Debugging
    //         std::cout << "Inserting smaller[" << insertionIndexes[i] << "] = " << valueToInsert << " at larger[" << position << "]" << std::endl;

    //         mainChain.insert((mainChain.begin() + position), valueToInsert);
    //         printContainer("Debug seq after insertion = ", mainChain);

    //         inserted[insertIndex] = true;
    //     }
    // }

    // // Step 4: Insert any remaining elements from smaller
    // for (size_t i = 0; i < pending.size(); ++i) {
    //     if (!inserted[i]) {
    //         int valueToInsert = pending[i];
    //         size_t position = binarySearch(mainChain, valueToInsert, mainChain.size());

    //         // Debugging
    //         std::cout << "Inserting remaining value " << valueToInsert << " at position " << position << std::endl;

    //         mainChain.insert((mainChain.begin() + position), valueToInsert);
    //         printContainer("Debug seq after remaining insertion = ", mainChain);
    //     }
    // }
}

std::ostream& operator<<(std::ostream& os, const t_pair& pair) {
    os << "(" << pair._larger << ", " << pair._smaller << ")";
    return os;
}