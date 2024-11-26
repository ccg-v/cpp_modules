/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/26 20:21:25 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() {
	// _vecPairStraggler._smaller = 0;
    // _vecPairStraggler._larger = 0;
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _intsVector(source._intsVector), _pairsVector(source._pairsVector) {} //, _vecPairStraggler(source._vecPairStraggler) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_intsVector = source._intsVector;
		this->_pairsVector = source._pairsVector;
		// this->_vecPairStraggler = source._vecPairStraggler;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<int> & PmergeMe::getIntsVector() {
	return this->_intsVector;
}

std::vector<t_pair> & PmergeMe::getPairsVector() {
	return this->_pairsVector;
}
// std::vector<t_pair> & PmergeMe::getPairSortedVector() {
// 	return this->_pairedVector;
// }

// std::deque<t_pair> & PmergeMe::getPairSortedDeque() {
// 	return this->_deqPairs;
// }

// int	PmergeMe::getVectorStraggler() {
// 	return this->_vecStraggler;=
// }

// t_pair PmergeMe::getVecPairStraggler() {
// 	return this->_vecPairStraggler;
// }

// bool	PmergeMe::getHasStraggler() {
// 	return this->_hasStraggler;
// }

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setIntsVector(int value) {
	_intsVector.push_back(value);
}

void PmergeMe::setPairsVector(void) {
	
    for (size_t i = 0; (i + 1) < _intsVector.size(); i += 2) {
        t_pair newPair;
        // if (_intsVector[i] > _intsVector[i + 1]) {
            newPair._larger = _intsVector[i];
            newPair._smaller = _intsVector[i + 1];
        // } else {
        //     newPair._larger = _intsVector[i + 1];
        //     newPair._smaller = _intsVector[i];
        // }
		if (newPair._smaller > newPair._larger)
			std::swap(newPair._smaller, newPair._larger);
		_pairsVector.push_back(newPair);   
    }

	DEBUG_PRINT(printContainer("pairsVector = ", _pairsVector));
	DEBUG_PRINT(std::cout << " --- Start recursive sorting of main chain --- " << std::endl);
}


// void	PmergeMe::setVectorStraggler(std::vector<t_pair> & pairedSeq) {
// 	if (pairedSeq.back()._smaller == -1) {
// 		_vecStraggler = pairedSeq.back()._larger;
// 		pairedSeq.pop_back();
// 	}
// }

// void	PmergeMe::setVectorPairStraggler(std::vector<t_pair> & mainChain) {
// 	if (mainChain.size() % 2 > 0) {
// 		_vecPairStraggler = mainChain.back();
// 		mainChain.pop_back();
// 	}
// }

// void	PmergeMe::setIntStraggler(std::vector<int> & inputSeq) {
// 	if (inputSeq.size() % 2 == 1) {
// 		_vecIntStraggler = inputSeq.back();
// 		inputSeq.pop_back();
// 	}
// }

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
			// setPairSortedVector(value);
			setIntsVector(value);
			// setDeque(value);
		}
	}

	DEBUG_PRINT(printContainer("intsVector = ", _intsVector));

}

// bool	PmergeMe::hasStraggler(std::vector<t_pair> & pairedSeq) {
// 	if (_pairedVector.back()._smaller == -1) {
// 		_vecStraggler = _pairedVector.back()._larger;
// 		_pairedVector.pop_back();
// 		return true;
// 	}
// 	return false;
// }

/* --- Member methods for a VECTOR container ------------------------------- */

// void	PmergeMe::sortAdjacentNumbers(std::vector<t_pair> & pairedSeq) {
// 	if (pairedSeq.size() <= 1)
// 		return;
// 	for (size_t i = 0; i < pairedSeq.size(); i++) {
// 		if (pairedSeq[i]._smaller > pairedSeq[i]._larger) {
// 			std::cout << "Swapping smaller " << pairedSeq[i]._smaller << " and larger " << pairedSeq[i]._larger << std::endl; 
// 			std::swap(pairedSeq[i]._smaller, pairedSeq[i]._larger);
// 		}
// 	}
// }

void	PmergeMe::sortAdjacentPairs(std::vector<t_pair> & pairedSeq) {

	DEBUG_PRINT(std::cout << "sortAdjacentPairs():" << std::endl);
	
	for (size_t i = 0; (i + 1) < pairedSeq.size(); i += 2) {
		if (pairedSeq[i]._larger > pairedSeq[i + 1]._larger) {
			DEBUG_PRINT(std::cout << "\tSwapping  " << pairedSeq[i] << " and larger " << pairedSeq[i + 1] << std::endl); 
			std::swap(pairedSeq[i], pairedSeq[i + 1]);
		}		
	}

	DEBUG_PRINT(printContainer("\tpairedSeq = ", pairedSeq));
}

void PmergeMe::divideSequence(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending, std::vector<t_pair> & mainChain) {

	DEBUG_PRINT(std::cout << "divideSequence():" << std::endl);

    for (size_t i = 0; (i + 1) < pairedSeq.size(); i +=2) {
        pending.push_back(pairedSeq[i]); 
        mainChain.push_back(pairedSeq[i + 1]); 
    }

    pairedSeq = mainChain;

	DEBUG_PRINT(printContainer("\tmain chain = ", pairedSeq));
	DEBUG_PRINT(printContainer("\tpending    = ", pending));
}

