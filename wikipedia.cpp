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

	void	sortPairs(std::vector<int>& seq) {
        if (seq.size() <= 1)
            return;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
            if (seq[i] > seq[i + 1]) {
				std::swap(seq[i], seq[i + 1]);
            }
        }
	}

    void divideSequence(std::vector<int>& seq, std::vector<int>& smaller) {
        if (seq.size() <= 1)
            return;

        std::vector<int> larger;
        for (size_t i = 0; i < seq.size() - 1; i += 2) {
		// for (size_t i = 0; i + 1 < seq.size(); i += 2) {
                smaller.push_back(seq[i]);
                larger.push_back(seq[i + 1]);
        }
        if (seq.size() % 2 == 1) {
            larger.push_back(seq[seq.size() - 1]);
			// larger.push_back(seq.back());
        }
        
        seq = larger; // Now `seq` holds only the larger elements

std::cout << "larger  = ";
printContainer(seq);
std::cout << "smaller = ";
printContainer(smaller);
std::cout << "--------------------------" << std::endl;

    }

	std::vector<int> generateJacobsthalSeq(size_t len)
	{
		std::vector<int>	JacobsthalSeq;
		size_t				num;

		JacobsthalSeq.push_back(0);
		JacobsthalSeq.push_back(1);
		for (size_t i = 2; i < len; i++) {
			num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
			JacobsthalSeq.push_back(num);
		}
		return JacobsthalSeq;
	}

	std::vector<int> get_insertion_order(int n) {
		std::vector<int> result;
		if (n < 1) return result;
		
		// Get Jacobsthal numbers up to n
		std::vector<int> jacobsthal = generateJacobsthalSeq(n);
		
		// Initialize result with first Jacobsthal number (always 1)
		result.push_back(1);
		
		// For each pair of consecutive Jacobsthal numbers
		for (size_t i = 0; i < jacobsthal.size() - 1; ++i) {
			int current = jacobsthal[i];
			int next_j = jacobsthal[i + 1];
			
			// Add numbers between Jacobsthal numbers in reverse order
			for (int j = next_j - 1; j > current; --j) {
				if (j <= n) {
					result.push_back(j);
				}
			}
		}
		for (int i = n; i > jacobsthal.back(); --i) {
			result.push_back(i);
		}
		return result;
	}

    size_t binarySearch(const std::vector<int>& seq, int value, size_t end) {
        size_t 	left = 0;
		size_t	right = end;
		size_t	comparisons;
        while (left < right) {
            size_t mid = (left + right) / 2;
            if (seq[mid] > value)
                right = mid;
            else
                left = mid + 1;
			comparisons++;
        }
		std::cout << "Comparisons = " << comparisons << std::endl;
        return left;
    }

    // void insertElement(std::vector<int>& seq, int value, size_t pos) {
    //     seq.insert(seq.begin() + pos, value);
    // }

std::vector<int> insert_pends(const std::vector<int>& larger, const std::vector<int>& pends) {
    std::vector<int> result(larger.begin(), larger.end());
    if (pends.empty()) return result;

    // Get insertion order for pends
    std::vector<int> insertion_order = get_insertion_order(pends.size());

    // Insert the first pend (b1) at the beginning since we know b1 ≤ a1
    result.insert(result.begin(), pends[0]);
    std::cout << "Initial insertion of first pend: ";
    printContainer(result);

    // Insert remaining pends according to Jacobsthal order
    for (size_t i = 1; i < insertion_order.size(); ++i) {
        int idx = insertion_order[i] - 1;  // Convert to 0-based index
        if (idx < static_cast<int>(pends.size())) {
            int element = pends[idx];
            
            // Binary search in the sorted portion of result (up to current size)
            size_t left = 0;
            size_t right = result.size();
            while (left < right) {
                size_t mid = left + (right - left) / 2;
                if (result[mid] > element) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            
            // Insert `element` at the calculated position
            result.insert(result.begin() + left, element);

            // Debugging output to trace insertions
            std::cout << "Inserted " << element << " at position " << left << ": ";
            printContainer(result);
        }
    }
    return result;
}


	// std::vector<int> insert_pends(const std::vector<int>& larger, const std::vector<int>& pends) {
	// 	std::vector<int> result;
	// 	if (pends.empty()) return larger;

	// 	// Get insertion order for pends
	// 	std::vector<int> insertion_order = get_insertion_order(pends.size());

	// 	// Insert first pend (b1) at the beginning since we know b1 ≤ a1
	// 	result.push_back(pends[0]);
	// 	for (size_t i = 0; i < larger.size(); ++i) {
	// 		result.push_back(larger[i]);
	// 	}

	// 	// Insert remaining pends according to Jacobsthal order
	// 	for (size_t i = 1; i < insertion_order.size(); ++i) {
	// 		int idx = insertion_order[i] - 1;  // Convert to 0-based index
	// 		if (idx < static_cast<int>(pends.size())) {
	// 			const int element = pends[idx];
				
	// 			// Find the corresponding paired element position in the main chain
	// 			// idx + 1 because we need to account for the first pend already inserted
	// 			size_t paired_pos = idx + 1;
				
	// 			// Binary search in the optimized range
	// 			// Start: beginning of result
	// 			// End: position of paired element ak (paired_pos)
	// 			size_t left = 0;
	// 			size_t right = paired_pos;
				
	// 			while (left < right) {
	// 				size_t mid = left + (right - left) / 2;
	// 				if (result[mid] >= element) {
	// 					right = mid;
	// 				} else {
	// 					left = mid + 1;
	// 				}
	// 			}
				
	// 			// Insert at the found position
	// 			result.insert(result.begin() + left, element);
	// 		}
	// 	}
	// 	return result;
	// }


public:
    void fordJohnsonSort(std::vector<int> & seq) {
        if (seq.size() <= 1) return;
        if (seq.size() == 2) {
            if (seq[0] > seq[1])
                std::swap(seq[0], seq[1]);
            return;
        }

// generateJacobsthalSeq(10);

        std::vector<int> smaller;
        sortPairs(seq);
		divideSequence(seq, smaller);  // Splits into 'seq' (larger elements) and 'smaller'
        fordJohnsonSort(seq);  // Recursively sort 'seq'

// std::cout << "larger  = ";
// printContainer(seq);
// std::cout << "smaller = ";
// printContainer(smaller);
// std::cout << "-#######################" << std::endl;

//         // Insert the remaining elements from `smaller`
//         for (size_t i = 0; i < smaller.size(); ++i) {
//             size_t pos = binarySearch(seq, smaller[i], seq.size());
// std::cout << "Inserting " << smaller[i] << " in position " << pos << std::endl;
//             insertElement(seq, smaller[i], pos);
//         }

		seq = insert_pends(seq, smaller);
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
    numbers.push_back(10);
    numbers.push_back(4);
    numbers.push_back(6);

    PmergeMe sorter;
    sorter.fordJohnsonSort(numbers);
    printContainer(numbers);

    return 0;
}