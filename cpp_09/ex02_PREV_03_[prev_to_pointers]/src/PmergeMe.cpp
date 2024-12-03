/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/11/30 00:57:27 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _intsVector(source._intsVector), _pairsVector(source._pairsVector), 
	_intStraggler(source._intStraggler), _pairStraggler(source._pairStraggler) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_intsVector = source._intsVector;
		this->_pairsVector = source._pairsVector;
		this->_intStraggler = source._intStraggler;
		this->_pairStraggler = source._pairStraggler;
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

std::vector<int> & PmergeMe::getIntStraggler() {
	return this->_intStraggler;
}

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setIntsVector(int value) {
	_intsVector.push_back(value);
}

void PmergeMe::setPairsVector(void) {
	
    for (size_t i = 0; (i + 1) < _intsVector.size(); i += 2) {
        t_pair newPair;
            newPair._larger = _intsVector[i];
            newPair._smaller = _intsVector[i + 1];
		if (newPair._smaller > newPair._larger)
			std::swap(newPair._smaller, newPair._larger);
		_pairsVector.push_back(newPair);   
    }

	DEBUG_PRINT(printContainer("pairsVector = ", _pairsVector));
	DEBUG_PRINT(std::cout << "\n --- Start recursive sorting of main chain --- " << std::endl);
}


void	PmergeMe::setIntStraggler() {
if (_intsVector.size() % 2 == 1)
	{
		_intStraggler.push_back(_intsVector.back());
		_intsVector.pop_back();
		DEBUG_PRINT(printContainer("intStraggler = ", _intStraggler));
		DEBUG_PRINT(printContainer("intsVector without straggler = ", _intsVector));
	}
}

/* --- Common member methods ------------------------------------------------ */

void PmergeMe::checkInputAndSetContainers(int argc, char** argv) {

	for (int i = 1; i < argc; ++i) {

		std::string input = argv[i];
		
		if (input.empty() || onlyWhitespace(input)) {
			throw std::runtime_error("Error: input is empty.");
		}

		std::istringstream argStream(input);
		std::string element;

		while (argStream >> element) {
			if (!isPositiveNumber(element)) {
				throw std::runtime_error("Error: sequence values must be positive integers.");
			}

			if (!isIntegerRange(element)) {
				throw std::runtime_error("Error: value out of integer's range found.");
			}

			int value = atoi(element.c_str());
			
			setIntsVector(value);
			// setDeque(value);
		}
	}

	if (isSorted(getIntsVector()))
		throw std::runtime_error("Error: the input sequence is already sorted.");

	DEBUG_PRINT(printContainer("intsVector = ", _intsVector));

}

/* ===========================================================================

   Member methods for a VECTOR container

   ===========================================================================*/