void	PmergeMe::extractPendingAndMainChain(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<int> & mainChain) {

	DEBUG_PRINT(std::cout << " --- End recursive sorting of main chain ----- " << std::endl);
	DEBUG_PRINT(printContainer("Pairs sequence (pre-sorted by pair's larger values) = ", _pairsVector));
	DEBUG_PRINT(std::cout << "extractPendingAndMainChain():" << std::endl);

    for (size_t i = 0; i < pairedSeq.size(); i ++) {

		DEBUG_PRINT(std::cout << "\tAppending " << pairedSeq[i]._larger  << " to main chain" << std::endl);
		DEBUG_PRINT(std::cout << "\tAppending " << pairedSeq[i]._smaller << " to pending" << std::endl);
		
        pending.push_back(pairedSeq[i]._smaller);
		mainChain.push_back(pairedSeq[i]._larger);
    }
	
	DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
	DEBUG_PRINT(printContainer("\tPending    = ", pending));
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

size_t PmergeMe::pairBinarySearch(const std::vector<t_pair> & seq, t_pair value, size_t end) {
    size_t left = 0;
    size_t right = end;
    while (left < right) { 
        size_t mid = (left + right) / 2;
        if (seq[mid]._larger > value._larger)
            right = mid;
        else
            left = mid + 1;
    }
    return left;
}


size_t PmergeMe::intBinarySearch(const std::vector<int> & seq, int value, size_t end) {
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

std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize) {
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

        // Insert interleaved indices between `current` and `boundary` in descending order
        for (size_t j = boundary; j >= static_cast<size_t>(current); --j) {
            if (!inserted[j]) {
                result.push_back(j);
                inserted[j] = true;
            }
        }

        current = boundary + 1; // Move to the next range
    }

    for (size_t i = smallerSize; i > current; --i) {
        if (!inserted[i]) {
            result.push_back(i);
        }
    }

    return result;
}

void PmergeMe::recursiveSort(std::vector<t_pair> & pairedSeq) {

    if (pairedSeq.size() < 1) {
        return;
	}

	std::vector<t_pair> mainChain;
    std::vector<t_pair> pending;

	sortAdjacentPairs(pairedSeq);

	t_pair currentStraggler = {0, 0};
	if (pairedSeq.size() % 2 == 1) {
		currentStraggler = pairedSeq.back();
		pairedSeq.pop_back();

		DEBUG_PRINT(std::cout << "\t<<<<< EXTRACTING " << currentStraggler << " from mainChain" << std::endl);
	}

    divideSequence(pairedSeq, pending, mainChain);

    recursiveSort(mainChain);

	if (currentStraggler._larger != 0 && currentStraggler._smaller != 0) {
		size_t position = pairBinarySearch(mainChain, currentStraggler, mainChain.size());
		mainChain.insert(mainChain.begin() + position, currentStraggler);

		DEBUG_PRINT(std::cout << "\t>>>>> INSERTING " << currentStraggler << " in mainChain" << std::endl);
	}

	DEBUG_PRINT(std::cout << "recursiveSort() unwinding" << std::endl);
	DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));

	pairMergeInsertion(pending, mainChain);
	
	pairedSeq = mainChain;

}


void	PmergeMe::pairMergeInsertion(std::vector<t_pair> & pending, std::vector<t_pair> & mainChain) {
    // Step 2: Generate insertion order using Jacobsthal sequence
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> insertionIndexes = getInsertionOrder(jacobsthalSeq, pending.size());

    // Step 3: Insert smaller elements into seq based on insertionIndexes
    std::vector<bool> inserted(pending.size(), false); // Track inserted elements
    for (size_t i = 0; i < insertionIndexes.size(); ++i) {
        size_t insertIndex = insertionIndexes[i];
        if (insertIndex < pending.size() && !inserted[insertIndex]) {
            t_pair valueToInsert = pending[insertIndex];
            size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size());

            DEBUG_PRINT(std::cout << "\tInserting pending[" << insertionIndexes[i] << "] = " << valueToInsert << " at mainChain[" << position << "]" << std::endl);

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));

            inserted[insertIndex] = true;
        }
    }

    // Step 4: Insert any remaining elements from smaller
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            t_pair valueToInsert = pending[i];
			if (pending[i]._smaller != 0 && pending[i]._larger != 0) {
				size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size());

				DEBUG_PRINT(std::cout << "\tInserting remaining value " << valueToInsert << " at position " << position << std::endl);

				mainChain.insert((mainChain.begin() + position), valueToInsert);
			}
            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
        }
    }
}

 /* 
  *	intMergeInsertion()
  *
  * We pick integers from a vector of integers (pending) and insert them in
  *	another vector of integers (main chain).
  */
void	PmergeMe::intMergeInsertion(std::vector<int> & pending, std::vector<int> & mainChain) {

	DEBUG_PRINT(std::cout << "intMergeInsertion():" << std::endl);
	
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> insertionIndexes = getInsertionOrder(jacobsthalSeq, pending.size());
    // Step 3: Insert smaller elements into seq based on insertionIndexes
    std::vector<bool> inserted(pending.size(), false); // Track inserted elements
    for (size_t i = 0; i < insertionIndexes.size(); ++i) {
        size_t insertIndex = insertionIndexes[i];
        if (insertIndex < pending.size() && !inserted[insertIndex]) {
            int valueToInsert = pending[insertIndex];
            size_t position = intBinarySearch(mainChain, valueToInsert, mainChain.size());

            DEBUG_PRINT(std::cout << "\tInserting pending[" << insertionIndexes[i] << "] = " << valueToInsert << " at mainChain[" << position << "]" << std::endl);

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));

            inserted[insertIndex] = true;
        }
    }

    // Step 4: Insert any remaining elements from smaller
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            int valueToInsert = pending[i];
            size_t position = intBinarySearch(mainChain, valueToInsert, mainChain.size());

            DEBUG_PRINT(std::cout << "\n\tInserting remaining value " << valueToInsert << " at position " << position << std::endl);

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
        }
    }
}

std::ostream& operator<<(std::ostream& os, const t_pair& pair) {
    os << "(" << pair._larger << ", " << pair._smaller << ")";
    return os;
}

