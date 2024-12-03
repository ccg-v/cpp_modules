#include "PmergeMe.hpp"
#include "Utils.hpp"
#include <iostream>	// For std::cout(), std::cerr()
#include <ctime>	// For clock()

int main(int argc, char* argv[]) {

	try {
		if (argc > 1) {
			PmergeMe pmergeme;
			// Fill the containers and check input element's validity
			pmergeme.checkInputAndSetContainers(argc, argv);
			printContainer("intsVector = ", pmergeme.getIntsVector());

			// Check if input sequence is already sorted
			if (isSorted(pmergeme.getIntsVector()))
				throw std::runtime_error("Error: The input sequence is already sorted");

			// If sequence has odd number of elements, save last element as straggler and remove it from sequence
			int intStraggler;
			if (pmergeme.getIntsVector().size() % 2 == 1)
			{
				intStraggler = pmergeme.getIntsVector().back();
				pmergeme.getIntsVector().pop_back();
				std::cout << "intStraggler = " << intStraggler << std::endl;
				printContainer("intsVector without straggler = ", pmergeme.getIntsVector());
			}

			// Pair adjacent elements in the vector of integers and load them in a vector of pairs
			pmergeme.setPairsVector();
			printContainer("pairsVector = ", pmergeme.getPairsVector());

			// Recursively sort main chain
			std::cout << " --- Start recursive sorting of main chain --- " << std::endl;
			pmergeme.fordJohnsonSort(pmergeme.getPairsVector());
			std::cout << " --- End recursive sorting of main chain ----- " << std::endl;
			printContainer("main(): SORTED PAIR = ", pmergeme.getPairsVector());

		} else {
			throw std::runtime_error("Error: Wrong number of arguments");			
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

    return 0;
}