void	PmergeMe::sortAdjacentPairs(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending) {

	DEBUG_PRINT(std::cout << "sortAdjacentPairs():" << std::endl);

	for (size_t i = 0; (i + 1) < pairedSeq.size(); i += 2) {
		if (pairedSeq[i]._larger > pairedSeq[i + 1]._larger) {
			DEBUG_PRINT(std::cout << "\tSwapping main chain " << pairedSeq[i] << " and " << pairedSeq[i + 1] << std::endl); 
			std::swap(pairedSeq[i], pairedSeq[i + 1]);
			if (pending.size() > 0) {
				std::swap(pending[i], pending[i + 1]);
				DEBUG_PRINT(std::cout << "\tSwapping pending " << pending[i] << " and " << pending[i + 1] << std::endl);
			}
		}		
	}
if (pending.size() == 0)
	std::cout << "PENDING IS EMPTY!!!!!!!!!!!!!!!!!!" << std::endl;
printContainer("============== Pending = ", pending);	
	DEBUG_PRINT(printContainer("\tHOLA = ", pairedSeq));
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

	DEBUG_PRINT(std::cout << " --- End recursive sorting of main chain -----\n" << std::endl);
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

// size_t	PmergeMe::intBubbleSort(const std::vector<int> & seq, int value, size_t end, size_t & comparisons) {
// 	size_t len = seq.size();
// 	for (size_t i = 0; i < len; i++) {
// 		if (seq)
// 	}
// }

size_t PmergeMe::pairBinarySearch(const std::vector<t_pair> & mainChain, t_pair value, size_t end, size_t & comparisons) {

    size_t left = 0;
    size_t right = end;
    while (left < right) { 
        size_t mid = (left + right) / 2;
        if (mainChain[mid]._larger > value._larger)
            right = mid;
        else
            left = mid + 1;
		comparisons++;
    }
    return left;
}

size_t PmergeMe::intBinarySearch(const std::vector<int> & mainChain, int value, size_t end, size_t & comparisons) {
	// size_t partial_comp = comparisons;
	std::cout << "\t\tupperBound search is mainChain[" << end << "] = " << mainChain[end] << std::endl; 
    size_t left = 0;
    size_t right = end;
    while (left < right) { 
        size_t mid = (left + right) / 2;
        if (mainChain[mid] > value)
            right = mid;
        else
            left = mid + 1;
		comparisons++;
		std::cout << "\t\t...comparing pending " << value << " with " << mainChain[mid] << " in position [" << mid << "]..." << std::endl;
    }
	// std::cout << "\t\tcomparisons made = " << comparisons - partial_comp << " | total = " << comparisons << std::endl;
    return left;
}

std::vector<int> PmergeMe::getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t smallerSize) {
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

// void PmergeMe::recursiveSort(std::vector<t_pair> & pairedSeq, size_t & comparisons) {

//     if (pairedSeq.size() < 1) {
//         return;
// 	}

// 	std::vector<t_pair> mainChain;
//     std::vector<t_pair> pending;

// 	sortAdjacentPairs(pairedSeq);

// 	// Store first straggler
// 	t_pair currentStraggler = {0, 0};
// 	if (pairedSeq.size() % 2 == 1) {
// 		currentStraggler = pairedSeq.back();
// 		pairedSeq.pop_back();

// 		DEBUG_PRINT(std::cout << "\t<<<<< EXTRACTING " << currentStraggler << " from mainChain" << std::endl);
// 	}

//     divideSequence(pairedSeq, pending, mainChain);

//     recursiveSort(mainChain, comparisons);

// 	// Insert back first straggler
// 	if (currentStraggler._larger != 0 && currentStraggler._smaller != 0) {

// 		DEBUG_PRINT(std::cout << "\t>>>>> INSERTING " << currentStraggler << " in mainChain" << std::endl);
		
// 		size_t position = pairBinarySearch(mainChain, currentStraggler, mainChain.size(), comparisons);
// 		mainChain.insert(mainChain.begin() + position, currentStraggler);
// 	}

// 	DEBUG_PRINT(std::cout << "recursiveSort() unwinding: " << std::endl);
// 	DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));

// 	pairMergeInsertion(pending, mainChain, comparisons);
	
// 	pairedSeq = mainChain;

// }

void PmergeMe::recursiveSort(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & mainChain, std::vector<t_pair> & pending, std::vector<int> & pairPositions, size_t & comparisons) {

    if (pairedSeq.size() < 1) {
        return;
	}

	// std::vector<t_pair> mainChain;
    // std::vector<t_pair> pending;

	sortAdjacentPairs(pairedSeq, pending);


	// Store first straggler
	t_pair currentStraggler = {0, 0};
	if (pairedSeq.size() % 2 == 1) {
		currentStraggler = pairedSeq.back();
		pairedSeq.pop_back();

		DEBUG_PRINT(std::cout << "\t<<<<< EXTRACTING " << currentStraggler << " from mainChain" << std::endl);
	}

    divideSequence(pairedSeq, pending, mainChain);

    recursiveSort(pairedSeq, mainChain, pending, pairPositions, comparisons);

	// Insert back first straggler
	if (currentStraggler._larger != 0 && currentStraggler._smaller != 0) {

		DEBUG_PRINT(std::cout << "\t>>>>> INSERTING " << currentStraggler << " in mainChain" << std::endl);
		
		size_t position = pairBinarySearch(mainChain, currentStraggler, mainChain.size(), comparisons);
		mainChain.insert(mainChain.begin() + position, currentStraggler);
	}

	DEBUG_PRINT(std::cout << "recursiveSort() unwinding: " << std::endl);
	DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));



	pairMergeInsertion(pending, mainChain, pairPositions, comparisons);
	
	pairedSeq = mainChain;

}

/* 
 *	pairMergeInsertion()
 *
 *	We pick PAIRS of integers from a vector of PAIRS of integers (pending) and insert them in
 *	another vector of PAIRS of integers (main chain).
 */
