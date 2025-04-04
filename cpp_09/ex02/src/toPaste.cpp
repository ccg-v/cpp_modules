/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   toPaste.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/03/30 22:43:53 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _vectorStraggler(-1), _comparisons(0) {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _vectorSeq(source._vectorSeq), _vectorMain(source._vectorMain), 
	  _vectorPending(source._vectorMain), _vectorStraggler(source._vectorStraggler), 
	  _comparisons(source._comparisons) {}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source)
{
	if (this != &source) {
		this->_vectorSeq = source._vectorSeq;
		this->_vectorMain = source._vectorMain;
		this->_vectorPending = source._vectorPending;
		this->_vectorStraggler = source._vectorStraggler;
		this->_comparisons = source._comparisons;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<int> & PmergeMe::getVector()
{
	return this->_vectorSeq;
}

std::vector<int> & PmergeMe::getVectorMain()
{
	return this->_vectorMain;
}

int	PmergeMe::getVectorStraggler()
{
	return this->_vectorStraggler;
}

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setVector(int value)
{
	_vectorSeq.push_back(value);
}

void	PmergeMe::setVectorStraggler()
{
	if (_vectorSeq.size() % 2 == 1) {
		_vectorStraggler = _vectorSeq.back();
		_vectorSeq.pop_back();
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
    return groupSize;
}

void PmergeMe::sortAdjacentPairs(size_t groupSize)
{
    size_t tail = groupSize - 1;

    while (tail + groupSize < _vectorSeq.size())
	{
        std::vector<int>::iterator first = _vectorSeq.begin();
        std::advance(first, tail);

        std::vector<int>::iterator second = _vectorSeq.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second)
		{
            std::vector<int>::iterator trueFirst = _vectorSeq.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::vector<int>::iterator trueSecond = _vectorSeq.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
			// swap_ranges args: (range start, range end, place to insert)
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
		
		_comparisons++;
    }
}

void PmergeMe::divideSequence(size_t groupSize)
{
	_vectorMain.clear();
	_vectorPending.clear();
	
    size_t numberOfGroups = _vectorSeq.size() / groupSize;
    for (size_t j = 1; j <= numberOfGroups; j++)
	{
        size_t start = (j - 1) * groupSize;
        size_t end = std::min(j * groupSize, _vectorSeq.size()); // Safeguard against out-of-bounds

        if (j % 2 != 0) // Odd group, values go to pending
		{ 
            _vectorPending.insert(_vectorPending.end(), _vectorSeq.begin() + start, _vectorSeq.begin() + end);
        }
		else // Even group, values go to mainChain
		{          
            _vectorMain.insert(_vectorMain.end(), _vectorSeq.begin() + start, _vectorSeq.begin() + end);
        }
    }

    // Handle remaining stragglers (if any)
    size_t stragglerStart = numberOfGroups * groupSize;
    if (stragglerStart < _vectorSeq.size())
	{
        _vectorPending.insert(_vectorPending.end(), _vectorSeq.begin() + stragglerStart, _vectorSeq.end());
    }
}

std::vector<int> PmergeMe::buildJacobsthalVec(size_t len)
{
    std::vector<int>	JacobsthalSeq;
    size_t				num;

    JacobsthalSeq.push_back(0);
    JacobsthalSeq.push_back(1);
    for (size_t i = 2; i < len; i++)
	{
        num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		if (num >= len)
			break ;
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
    if (seqSize > 0)
	{
        result.push_back(0);
        inserted[0] = true;
    }

    size_t current = 1; // Start interleaving from index 1

    // Process each Jacobsthal boundary
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i)
	{
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(seqSize))
            break ; // Ignore out-of-bounds Jacobsthal indices

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
        if (!inserted[i])
            result.push_back(i);
    }
    return result;
}

size_t PmergeMe::binarySearch(int valueToInsert, size_t end, size_t groupSize)
{
	size_t	numOfMainGroups = _vectorMain.size() / groupSize;
	size_t	leftGroup = 0;
	size_t	rightGroup = (((end + 1) / groupSize) - 1) - 1;

	if (rightGroup >= numOfMainGroups)
		rightGroup = numOfMainGroups - 1;

	size_t	upperBoundIndex = end;
	if (upperBoundIndex >= _vectorMain.size()) 
		upperBoundIndex = _vectorMain.size() - 1;

	size_t	upperBoundGroup = end / groupSize;
	if (upperBoundGroup >= numOfMainGroups)
		upperBoundGroup = numOfMainGroups - 1;

    while (leftGroup <= rightGroup)
    {	

		size_t	midGroup = (leftGroup + rightGroup) / 2;
		size_t	midIndex = (groupSize - 1) + (midGroup * groupSize);
		size_t	midValue = _vectorMain[(groupSize - 1) + (midGroup * groupSize)];

		if (midValue == static_cast<size_t>(_vectorMain[end]))
		{
			_comparisons++;
			break ;
		}

        if (midValue > static_cast<size_t>(valueToInsert))
        { 
			if (midIndex < groupSize) // midIndex points to the leftmost value to be compared with, I break to prevent underflow
			{ 
				_comparisons++;
				break ;
			}
            rightGroup = midGroup - 1; // Move 'right' to the previous group index
        }
        else
        {
            leftGroup = midGroup + 1; // Move 'left' to the next group index
        }

        _comparisons++;
    }

    // Translate 'left' to the correct position for insertion
    size_t insertionIndex = (leftGroup * groupSize);
	
    return (insertionIndex);
}

void PmergeMe::binaryInsertion(size_t groupSize)
{
	size_t numOfPendingGroups = _vectorPending.size() / groupSize;
	size_t numOfMainGroups = _vectorMain.size() / groupSize;

    std::vector<int> jacobsthalSeq = buildJacobsthalVec(numOfPendingGroups);
	std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, numOfPendingGroups);
	std::vector<size_t> upperBoundsTrack;

    // Initialize pair positions
    for (size_t i = 0; i < numOfPendingGroups; ++i)
	{
        upperBoundsTrack.push_back(i);
    }

	for (size_t groupIndex = 0; groupIndex < numOfPendingGroups; ++groupIndex)
	{

		size_t	pickingIndex = pickingIndexes[groupIndex];
        size_t	startIdx = pickingIndex * groupSize;
        size_t 	endIdx = startIdx + groupSize;
		size_t	upperBoundGroupIndex = upperBoundsTrack[pickingIndex];
		size_t	upperBoundMainIndex = (upperBoundGroupIndex * groupSize) + (groupSize - 1);

        // Identify the "larger" value (rightmost in the group)
        int largerValue = _vectorPending[endIdx - 1];

		size_t position;
        // Find the insertion position for the "larger" value  

		if (upperBoundGroupIndex == 0) 
			position = 0;
		else if (upperBoundGroupIndex >= _vectorMain.size())
			position = binarySearch(largerValue, _vectorMain.size(), groupSize);
		else
			position = binarySearch(largerValue, upperBoundMainIndex, groupSize);

		// Insert the entire group at the determined position
		_vectorMain.insert(_vectorMain.begin() + position, _vectorPending.begin() + startIdx, _vectorPending.begin() + endIdx);

		for (size_t j = 0; j < upperBoundsTrack.size(); ++j) {
			if (upperBoundsTrack[j] >= (position / groupSize))
				upperBoundsTrack[j] = upperBoundsTrack[j] + 1;
		}

    }

	// inserting remains AT THE END OF MAIN CHAIN (no binary insertion)
	size_t	remainsStartIdx = _vectorPending.size() - (_vectorPending.size() % groupSize);
    for (size_t i = remainsStartIdx; i < _vectorPending.size(); ++i) 
	{
        int valueToInsert = _vectorPending[i];
        _vectorMain.insert(_vectorMain.end(), valueToInsert);
    }

	_vectorSeq = _vectorMain;
}

void PmergeMe::mergeInsertionSort_vector(size_t depth)
{
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= _vectorSeq.size())
	{
        return; // Base case: No more groups to sort
    }

	if (_vectorSeq.size() % 2 == 1)
	{
		_vectorStraggler = _vectorSeq.back();
		_vectorSeq.pop_back();
	}

    // Step 1: Sort pairs of elements at this depth
    sortAdjacentPairs(groupSize);
	printContainer("", groupSize, _vectorSeq);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort_vector(depth + 1);

	divideSequence(groupSize);
	
    // Step 3: Insert remaining elements into the sorted sequence
    binaryInsertion(groupSize);

	if (groupSize == 1 && _vectorStraggler > 0)
	{
		size_t position = binarySearch(_vectorStraggler,_vectorMain.size(), groupSize);
		_vectorMain.insert(_vectorMain.begin() + position, _vectorStraggler);
	}
}
