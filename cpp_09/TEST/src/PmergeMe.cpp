/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccarrace <ccarrace@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 20:16:24 by ccarrace          #+#    #+#             */
/*   Updated: 2025/04/02 02:08:48 by ccarrace         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include "debug.hpp"

/* --- Orthodox Canonical Form ---------------------------------------------- */

// Default constructor
PmergeMe::PmergeMe() : _comparisons(0), _vectorStraggler(-1), _dequeStraggler(-1)
{
}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe & source) 
	: _comparisons(source._comparisons), _inputSeq(source._inputSeq), 
	  _vectorSeq(source._vectorSeq), _vectorMain(source._vectorMain), 
	  _vectorPending(source._vectorMain), _vectorStraggler(source._vectorStraggler), 
	  _dequeSeq(source._dequeSeq), _dequeMain(source._dequeMain),
	  _dequePending(source._dequePending), _dequeStraggler(source._dequeStraggler)
	 
{
}

// Copy assignment operator
PmergeMe & PmergeMe::operator=(const PmergeMe & source)
{
	if (this != &source)
	{
		this->_comparisons = source._comparisons;
		this->_inputSeq = source._inputSeq;

		this->_vectorSeq = source._vectorSeq;
		this->_vectorMain = source._vectorMain;
		this->_vectorPending = source._vectorPending;
		this->_vectorStraggler = source._vectorStraggler;

		this->_dequeSeq = source._dequeSeq;
		this->_dequeMain = source._dequeMain;
		this->_dequePending = source._dequePending;
		this->_dequeStraggler = source._dequeStraggler;
	}
	return *this;
}

// Default destructor
PmergeMe::~PmergeMe() {}

/* --- Getters -------------------------------------------------------------- */

std::vector<int> & PmergeMe::getInput()
{
	return this->_inputSeq;
}

// For vector
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

// For deque
std::deque<int> & PmergeMe::getDeque()
{
	return this->_dequeSeq;
}

std::deque<int> & PmergeMe::getDequeMain()
{
	return this->_dequeMain;
}

int	PmergeMe::getDequeStraggler()
{
	return this->_dequeStraggler;
}

/* --- Setters -------------------------------------------------------------- */

void	PmergeMe::setInput(int value)
{
	_inputSeq.push_back(value);
}

// For vector
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

// For deque
void	PmergeMe::setDeque(int value)
{
	_dequeSeq.push_back(value);
}

void	PmergeMe::setDequeStraggler()
{
	if (_dequeSeq.size() % 2 == 1) {
		_dequeStraggler = _dequeSeq.back();
		_dequeSeq.pop_back();
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
			
			setInput(value);
			setVector(value);
			setDeque(value);
		}
	}

	if (isSorted(getInput()))
		throw std::runtime_error("The input sequence is already sorted.");
}

size_t PmergeMe::calculateGroupSize(size_t depth)
{
    size_t groupSize = 1;
    for (size_t i = 0; i < depth; ++i) {
        groupSize *= 2; // Multiply by 2 for each level of depth
	}

    return (groupSize);
}

/* ===========================================================================

   Member methods for VECTOR-based sorting

   ===========================================================================*/

