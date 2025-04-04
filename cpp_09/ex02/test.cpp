#include <iostream>
#include <vector>
#include <algorithm> // For std::sort and std::lower_bound
#include <utility>   // For std::pair
#include <deque>

void printContainer(std::string msg, int groupSize, std::deque<int> sequence) {
    std::cout << msg << ": " << groupSize << std::endl;

    size_t fullGroups = sequence.size() / groupSize; // Number of full groups
    size_t remainder = sequence.size() % groupSize; // Remaining elements

    size_t index = 0;
    for (size_t group = 0; group < fullGroups; ++group) {
        std::cout << "[ ";
        for (size_t i = 0; i < groupSize; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
        std::cout << "] ";
    }

    // Print remaining elements (not part of a full group)
    if (remainder > 0) {
        for (size_t i = 0; i < remainder; ++i, ++index) {
            std::cout << sequence[index] << " ";
        }
    }
    std::cout << std::endl;
}


static void	sortPairs( std::deque<int> & src, size_t groupSize ) {
	size_t	tail = groupSize - 1;
//	size_t	count = 0;
	while ( tail + groupSize < src.size() ) {
		std::deque< int >::iterator	first = src.begin();
		std::advance( first, tail );
		std::deque< int >::iterator	second = src.begin();
		std::advance( second, tail + groupSize );
//		count++;
		if ( *first > *second ) {
			std::deque< int >::iterator	trueFirst = src.begin();
			std::advance( trueFirst, tail - groupSize + 1 );
			std::deque< int >::iterator	trueSecond = src.begin();
			std::advance( trueSecond, tail + 1 );
			std::advance( first, 1 );
			std::swap_ranges( trueFirst, first, trueSecond ); 
		}
		tail += groupSize * 2;
	}
//	std::cout << "COUNT IN PAIRS: " << count << std::endl;
}

int main() {
    std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16, 18};

	for (int i = 1; i < sequence.size(); i *= 2) 
	{
		printContainer("Group size", i, sequence);
		sortPairs(sequence, i);
	}

    return 0;
}

// static void sortPairs(std::deque<int>& src, size_t groupSize) {
//     for (size_t tail = groupSize - 1; tail + groupSize < src.size(); tail += groupSize * 2) {
//         for (size_t i = 0; i < groupSize; ++i) {
//             if (src[tail - groupSize + 1 + i] > src[tail + 1 + i]) {
//                 std::swap(src[tail - groupSize + 1 + i], src[tail + 1 + i]);
//             }
//         }
//     }
// }

// int main() {
//     std::deque<int> sequence = {6, 14, 17, 5, 12, 1, 3, 7, 13, 8, 2, 11, 15, 4, 10, 9, 16};


//     std::cout << "Original sequence:\n";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << "\n";

//     sortPairs(sequence, 1);

//     // Recursion: Sort groups
//     // fordJohnsonRecursion(sequence, relationships, groupBoundaries);

//     // Unwinding: Insert smaller into larger
//     // fordJohnsonUnwinding(sequence, relationships, groupBoundaries);

//     std::cout << "Paired sequence:\n";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << "\n";

// 	sortPairs(sequence, 2);

//     std::cout << "Paired sequence:\n";
//     for (size_t i = 0; i < sequence.size(); ++i) {
//         std::cout << sequence[i] << " ";
//     }
//     std::cout << "\n";

//     return 0;
// }





