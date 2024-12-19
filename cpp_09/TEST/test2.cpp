#include <deque>
#include <iostream>


void printContainer(std::string msg, int groupSize, std::deque<int> sequence) {
    // std::cout << msg << ": " << groupSize << std::endl;

    size_t fullGroups = sequence.size() / groupSize; // Number of full groups
    size_t remainder = sequence.size() % groupSize; // Remaining elements

    size_t index = 0;
    for (size_t group = 0; group < fullGroups; ++group) {
        std::cout << "[ ";
        for (size_t i = 0; i < groupSize; ++i, ++index) {
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

void sortPairs(std::deque<int>& src, size_t groupSize) {
    size_t tail = groupSize - 1;

    while (tail + groupSize < src.size()) {
        std::deque<int>::iterator first = src.begin();
        std::advance(first, tail);

        std::deque<int>::iterator second = src.begin();
        std::advance(second, tail + groupSize);

        if (*first > *second) {
            std::deque<int>::iterator trueFirst = src.begin();
            std::advance(trueFirst, tail - groupSize + 1);

            std::deque<int>::iterator trueSecond = src.begin();
            std::advance(trueSecond, tail + 1);

            std::advance(first, 1);
            std::swap_ranges(trueFirst, first, trueSecond);
        }
        tail += groupSize * 2;
    }
}

void binarySearchInsertion(std::deque<int>& src, size_t groupSize) {
    // Placeholder for binary search insertion logic
    std::cout << "Performing binary search insertion for group size: " << groupSize << "\n";
    size_t fullGroups = sequence.size() / groupSize; // Number of full groups
	for (int i = 0; i <= fullGroups; ++i) {
		int left = 
	}
}

void mergeInsertionSort(std::deque<int>& sequence, size_t depth) {
    size_t groupSize = calculateGroupSize(depth); // Calculate group size as 2^depth

    if (groupSize >= sequence.size()) {
        return; // Base case: No more groups to sort
    }

    // Step 1: Sort pairs of elements at this depth
    sortPairs(sequence, groupSize);
	printContainer("Group size", groupSize, sequence);

    // Step 2: Recursively sort larger groups
    mergeInsertionSort(sequence, depth + 1);

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
// 		mergeInsertionSort(sequence, recursionDepth);
// 	}

//     return 0;
// }

int main() {
    std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};

    std::cout << "Original sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	size_t	recursionDepth = 0;

	// In each recursive call we calculate the group size as 2^depth
	// Recursion stops when the group size becomes larger than sequence size
    mergeInsertionSort(sequence, recursionDepth);

    std::cout << "Sorted sequence: ";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	// for (int i = 1; i < sequence.size(); i *= 2) 
	// 	printContainer("Group size", i, sequence);

    return 0;
}