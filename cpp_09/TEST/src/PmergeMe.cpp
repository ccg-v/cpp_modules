/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/01/06 03:48:32 by ccarrace         ###   ########.fr       */
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
		DEBUG_PRINT(std::cout << "sortAdjacentPairs: COMPARISONS = " << _comparisons << "\n" << std::endl);
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

    // Handle remaining stragglers (if any)
    size_t stragglerStart = numberOfGroups * groupSize;
    if (stragglerStart < _vecSequence.size()) {
        _pending.insert(_pending.end(), _vecSequence.begin() + stragglerStart, _vecSequence.end());
    }

	// printContainer("\tdivideSequence(): Main chain = ", groupSize, _mainChain);
	// printContainer("\tdivideSequence(): Pending    = ", groupSize, _pending);
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

// // binarySearch             (largerValue, upperBoundIndex * groupSize,    groupSize);
// size_t PmergeMe::binarySearch(int value, size_t end, size_t groupSize)
// {
//     // size_t left = 0;       // Start at the first element
//     // size_t right = end;    // End at the last valid index
// 	size_t	left = groupSize - 1;
// 	size_t	right = left + (end * groupSize);

// 	printContainer("binarySearch: input mainChain = ", groupSize, _mainChain);
// 	printContainer("binarySearch: input pending   = ", groupSize, _pending);

//     while (left < right)
// 	{
//         size_t mid = (left + right) / 2;
// std::cout << "\t\t...comparing pending " << value << " with " << _mainChain[mid] << " in position [" << mid << "]..." << std::endl;
//         // Check only the larger value (end of group) for comparison
//         size_t groupEnd = ((mid / groupSize) + 1) * groupSize - 1;
//         groupEnd = std::min(groupEnd, end - 1); // Avoid out-of-bounds access

//         if (_mainChain[groupEnd] > value)
//             right = mid;
//         else
//             left = groupEnd + 1; // Move to the next group
		
// 		_comparisons++;
//     }
// 	DEBUG_PRINT(std::cout << "binarySearch: COMPARISONS = " << _comparisons << "\n" << std::endl);
//     return left;
// }

// size_t PmergeMe::binarySearch(int value, size_t end, size_t groupSize)
// {
//     // Initialize 'left' and 'right' to the first and last valid group boundaries
//     size_t left = groupSize - 1;                    // First group boundary
//     size_t right = (end / groupSize) * groupSize - 1; // Last complete group's boundary
//     right = std::min(right, end - 1);              // Ensure 'right' is within bounds

// 	printContainer("binarySearch: input mainChain = ", groupSize, _mainChain);
// 	printContainer("binarySearch: input pending   = ", groupSize, _pending);

//     while (left <= right)
//     {
//         // Calculate 'mid' as the middle group's boundary
//         size_t mid = left + (right - left) / (2 * groupSize) * groupSize;
// std::cout << "\t\t...comparing pending " << value << " with " << _mainChain[mid] << " in position [" << mid << "]..." << std::endl;

//         // Compare 'value' with the rightmost value of the group at 'mid'
//         if (_mainChain[mid] > value)
//         {
//             right = mid - groupSize; // Move 'right' to the previous group boundary
//         }
//         else
//         {
//             left = mid + groupSize; // Move 'left' to the next group boundary
//         }

//         _comparisons++;
//     }
// std::cout << "\t\tLeft value returned for insertion is " << left << std::endl;
// 	DEBUG_PRINT(std::cout << "binarySearch: COMPARISONS = " << _comparisons << "\n" << std::endl);
//     // Return the insertion index, which is 'left' adjusted to group boundaries
//     return left - groupSize;
// }

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
std::cout << "\t\tValue returned for insertion is " << insertionIndex << std::endl;
	DEBUG_PRINT(std::cout << "binarySearch: COMPARISONS = " << _comparisons << "\n" << std::endl);
    return insertionIndex;
}


