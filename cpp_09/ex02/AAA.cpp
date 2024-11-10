#include <vector>
#include <algorithm>
#include <iostream>

void printContainer(const std::vector<int>& container) {
    if (!container.empty()) {
        std::cout << "{ ";
        for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "}" << std::endl;
    }
}

class PmergeMe {
private:

    void sortPairs(std::vector<int>& seq) {
        if (seq.size() <= 1) return;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
                std::swap(seq[i], seq[i + 1]);
            }
        }
    }

    void divideSequence(std::vector<int>& seq, std::vector<int>& smaller) {
        if (seq.size() <= 1) return;

        std::vector<int> larger;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            smaller.push_back(seq[i]);
            larger.push_back(seq[i + 1]);
        }
        if (seq.size() % 2 == 1) {
            larger.push_back(seq.back());
        }

        seq = larger;

        std::cout << "larger  = ";
        printContainer(seq);
        std::cout << "smaller = ";
        printContainer(smaller);
        std::cout << "--------------------------" << std::endl;
    }

    std::vector<int> generateJacobsthalSeq(size_t len) {
        std::vector<int> JacobsthalSeq = {0, 1};
        while (JacobsthalSeq.back() < len) {
            size_t next = JacobsthalSeq.back() + 2 * JacobsthalSeq[JacobsthalSeq.size() - 2];
            if (next >= len) break;
            JacobsthalSeq.push_back(next);
        }
        return JacobsthalSeq;
    }

    size_t binarySearch(const std::vector<int>& seq, int value, size_t end) {
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

    void insertElement(std::vector<int>& seq, int value, size_t pos) {
        seq.insert(seq.begin() + pos, value);
    }


	std::vector<int> getInsertionOrder(const std::vector<int>& jacobsthalSeq, size_t size) {
		std::vector<int> insertionOrder;

		// Add all Jacobsthal-indexed elements and interleave non-Jacobsthal elements in reverse order
		for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
			size_t currentJacobIndex = jacobsthalSeq[i];

			// Stop if the current Jacobsthal index exceeds the given size
			if (currentJacobIndex >= size) break;

			// Add current Jacobsthal-indexed element
			insertionOrder.push_back(currentJacobIndex);

			// If there's a previous Jacobsthal index, add interleaved indices in reverse order
			if (i > 0) {
				size_t prevJacobIndex = jacobsthalSeq[i - 1];
				for (size_t j = currentJacobIndex - 1; j > prevJacobIndex; --j) {
					if (j < size) {
						insertionOrder.push_back(j);
					}
				}
			}
		}

		// For any remaining values past the last Jacobsthal index, add them in reverse order
		size_t lastJacobIndex = jacobsthalSeq.back();
		for (size_t k = size - 1; k > lastJacobIndex; --k) {
			insertionOrder.push_back(k);
		}

		return insertionOrder;
	}


public:
	void fordJohnsonSort(std::vector<int>& seq) {
		if (seq.size() <= 1) return;
		if (seq.size() == 2) {
			if (seq[0] > seq[1]) std::swap(seq[0], seq[1]);
			return;
		}

		std::vector<int> smaller;
		sortPairs(seq);
		divideSequence(seq, smaller);  
		fordJohnsonSort(seq);

		std::vector<int> jacobsthalOrder = generateJacobsthalSeq(40);
		std::cout << "\tJacobsthal sequence for insertion order: ";
		printContainer(jacobsthalOrder);

		std::vector<int> insertionOrder = getInsertionOrder(jacobsthalOrder, smaller.size());
		std::cout << "Insertion order: ";
		printContainer(insertionOrder);

		std::vector<bool> inserted(smaller.size(), false);
		
		// Track the previous Jacobsthal index to manage interleaved insertion
		for (size_t jIndex = 0; jIndex < jacobsthalOrder.size(); ++jIndex) {
			size_t jacobIndex = jacobsthalOrder[jIndex];

			// Insert the current Jacobsthal-indexed value if it's within bounds
			if (jacobIndex < smaller.size() && !inserted[jacobIndex]) {
				int value = smaller[jacobIndex];
				size_t pos = binarySearch(seq, value, seq.size());
				std::cout << "Inserting Jacobsthal-indexed smaller[" << jacobIndex << "] = " << value << " at position " << pos << std::endl;
				insertElement(seq, value, pos);
				inserted[jacobIndex] = true;
			}

			// Check if it's time to insert interleaved values between the last two Jacobsthal elements
			if (jIndex > 0) {
				size_t prevJacobIndex = jacobsthalOrder[jIndex - 1];
				for (size_t k = prevJacobIndex + 1; k < jacobIndex && k < smaller.size(); ++k) {
					if (!inserted[k]) {
						int interleavedValue = smaller[k];
						size_t pos = binarySearch(seq, interleavedValue, seq.size());
						std::cout << "Inserting interleaved smaller[" << k << "] = " << interleavedValue << " at position " << pos << std::endl;
						insertElement(seq, interleavedValue, pos);
						inserted[k] = true;
					}
				}
			}
		}

		// Insert any remaining unprocessed elements in reverse order if not yet inserted
		for (int k = smaller.size() - 1; k >= 0; --k) {
			if (!inserted[k]) {
				int remainingValue = smaller[k];
				size_t pos = binarySearch(seq, remainingValue, seq.size());
				std::cout << "Inserting remaining smaller[" << k << "] = " << remainingValue << " at position " << pos << std::endl;
				insertElement(seq, remainingValue, pos);
			}
		}
	}
};

int main() {
    std::vector<int> numbers = { 5, 3, 9, 2, 1, 7, 8, 10, 4, 6, 11, 12, 15, 19, 17, 13, 18, 20, 14, 16, 25, 29, 23, 21, 22, 28, 30, 24, 26, 27};
    PmergeMe sorter;
    sorter.fordJohnsonSort(numbers);
    printContainer(numbers);
    return 0;
}
