#include <iostream>
#include <string>
#include <cfloat>
#include <cstdlib>

void	toDouble(const std::string & literal) {

    char* end;
    double d_value = std::strtod(literal.c_str(), &end);
	if (d_value > DBL_MAX)
		std::cout << d_value << " is greater than DBL_MAX" << std::endl;
	else if (d_value == DBL_MAX)
		std::cout << d_value << " is equal to DBL_MAX" << std::endl;
	else		
		std::cout << d_value << " is smaller than DBL_MAX" << std::endl;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')" << std::endl;
        return 1;
    }
    toDouble(argv[1]);
    return 0;
}