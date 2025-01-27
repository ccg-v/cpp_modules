#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe {
private:
    // Helper function to sort pairs and separate into sequences
    void sortPairs(std::vector<int>& seq, std::vector<int>& smaller) {
        std::cout << "sortPairs() - Input seq: ";
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        if (seq.size() <= 1)
            return;

        std::vector<int> newSeq;
        // Handle pairs
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
                smaller.push_back(seq[i + 1]);
                newSeq.push_back(seq[i]);
            } else {
                smaller.push_back(seq[i]);
                newSeq.push_back(seq[i + 1]);
            }
        }
        
        // Handle last element if size is odd
        if (seq.size() % 2 == 1)
            newSeq.push_back(seq[seq.size() - 1]);
        
        // Continue recursion with larger elements
        if (newSeq.size() > 2) {
            std::vector<int> nextSmaller;
            sortPairs(newSeq, nextSmaller);
            // Merge nextSmaller back into smaller in correct order
            smaller.insert(smaller.begin(), nextSmaller.begin(), nextSmaller.end());
        }
        
        std::cout << "sortPairs() - Output seq: ";
        for (int num : newSeq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
        std::cout << "sortPairs() - Output smaller: ";
        for (int num : smaller) {
            std::cout << num << " ";
        }
        std::cout << std::endl << std::endl;

        // Copy back to original sequence
        seq = newSeq;
    }

    // Binary search for insertion position
    size_t findInsertionPos(const std::vector<int>& seq, int value, size_t end) {
        size_t left = 0;
        size_t right = end;
        
        while (left < right) {
            size_t mid = (left + right) / 2;
            if (seq[mid] > value)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }

    // Insert element at the correct position
    void insertElement(std::vector<int>& seq, int value, size_t pos) {
        seq.insert(seq.begin() + pos, value);
    }

public:
    void fordJohnsonSort(std::vector<int>& seq) {
        std::cout << "fordJohnsonSort() - Input seq: ";
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << std::endl;

        if (seq.size() <= 1)
            return;

        // Handle size 2 specially
        if (seq.size() == 2) {
            if (seq[0] > seq[1])
                std::swap(seq[0], seq[1]);
            return;
        }

        // Step 1: Separate into sequences
        std::vector<int> smaller;
        sortPairs(seq, smaller);

        // Step 2: Create result vector with the main chain
        std::vector<int> result;
        result.push_back(seq[0]);  // First element of main chain

        // Step 3: Insert remaining elements from main chain
        for (size_t i = 1; i < seq.size(); ++i) {
            size_t pos = findInsertionPos(result, seq[i], result.size());
            insertElement(result, seq[i], pos);
        }

        // Step 4: Insert elements from smaller sequence
        for (size_t i = 0; i < smaller.size(); ++i) {
            size_t pos = findInsertionPos(result, smaller[i], result.size());
            insertElement(result, smaller[i], pos);
        }

        std::cout << "fordJohnsonSort() - Output seq: ";
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl << std::endl;

        // Copy result back to original sequence
        seq = result;
    }
};

int main() {
    std::vector<int> numbers;
    numbers.push_back(5);
    numbers.push_back(3);
    numbers.push_back(9);
    numbers.push_back(2);
    numbers.push_back(1);
    numbers.push_back(7);
    numbers.push_back(8);
    numbers.push_back(0);
    numbers.push_back(4);
    numbers.push_back(6);

    PmergeMe sorter;
    sorter.fordJohnsonSort(numbers);
    
    return 0;
}