// void	PmergeMe::pairMergeInsertion(std::vector<t_pair> & pending, std::vector<t_pair> & mainChain, size_t & comparisons) {

//     // Generate insertion order using Jacobsthal sequence
//     std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
//     std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, pending.size());

//     // Insert smaller elements into seq based on pickingIndexes
//     std::vector<bool> inserted(pending.size(), false); // Track inserted elements
//     for (size_t i = 0; i < pickingIndexes.size(); ++i) {
//         size_t pickingIndex = pickingIndexes[i];
//         if (pickingIndex < pending.size() && !inserted[pickingIndex]) {
//             t_pair valueToInsert = pending[pickingIndex];
//             size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size(), comparisons);
//             mainChain.insert((mainChain.begin() + position), valueToInsert);
//             inserted[pickingIndex] = true;

//             DEBUG_PRINT(std::cout << "\tInserting pending[" << pickingIndexes[i] << "] = " << valueToInsert << " at mainChain[" << position << "]" << std::endl);
//             DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
//         }
//     }

//     // Insert any remaining elements from smaller
//     for (size_t i = 0; i < pending.size(); ++i) {
//         if (!inserted[i]) {
//             t_pair valueToInsert = pending[i];
// 			if (pending[i]._smaller != 0 && pending[i]._larger != 0) {
// 				size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size(), comparisons);

// 				DEBUG_PRINT(std::cout << "\tInserting remaining value " << valueToInsert << " at position " << position << std::endl);

// 				mainChain.insert((mainChain.begin() + position), valueToInsert);
// 			}
//             DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
//         }
//     }
// }


void	PmergeMe::pairMergeInsertion(std::vector<t_pair> & pending, std::vector<t_pair> & mainChain, std::vector<int> & pairPositions,  size_t & comparisons) {

	DEBUG_PRINT({if(pending.size() > 1) std::cout << "\npairMergeInsertion():" << std::endl;});
	DEBUG_PRINT({if (pending.size() == 1 && _pairStraggler.size() > 0) printContainer("\n\tpairStraggler = ", _pairStraggler);});

    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, pending.size());
	// std::vector<size_t> pairPositions;

    // // Initialize pair positions
    // for (size_t i = 0; i < pending.size(); ++i) {
    //     pairPositions.push_back(i); // Assume pending[i] ↔ mainChain[i]
    // }
printContainer("pairPositions   = ", pairPositions);
printContainer("picking indexes = ", pickingIndexes);

    // Insert smaller elements into seq based on pickingIndexes
    std::vector<bool> inserted(pending.size(), false); // Track inserted elements
	size_t	pickingIndex;
	t_pair	valueToInsert;
	size_t	position;
	size_t	upperBound;


    for (size_t i = 0; i < pending.size(); i++) {

        pickingIndex = pickingIndexes[i];
		upperBound = pairPositions[pickingIndex];

        if (pickingIndex < pending.size() && !inserted[pickingIndex]) {
            valueToInsert = pending[pickingIndex];

			DEBUG_PRINT(std::cout << "\tinserting pending[" << pickingIndexes[i] << "] = " << valueToInsert << " at mainChain[" << upperBound 
			<< "] | upperBound = " << mainChain[upperBound] << std::endl);

			// to insert values we limit the binary search to the upper bound
			// but to insert the straggler we binary search in the whole mainChain
			if (pending.size() == 1 && _intStraggler.size() > 0) {
             	position = pairBinarySearch(mainChain, valueToInsert, mainChain.size() - 1, comparisons);				
			} else {
            	position = pairBinarySearch(mainChain, valueToInsert, upperBound, comparisons);
			}
            // position = pairBinarySearch(mainChain, valueToInsert, mainChain.size(), comparisons);
            
			mainChain.insert((mainChain.begin() + position), valueToInsert);
            inserted[pickingIndex] = true;

            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
			DEBUG_PRINT(printContainer("\tPending    = ", pending));

			// update (shift) pairPositions after the insertion
			for (size_t i = 0; i < pairPositions.size(); i++) {
				pairPositions[i] = pairPositions[i] + 1;
			}
			DEBUG_PRINT(printContainer("\t******** Updated pairPositions = ", pairPositions));
        }
    }

    // Insert any remaining elements from smaller
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            t_pair valueToInsert = pending[i];
			if (pending[i]._smaller != 0 && pending[i]._larger != 0) {
				size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size(), comparisons);

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
 * We pick INTEGERS from a vector of INTEGERS (pending) and insert them in
 *	another vector of INTEGERS (main chain).
 */
