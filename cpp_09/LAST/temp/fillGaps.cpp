#include <iostream>
#include <vector>
#include <sstream>

std::vector<int> fillGaps(const std::vector<int>& sortedSequence) {
    std::vector<int> result;

    for (size_t i = 0; i < sortedSequence.size(); ++i) {
        int current = sortedSequence[i];
        result.push_back(current); // Store the current number (lower boundary)

        // Check if there is a next number and a gap to fill
        if (i < sortedSequence.size() - 1) {
            int next = sortedSequence[i + 1];
            // If there is a gap between current and next number
            if (next > current + 1) {
                // Store the upper boundary
                result.push_back(next);
                // Fill the gap after storing the upper boundary, in descending order
                for (int j = next - 1; j > current; --j) {
                    result.push_back(j);
                }
                i++; // Skip the next element as it's already added as the upper boundary
            }
        }
    }

    return result;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Please provide a sequence of integers.\n";
        return 1;
    }

    std::vector<int> sortedSequence;
    for (int i = 1; i < argc; ++i) {
        int number;
        std::istringstream(argv[i]) >> number;
        sortedSequence.push_back(number);
    }

    // Assuming the input sequence is already sorted.
    std::vector<int> result = fillGaps(sortedSequence);

    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}





