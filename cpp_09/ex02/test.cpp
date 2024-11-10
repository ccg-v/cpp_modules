#include <vector>
#include <iostream>

void printContainer(const std::vector<int>& container) {
    if (!container.empty()) {
        std::cout << "{ ";
        for (std::vector<int>::const_iterator it = container.begin(); it != container.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << "}" << std::endl;
    }
}

// std::vector<int> generateJacobsthalSeq(size_t len) {
// 	std::vector<int> JacobsthalSeq = {0, 1};
// 	while (JacobsthalSeq.back() < len) {
// 		size_t next = JacobsthalSeq.back() + 2 * JacobsthalSeq[JacobsthalSeq.size() - 2];
// 		if (next >= len) break;
// 		JacobsthalSeq.push_back(next);
// 	}
// 	return JacobsthalSeq;
// }


std::vector<int> generateJacobsthalSeq(size_t len)
{
	std::vector<int>	JacobsthalSeq;
	size_t				num;

	JacobsthalSeq.push_back(0);
	JacobsthalSeq.push_back(1);
	for (size_t i = 2; i < len; i++) {
		num = JacobsthalSeq[i - 1] + (2 * JacobsthalSeq[i - 2]);
		JacobsthalSeq.push_back(num);
	}

	return JacobsthalSeq;
}

int main (int argc, char **argv) {
	if (argc == 2) {
		int len = atoi(argv[1]);
		std::vector<int> insertionOrder = generateJacobsthalSeq(len);
		printContainer(insertionOrder);
	}
	return 0;
}