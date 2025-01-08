/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toPaste.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/01/07 19:55:49 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _straggler(-1), _comparisons(0) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _vecSequence(source._vecSequence), _mainChain(source._mainChain), 
	  _pending(source._mainChain), _straggler(source._straggler), 
	  _comparisons(source._comparisons) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source)
{
	if (this != &source) {
		this->_vecSequence = source._vecSequence;
		this->_mainChain = source._mainChain;
		this->_pending = source._pending;
		this->_straggler = source._straggler;
		this->_comparisons = source._comparisons;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<int> & PmergeMe::getVector()
{
	return this->_vecSequence;
}

std::vector<int> & PmergeMe::getMainChain()
{
	return this->_mainChain;
}

int	PmergeMe::getStraggler()
{
	return this->_straggler;
}

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setVector(int value)
{
	_vecSequence.push_back(value);
}

void	PmergeMe::setStraggler()
{
	if (_vecSequence.size() % 2 == 1) {
		_straggler = _vecSequence.back();
		_vecSequence.pop_back();
	}
}

/* --- Common member methods ------------------------------------------------ */

void PmergeMe::checkInputAndSetContainers(int argc, char** argv)
{
	for (int i = 1; i < argc; ++i)
	{
		std::string input = argv[i];
		
		if (input.empty() || onlyWhitespace(input))
			throw std::runtime_error("Error: input is empty.");

		std::istringstream argStream(input);
		std::string element;

		while (argStream >> element)
		{
			if (!isPositiveNumber(element))
				throw std::runtime_error("Error: sequence values must be positive integers.");

			if (!isIntegerRange(element))
				throw std::runtime_error("Error: value out of integer's range found.");

			int value = atoi(element.c_str());
			
			setVector(value);
			// setDeque(value);
		}
	}

	if (isSorted(getVector()))
		throw std::runtime_error("The input sequence is already sorted.");

	// DEBUG_PRINT(printContainer("intsVector = ", _intsVector));
}

/* ===========================================================================

   Member methods for a VECTOR container

   ===========================================================================*/

size_t PmergeMe::calculateGroupSize(size_t depth)
{
    size_t groupSize = 1;
    for (size_t i = 0; i < depth; ++i) {
        groupSize *= 2; // Multiply by 2 for each level of depth
	}
	std::cout << "groupSize = " << groupSize << std::endl;
    return groupSize;
}

void PmergeMe::sortAdjacentPairs(size_t groupSize)
{
    size_t tail = groupSize - 1;

    while (tail + groupSize < _vecSequence.size())
	{
        std::vector<int>::iterator first = _vecSequence.begin();
        std::advance(first, tail);

        std::vector<int>::iterator second = _vecSequence.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second)
		{
            std::vector<int>::iterator trueFirst = _vecSequence.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::vector<int>::iterator trueSecond = _vecSequence.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
		
		_comparisons++;
    }
}

void PmergeMe::divideSequence(size_t groupSize)
{
	_mainChain.clear();
	_pending.clear();
	
    size_t numberOfGroups = _vecSequence.size() / groupSize;
    for (size_t j = 1; j <= numberOfGroups; j++) {
        size_t start = (j - 1) * groupSize;
        size_t end = std::min(j * groupSize, _vecSequence.size()); // Safeguard against out-of-bounds

        if (j % 2 != 0) { // Odd group, values go to pending
            _pending.insert(_pending.end(), _vecSequence.begin() + start, _vecSequence.begin() + end);
        } else {          // Even group, values go to mainChain
            _mainChain.insert(_mainChain.end(), _vecSequence.begin() + start, _vecSequence.begin() + end);
        }
    }
    size_t stragglerStart = numberOfGroups * groupSize;
    if (stragglerStart < _vecSequence.size()) {
        _pending.insert(_pending.end(), _vecSequence.begin() + stragglerStart, _vecSequence.end());
    }
}

std::vector<int> PmergeMe::buildJacobsthalVec(size_t len)
{
    std::vector<int>	JacobsthalSeq;
    size_t			num;

    JacobsthalSeq.push_back(0);
    JacobsthalSeq.push_back(1);
    for (size_t i = 2; i < len; i++)
	{
        num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		if (num >= len)
			break;
        JacobsthalSeq.push_back(num);
    }

    // Remove the first two elements if the sequence has at least two elements
    if (JacobsthalSeq.size() > 2)
        JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);

    return (JacobsthalSeq);
}

std::vector<int> PmergeMe::getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t seqSize)
{
    std::vector<int> result;
    std::vector<bool> inserted(seqSize, false); // Track inserted indices

    // Always add index 0 first
    if (seqSize > 0) {
        result.push_back(0);
        inserted[0] = true;
    }

    size_t current = 1; // Start interleaving from index 1

    // Process each Jacobsthal boundary
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
	{
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(seqSize))
            break; // Ignore out-of-bounds Jacobsthal indices

        // Add the current boundary
        if (!inserted[boundary])
		{
            result.push_back(boundary);
            inserted[boundary] = true;
        }

        // Insert interleaved indices between `current` and `boundary` in descending order
        for (size_t j = boundary; j >= static_cast<size_t>(current); --j) 
		{
            if (!inserted[j])
			{
                result.push_back(j);
                inserted[j] = true;
            }
        }

        current = boundary + 1; // Move to the next range
    }
    for (size_t i = seqSize - 1; i >= current; --i)
	{
        if (!inserted[i]) {
            result.push_back(i);
        }
    }
    return result;
}

