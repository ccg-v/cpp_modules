#include <vector>
#include <cstdlib>
#include <iostream>

template <typename T>
void printContainer(const std::string msg, const T& container) {
	if (container.size() > 0) {
		std::cout << msg << "{ ";
		for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
			std::cout << *it << " ";
		}
		std::cout << "}" << std::endl;
	}
}

std::vector<int> buildJacobsthalVec(size_t len)
{
    std::vector<int>    JacobsthalSeq;
    size_t				num;

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

int	main(int argc, char **argv) {
	if (argc == 2) {
		std::vector<int> jacobsthalSeq = buildJacobsthalVec(atoi(argv[1]));
		printContainer("Jacobsthal numbers = ", jacobsthalSeq);
	}
	return(0);
}