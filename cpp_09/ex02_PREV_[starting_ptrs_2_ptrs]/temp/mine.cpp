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
	void sortPairs(std::vector<int>& seq) {
        if (seq.size() <= 1)
            return;	
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
				std::swap(seq[i], seq[i + 1]);
            } 
        }

std::cout << "After sortPairs(): ";
printContainer(seq);
	}

    void divideSequence(std::vector<int>& seq, std::vector<int>& smaller) {
        if (seq.size() <= 1)
            return;

        std::vector<int> larger;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
			smaller.push_back(seq[i]);
			larger.push_back(seq[i + 1]);
        } 
        if (seq.size() % 2 == 1) {
            larger.push_back(seq[seq.size() - 1]);
        }
        
        seq = larger; // Now `seq` holds only the larger elements

std::cout << "After divideSequence(): larger  = ";
printContainer(larger);
std::cout << "After divideSequence(): smaller = ";
printContainer(smaller);
    }

    size_t findInsertionPos(const std::vector<int>& seq, int value, size_t end) {
        size_t left = 0, right = end;
printContainer(seq);
        while (left < right) {
            size_t mid = (left + right) / 2;
std::cout << "left = " << left << "; right = " << right << "; mid = " << mid << std::endl;
std::cout << "value = " << value << "; seq[" << mid << "] = " << seq[mid] << std::endl;
            if (seq[mid] > value)
                right = mid;
            else
                left = mid + 1;
        }
std::cout << "LEFT IS " << left << std::endl;
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
        sortPairs(seq);
		divideSequence(seq, smaller);  // Splits into `seq` (larger elements) and `smaller`
        fordJohnsonSort(seq);  // Recursively sort `seq`

        // Insert the remaining elements from `smaller`
        for (size_t i = 0; i < smaller.size(); ++i) {
            size_t pos = findInsertionPos(seq, smaller[i], seq.size());
            insertElement(seq, smaller[i], pos);
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