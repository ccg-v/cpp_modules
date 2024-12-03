#include <vector>
#include <iostream>

std::vector<int> generate_jacobsthal(int n) {
    std::vector<int> jacobsthal;
    if (n < 1) return jacobsthal;
    
    jacobsthal.push_back(1);
    if (n < 2) return jacobsthal;
    jacobsthal.push_back(3);
    
    while (jacobsthal.back() < n) {
        // Next Jacobsthal = 2 * previous - previous_before_that
        int next_num = 2 * jacobsthal.back() - jacobsthal[jacobsthal.size()-2];
        if (next_num > n) break;
        jacobsthal.push_back(next_num);
    }
    return jacobsthal;
}

std::vector<int> get_insertion_order(int n) {
    std::vector<int> result;
    if (n < 1) return result;
    
    // Get Jacobsthal numbers up to n
    std::vector<int> jacobsthal = generate_jacobsthal(n);
    
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
    
    // Add remaining numbers in reverse order
    for (int i = n; i > jacobsthal.back(); --i) {
        result.push_back(i);
    }
    
    return result;
}

template<typename T>
std::vector<T> insert_pends(const std::vector<T>& larger, const std::vector<T>& pends) {
    std::vector<T> result;
    if (pends.empty()) return larger;
    
    // Get insertion order for pends
    std::vector<int> insertion_order = get_insertion_order(pends.size());
    
    // Insert first pend (b1) at the beginning since we know b1 ≤ a1
    result.push_back(pends[0]);
    for (size_t i = 0; i < larger.size(); ++i) {
        result.push_back(larger[i]);
    }
    
    // Insert remaining pends according to Jacobsthal order
    for (size_t i = 1; i < insertion_order.size(); ++i) {  // Skip first since we already inserted it
        int idx = insertion_order[i] - 1;  // Convert to 0-based index
        if (idx < static_cast<int>(pends.size())) {
            // Binary search to find insertion position
            // TODO: Implement optimized binary search using bk ≤ ak relationship
            const T& element = pends[idx];
            typename std::vector<T>::iterator it;
            for (it = result.begin(); it != result.end(); ++it) {
                if (element <= *it) {
                    result.insert(it, element);
                    break;
                }
            }
            if (it == result.end()) {
                result.push_back(element);
            }
        }
    }
    
    return result;
}

// Example usage:

int main() {
    std::vector<int> larger;  // Main chain: a1, a2, a3, a4
    larger.push_back(10);
    larger.push_back(20);
    larger.push_back(30);
    larger.push_back(40);
    
    std::vector<int> pends;   // Pend elements: b1, b2, b3, b4
    pends.push_back(5);
    pends.push_back(15);
    pends.push_back(25);
    pends.push_back(35);
    
    std::vector<int> result = insert_pends(larger, pends);
    
    // Print result
    for (size_t i = 0; i < result.size(); ++i) {
        std::cout << result[i] << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
