#include <iostream>
#include "debug.hpp"

void standardExec() {
    DEBUG_PRINT("Standard execution started");
    // Standard logic here
    DEBUG_PRINT("Standard execution finished");
}

void debugExec() {
    DEBUG_PRINT("Debug execution started");
    // Debug-specific logic here
    DEBUG_PRINT("Debug execution finished");
}

// int main() {
// #ifdef DEBUG_MODE
//     debugExec();
// #else
//     standardExec();
// #endif
//     return 0;
// }

int multiply(int a, int b) {
	return (a * b);
}

int main() {
	#ifdef DEBUG_MODE
		std::cout << "DEBUG_MODE is ON" << std::endl;
	#else
		std::cout << "DEBUG_MODE is OFF" << std::endl;
	#endif

	std::cout << "This should be displayed anyway" << std::endl;
	DEBUG_PRINT("This straight printing should be seen only in debug mode");
	// result = multiply(3, 5);
	DEBUG_PRINT("3 * 5 = " << multiply(3, 5));
	std::cout << "7 * 6 = " << multiply(7, 6) << std::endl;
}