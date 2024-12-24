#include <iostream>
#include <vector>

void fill_gaps(std::vector<int>& sequence) {
    std::vector<int> result;
    result.push_back(sequence[0]);  // Add first number

    // Process each adjacent pair of numbers
    for (size_t i = 1; i < sequence.size(); i++) {
        result.push_back(sequence[i]);  // Add current number
        
        // Fill gaps between previous and current number
        int prev = sequence[i-1];
        int curr = sequence[i];
        
        if (curr - prev > 1) {
            // Fill gap in descending order
            for (int j = curr - 1; j > prev; j--) {
                result.push_back(j);
            }
        }
    }

    sequence = result;  // Update original sequence
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <sequence of integers>" << std::endl;
        return 1;
    }

    // Parse command line arguments into vector
    std::vector<int> sequence;
    for (int i = 1; i < argc; i++) {
        sequence.push_back(std::stoi(argv[i]));
    }

    // Process sequence
    fill_gaps(sequence);

    // Print result
    for (int num : sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
