#include <vector>
#include <iostream>
#include <cmath>


void printContainer(std::string msg, int groupSize, std::vector<int> sequence) {
    // std::cout << msg << ": " << groupSize << std::endl;
    size_t numberOfGroups = sequence.size() / groupSize; // Number of full groups
    size_t remainder = sequence.size() % groupSize; // Remaining elements

    size_t index = 0;
	std::cout << msg;
    for (size_t group = 0; group < numberOfGroups; ++group) {
        std::cout << "[ ";
        for (size_t i = 0; i < static_cast<size_t>(groupSize); ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
        std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0) {
        for (size_t i = 0; i < remainder; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
    }
    std::cout << std::endl;
}

size_t calculateGroupSize(size_t depth) {
    size_t groupSize = 1;
    for (size_t i = 0; i < depth; ++i) {
        groupSize *= 2; // Multiply by 2 for each level of depth
    }
std::cout << "groupSize = " << groupSize << std::endl;
    return groupSize;
}

void sortPairs(std::vector<int>& src, size_t groupSize) {
    size_t tail = groupSize - 1;

    while (tail + groupSize < src.size()) {
        std::vector<int>::iterator first = src.begin();
        std::advance(first, tail);

        std::vector<int>::iterator second = src.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second) {
            std::vector<int>::iterator trueFirst = src.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::vector<int>::iterator trueSecond = src.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
    }
}

std::vector<int> buildJacobsthalVec(size_t len)
{
    std::vector<int>	JacobsthalSeq;
    size_t			num;
std::cout << "buildJacobsthal(): len received is " << len << std::endl;
    JacobsthalSeq.push_back(0);
    JacobsthalSeq.push_back(1);
    for (size_t i = 2; i < len; i++) {
        num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		if (num > len)
			break;
        JacobsthalSeq.push_back(num);
    }
    // Remove the first two elements if the sequence has at least two elements
    if (JacobsthalSeq.size() > 2) {
        JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
    }
    return JacobsthalSeq;
}

std::vector<int> getPickingOrder(const std::vector<int> & jacobsthalSeq, size_t seqSize)
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
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(seqSize)) {
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
    for (size_t i = seqSize; i > current; --i)
	{
        if (!inserted[i]) {
            result.push_back(i);
        }
    }
    return result;
}

// void	divideSequence(std::vector<int> sequence, std::vector<int> & mainChain, 
// 		std::vector<int> & pending, size_t groupSize)
// {
// 	size_t numberOfGroups = sequence.size() / groupSize;
// 	for (size_t j = 1; j < numberOfGroups; j++) {
// 		size_t start = (j - 1) * groupSize; // Start index of the current group
// 		size_t end = j * groupSize;         // End index (exclusive) of the current group

// 		if (j % 2 != 0) { // Odd group, values go to pending
// 			for (size_t k = start; k < end; k++) {
// 				pending.push_back(sequence[k]);
// 			}
// 		} else {          // Even group, values go to mainChain
// 			for (size_t k = start; k < end; k++) {
// 				mainChain.push_back(sequence[k]);
// 			}
// 		}
// 	}
// }

void divideSequence(const std::vector<int> &sequence, std::vector<int> &mainChain, 
                    std::vector<int> &pending, size_t groupSize) {
    // if (groupSize == 0) {
    //     throw std::invalid_argument("Group size must be greater than 0.");
    // }

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


// size_t	binarySearch(const std::vector<int> & mainChain, int value, size_t end)
// {
// 	std::cout << " | upper bound is mainChain[" << end << "] = " << mainChain[end] << std::endl; 
//     size_t left = 0;
//     size_t right = end;
//     while (left < right) {
// 		// _comparisons++;
//         size_t mid = (left + right) / 2;
//         if (mainChain[mid] > value)
//             right = mid;
//         else
//             left = mid + 1;
// 		std::cout << "\t\t...comparing pending " << value << " with " << mainChain[mid] << " in position [" << mid << "]..." << std::endl;
//     }
//     return left;
// }

size_t binarySearch(const std::vector<int> &mainChain, int value, size_t end, size_t groupSize) {
    size_t left = 0;       // Start at the first element
    size_t right = end;    // End at the last valid index

    while (left < right) {
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


// size_t	binarySearch(const std::vector<int> & mainChain, int value, size_t end, size_t groupSize)
// {
// 	std::cout << " | upper bound is mainChain[" << end << "] = " << mainChain[end] << std::endl; 
//     size_t left = groupSize - 1;
//     size_t right = end;
//     while (left < right) {
// 		// _comparisons++;
//         size_t mid = (left + right) / 2;
//         if (mainChain[mid] > value)
//             right = mid;
//         else
//             left = mid + groupSize;
// 		std::cout << "\t\t...comparing pending " << value << " with " << mainChain[mid] << " in position [" << mid << "]..." << std::endl;
//     }
//     return left;
// }

void binarySearchInsertion(std::vector<int> & sequence, size_t groupSize) {
	
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


// void binarySearchInsertion(std::vector<int> & sequence, size_t groupSize) {
//     // Placeholder for binary search insertion logic
// 	size_t numberOfGroups = sequence.size() / groupSize;

// 	if (numberOfGroups > 1) {
// 		std::cout << "\nPerforming binary search insertion for group size: " << groupSize;
// 		std::cout << " | Number of groups: " << numberOfGroups << std::endl;
// 	}

// 	printContainer("sequence    = ", groupSize, sequence);
// 	std::vector<int> mainChain;
// 	std::vector<int> pending;

// 	divideSequence(sequence, mainChain, pending, groupSize);
	
// 	// Generate insertion order using Jacobsthal sequence
// 	std::vector<int> jacobsthalSeq = buildJacobsthalVec(numberOfGroups);
// 	std::vector<int> pickingIndexes = getPickingOrder(jacobsthalSeq, numberOfGroups);
// 	std::vector<int> upperBoundsPositions;

//     // Initialize upper bounds positions
//     for (size_t i = 0; i < pending.size(); ++i) {
//         upperBoundsPositions.push_back(i);
//     }

// 	printContainer("Main chain = ", groupSize, mainChain);
// 	printContainer("Pending    = ", groupSize, pending);
// 	printContainer("Jacobsthal sequence = ", numberOfGroups, jacobsthalSeq);
// 	printContainer("Picking order seq   = ", numberOfGroups, pickingIndexes);

//     std::vector<bool> inserted(pending.size(), false);
//     for (size_t i = 0 ; i < pending.size(); i++)
// 	{
//         size_t pickingIndex = pickingIndexes[i];
// 		size_t upperBound = upperBoundsPositions[pickingIndex + (groupSize - 1)];

//         if (pickingIndex < pending.size() && !inserted[pickingIndex])
// 		{
//             int valueToInsert = pending[pickingIndex + (groupSize - 1)];
// 			std::cout << "groupSize is " << groupSize << std::endl;
// 			std::cout << "\tinserting pending[" << pickingIndexes[i] << "] = " << valueToInsert;

//             size_t position;
//            	position = binarySearch(mainChain, valueToInsert, upperBound, groupSize);

// 			std::cout << "\tvalue to insert: " << valueToInsert << std::endl;
// 			mainChain.insert((mainChain.begin() + position - i), valueToInsert, groupSize);

//             inserted[pickingIndex] = true;

// 			for (size_t j = 0; j < static_cast<size_t>(upperBoundsPositions.size()); ++j) {
// 				if (static_cast<size_t>(upperBoundsPositions[j]) >= position)
// 					upperBoundsPositions[j] = upperBoundsPositions[j] + 1;
// 			}
// 			printContainer("\tupperBoundsPositions = ", upperBoundsPositions.size(), upperBoundsPositions);
// 			// std::cout << "....... COMPARISONS = " << _comparisons << "\n" << std::endl;
//         }
// 		printContainer("Main chain = ", groupSize, mainChain);
// 		printContainer("Pending    = ", groupSize, pending);
// 	}
// }

void mergeInsertionSort_vector(std::vector<int>& sequence, size_t depth) {
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
    sortPairs(sequence, groupSize);
	printContainer("", groupSize, sequence);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort_vector(sequence, depth + 1);

    // Step 3: Insert remaining elements into the sorted sequence
    binarySearchInsertion(sequence, groupSize);
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
// 		mergeInsertionSort_vector(sequence, recursionDepth);
// 	}

//     return 0;
// }

int main() {
	// std::vector<int> sequence = {3, 1, 2, 5, 4};
    // std::vector<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};
    std::vector<int> sequence = {1, 7, 4, 11, 5, 16, 6, 19, 8, 14, 20, 23, 9, 15, 22, 24, 2, 10, 3, 12, 13, 18, 17, 25, 21};

    std::cout << "Original sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	size_t	recursionDepth = 0;

	// In each recursive call we calculate the group size as 2^depth
	// Recursion stops when the group size becomes larger than sequence size
    mergeInsertionSort_vector(sequence, recursionDepth);

    std::cout << "Sorted sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	// for (int i = 1; i < sequence.size(); i *= 2) 
	// 	printContainer("Group size", i, sequence);

    return 0;
}