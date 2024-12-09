#include <vector>
#include <algorithm>
#include <iostream>

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
// 	// Remove the first two elements if the sequence has at least two elements
// 	if (JacobsthalSeq.size() > 2) {
// 		JacobsthalSeq.erase(JacobsthalSeq.begin(), JacobsthalSeq.begin() + 2);
// 	}
// 	return JacobsthalSeq;
// }

// void fillVectorWithJacobsthalAndGaps(std::vector<int>& result, 
//                                     const std::vector<int>& jacobsthal, 
//                                     size_t targetSize) {
//     if (targetSize == 0 || jacobsthal.empty()) return;
    
//     result.clear();
//     result.reserve(targetSize);
    
//     // Add first number
//     result.push_back(jacobsthal[0]);  // Should be 0
//     if (result.size() >= targetSize) return;

//     // Add second number (1)
//     size_t jacobIndex = 1;
//     while (jacobIndex < jacobsthal.size() && 
//            jacobsthal[jacobIndex] == jacobsthal[jacobIndex - 1]) {
//         jacobIndex++;
//     }
//     if (jacobIndex < jacobsthal.size() && result.size() < targetSize) {
//         result.push_back(jacobsthal[jacobIndex++]);
//     }

//     // For each subsequent Jacobsthal number
//     while (result.size() < targetSize && jacobIndex < jacobsthal.size()) {
//         // Skip duplicates
//         while (jacobIndex < jacobsthal.size() && 
//                jacobsthal[jacobIndex] == jacobsthal[jacobIndex - 1]) {
//             jacobIndex++;
//         }
//         if (jacobIndex >= jacobsthal.size()) break;

//         int nextJacob = jacobsthal[jacobIndex];
//         int lastValue = result.back();
//         int prevValue = result[result.size() - 2];  // Value before lastValue

//         // If we're still filling gaps between previous numbers
//         if (lastValue > nextJacob && lastValue > prevValue) {
//             // Continue filling the gap in descending order
//             result.push_back(lastValue - 1);
//         }
//         // If we've filled all gaps, add the next Jacobsthal number
//         else {
//             result.push_back(nextJacob);
//             jacobIndex++;
//         }
//     }
// }

// // Helper function to test the results
// void printVector(const std::vector<int>& vec) {
//     for (size_t i = 0; i < vec.size(); ++i) {
//         std::cout << vec[i];
//         if (i < vec.size() - 1) std::cout << ", ";
//     }
//     std::cout << std::endl;
// }

// int main(int argc, char **argv) {

// 	if (argc == 2 ){
// 		std::vector<int> result;
// 		std::vector<int> jacobsthalSeq = buildJacobsthalVec(atoi(argv[1]));
// 		// printVector(jacobsthalSeq);
// 		fillVectorWithJacobsthalAndGaps(result, jacobsthalSeq, atoi(argv[1]));
// 		printVector(result);
// 	} else {
// 		std::cerr << "Wrong args!" << std::endl;
// 	}
// 	return 0;
// }

void generateJacobsthalSequence(std::vector<int>& vec, size_t size) {
    // Generate first numbers
    vec.push_back(0);
    if (size > 1) vec.push_back(1);
    if (size > 2) vec.push_back(1);
    
    // Generate rest of the sequence
    size_t i = 2;
    while (vec.size() < size) {
        vec.push_back(vec[i] + 2 * vec[i-1]);
        i++;
    }
}

void fillVectorWithJacobsthalAndGaps(std::vector<int>& result, size_t size) {
    if (size == 0) return;
    
    // First get the Jacobsthal sequence
    std::vector<int> jacob;
    generateJacobsthalSequence(jacob, size);
    
    result.clear();
    result.reserve(size);
    
    // Add first two numbers
    result.push_back(jacob[0]);  // 0
    if (size == 1) return;
    result.push_back(jacob[1]);  // 1
    if (size == 2) return;
    
    // Skip the duplicate 1 in Jacobsthal sequence
    size_t jacobIndex = 3;  // Start with 3
    
    while (result.size() < size) {
        // Get current and previous meaningful values
        int prevJacob = result[result.size() - 2];  // Previous Jacobsthal
        int lastValue = result.back();              // Last value added
        int nextJacob = jacob[jacobIndex];          // Next Jacobsthal
        
        // If we need to fill more gaps between previous numbers
        if (lastValue > nextJacob && lastValue > prevJacob) {
            result.push_back(lastValue - 1);
        }
        // If gaps are filled, add next Jacobsthal number
        else {
            result.push_back(nextJacob);
            jacobIndex++;
        }
    }
}

void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i < vec.size() - 1) std::cout << ", ";
    }
    std::cout << std::endl;
}


int main() {
    std::vector<int> result;
    
    // Test different sizes
    for (size_t size = 1; size <= 15; ++size) {
        fillVectorWithJacobsthalAndGaps(result, size);
        printVector(result);
    }
    
    return 0;
}