size_t PmergeMe::binarySearch(int value, size_t end, size_t groupSize)
{
    // Initialize 'left' and 'right' to the first and last valid group boundaries
    size_t left = groupSize - 1;                    // First group boundary
    size_t right = (end / groupSize) * groupSize - 1; // Last complete group's boundary
    right = std::min(right, end - 1);              // Ensure 'right' is within bounds

	printContainer("binarySearch: input mainChain = ", groupSize, _mainChain);
	printContainer("binarySearch: input pending   = ", groupSize, _pending);

    while (left <= right)
    {
        // Calculate 'mid' as the middle group's boundary
        size_t mid = left + (right - left) / (2 * groupSize) * groupSize;
		mid = std::min(mid, right); // Ensure 'mid' does not exceed 'right'
std::cout << "\t\t...comparing pending " << value << " with " << _mainChain[mid] << " in mainChain [" << mid << "]..." << std::endl;

        // Compare 'value' with the rightmost value of the group at 'mid'
        if (_mainChain[mid] > value)
        {
			if (mid < groupSize){
				_comparisons++;
				break; // Prevent underflow
			}
            right = mid - groupSize; // Move 'right' to the previous group boundary
        }
        else
        {
            left = mid + groupSize; // Move 'left' to the next group boundary
        }

        _comparisons++;
    }

    // Translate 'left' to the correct position for insertion
    size_t insertionIndex = left;
    if (left > end)
    {
        // If 'left' exceeds 'end', set it to 'end'
        insertionIndex = end;
    }
    else if (left % groupSize != 0)
    {
        // Adjust 'left' to align with the start of the next group
        insertionIndex = (left / groupSize) * groupSize;
    }
    return insertionIndex;
}


void PmergeMe::binaryInsertion(size_t groupSize)
{
	size_t numOfPendingGroups = _pending.size() / groupSize;
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(numOfPendingGroups);
	std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, numOfPendingGroups);
	std::vector<size_t> upperBoundsTrack;

    // Initialize pair positions
    for (size_t i = 0; i < numOfPendingGroups; ++i) {
        upperBoundsTrack.push_back(i);
    }

	size_t pendingGroups = _pending.size() / groupSize;
	for (size_t groupIndex = 0; groupIndex < pendingGroups; ++groupIndex)
	{
		size_t	pickingIndex = pickingIndexes[groupIndex];
        size_t	startIdx = pickingIndex * groupSize;
        size_t 	endIdx = startIdx + groupSize;
		size_t	upperBoundIndex = upperBoundsTrack[pickingIndex];       
        int largerValue = _pending[endIdx - 1]; // Identify the "larger" value (rightmost in the group)
		size_t position;

		if (upperBoundIndex == 0) 
			position = 0;
		else
			position = binarySearch(largerValue, upperBoundIndex * groupSize, groupSize);
		
		_mainChain.insert(_mainChain.begin() + position, _pending.begin() + startIdx, _pending.begin() + endIdx);

		for (size_t j = 0; j < upperBoundsTrack.size(); ++j) {
			if (upperBoundsTrack[j] >= (position / groupSize))
				upperBoundsTrack[j] = upperBoundsTrack[j] + 1;
		}

	// inserting remains AT THE END OF MAIN CHAIN (no binary insertion)
	size_t	remainsStartIdx = _pending.size() - (_pending.size() % groupSize);
    for (size_t i = remainsStartIdx; i < _pending.size(); ++i) {
        int valueToInsert = _pending[i];
        _mainChain.insert(_mainChain.end(), valueToInsert);
    }

	_vecSequence = _mainChain;
}

void PmergeMe::mergeInsertionSort(size_t depth)
{
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= _vecSequence.size())
	{
        return; // Base case: No more groups to sort
    }

	// Step 1: Pop straggler if number of elements is odd
	if (_vecSequence.size() % 2 == 1)
	{
		_straggler = _vecSequence.back();
		_vecSequence.pop_back();
	}

    // Step 2: Sort pairs of elements at this depth
    sortAdjacentPairs(groupSize);
	printContainer("", groupSize, _vecSequence);

    // Step 3: Recursively sort larger groups
    mergeInsertionSort(depth + 1);

	divideSequence(groupSize);
	
    // Step 4: Insert remaining elements into the sorted sequence
    binaryInsertion(groupSize);

	// Step 5: Insert straggler if saved in step 1
	if (groupSize == 1 && _straggler > 0)
	{
		size_t position = binarySearch(_straggler,_mainChain.size(), groupSize);
		_mainChain.insert(_mainChain.begin() + position, _straggler);
	}
}

int main(int argc, char** argv) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;
			
			pmergeme.checkInputAndSetContainers(argc, argv);

			size_t	recursionDepth = 0;
			pmergeme.mergeInsertionSort(recursionDepth);
			
			printContainer("Sorted sequence = ", 1, pmergeme.getMainChain());
			std::cout << "COMPARISONS = " << pmergeme._comparisons << std::endl;
		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

    return 0;
}