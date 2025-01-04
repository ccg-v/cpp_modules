/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/01/04 19:57:59 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _comparisons(0) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _vecSequence(source._vecSequence), _straggler(source._straggler),
	  _comparisons(source._comparisons) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source)
{
	if (this != &source) {
		this->_vecSequence = source._vecSequence;
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
    for (size_t i = 0; i < depth; ++i)
        groupSize *= 2; // Multiply by 2 for each level of depth
    return groupSize;
}

void PmergeMe::sortAdjacentPairs(std::vector<int>& sequence, size_t groupSize)
{
    size_t tail = groupSize - 1;

    while (tail + groupSize < sequence.size())
	{
        std::vector<int>::iterator first = sequence.begin();
        std::advance(first, tail);

        std::vector<int>::iterator second = sequence.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second)
		{
            std::vector<int>::iterator trueFirst = sequence.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::vector<int>::iterator trueSecond = sequence.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
    }
}

void PmergeMe::divideSequence(std::vector<int> & sequence, std::vector<int> & mainChain, 
                    std::vector<int> & pending, size_t groupSize)
{
    size_t numberOfGroups = sequence.size() / groupSize;
    for (size_t j = 1; j <= numberOfGroups; j++) {
        size_t start = (j - 1) * groupSize;
        size_t end = std::min(j * groupSize, sequence.size()); // Safeguard against out-of-bounds

        if (j % 2 != 0) { // Odd group, values go to pending
            pending.insert(pending.end(), sequence.begin() + start, sequence.begin() + end);
        } else {          // Even group, values go to mainChain
            mainChain.insert(mainChain.end(), sequence.begin() + start, sequence.begin() + end);
        }
    }

    // Handle remaining stragglers (if any)
    size_t stragglerStart = numberOfGroups * groupSize;
    if (stragglerStart < sequence.size()) {
        pending.insert(pending.end(), sequence.begin() + stragglerStart, sequence.end());
    }
	printContainer("\tdivideSequence(): Main chain = ", groupSize, mainChain);
	printContainer("\tdivideSequence(): Pending    = ", groupSize, pending);
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
		if (num > len)
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
    for (size_t i = seqSize; i > current; --i)
	{
        if (!inserted[i]) {
            result.push_back(i);
        }
    }
    return result;
}

size_t PmergeMe::binarySearch(const std::vector<int> &mainChain, int value, size_t end, size_t groupSize)
{
    size_t left = 0;       // Start at the first element
    size_t right = end;    // End at the last valid index

    while (left < right)
	{
        size_t mid = (left + right) / 2;

        // Check only the larger value (end of group) for comparison
        size_t groupEnd = ((mid / groupSize) + 1) * groupSize - 1;
        groupEnd = std::min(groupEnd, end - 1); // Avoid out-of-bounds access

        if (mainChain[groupEnd] > value)
            right = mid;
        else
            left = groupEnd + 1; // Move to the next group
    }

    return left;
}

void PmergeMe::binaryInsertion(std::vector<int> & sequence, size_t groupSize)
{
	printContainer("sequence    = ", groupSize, sequence);
	std::vector<int> mainChain;
	std::vector<int> pending;
	std::vector<int> straggler;

    // Determine the number of complete groups
    size_t numberOfGroups = sequence.size() / groupSize;

	if (sequence.size() % 2 > 0) {
		std::vector<int>::iterator start = sequence.begin() + (numberOfGroups * groupSize);
		std::vector<int>::iterator end = sequence.end();
		straggler.insert(straggler.end(), start, end);
		// // Erase the range from the source vector
		// sequence.erase(start, end);
		// printContainer("Straggler = ", groupSize, straggler);
	}

	std::cout << "sequence.size() = " << sequence.size() << " | groupSize = " << groupSize << " | Number of groups = " << numberOfGroups << std::endl;
	if (numberOfGroups > 1) {
		std::cout << "\nPerforming binary search insertion for group size: " << groupSize;
		std::cout << " | Number of groups: " << numberOfGroups << std::endl;
	}
	std::cout << "Dividing sequence: numberOfGroups = " << numberOfGroups << " | groupSize = " << groupSize << std::endl;
	divideSequence(sequence, mainChain, pending, groupSize);

    // Process each complete group
    // for (size_t groupIndex = 0; groupIndex < numberOfGroups; ++groupIndex) {
    //     size_t startIdx = groupIndex * groupSize;
    //     size_t endIdx = startIdx + groupSize;

	size_t pendingGroups = pending.size() / groupSize;
	for (size_t groupIndex = 0; groupIndex < pendingGroups; ++groupIndex) {
        size_t startIdx = groupIndex * groupSize;
        size_t endIdx = startIdx + groupSize;

		std::cout << ">>> >>> >>> groupIndex = " << groupIndex << " < " << " numberOfGroups = " << numberOfGroups << std::endl;
		std::cout << ">>> >>> >>> group startIdx = " << startIdx << " | endIdx = " << endIdx << std::endl;
        // Identify the "larger" value (rightmost in the group)
        int largerValue = pending[endIdx - 1];
  
        // Find the insertion position for the "larger" value
		if (numberOfGroups > 1 ) {
        	size_t position = binarySearch(mainChain, largerValue, mainChain.size(), groupSize);

			// Insert the entire group at the determined position
			mainChain.insert(mainChain.begin() + position, pending.begin() + startIdx, pending.begin() + endIdx);
			for (size_t i = 0; i < groupSize; i++) {
				std::cout << *(pending.begin() + startIdx + i) << " ";
			}
			std::cout << std::endl;
			printContainer("\tAfter BSinsertion: Main chain = ", groupSize, mainChain);
			printContainer("\tAfter BSinsertion: Pending    = ", groupSize, pending);
		}
    }
	
    // Handle remaining stragglers
    size_t stragglersStartIdx = numberOfGroups * groupSize;
    for (size_t i = stragglersStartIdx; i < pending.size(); ++i) {
        int valueToInsert = pending[i];
        size_t position = binarySearch(mainChain, valueToInsert, mainChain.size(), groupSize);
        mainChain.insert(mainChain.begin() + position, valueToInsert);
    }
	printContainer("\tAfter BSinsertion: Main chain = ", groupSize, mainChain);
	printContainer("\tAfter BSinsertion: Pending    = ", groupSize, pending);

    // size_t remainingStartIdx = numberOfGroups * groupSize;
	// std::cout << ">>>>> >>>>> remainingStartIdx = " << remainingStartIdx << std::endl;
    // if (remainingStartIdx < pending.size()) {
    //     // Insert remaining elements individually
    //     for (size_t i = remainingStartIdx; i < pending.size(); ++i) {
    //         int remainingValue = pending[i];
    //         size_t position = binarySearch(mainChain, remainingValue, mainChain.size(), groupSize);
    //         mainChain.insert(mainChain.begin() + position, remainingValue);
    //     }
    // }

}

void PmergeMe::mergeInsertionSort(std::vector<int>& sequence, size_t depth)
{
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= sequence.size()) {
        return; // Base case: No more groups to sort
    }

	// int	straggler;
	// if (sequence.size() % 2 == 1) {
	// 	straggler = sequence.back();
	// 	sequence.pop_back();
	// }

    // Step 1: Sort pairs of elements at this depth
    sortAdjacentPairs(sequence, groupSize);
	printContainer("", groupSize, sequence);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort(sequence, depth + 1);

    // Step 3: Insert remaining elements into the sorted sequence
    binaryInsertion(sequence, groupSize);
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