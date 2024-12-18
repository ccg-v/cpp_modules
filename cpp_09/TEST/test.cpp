#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::lower_bound
#include <utility>   // For std::pair
#include <deque>

static void sortPairs(std::deque<int>& src, size_t groupSize) {
    for (size_t tail = groupSize - 1; tail + groupSize < src.size(); tail += groupSize * 2) {
        for (size_t i = 0; i < groupSize; ++i) {
            if (src[tail - groupSize + 1 + i] > src[tail + 1 + i]) {
                std::swap(src[tail - groupSize + 1 + i], src[tail + 1 + i]);
            }
        }
    }
}




int main() {
    std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16};


    std::cout << "Original sequence:\n";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

    sortPairs(sequence, 1);

    // Recursion: Sort groups
    // fordJohnsonRecursion(sequence, relationships, groupBoundaries);

    // Unwinding: Insert smaller into larger
    // fordJohnsonUnwinding(sequence, relationships, groupBoundaries);

    std::cout << "Paired sequence:\n";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

	sortPairs(sequence, 2);

    std::cout << "Paired sequence:\n";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

    return 0;
}





