void	PmergeMe::fillContainers(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		std::string input = argv[i];

		if (input.empty() || onlyWhitespace(input)) {
			throw std::runtime_error("Error: input is empty.");
		}

		std::istringstream argStream(input);
		std::string element;

		while (argStream >> element) {
			if (!isPositiveNumber(element)) {
				throw std::runtime_error("Error: sequence must be made up of positive integers.");
			}

			if (!isIntegerRange(element)) {
				throw std::runtime_error("Error: value out of integer's range found.");
			}

			int value = atoi(element.c_str());
			_vec.push_back(value);
			_deq.push_back(value);
		}
	}

	if (isSorted(_vec)) {
		throw std::runtime_error("Error: sequence is already sorted.");
	}
}

void	PmergeMe::sortPairs(std::vector<int> & seq) {
	if (seq.size() <= 1)
		return;
	for (size_t i = 0; i < seq.size() - 1; i += 2) {
		if (seq[i] > seq[i + 1]) {
			std::swap(seq[i], seq[i + 1]);
		}
	}
}

void	PmergeMe::divideSequence(std::vector<int> &seq, std::vector<int> &smaller) {
    if (seq.size() <= 1) 
        return;

    std::vector<int> larger;
    for (size_t i = 0; i < seq.size() - 1; i += 2) {
        smaller.push_back(seq[i]);
        larger.push_back(seq[i + 1]);
    }
    if (seq.size() % 2 == 1) {
        larger.push_back(seq.back());
    }

    seq = larger;

    // Debugging
    printContainer("Debug larger  = ", seq);
    printContainer("Debug smaller = ", smaller);
}


std::vector<int> PmergeMe::buildJacobsthalVec(size_t len)
{
    std::vector<int>    JacobsthalSeq;
    size_t                num;

    JacobsthalSeq.push_back(0);
    JacobsthalSeq.push_back(1);
    for (size_t i = 2; i < len; i++) {
        num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
        JacobsthalSeq.push_back(num);
    }
    // Remove the first two elements if the sequence has at least two elements
    if (JacobsthalSeq.size() > 2) {
        JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
    }
    return JacobsthalSeq;
}

size_t PmergeMe::binarySearch(const std::vector<int> & seq, int value, size_t end) {
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

std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int>& jacobsthalSeq, size_t smallerSize) {
    std::vector<int> result;
    std::vector<bool> inserted(smallerSize, false); // Track inserted indices

std::cout << "SMALLERSIZE = " << smallerSize << std::endl;

    // Always add index 0 first
    if (smallerSize > 0) {
        result.push_back(0);
        inserted[0] = true;
    }

    size_t current = 1; // Start interleaving from index 1

    // Process each Jacobsthal boundary
    for (size_t i = 0; i < jacobsthalSeq.size(); ++i) {
        int boundary = jacobsthalSeq[i];

        if (boundary >= static_cast<int>(smallerSize)) {
            break; // Ignore out-of-bounds Jacobsthal indices
        }

        // Add the current boundary
        if (!inserted[boundary]) {
            result.push_back(boundary);
            inserted[boundary] = true;
        }

        // Insert interleaved indices between `current` and `boundary` in descending order
        for (size_t j = boundary; j >= static_cast<size_t>(current); --j) {
            if (!inserted[j]) {		
                result.push_back(j);
                inserted[j] = true;
            }
        }

        current = boundary + 1; // Move to the next range
    }

    for (size_t i = smallerSize; i > current; --i) {
        if (!inserted[i]) {
            result.push_back(i);
        }
    }

    return result;
}

void PmergeMe::fordJohnsonSort(std::vector<int> &seq) {
    if (seq.size() <= 1)
        return;
    if (seq.size() == 2) {
        if (seq[0] > seq[1])
            std::swap(seq[0], seq[1]);
        return;
    }

    // Step 1: Pair and sort
    std::vector<int> smaller;
    sortPairs(seq);
    divideSequence(seq, smaller);
    fordJohnsonSort(seq);

    // Step 2: Generate insertion order using Jacobsthal sequence
    std::vector<int> jacobsthalSeq = buildJacobsthalVec(smaller.size());
    std::vector<int> insertionIndexes = getInsertionOrder(jacobsthalSeq, smaller.size());

    // Step 3: Insert smaller elements into seq based on insertionIndexes
    std::vector<bool> inserted(smaller.size(), false); // Track inserted elements
    for (size_t i = 0; i < insertionIndexes.size(); ++i) {
        size_t insertIndex = insertionIndexes[i];
        if (insertIndex < smaller.size() && !inserted[insertIndex]) {
            int valueToInsert = smaller[insertIndex];
            size_t position = binarySearch(seq, valueToInsert, seq.size());
            seq.insert((seq.begin() + position), valueToInsert);
            inserted[insertIndex] = true;
        }
    }

    // Step 4: Insert any remaining elements from smaller
    for (size_t i = 0; i < smaller.size(); ++i) {
        if (!inserted[i]) {
            int valueToInsert = smaller[i];
            size_t position = binarySearch(seq, valueToInsert, seq.size());
            seq.insert((seq.begin() + position), valueToInsert);
        }
    }
}

int main(int argc, char* argv[]) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;
			
			pmergeme.fillContainers(argc, argv);
			
			printContainer("Before:  ", pmergeme.getVector());
			pmergeme.fordJohnsonSort(pmergeme.getVector());
			printContainer("After :  ", pmergeme.getVector());

		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

    return 0;
}
