/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2024/12/28 03:10:06 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _comparisons(0) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _intsVector(source._intsVector), _pairsVector(source._pairsVector), 
	_intStraggler(source._intStraggler), _comparisons(source._comparisons) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_intsVector = source._intsVector;
		this->_pairsVector = source._pairsVector;
		this->_intStraggler = source._intStraggler;
		this->_comparisons = source._comparisons;
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
		_comparisons++;

		newPair._larger = _intsVector[i];
		newPair._smaller = _intsVector[i + 1];
		if (newPair._smaller > newPair._larger)
			std::swap(newPair._smaller, newPair._larger);
		_pairsVector.push_back(newPair);   
    }

	DEBUG_PRINT(printContainer("pairsVector = ", _pairsVector));
	DEBUG_PRINT(std::cout << "....... COMPARISONS = " << _comparisons << "\n" << std::endl);
	DEBUG_PRINT(std::cout << " --- Start recursive sorting of main chain ---\n" << std::endl);
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
		throw std::runtime_error("The input sequence is already sorted.");

	DEBUG_PRINT(printContainer("intsVector = ", _intsVector));

}

/* ===========================================================================

   Member methods for a VECTOR container

   ===========================================================================*/

void	PmergeMe::sortAdjacentPairs(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending) {

	DEBUG_PRINT(std::cout << "sortAdjacentPairs():" << std::endl);

    // for (size_t i = 0; i < _pairsVector.size(); i++) {
	// 	_comparisons++;
	// 	if (_pairsVector[i]._smaller > _pairsVector[i]._larger)
	// 		std::swap(_pairsVector[i]._smaller, _pairsVector[i]._larger);
	// }
	if (pairedSeq.size() < 2)
		return;	
	for (size_t i = 0; (i + 1) < pairedSeq.size(); i += 2) {
		_comparisons++;
		if (pairedSeq[i]._larger > pairedSeq[i + 1]._larger) {
			DEBUG_PRINT(std::cout << "\tSwapping main chain " << pairedSeq[i] << " and " << pairedSeq[i + 1] << std::endl); 
			std::swap(pairedSeq[i], pairedSeq[i + 1]);
			// if (!pending.empty()) {
				DEBUG_PRINT(std::cout << "\tSwapping pending " << pending[i] << " and " << pending[i + 1] << std::endl); 
				std::swap(pending[i], pending[i + 1]);
			// }
		}		
	}

	DEBUG_PRINT(printContainer("\tmain chain = ", pairedSeq));
	DEBUG_PRINT(printContainer("\tpending    = ", pending));
	DEBUG_PRINT(std::cout << "....... COMPARISONS = " << _comparisons << "\n" << std::endl);
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

	sortAdjacentPairs(mainChain, pending);

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

size_t PmergeMe::pairBinarySearch(const std::vector<t_pair> & mainChain, t_pair value, size_t end) {
	// if (end > 0)
		// std::cout << " | upperBound is mainChain[" << end - 1 << "] = " << mainChain[end - 1] << std::endl;
    size_t left = 0;
    size_t right = end;
    while (left < right) {
		_comparisons++;
        size_t mid = (left + right) / 2;
        if (mainChain[mid]._larger > value._larger)
            right = mid;
        else
            left = mid + 1;
		std::cout << "\t\t...comparing pending " << value << " with " << mainChain[mid] << " in position [" << mid << "]..." << std::endl;
    }
	// DEBUG_PRINT(printContainer("pairBS -> Main chain = ", mainChain));
	// DEBUG_PRINT(std::cout << "pairBS -> ....... COMPARISONS = " << _comparisons << "\n" << std::endl);
    return left;
}

size_t PmergeMe::intBinarySearch(const std::vector<int> & mainChain, int value, size_t end) {
	// size_t partial_comp = comparisons;
	std::cout << " | upper bound is mainChain[" << end << "] = " << mainChain[end] << std::endl; 
    size_t left = 0;
    size_t right = end;
    while (left < right) {
		_comparisons++;
        size_t mid = (left + right) / 2;
        if (mainChain[mid] > value)
            right = mid;
        else
            left = mid + 1;
		std::cout << "\t\t...comparing pending " << value << " with " << mainChain[mid] << " in position [" << mid << "]..." << std::endl;
    }
	// std::cout << "\t\tcomparisons made = " << comparisons - partial_comp << " | total = " << comparisons << std::endl;
	// DEBUG_PRINT(printContainer("intBS -> Main chain = ", mainChain));
	// DEBUG_PRINT(std::cout << "intBS -> ....... COMPARISONS = " << _comparisons << "\n" << std::endl);
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

void PmergeMe::recursiveSort(std::vector<t_pair> & pairedSeq) {

    if (pairedSeq.size() < 1) {
        return;
	}

	std::vector<t_pair> mainChain;
    std::vector<t_pair> pending;

	// sortAdjacentPairs(pairedSeq);

	// Store first straggler
	t_pair currentStraggler = {0, 0};
	if (pairedSeq.size() % 2 == 1) {
		currentStraggler = pairedSeq.back();
		pairedSeq.pop_back();

		DEBUG_PRINT(std::cout << "\t<<<<< Extracting straggler " << currentStraggler << " from mainChain" << std::endl);
	}

    divideSequence(pairedSeq, pending, mainChain);

    recursiveSort(mainChain);

	// Insert back first straggler
	if (currentStraggler._larger != 0 && currentStraggler._smaller != 0) {

		DEBUG_PRINT(std::cout << "\t>>>>> Inserting straggler " << currentStraggler << " in mainChain" << std::endl);
		
		size_t position = pairBinarySearch(mainChain, currentStraggler, mainChain.size());
		mainChain.insert(mainChain.begin() + position, currentStraggler);

		DEBUG_PRINT(printContainer("RecSort->InsStraggler-> Main chain = ", mainChain));
		DEBUG_PRINT(std::cout << "RecSort->InsStraggler-> ....... COMPARISONS = " << _comparisons << "\n" << std::endl);
	}

	// DEBUG_PRINT(std::cout << "recursiveSort() unwinding: " << std::endl);
	// DEBUG_PRINT(printContainer("RecSort -> Main chain = ", mainChain));
	// DEBUG_PRINT(std::cout << "RecSort -> ....... COMPARISONS = " << _comparisons << "\n" << std::endl);

	pairMergeInsertion(pending, mainChain);
	
	pairedSeq = mainChain;

}

/* 
 *	pairMergeInsertion()
 *
 *	We pick PAIRS of integers from a vector of PAIRS of integers (pending) and insert them in
 *	another vector of PAIRS of integers (main chain).
 */
void	PmergeMe::pairMergeInsertion(std::vector<t_pair> & pending, std::vector<t_pair> & mainChain) {

    // Generate insertion order using Jacobsthal sequence
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, pending.size());

    // Insert smaller elements into seq based on pickingIndexes
    std::vector<bool> inserted(pending.size(), false); // Track inserted elements
    for (size_t i = 0; i < pickingIndexes.size(); ++i) {
        size_t pickingIndex = pickingIndexes[i];
        if (pickingIndex < pending.size() && !inserted[pickingIndex]) {
            t_pair valueToInsert = pending[pickingIndex];

            DEBUG_PRINT(std::cout << "\tInserting pending[" << pickingIndexes[i] << "] = " << valueToInsert 
				<< " | upper bound is mainChain[" << mainChain.size() - 1 << "] = " << mainChain[mainChain.size()] << std::endl);
				
            size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size());
            mainChain.insert((mainChain.begin() + position), valueToInsert);
            inserted[pickingIndex] = true;

			DEBUG_PRINT(printContainer("pairBS -> Main chain = ", mainChain));
			DEBUG_PRINT(std::cout << "pairBS -> ....... COMPARISONS = " << _comparisons << "\n" << std::endl);

        }
    }

	
    // Insert any remaining elements from smaller
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            t_pair valueToInsert = pending[i];
			if (pending[i]._smaller != 0 && pending[i]._larger != 0) {

				DEBUG_PRINT(std::cout << "\tInserting 'REMAINING' pending[" << pickingIndexes[i] << "] = " << valueToInsert 
					<< " | upper bound is mainChain[" << mainChain.size() - 1 << "] = " << mainChain[mainChain.size() - 1] << std::endl);
					
				size_t position = pairBinarySearch(mainChain, valueToInsert, mainChain.size());

				// DEBUG_PRINT(std::cout << "\tInserting '''REMAINING''' value " << valueToInsert << " at position " << position << std::endl);

				mainChain.insert((mainChain.begin() + position), valueToInsert);
			}
            // DEBUG_PRINT(printContainer("pairMI->Remains-> Main chain = ", mainChain));
			// DEBUG_PRINT(std::cout << "v........ COMPARISONS = " << _comparisons << "\n" << std::endl);
        }
    }
	// DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
	// DEBUG_PRINT(std::cout << "............... COMPARISONS = " << _comparisons << " ...............\n" << std::endl);
}

