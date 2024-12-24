#include "PmergeMe.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _intsVector(source._intsVector), _pairsVector(source._pairsVector) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source) {
	if (this != &source) {
		this->_intsVector = source._intsVector;
		this->_pairsVector = source._pairsVector;
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
			// setPairSortedVector(value);
			setIntsVector(value);
			// setDeque(value);
		}
	}
}

/* --- Member methods for a VECTOR container ------------------------------- */

void	PmergeMe::sortAdjacentPairs(std::vector<t_pair> & pairedSeq) {
	if (pairedSeq.size() <= 1)
		return;
	for (size_t i = 0; (i + 1) < pairedSeq.size(); i += 2) {
		if (pairedSeq[i]._larger > pairedSeq[i + 1]._larger) {
			std::cout << "Swapping  " << pairedSeq[i] << " and larger " << pairedSeq[i + 1] << std::endl; 
			std::swap(pairedSeq[i], pairedSeq[i + 1]);
		}		
	}
	printContainer("*****sortAdjacentPairs: pairedSeq = ", pairedSeq);
}

void	PmergeMe::divideSequence(std::vector<t_pair> & pairedSeq, std::vector<t_pair> & pending, std::vector<t_pair> & mainChain) {
    if (pairedSeq.size() <= 1) {
        return;
	}
	if (pairedSeq.size() % 2 == 1) {
		_hasStraggler = 1;
		_vecPairStraggler = pairedSeq.back();
		pairedSeq.pop_back();
	}
	if (_hasStraggler == 1) {
		std::cout << "\t******************* THE PAIRED SEQUENCE HAS STRAGGLER " << _vecPairStraggler << std::endl;
	} else {
		std::cout << "\t******************* THE PAIRED SEQUENCE DOESN'T HAVE STRAGGLER" << std::endl;
	}

    for (size_t i = 0; (i + 1) < pairedSeq.size(); i +=2) {
        pending.push_back(pairedSeq[i]); 
		mainChain.push_back(pairedSeq[i + 1]); 
    }

    // Debugging
    printContainer("divideSequence(): Debug main chain = ", mainChain);
    printContainer("divideSequence(): Debug pending    = ", pending);

	pairedSeq = mainChain;
}

void	PmergeMe::extractPendingAndMainChain(std::vector<t_pair> & pairedSeq, std::vector<int> & pending, std::vector<int> & mainChain) {
    if (pairedSeq.size() <= 1) 
        return;
    for (size_t i = 0; i < pairedSeq.size(); i ++) {
		std::cout << "extracting " << pairedSeq[i]._smaller  << std::endl;
		std::cout << "extracting " << pairedSeq[i]._larger  << std::endl;
        pending.push_back(pairedSeq[i]._smaller);
		mainChain.push_back(pairedSeq[i]._larger);
    }	
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

size_t PmergeMe::binarySearch(const std::vector<t_pair> & seq, t_pair value, size_t end) {
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

void PmergeMe::fordJohnsonSort(std::vector<t_pair> & pairedSeq) {
    if (pairedSeq.size() < 1) {
        return;
	}
    if (pairedSeq.size() == 1) {
        if (pairedSeq[0]._smaller > pairedSeq[0]._larger)
            std::swap(pairedSeq[0]._smaller, pairedSeq[0]._larger);
        return;
    }

    // Step 1: Pair and sort
	std::vector<t_pair> mainChain;
    std::vector<t_pair> pending;

	sortAdjacentPairs(pairedSeq);
    divideSequence(pairedSeq, pending, mainChain);

    fordJohnsonSort(mainChain);
	if (_hasStraggler) {
		pending.push_back(_vecPairStraggler);
		_hasStraggler = 0;
	}
	printContainer("fordJohnson(): Main chain = ", mainChain);

    // Step 2: Generate insertion order using Jacobsthal sequence
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(pending.size());
    std::vector<int> insertionIndexes = getInsertionOrder(jacobsthalSeq, pending.size());

    // Step 3: Insert smaller elements into seq based on insertionIndexes
    std::vector<bool> inserted(pending.size(), false); // Track inserted elements
    for (size_t i = 0; i < insertionIndexes.size(); ++i) {
        size_t insertIndex = insertionIndexes[i];
        if (insertIndex < pending.size() && !inserted[insertIndex]) {
            t_pair valueToInsert = pending[insertIndex];
            size_t position = binarySearch(mainChain, valueToInsert, mainChain.size());

            // Debugging
            std::cout << "Inserting pending[" << insertionIndexes[i] << "] = " << valueToInsert << " at mainChain[" << position << "]" << std::endl;

            mainChain.insert((mainChain.begin() + position), valueToInsert);
            printContainer("Debug seq after insertion = ", mainChain);

            inserted[insertIndex] = true;
        }
    }

    // Step 4: Insert any remaining elements from smaller
    for (size_t i = 0; i < pending.size(); ++i) {
        if (!inserted[i]) {
            t_pair valueToInsert = pending[i];
			if (pending[i]._smaller != 0 && pending[i]._larger != 0) {
				size_t position = binarySearch(mainChain, valueToInsert, mainChain.size());

				// Debugging
				std::cout << "Inserting remaining value " << valueToInsert << " at position " << position << std::endl;

				mainChain.insert((mainChain.begin() + position), valueToInsert);
			}
            printContainer("Debug seq after remaining insertion = ", mainChain);
        }
    }
	
	pairedSeq = mainChain;
}

std::ostream& operator<<(std::ostream& os, const t_pair& pair) {
    os << "(" << pair._larger << ", " << pair._smaller << ")";
    return os;
}

