#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::lower_bound
#include <utility>   // For std::pair

// Utility function to print a sequence
void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << (i + 1 < vec.size() ? " " : "\n");
    }
}

void fordJohnsonRecursion(std::vector<int>& sequence,
                          std::vector<std::pair<int, int> >& relationships,
                          std::vector<std::pair<int, int> >& groupBoundaries) {
    size_t n = sequence.size();
    if (n <= 1) {
        groupBoundaries.push_back(std::make_pair(0, n - 1)); // Base case: one group
        return;
    }

    // Step 1: Initialize groups as single elements
    groupBoundaries.clear();
    for (size_t i = 0; i < n; ++i) {
        groupBoundaries.push_back(std::make_pair(i, i));
    }

    std::vector<std::pair<int, int> > nextLevelGroups;

    while (groupBoundaries.size() > 1) {
        nextLevelGroups.clear();

        // Step 2: Pair adjacent groups
        for (size_t i = 0; i < groupBoundaries.size(); i += 2) {
            int start1 = groupBoundaries[i].first;
            int end1 = groupBoundaries[i].second;

            if (i + 1 >= groupBoundaries.size()) { // Handle odd group
                nextLevelGroups.push_back(std::make_pair(start1, end1));
                break;
            }

            int start2 = groupBoundaries[i + 1].first;
            int end2 = groupBoundaries[i + 1].second;

            // Compare the largest elements of both groups
            int largest1 = sequence[end1];
            int largest2 = sequence[end2];

            if (largest1 > largest2) {
                // Keep first group first
                nextLevelGroups.push_back(std::make_pair(start1, end2));
                relationships.push_back(std::make_pair(start2, start1)); // Relate smaller to larger
            } else {
                // Swap groups
                nextLevelGroups.push_back(std::make_pair(start2, end1));
                relationships.push_back(std::make_pair(start1, start2)); // Relate smaller to larger
            }
        }

        groupBoundaries = nextLevelGroups;

        // Debug: Print current groups
        std::cout << "Groups after merge step:\n";
        for (size_t i = 0; i < groupBoundaries.size(); ++i) {
            for (int j = groupBoundaries[i].first; j <= groupBoundaries[i].second; ++j) {
                std::cout << sequence[j] << " ";
            }
            std::cout << "| ";
        }
        std::cout << std::endl;
    }
}


void fordJohnsonUnwinding(std::vector<int>& sequence,
                          std::vector<std::pair<int, int> >& relationships,
                          std::vector<std::pair<int, int> >& groupBoundaries) {
    std::vector<int> sortedResult;

    // Start with the largest group
    int start = groupBoundaries[0].first;
    int end = groupBoundaries[0].second;
    for (int i = start; i <= end; ++i) {
        sortedResult.push_back(sequence[i]);
    }

    // Insert smaller groups using relationships
    for (size_t i = 0; i < relationships.size(); ++i) {
        int smallerIndex = relationships[i].first;
        // int largerIndex = relationships[i].second;

        // Find the range of the smaller group
        int startSmall = groupBoundaries[smallerIndex].first;
        int endSmall = groupBoundaries[smallerIndex].second;

        for (int j = startSmall; j <= endSmall; ++j) {
            // Perform binary insertion
            int value = sequence[j];
            std::vector<int>::iterator pos = std::upper_bound(sortedResult.begin(), sortedResult.end(), value);
            sortedResult.insert(pos, value);
        }
    }

    // Debug: Print final sorted result
    std::cout << "Sorted sequence: ";
    for (size_t i = 0; i < sortedResult.size(); ++i) {
        std::cout << sortedResult[i] << " ";
    }
    std::cout << std::endl;
}



int main() {
    std::vector<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16};
    std::vector<std::pair<int, int> > relationships;
    std::vector<std::pair<int, int> > groupBoundaries;

    std::cout << "Original sequence:\n";
    for (size_t i = 0; i < sequence.size(); ++i) {
        std::cout << sequence[i] << " ";
    }
    std::cout << "\n";

    // Recursion: Sort groups
    fordJohnsonRecursion(sequence, relationships, groupBoundaries);

    // Unwinding: Insert smaller into larger
    fordJohnsonUnwinding(sequence, relationships, groupBoundaries);

    return 0;
}





