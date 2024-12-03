#include <iostream>
#include <vector>
#include <algorithm>

class PmergeMe {
private:
    // Helper function to sort pairs and separate into sequences
    void sortPairs(std::vector<int>& seq, std::vector<int>& smaller, std::vector<int>& mainChain, int depth = 0) {
        std::string indent(depth * 2, ' ');

        std::cout << indent << "Level " << depth << " - Processing sequence: ";
        for (size_t i = 0; i < seq.size(); ++i)
            std::cout << seq[i] << " ";
        std::cout << "\n";

        if (seq.size() <= 1)
            return;

        std::vector<int> newSeq;
        // Print pairs as they're being formed
        std::cout << indent << "Pairs formed: ";
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            std::cout << "(" << seq[i] << "," << seq[i + 1] << ") ";
            if (seq[i] > seq[i + 1]) {
                smaller.push_back(seq[i + 1]);
                newSeq.push_back(seq[i]);
            } else {
                smaller.push_back(seq[i]);
                newSeq.push_back(seq[i + 1]);
            }
        }
        if (seq.size() % 2 == 1) {
            newSeq.push_back(seq[seq.size() - 1]);
            std::cout << "(" << seq[seq.size() - 1] << ")";
        }
        std::cout << "\n";

        if (newSeq.size() > 2) {
            std::vector<int> nextSmaller;
            sortPairs(newSeq, nextSmaller, mainChain, depth + 1);
            smaller.insert(smaller.begin(), nextSmaller.begin(), nextSmaller.end());
        } else {
            // Update the main chain
            mainChain.insert(mainChain.end(), newSeq.begin(), newSeq.end());
        }

        std::cout << indent << "Level " << depth << " - Resulting sequence: ";
        for (size_t i = 0; i < newSeq.size(); ++i)
            std::cout << newSeq[i] << " ";
        std::cout << "\n";
        std::cout << indent << "Level " << depth << " - Smaller elements: ";
        for (size_t i = 0; i < smaller.size(); ++i)
            std::cout << smaller[i] << " ";
        std::cout << "\n";
        std::cout << indent << "Level " << depth << " - Main chain: ";
        for (size_t i = 0; i < mainChain.size(); ++i)
            std::cout << mainChain[i] << " ";
        std::cout << "\n\n";

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
        std::cout << "fordJohnsonSort() - Input sequence: ";
        for (int num : seq) {
            std::cout << num << " ";
        }
        std::cout << "\n";

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
        std::vector<int> mainChain;
        sortPairs(seq, smaller, mainChain);

        // Step 2: Insert remaining elements from main chain
        for (size_t i = 0; i < mainChain.size(); ++i) {
            size_t pos = findInsertionPos(smaller, mainChain[i], smaller.size());
            insertElement(smaller, mainChain[i], pos);
        }

        std::cout << "fordJohnsonSort() - Output sequence: ";
        for (int num : smaller) {
            std::cout << num << " ";
        }
        std::cout << "\n";
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