/* 
 *	intMergeInsertion()
 *
 * We pick INTEGERS from a vector of INTEGERS (pending) and insert them in
 *	another vector of INTEGERS (main chain).
 */
void	PmergeMe::intMergeInsertion(std::vector<int> & pending, std::vector<int> & mainChain) {

	DEBUG_PRINT({if(pending.size() > 1) std::cout << "\nintMergeInsertion():" << std::endl;});
	DEBUG_PRINT({if (pending.size() == 1 && _intStraggler.size() > 0) printContainer("\n\tintStraggler = ", _intStraggler);});
	
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, pending.size());
	std::vector<size_t> pairPositions;

    // Initialize pair positions
    for (size_t i = 0; i < pending.size(); ++i) {
        pairPositions.push_back(i);
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

			DEBUG_PRINT(std::cout << "\tinserting pending[" << pickingIndexes[i] << "] = " << valueToInsert);

			// to insert values we limit the binary search to the upper bound
			// but to insert the straggler we binary search in the whole mainChain
            size_t position;
			if (pending.size() == 1 && _intStraggler.size() > 0) {
std::cout << "INSERTING STRAGGLER......................................" << std::endl;
             	position = intBinarySearch(mainChain, valueToInsert, mainChain.size());				
			} else {
            	position = intBinarySearch(mainChain, valueToInsert, upperBound);
			}

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            inserted[pickingIndex] = true;

            DEBUG_PRINT(printContainer("\tMain chain    = ", mainChain));
			DEBUG_PRINT(printContainer("\tPending       = ", pending));

			// this is the key to avoid having to perform searches to find the upper bound
			// pairPositions holds the position of all larger values in main chain (ONLY
			// the larger) and updates them every time an insertion is made (values after
			// the inserted one are shifted, hence their index in pairPositions will be 
			// incremented)
			for (size_t j = 0; j < pairPositions.size(); ++j) {
				if (pairPositions[j] >= position)
					pairPositions[j] = pairPositions[j] + 1;
			}
			printContainer("\tpairPositions = ", pairPositions);
			DEBUG_PRINT(std::cout << "....... COMPARISONS = " << _comparisons << "\n" << std::endl);
        }
    }

    // Insert any remaining elements from smaller (those with position greater than last Jacobsthal number used)
    for (size_t i = 0; i < pending.size(); i++) {

        if (!inserted[i] && pending[i] != 0) {
            int valueToInsert = pending[i];

			DEBUG_PRINT(std::cout << "\tinserting remaining pending[" << pickingIndexes[i] << "] = " << valueToInsert);
						
            size_t position = intBinarySearch(mainChain, valueToInsert, mainChain.size());
            mainChain.insert((mainChain.begin() + position), valueToInsert);

            DEBUG_PRINT(printContainer("\tMain chain = ", mainChain));
			DEBUG_PRINT(printContainer("\tPending    = ", pending));
        }
    }
}


/* Is it necessary to keep getters and setters out from main??????????????????????????
*/
void	PmergeMe::vecFordJohnsonSort() {

	setIntStraggler();
	setPairsVector();

	recursiveSort(getPairsVector());

	std::vector<int> pending;
	std::vector<int> mainChain;

	extractPendingAndMainChain(getPairsVector(), pending, mainChain);
	intMergeInsertion(pending, mainChain);
	intMergeInsertion(getIntStraggler(), mainChain);
	

	printContainer("Sorted sequence = ", mainChain);
	std::cout << "Sequence length = " << mainChain.size() << std::endl;
	std::cout << "COMPARISONS = " << _comparisons << std::endl;
	DEBUG_PRINT(std::cout << (isSorted(mainChain) ? "The sequence is sorted" : "Error: The sequence is NOT sorted") << std::endl);
	
}

std::ostream& operator<<(std::ostream& os, const t_pair& pair) {
    os << "(" << pair._smaller << ", " << pair._larger << ")";
    return os;
}

