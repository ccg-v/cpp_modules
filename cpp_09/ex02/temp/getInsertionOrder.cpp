// #include <vector>
// #include <algorithm>
// #include <iostream>

// void printContainer(std::vector<int> container) {
// 	if (container.size() > 0) {
// 		std::cout << "{ ";
// 		for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
// 			std::cout << *it << " ";
// 		}
// 		std::cout << "}" << std::endl;
// 	}
// }

// std::vector<int> buildJacobsthalVec(size_t len)
// {
// 	std::vector<int>	JacobsthalSeq;
// 	size_t				num;

// 	JacobsthalSeq.push_back(0);
// 	JacobsthalSeq.push_back(1);
// 	for (size_t i = 2; i < len; i++) {
// 		num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
// 		JacobsthalSeq.push_back(num);
// 	}
// 	// // Remove the first two elements if the sequence has at least two elements
// 	// if (JacobsthalSeq.size() > 2) {
// 	// 	JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
// 	// }
// 	// Remove the first two elements if the sequence has at least two elements
// 	if (JacobsthalSeq.size() > 2) {
// 		JacobsthalSeq.erase(JacobsthalSeq.begin() + 1);
// 	}
// 	return JacobsthalSeq;
// }


// std::vector<int> getInsertionIndexes(const std::vector<int> & jacobsthalSeq, size_t smallerSize) {

// 	std::vector<int> insertionIndexes;
// 	int	j = 0;

// 	printContainer(jacobsthalSeq);
// 	// std::cout << "smallerSize = " << smallerSize << std::endl;
// 	for (int i = 0; jacobsthalSeq[i] < smallerSize; i++) {

// 		// std::cout << "jacobsthalSeq[" << i << "] = " << jacobsthalSeq[i] << std::endl;
		
// 		insertionIndexes.push_back(jacobsthalSeq[j]);

// 		// std::cout << "j = " << j << " | jacobsthal[j - 1] = " << jacobsthalSeq[j - 1] << " | jacobsthalSeq[j] = " << jacobsthalSeq[j] << std::endl;
		
// 		if (j > 0 && (jacobsthalSeq[j] - jacobsthalSeq[j - 1]) > 1) {
// 			int gap = jacobsthalSeq[j] - jacobsthalSeq[j - 1] - 1;
// 			// std::cout << "\tgap = " << gap << " | jacobsthalSeq[" << gap << "] = " << jacobsthalSeq[gap] << std::endl;
// 			int k = jacobsthalSeq[j] - 1;
// 			while (gap > 0) {
// 				// std::cout << "\t\tk = " << k << " | inserting " << k << std::endl;
// 				insertionIndexes.push_back(k);
// 				gap--;
// 				k--;
// 			}
// 		}
// 		j++;
// 	}
// 	return insertionIndexes;
// }

// int main(int argc, char **argv) {

// 	if (argc == 2 ){
// 		std::vector<int> jacobsthalSeq = buildJacobsthalVec(atoi(argv[1]));
// 		std::vector<int> insertionIndexes = getInsertionIndexes(jacobsthalSeq, atoi(argv[1]));
// 		printContainer(insertionIndexes);
// 	} else {
// 		std::cerr << "Wrong args!" << std::endl;
// 	}
// 	return 0;
// }

#include <iostream>
#include <vector>

void printContainer(std::vector<int> container) {
    if (container.size() > 0) {
        std::cout << "{ ";
        for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "}" << std::endl;
    }
}

std::vector<int> buildJacobsthalVec(size_t len) {
    std::vector<int> JacobsthalSeq;
    size_t num;
    
    JacobsthalSeq.push_back(0);
    JacobsthalSeq.push_back(1);
    
    for (size_t i = 2; i < len; i++) {
        num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
        JacobsthalSeq.push_back(num);
    }
    
    // Remove only the first element (0) if the sequence has at least two elements
    if (JacobsthalSeq.size() > 2) {
        JacobsthalSeq.erase(JacobsthalSeq.begin());
    }
    
    return JacobsthalSeq;
}

std::vector<int> getInsertionIndexes(const std::vector<int>& jacobsthalSeq, size_t smallerSize) {
    std::vector<int> insertionIndexes;
    size_t j = 0;
    
    // Only proceed if we have elements in the sequence
    while (j < jacobsthalSeq.size() && jacobsthalSeq[j] < smallerSize) {
        insertionIndexes.push_back(jacobsthalSeq[j]);
        
        if (j > 0 && (jacobsthalSeq[j] - jacobsthalSeq[j - 1]) > 1) {
            int k = jacobsthalSeq[j] - 1;
            while (k > jacobsthalSeq[j - 1]) {
                insertionIndexes.push_back(k);
                k--;
            }
        }
        j++;
    }
    
    // Add any remaining numbers less than smallerSize that haven't been added yet
    int lastNum = (insertionIndexes.empty() ? 0 : insertionIndexes.back());
    for (int i = lastNum + 1; i < smallerSize; i++) {
        insertionIndexes.push_back(i);
    }
    
    return insertionIndexes;
}

int main(int argc, char **argv) {
    if (argc == 2) {
        int size = atoi(argv[1]);
        std::vector<int> jacobsthalSeq = buildJacobsthalVec(size);
        std::cout << "Jacobsthal sequence: ";
        printContainer(jacobsthalSeq);
        
        std::vector<int> insertionIndexes = getInsertionIndexes(jacobsthalSeq, size);
        std::cout << "Insertion indexes: ";
        printContainer(insertionIndexes);
    } else {
        std::cerr << "Wrong args!" << std::endl;
    }
    return 0;
}