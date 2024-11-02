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