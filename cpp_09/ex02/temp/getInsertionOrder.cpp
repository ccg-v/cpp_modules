std::vector<int> PmergeMe::getInsertionOrder(const std::vector<int> & jacobsthalSeq, size_t size) {
	std::vector<int> insertionOrder;

	// Add all Jacobsthal-indexed elements and interleave non-Jacobsthal elements in reverse order
	for (size_t i = 0; i < jacobsthalSeq.size(); i++) {
		size_t currentJacobIndex = jacobsthalSeq[i];

		// Stop if the current Jacobsthal index exceeds the given size
		if (currentJacobIndex >= size) break;

		// Add current Jacobsthal-indexed element
		insertionOrder.push_back(currentJacobIndex);

		// If there's a previous Jacobsthal index, add interleaved indices in reverse order
		if (i > 0) {
			size_t prevJacobIndex = jacobsthalSeq[i - 1];
			for (size_t j = currentJacobIndex - 1; j >= prevJacobIndex + 1; --j) {
				if (j < size) {
					insertionOrder.push_back(j);
				}
			}
		}
	}

	// For any remaining values past the last Jacobsthal index, add them in reverse order
	size_t lastJacobIndex = jacobsthalSeq.back();
	for (size_t k = size - 1; k > lastJacobIndex; --k) {
		insertionOrder.push_back(k);
	}

	// Ensure '0' is included as the first index if it's missing
	if (insertionOrder.empty() || insertionOrder[0] != 0) {
		insertionOrder.insert(insertionOrder.begin(), 0);
	}

	return insertionOrder;
}