void PmergeMe::sortAdjacentPairs(size_t groupSize)
{
	if (groupSize > _vectorSeq.size())
		return;

	DEBUG_PRINT(std::cout << "\nSorting adjacent pairs ------------------------------------------------------" << std::endl);
	DEBUG_PRINT(std::cout << "   · groupSize = " << groupSize << std::endl);
		
    size_t tail = groupSize - 1;

    while (tail + groupSize < _vectorSeq.size())
    {
        size_t firstIdx = tail;
        size_t secondIdx = tail + groupSize;

        if (_vectorSeq[firstIdx] > _vectorSeq[secondIdx])
        {
            size_t trueFirstIdx = tail - groupSize + 1;
            size_t trueSecondIdx = tail + 1;

            for (size_t i = 0; i < groupSize; ++i)
                std::swap(_vectorSeq[trueFirstIdx + i], _vectorSeq[trueSecondIdx + i]);
        }
        tail += groupSize * 2;
        
        _comparisons++;
			
        DEBUG_PRINT(std::cout << "\tComparisons = " << YELLOW << _comparisons << RESET << std::endl);
    }
	DEBUG_PRINT(printContainer("     After pair sorting: ", groupSize, _vectorSeq));
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

	if (numberOfGroups != 1)
	{
		DEBUG_PRINT(std::cout << "\nDividing sequence -----------------------------------------------------------" << std::endl);
		DEBUG_PRINT(std::cout << "   · groupSize = " << groupSize << std::endl);
		DEBUG_PRINT(std::cout << "     numberOfGroups = " << numberOfGroups << std::endl);
		DEBUG_PRINT(printContainer("     To divide  = ", groupSize, _vectorSeq));
		DEBUG_PRINT(printContainer("     Main chain = ", groupSize, _vectorMain));
		DEBUG_PRINT(printContainer("     Pending    = ", groupSize, _vectorPending));
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
	
	// I substract 1 to rightGroup to initialize it as the group at the 
	// left of the upperBound to avoid unnecessary comparisons with the
	// upperBound (we already know its always greater than the value to
	// be inserted)
	// --> The progression of the number of comparisons performed turns
	// 		unbalanced (0 + 2 + 3 + 2 + ...) which is strange
	size_t	rightGroup = (((end + 1) / groupSize) - 1) - 1;
	// size_t	rightGroup = (((end + 1) / groupSize) - 1);
	if (rightGroup >= numOfMainGroups)
		rightGroup = numOfMainGroups - 1;

	// DEBUG_PRINT(printContainer("binarySearch: input mainChain = ", groupSize, _vectorMain));
	// DEBUG_PRINT(printContainer("binarySearch: input pending   = ", groupSize, _vectorPending));

	size_t	upperBoundIndex = end;
	if (upperBoundIndex >= _vectorMain.size()) 
		upperBoundIndex = _vectorMain.size() - 1;

	size_t	upperBoundGroup = end / groupSize;
	if (upperBoundGroup >= numOfMainGroups)
		upperBoundGroup = numOfMainGroups - 1;

	// DEBUG_PRINT(std::cout << "\n\t... upperBoundMainIndex is ")
	DEBUG_PRINT(std::cout << "\t... upperBound is mainChain[" << upperBoundIndex << "] = " 
			  << GREEN << _vectorMain[upperBoundIndex] << RESET << " in group[" 
			  << upperBoundGroup << "]" << std::endl);
	DEBUG_PRINT(std::cout << "\n\tBinary searching insertion point: -----------------------------------" << std::endl);

    while (leftGroup <= rightGroup)
    {	
		size_t	midGroup = (leftGroup + rightGroup) / 2;
		size_t	midIndex = (groupSize - 1) + (midGroup * groupSize);
		size_t	midValue = _vectorMain[(midGroup * groupSize) + (groupSize - 1)];
		// size_t	leftValue = _vectorMain[(leftGroup * groupSize) + groupSize - 1];
		// size_t	rightValue = _vectorMain[(rightGroup * groupSize) + groupSize - 1];

		DEBUG_PRINT(std::cout << "\t    ... left bound is " << _vectorMain[(leftGroup * groupSize) + groupSize - 1] << " | ");
		DEBUG_PRINT(std::cout << "right bound is " << _vectorMain[(rightGroup * groupSize) + groupSize - 1] << " -> ");
		DEBUG_PRINT(std::cout << "mid value is " << midValue << " -> ");
		if (static_cast<size_t>(valueToInsert) > midValue)
			DEBUG_PRINT(std::cout << valueToInsert << " > " << midValue << std::endl);
		else
			DEBUG_PRINT(std::cout << valueToInsert << " < " << midValue << std::endl);

		if (midValue == static_cast<size_t>(_vectorMain[end]))
		{
			_comparisons++;
			DEBUG_PRINT(std::cout << "\t\tComparisons = " << YELLOW << _comparisons << RESET << std::endl);
			break ;
		}
		
        if (midValue > static_cast<size_t>(valueToInsert))
        { 
			if (midIndex < groupSize) // midIndex points to the leftmost value to be compared with, I break to prevent underflow
			{ 
				_comparisons++;
				DEBUG_PRINT(std::cout << "\t\tComparisons = " << YELLOW << _comparisons << RESET << std::endl);
				break ;
			}
            rightGroup = midGroup - 1; // Move 'right' to the previous group index
        }
        else
        {
            leftGroup = midGroup + 1; // Move 'left' to the next group index
        }

        _comparisons++;
		DEBUG_PRINT(std::cout << "\t\tComparisons = " << YELLOW << _comparisons << RESET << std::endl);
    }

    // Translate 'left' to the correct position for insertion
    size_t insertionIndex = (leftGroup * groupSize);
	DEBUG_PRINT(std::cout << "\t\t--> insertion position is " << insertionIndex << std::endl);
	// DEBUG_PRINT(std::cout << "\t\tValue returned for insertion is " << insertionIndex << std::endl);
	// DEBUG_PRINT(std::cout << "binarySearch: COMPARISONS = " << _comparisons << "\n" << std::endl);
	
    return (insertionIndex);
}

void PmergeMe::binaryInsertion(size_t groupSize)
{
	size_t 				numOfPendingGroups = _vectorPending.size() / groupSize;
	size_t 				numOfMainGroups = _vectorMain.size() / groupSize;
    std::vector<int> 	jacobsthalSeq = buildJacobsthalVec(numOfPendingGroups);
	std::vector<int> 	pickingIndexes = getPickingOrder(jacobsthalSeq, numOfPendingGroups);
	std::vector<size_t> upperBoundsTrack;

    // Initialize pair positions
    for (size_t i = 0; i < numOfPendingGroups; ++i)
	{
        upperBoundsTrack.push_back(i);
    }

	DEBUG_PRINT(std::cout << "\nPerforming binary search & binary insertion ---------------------------------" << std::endl);
	DEBUG_PRINT(printContainer("     Before insertion: Main chain = ", groupSize, _vectorMain));
	DEBUG_PRINT(printContainer("     Before insertion: Pending    = ", groupSize, _vectorPending));
	DEBUG_PRINT(printContainer("     jacobsthalSeq    = ", 1, jacobsthalSeq));
	DEBUG_PRINT(printContainer("     pickingIndexes   = ", 1, pickingIndexes));
	DEBUG_PRINT(printContainer("     upperBoundsTrack = ", 1, upperBoundsTrack));

	for (size_t groupIndex = 0; groupIndex < numOfPendingGroups; ++groupIndex)
	{
		size_t	pickingIndex = pickingIndexes[groupIndex];
        size_t	startIdx = pickingIndex * groupSize;
        size_t 	endIdx = startIdx + groupSize;
		size_t	upperBoundGroupIndex = upperBoundsTrack[pickingIndex];
		size_t	upperBoundMainIndex = (upperBoundGroupIndex * groupSize) + (groupSize - 1);

        // Identify the "larger" value (rightmost in the group)
        int largerValue = _vectorPending[endIdx - 1];

		DEBUG_PRINT(std::cout << "\n     Inserting group[" << pickingIndex << "] | largerValue = " 
							  << GREEN << largerValue << RESET << " -----------------------------------" << std::endl);

        // Find the insertion position for the "larger" value 
		size_t position;

		// Pending value to insert is greater than the rightmost in main chain, it must be appended, no need to perform binary search,
		if (upperBoundGroupIndex > numOfMainGroups  && largerValue > _vectorMain.back())
		{
			position = _vectorMain.size();
			_comparisons++;
			DEBUG_PRINT(std::cout << "\tComparisons = " << YELLOW << _comparisons << RESET << "\n" << std::endl);
		}
		else // Perform binary search
		{
			if (upperBoundGroupIndex == 0) 
				position = 0;
			else if (upperBoundGroupIndex >= _vectorMain.size())
				position = binarySearch(largerValue, _vectorMain.size(), groupSize);
			else
				position = binarySearch(largerValue, upperBoundMainIndex, groupSize);
		}

		// Insert the entire group at the determined position
		_vectorMain.insert(_vectorMain.begin() + position, _vectorPending.begin() + startIdx, _vectorPending.begin() + endIdx);

		// this is the key to avoid having to perform searches to find the upper bound
		// pairPositions holds the position of all larger values in main chain (ONLY
		// the larger) and updates them every time an insertion is made (values after
		// the inserted one are shifted, hence their index in pairPositions will be 
		// incremented)
		for (size_t j = 0; j < upperBoundsTrack.size(); ++j)
		{
			if (upperBoundsTrack[j] >= (position / groupSize))
				upperBoundsTrack[j] = upperBoundsTrack[j] + 1;
		}

		DEBUG_PRINT(printContainer("\tAfter insertion:  Main chain = ", groupSize, _vectorMain));
		DEBUG_PRINT(printContainer("\tAfter insertion:  Pending    = ", groupSize, _vectorPending));
    }

	// appends remains AT THE END OF MAIN CHAIN (no binary insertion)
	size_t	remainsStartIdx = _vectorPending.size() - (_vectorPending.size() % groupSize);
    for (size_t i = remainsStartIdx; i < _vectorPending.size(); ++i) 
	{
		DEBUG_PRINT(std::cout << "\t... inserting remaining value " << _vectorPending[i] << std::endl);
        int valueToInsert = _vectorPending[i];
        _vectorMain.insert(_vectorMain.end(), valueToInsert);
    }

	_vectorSeq = _vectorMain;

	// printContainer("\tdivideSequence(): SEQUENCE UPDATED = ", groupSize, _vectorMain);
}

void PmergeMe::mergeInsertionSort_vector(size_t depth)
{
	if (_vectorSeq.size() % 2 == 1)
	{
		_vectorStraggler = _vectorSeq.back();
		_vectorSeq.pop_back();
		DEBUG_PRINT(std::cout << "Even elements, popping straggler = " << _vectorStraggler << std::endl);
	}
	
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= _vectorSeq.size())
	{
        return; // Base case: No more groups to sort, stop recursion forwarding and start rewinding
    }

    // Step 1: Sort pairs of elements at this depth
    sortAdjacentPairs(groupSize);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort_vector(depth + 1);

	// Step 3: Divide sequence in main and pending at every rewinding recursion step
	divideSequence(groupSize);
	
    // Step 4: Insert pending into main at every rewinding recursion step
    binaryInsertion(groupSize);

	// Step 5: Insert the straggler, if there is one
	if (groupSize == 1 && _vectorStraggler > 0)
	{
		DEBUG_PRINT(std::cout << "\n     Inserting straggler = " << GREEN << _vectorStraggler << RESET << " ------------------------------------------------" << std::endl);
		if (_vectorStraggler > _vectorMain.back())
		{
			std::cout << "straggler value (" << _vectorStraggler << ") is bigger than end value (" << _vectorMain.back() << "), we insert it at the end" << std::endl;
        	_vectorMain.push_back(_vectorStraggler);
			_comparisons++;
			DEBUG_PRINT(std::cout << "\tComparisons = " << YELLOW << _comparisons << RESET << "\n" << std::endl);
		}
		else
		{
			size_t position = binarySearch(_vectorStraggler,_vectorMain.size() - 1, groupSize);
			_vectorMain.insert(_vectorMain.begin() + position, _vectorStraggler);
		}
	}
}

