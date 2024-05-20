#include <string>
#include <iostream>

int	main( void ) {
	std::string array[20];
	for (int i = 0; i < 20; i++) {
		array[i] = "idea_" + std::to_string(i);
	}
	for (int i = 0; i < 20; i++) {
		std::cout << array[i] << std::endl;
	}
}