void PmergeMe::binaryInsertion(size_t groupSize)
{
	size_t numOfPendingGroups = _pending.size() / groupSize;
	// size_t numOfMainGroups = _mainChain.size() / groupSize;

	std::cout << "\nPerforming binary search insertion ---------------------------------------------- " << std::endl;
	std::cout << "pending.size() is " << _pending.size() << std::endl;

    std::vector<int> jacobsthalSeq = buildJacobsthalVec(numOfPendingGroups);
	std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, numOfPendingGroups);
	std::vector<size_t> upperBoundsTrack;

    // Initialize pair positions
    for (size_t i = 0; i < numOfPendingGroups; ++i) {
        upperBoundsTrack.push_back(i);
    }

	printContainer("binaryInsertion: sequence to divide = ", groupSize, _vecSequence);
	printContainer("\tBefore BSinsertion: Main chain = ", groupSize, _mainChain);
	printContainer("\tBefore BSinsertion: Pending    = ", groupSize, _pending);
	std::cout << "pending.size() is " << _pending.size() << std::endl;
	printContainer("jacobsthalSeq = ", groupSize, jacobsthalSeq);
	printContainer("picking indexes = ", groupSize, pickingIndexes);
	printContainer("upperBoundsTrack = ", groupSize, upperBoundsTrack);

	// divideSequence(groupSize);

	size_t pendingGroups = _pending.size() / groupSize;
	for (size_t groupIndex = 0; groupIndex < pendingGroups; ++groupIndex)
	{
		size_t	pickingIndex = pickingIndexes[groupIndex];
        size_t	startIdx = pickingIndex * groupSize;
        size_t 	endIdx = startIdx + groupSize;

		size_t	upperBoundIndex = upperBoundsTrack[pickingIndex];

        // Identify the "larger" value (rightmost in the group)
        int largerValue = _pending[endIdx - 1];
		std::cout << "--------- Inserting group[" << pickingIndex << "] | largerValue = " << largerValue << std::endl;
		std::cout << "--------- upperBound index is " << upperBoundIndex << std::endl;
  
		size_t position;
        // Find the insertion position for the "larger" value  

		if (upperBoundIndex == 0) 
			position = 0;
		else
			position = binarySearch(largerValue, upperBoundIndex * groupSize, groupSize);
			
		std::cout << "--------- position is " << position << std::endl;
		std::cout << "--------- group size is " << groupSize << std::endl;
		printContainer("********* upperBoundsTrack = ", groupSize, upperBoundsTrack);
		
			// Insert the entire group at the determined position
			_mainChain.insert(_mainChain.begin() + position, _pending.begin() + startIdx, _pending.begin() + endIdx);
		// }

		for (size_t i = 0; i < groupSize; i++) {
			std::cout << *(_pending.begin() + startIdx + i) << " ";
		}
		std::cout << std::endl;

		// this is the key to avoid having to perform searches to find the upper bound
		// pairPositions holds the position of all larger values in main chain (ONLY
		// the larger) and updates them every time an insertion is made (values after
		// the inserted one are shifted, hence their index in pairPositions will be 
		// incremented)
		for (size_t j = 0; j < upperBoundsTrack.size(); ++j) {
			if (upperBoundsTrack[j] >= (position / groupSize))
				upperBoundsTrack[j] = upperBoundsTrack[j] + 1;
		}

		// printContainer("\tAfter BSinsertion: Main chain = ", groupSize, _mainChain);
		// printContainer("\tAfter BSinsertion: Pending    = ", groupSize, _pending);
    }
	
    // // Handle remaining stragglers
    // size_t stragglersStartIdx = numberOfGroups * groupSize;
    // for (size_t i = stragglersStartIdx; i < _pending.size(); ++i) {
    //     int valueToInsert = _pending[i];
    //     size_t position = binarySearch(valueToInsert, _mainChain.size(), groupSize);
    //     _mainChain.insert(_mainChain.begin() + position, valueToInsert);
    // }

	// inserting remains AT THE END OF MAIN CHAIN (no binary insertion)
	size_t	remainsStartIdx = _pending.size() - (_pending.size() % groupSize);
    for (size_t i = remainsStartIdx; i < _pending.size(); ++i) {
        int valueToInsert = _pending[i];
        _mainChain.insert(_mainChain.end(), valueToInsert);
    }

		// printContainer("\tAfter remains insertion: Main chain = ", groupSize, _mainChain);
		// printContainer("\tAfter remains insertion: Pending    = ", groupSize, _pending);

	_vecSequence = _mainChain;
	DEBUG_PRINT(std::cout << "binaryInsertion: COMPARISONS = " << _comparisons << "\n" << std::endl);
	// printContainer("\tdivideSequence(): SEQUENCE UPDATED = ", groupSize, _mainChain);
}

void PmergeMe::mergeInsertionSort(size_t depth)
{
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= _vecSequence.size())
	{
        return; // Base case: No more groups to sort
    }

	if (_vecSequence.size() % 2 == 1)
	{
		std::cout << "\n ........................ POPPING STRAGGLER .......................................\n" << std::endl;

		_straggler = _vecSequence.back();
		_vecSequence.pop_back();
	}

    // Step 1: Sort pairs of elements at this depth
    sortAdjacentPairs(groupSize);
	printContainer("", groupSize, _vecSequence);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort(depth + 1);

	divideSequence(groupSize);
	
    // Step 3: Insert remaining elements into the sorted sequence
    binaryInsertion(groupSize);

	if (groupSize == 1 && _straggler > 0)
	{
		std::cout << ">>>>>>>>>>>>>>>>>>>>>>>>> INSERTING STRAGGLER <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< " << std::endl;
		size_t position = binarySearch(_straggler,_mainChain.size(), groupSize);
		_mainChain.insert(_mainChain.begin() + position, _straggler);
		_comparisons++;		
	}
}

// int main() {
// 	std::cout << "--------------------- TEST 2 ---------------------------\n";
//     std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};

// 	for (int i = 1; i < sequence.size(); i *= 2) 
// 	{
		
// 		size_t	recursionDepth = 0;
// 		printContainer("Group size", i, sequence);
// 		// In each recursive call we calculate the group size as 2^depth
// 		// Recursion stops when the group size becomes larger than sequence size
// 		// 
// 		mergeInsertionSort(sequence, recursionDepth);
// 	}

//     return 0;
// }

// int main() {
// 	// std::vector<int> sequence = {3, 1, 2, 5, 4};
//     // std::vector<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};
//     std::vector<int> sequence = {1, 7, 4, 11, 5, 16, 6, 19, 8, 14, 20, 23, 9, 15, 22, 24, 2, 10, 3, 12, 13, 18, 17, 25, 21};

//     std::cout << "Original sequence: ";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << "\n";

// 	size_t	recursionDepth = 0;

// 	// In each recursive call we calculate the group size as 2^depth
// 	// Recursion stops when the group size becomes larger than sequence size
//     mergeInsertionSort(sequence, recursionDepth);

//     std::cout << "Sorted sequence: ";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << "\n";

// 	// for (int i = 1; i < sequence.size(); i *= 2) 
// 	// 	printContainer("Group size", i, sequence);

//     return 0;
// }