/* ===========================================================================

   Member methods for DEQUE-based sorting

   ===========================================================================*/


void PmergeMe::sortAdjacentPairs_deque(size_t groupSize)
{
    size_t tail = groupSize - 1;

    while (tail + groupSize < _dequeSeq.size())
    {
        size_t firstIdx = tail;
        size_t secondIdx = tail + groupSize;

        if (_dequeSeq[firstIdx] > _dequeSeq[secondIdx])
        {
            size_t trueFirstIdx = tail - groupSize + 1;
            size_t trueSecondIdx = tail + 1;

            // Swap elements manually
            for (size_t i = 0; i < groupSize; ++i)
                std::swap(_dequeSeq[trueFirstIdx + i], _dequeSeq[trueSecondIdx + i]);
        }
        tail += groupSize * 2;
    }
}

void PmergeMe::divideSequence_deque(size_t groupSize)
{
	_dequeMain.clear();
	_dequePending.clear();
	
    size_t numberOfGroups = _dequeSeq.size() / groupSize;

    for (size_t j = 1; j <= numberOfGroups; j++)
	{
        size_t start = (j - 1) * groupSize;
        size_t end = std::min(j * groupSize, _dequeSeq.size()); // Safeguard against out-of-bounds

    // for (size_t j = 0; j < numberOfGroups; ++j)
    // {
    //     size_t start = j * groupSize;
    //     size_t end = start + groupSize;
		
        if (j % 2 != 0) // Odd group, values go to pending
		{ 
            _dequePending.insert(_dequePending.end(), _dequeSeq.begin() + start, _dequeSeq.begin() + end);
        }
		else // Even group, values go to mainChain
		{          
            _dequeMain.insert(_dequeMain.end(), _dequeSeq.begin() + start, _dequeSeq.begin() + end);
        }
    }

    // Handle remaining stragglers (if any)
    size_t stragglerStart = numberOfGroups * groupSize;
    if (stragglerStart < _dequeSeq.size())
	{
        _dequePending.insert(_dequePending.end(), _dequeSeq.begin() + stragglerStart, _dequeSeq.end());
    }
}

