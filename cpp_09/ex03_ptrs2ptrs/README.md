# Exercise 02: PmergeMe

## Streams

In C++, a **stream** is an abstraction for a sequence of characters that can be read from or written to. Streams represent sources or destinations of data, such as files, user input, or strings, and they provide a consistent way to handle data regardless of where it’s coming from or going to.

- Types of Streams:
	- Input Stream: A stream you read data from (e.g., std::cin for console input or std::ifstream for reading from files).
	- Output Stream: A stream you write data to (e.g., std::cout for console output or std::ofstream for writing to files).

- Stream Classes in C++:

	The C++ Standard Library provides different types of stream classes:
	- std::istream for reading input.
	- std::ostream for writing output.
	- std::ifstream and std::ofstream for reading from and writing to files.
	- std::istringstream and std::ostringstream for reading from and writing to strings (in memory).

- How Streams Work:
	Streams allow you to use operators like **>> (extraction)** and **<< (insertion)** to read and write data.
	The **>> operator** reads formatted input from the stream (like integers, words, or lines).
	The **<< operator** writes formatted output to the stream.

## Why lists are inefficient for binary searches?
 
- Lack of Random Access:
	Binary search requires jumping to the "middle" element repeatedly. Lists are linked structures, so you can’t directly access an element by index. To get to the middle, you’d have to step through each link starting from the beginning, which turns each step in binary search into a linear traversal. This eliminates the efficiency of binary search, which relies on being able to jump to any element quickly.

- Time Complexity: 
	In a vector or deque, binary search has a logarithmic time complexity, `O(log n)`, due to direct access. In a list, it effectively becomes `O(n log n)` because each "middle" element access is linear `(O(n))`, compounded by the log n divisions from binary search.

 - Resource Consumption:
	Because lists don’t have contiguous memory, there’s extra overhead in moving through nodes, which can be costly in terms of both time and memory usage.

## Binary searches in vectors and deque lists

In comparing binary search efficiency between std::vector and std::deque, std::vector is generally better suited. Here’s why:

- Contiguous Memory Layout:
	std::vector stores elements in a single contiguous block of memory, allowing efficient, direct access to elements by index. This layout enables binary search to quickly jump to the middle element, divide the range, and repeat as needed without needing additional traversal.

- Random Access Iterators:
	std::vector provides random access iterators, allowing vec[mid] to directly access the middle element. This property makes binary search faster and simpler with vectors.

- Deque’s Split Memory Layout:
	std::deque stores its elements in multiple non-contiguous memory blocks (or “chunks”). Although std::deque allows fast access to the front and back, it doesn’t support as efficient index-based access for intermediate elements, as each index access may require a lookup within the underlying chunks. This can make binary search slower in a std::deque.

So, while you can perform binary search on both, std::vector is often more efficient due to its contiguous storage and true random access capabilities.