void	PmergeMe::intMergeInsertion(std::vector<int> & pending, std::vector<int> & mainChain, size_t & comparisons) {

	DEBUG_PRINT({if(pending.size() > 1) std::cout << "\nintMergeInsertion():" << std::endl;});
	DEBUG_PRINT({if (pending.size() == 1 && _intStraggler.size() > 0) printContainer("\n\tintStraggler = ", _intStraggler);});
	
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, pending.size());
	std::vector<size_t> pairPositions;

    // Initialize pair positions
    for (size_t i = 0; i < pending.size(); ++i) {
        pairPositions.push_back(i); // Assume pending[i] ↔ mainChain[i]
    }
printContainer("initial pairPositions = ", pairPositions);
printContainer("picking indexes = ", pickingIndexes);

    // Insert smaller elements into seq based on pickingIndexes
    std::vector<bool> inserted(pending.size(), false);
    for (size_t i = 0; i < pending.size(); i++) {

        size_t pickingIndex = pickingIndexes[i];
		size_t upperBound = pairPositions[pickingIndex];

        if (pickingIndex < pending.size() && !inserted[pickingIndex]) {
            int valueToInsert = pending[pickingIndex];

			DEBUG_PRINT(std::cout << "\tinserting pending[" << pickingIndexes[i] << "] = " << valueToInsert << std::endl);

			// to insert values we limit the binary search to the upper bound
			// but to insert the straggler we binary search in the whole mainChain
            size_t position;
			if (pending.size() == 1 && _intStraggler.size() > 0) {
             	position = intBinarySearch(mainChain, valueToInsert, mainChain.size() - 1, comparisons);				
			} else {
            	position = intBinarySearch(mainChain, valueToInsert, upperBound, comparisons);
			}

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            inserted[pickingIndex] = true;

            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
			DEBUG_PRINT(printContainer("\tPending    = ", pending));

			// update (shift) pairPositions after the insertion
			for (size_t j = 0; j < pending.size(); ++j) {
				pairPositions[j] = pairPositions[j] + 1;
			}
        }
    }

    // Insert any remaining elements from smaller (those with position greater than last Jacobsthal number used)
    for (size_t i = 0; i < pending.size(); i++) {
        if (!inserted[i]) {
            int valueToInsert = pending[i];

			DEBUG_PRINT(std::cout << "\tinserting remaining pending[" << pickingIndexes[i] << "] = " << valueToInsert << std::endl);
						
            size_t position = intBinarySearch(mainChain, valueToInsert, mainChain.size() - 1, comparisons);
            mainChain.insert((mainChain.begin() + position), valueToInsert);

            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
        }
    }
}


/* Is it necessary to keep getters and setters out from main??????????????????????????
*/
void	PmergeMe::vecFordJohnsonSort() {

	setIntStraggler();
	setPairsVector();

	size_t	comparisons = 0;

	std::vector<int> pairPositions;

    // Initialize pair positions
    for (size_t i = 0; i < getPairsVector().size(); ++i) {
        pairPositions.push_back(i); // Assume pending[i] ↔ mainChain[i]
    }

	std::vector<t_pair> pending;
	std::vector<t_pair> mainChain;

	recursiveSort(getPairsVector(), mainChain, pending, pairPositions, comparisons);

	std::vector<int> intPending;
	std::vector<int> intMainChain;

	extractPendingAndMainChain(getPairsVector(), intPending, intMainChain);
	intMergeInsertion(intPending, intMainChain, comparisons);
	intMergeInsertion(getIntStraggler(), intMainChain, comparisons);
	

	printContainer("Sorted sequence = ", intMainChain);
	std::cout << "Sequence length = " << intMainChain.size() << std::endl;
	std::cout << "COMPARISONS = " << comparisons << std::endl;
	DEBUG_PRINT(std::cout << (isSorted(intMainChain) ? "The sequence is sorted" : "Error: The sequence is NOT sorted") << std::endl);
	
}

std::ostream& operator<<(std::ostream& os, const t_pair& pair) {
    os << "(" << pair._larger << ", " << pair._smaller << ")";
    return os;
}