std::deque<int> PmergeMe::buildJacobsthalDeque(size_t len)
{
    std::deque<int>	JacobsthalSeq;
    size_t			num;

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

std::deque<int> PmergeMe::getPickingOrder_deque(const std::deque<int> & jacobsthalSeq, size_t seqSize)
{
    std::deque<int> result;
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

size_t PmergeMe::binarySearch_deque(int valueToInsert, size_t end, size_t groupSize)
{
	size_t	numOfMainGroups = _dequeMain.size() / groupSize;
	size_t	leftGroup = 0;
	
	size_t	rightGroup = (((end + 1) / groupSize) - 1) - 1;
	// size_t	rightGroup = (((end + 1) / groupSize) - 1);
	if (rightGroup >= numOfMainGroups)
		rightGroup = numOfMainGroups - 1;

	size_t	upperBoundIndex = end;
	if (upperBoundIndex >= _dequeMain.size()) 
		upperBoundIndex = _dequeMain.size() - 1;

	size_t	upperBoundGroup = end / groupSize;
	if (upperBoundGroup >= numOfMainGroups)
		upperBoundGroup = numOfMainGroups - 1;

    while (leftGroup <= rightGroup)
    {	
		size_t	midGroup = (leftGroup + rightGroup) / 2;
		size_t	midIndex = (groupSize - 1) + (midGroup * groupSize);
		size_t	midValue = _dequeMain[(groupSize - 1) + (midGroup * groupSize)];

		if (midValue == static_cast<size_t>(_dequeMain[end]))
		{
			break ;
		}
		
        if (midValue > static_cast<size_t>(valueToInsert))
        { 
			if (midIndex < groupSize) // midIndex points to the leftmost value to be compared with, I break to prevent underflow
			{ 
				break ;
			}
            rightGroup = midGroup - 1; // Move 'right' to the previous group index
        }
        else
        {
            leftGroup = midGroup + 1; // Move 'left' to the next group index
        }
    }

    // Translate 'left' to the correct position for insertion
    size_t insertionIndex = (leftGroup * groupSize);
	
    return (insertionIndex);
}

void PmergeMe::binaryInsertion_deque(size_t groupSize)
{
	size_t numOfPendingGroups = _dequePending.size() / groupSize;

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
        int largerValue = _dequePending[endIdx - 1];

         // Find the insertion position for the "larger" value 
		size_t position;
  
		if (upperBoundGroupIndex == 0) 
			position = 0;
		else if (upperBoundGroupIndex >= _dequeMain.size())
			position = binarySearch_deque(largerValue, _dequeMain.size(), groupSize);
		else
			position = binarySearch_deque(largerValue, upperBoundMainIndex, groupSize);

		// Insert the entire group at the determined position
		_dequeMain.insert(_dequeMain.begin() + position, _dequePending.begin() + startIdx, _dequePending.begin() + endIdx);

		for (size_t j = 0; j < upperBoundsTrack.size(); ++j)
		{
			if (upperBoundsTrack[j] >= (position / groupSize))
				upperBoundsTrack[j] = upperBoundsTrack[j] + 1;
		}
    }

	// inserting remains AT THE END OF MAIN CHAIN (no binary insertion)
	size_t	remainsStartIdx = _dequePending.size() - (_dequePending.size() % groupSize);
    for (size_t i = remainsStartIdx; i < _dequePending.size(); ++i) 
	{
        int valueToInsert = _dequePending[i];
        _dequeMain.insert(_dequeMain.end(), valueToInsert);
    }

	_dequeSeq = _dequeMain;
}

void PmergeMe::mergeInsertionSort_deque(size_t depth)
{
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= _dequeSeq.size())
	{
        return; // Base case: No more groups to sort
    }

	if (_dequeSeq.size() % 2 == 1)
	{
		_dequeStraggler = _dequeSeq.back();
		_dequeSeq.pop_back();
	}

    // Step 1: Sort pairs of elements at this depth
    sortAdjacentPairs_deque(groupSize);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort_deque(depth + 1);

	divideSequence_deque(groupSize);

    // Step 3: Insert remaining elements into the sorted sequence
    binaryInsertion_deque(groupSize);

	if (groupSize == 1 && _dequeStraggler > 0)
	{
		if (_dequeStraggler > _dequeMain.back())
		{
        	_dequeMain.push_back(_dequeStraggler);
		}
		else
		{
			size_t position = binarySearch(_dequeStraggler,_dequeMain.size() - 1, groupSize);
			_dequeMain.insert(_dequeMain.begin() + position, _dequeStraggler);
		}
	}
}
