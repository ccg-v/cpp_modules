#include <vector>
#include <algorithm>
#include <iostream>

void printContainer(std::vector<int> container) {
	if (container.size() > 0) {
		std::cout << "{ ";
		for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "}" << std::endl;
	}
}

class PmergeMe {
private:
    void sortPairs(std::vector<int>& seq, std::vector<int>& smaller) {
        if (seq.size() <= 1)
            return;

        std::vector<int> larger;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
                larger.push_back(seq[i]);
                smaller.push_back(seq[i + 1]);
            } else {
                larger.push_back(seq[i + 1]);
                smaller.push_back(seq[i]);
            }
        }
        if (seq.size() % 2 == 1) {
            larger.push_back(seq[seq.size() - 1]);
        }
        
        seq = larger; // Now `seq` holds only the larger elements
    }

    size_t findInsertionPos(const std::vector<int>& seq, int value, size_t end) {
        size_t left = 0, right = end;
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

public:
    void fordJohnsonSort(std::vector<int>& seq) {
        if (seq.size() <= 1) return;
        if (seq.size() == 2) {
            if (seq[0] > seq[1])
                std::swap(seq[0], seq[1]);
            return;
        }

        std::vector<int> smaller;
        sortPairs(seq, smaller);  // Splits into `seq` (larger elements) and `smaller`
        fordJohnsonSort(seq);  // Recursively sort `seq`

std::cout << "seq: ";
printContainer(seq);
std::cout << "smaller: ";
printContainer(smaller);

        // Insert the remaining elements from `smaller`
        for (size_t i = 0; i < smaller.size(); ++i) {
            size_t pos = findInsertionPos(seq, smaller[i], seq.size());
            insertElement(seq, smaller[i], pos);

std::cout << "\tInserting " << smaller[i] << std::endl;
std::cout << "\tseq: ";
printContainer(seq);

        }
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
    printContainer(numbers);
    return 0;
}