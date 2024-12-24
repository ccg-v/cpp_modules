#include <vector>
#include <iostream>
#include <cmath>

class FordJohnsonDemo {
private:
    // Helper function to check if a number is power of 2
    static bool isPowerOfTwo(int n) {
        return (n != 0) && ((n & (n - 1)) == 0);
    }

    // Get next power of 2 for a given number
    static int nextPowerOfTwo(int n) {
        int power = 1;
        while (power <= n) {
            power *= 2;
        }
        return power;
    }

    // Calculate nth Jacobsthal number
    static int jacobsthal(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;
        
        int prev2 = 0;
        int prev1 = 1;
        int result = 0;
        
        for (int i = 2; i <= n; ++i) {
            result = prev1 + 2 * prev2;
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }

public:
    static void getInsertionGroups(int n, std::vector<std::vector<int> >& groups, 
                                 std::vector<int>& insertionOrder) {
        std::vector<int> remaining;
        // Start from 3 as x[1] and x[2] are already handled
        for (int i = 3; i <= n; ++i) {
            remaining.push_back(i);
        }

        int currentSize = 2;  // First group size is 2
        
        while (!remaining.empty()) {
            std::vector<int> group;
            
            // Take elements for current group
            for (int i = 0; i < currentSize && !remaining.empty(); ++i) {
                group.push_back(remaining[0]);
                remaining.erase(remaining.begin());
            }
            
            if (!group.empty()) {
                groups.push_back(group);
                
                // Calculate next group size
                if (groups.size() > 1) {
                    int prevSum = groups[groups.size()-2].size() + 
                                groups[groups.size()-1].size();
                    int nextPower = nextPowerOfTwo(prevSum);
                    currentSize = nextPower - prevSum;
                } else {
                    currentSize = 2;  // Second group size is also 2
                }
            }
        }

        // Generate insertion order by reversing elements within each group
        for (size_t i = 0; i < groups.size(); ++i) {
            for (int j = groups[i].size() - 1; j >= 0; --j) {
                insertionOrder.push_back(groups[i][j]);
            }
        }
    }

    static void demonstrate(int n) {
        std::vector<std::vector<int> > groups;
        std::vector<int> insertionOrder;
        
        getInsertionGroups(n, groups, insertionOrder);

        // Print groups
        std::cout << "Groups of indexes:\n";
        for (size_t i = 0; i < groups.size(); ++i) {
            std::cout << "Group " << (i + 1) << ": ";
            for (size_t j = 0; j < groups[i].size(); ++j) {
                std::cout << groups[i][j] << " ";
            }
            std::cout << "(size: " << groups[i].size() << ")\n";
        }

        // Print insertion order
        std::cout << "\nInsertion order: ";
        for (size_t i = 0; i < insertionOrder.size(); ++i) {
            std::cout << "y[" << insertionOrder[i] << "] ";
        }
        std::cout << "\n";

        // Print first few Jacobsthal numbers
        std::cout << "\nFirst few Jacobsthal numbers: ";
        for (int i = 0; i < 10; ++i) {
            std::cout << jacobsthal(i) << " ";
        }
        std::cout << "\n";

        // Demonstrate binary search optimization
        std::cout << "\nBinary search lengths before each insertion:\n";
        for (size_t i = 0; i < insertionOrder.size(); ++i) {
            int searchLength = insertionOrder[i] - 1;
            std::cout << "y[" << insertionOrder[i] << "] searches in length " 
                     << searchLength << " ";
            if (isPowerOfTwo(searchLength + 1)) {
                std::cout << "(optimal: length + 1 is power of 2)";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    FordJohnsonDemo::demonstrate(12);
    return 0;
}
