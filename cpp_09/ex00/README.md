# Exercise 00: Bitcoin Exchange
## Target
Write a program that calculates and outputs the value of a certain amount of bitcoin on a certain date. It must take as a parameter an input file containing a list of dates and the amount of bitcoins corresponding each date. To calculate the results, the program will use a database in csv format -provided with this subject- which represents bitcoin price over time. This database is provided with this subject.
- Each line in the input file must use the following format: "date | value".
- Dates must follow the format: *Year-Month-Day*.
- Values must be either a float or a positive integer, between 0 and 1000.
- At least one container must be used in the code.
> [!WARNING]
> The type of container(s) chosen for this exercise **will no longer be usable for the rest of the module!**
-----------------------------------
## Flow chart
<p align="center">
	<img src="assets/BitcoinExchange.svg" />
</p>
-----------------------------------
<details>
<summary><h3> Date type: `std::string` or `std::time_t` </h3></summary>

**What is std::time_t?**

`std::time_t` is an integer type representing seconds since the *epoch*, i.e., 00:00, Jan 1, 1970, UTC. It's used in C++ to represent points in time (timestamps).

In our exercise, since dates are provided as std::string (YYYY-MM-DD), we will need to convert them into std::time_t timestamps.

* **Pros of Using `std::time_t`**

    - Efficient Comparison:
        When using std::time_t, comparisons (e.g., finding the closest date) are faster than string comparisons because you're comparing integers rather than performing lexicographical comparisons on strings.

    - Built-in Date Handling:
        Converting date strings to std::time_t helps avoid errors in date comparisons, leap year handling, and other date-related complexities. The std::tm struct and related functions (mktime, strftime, etc.) can handle date arithmetic more reliably.
        For example, you can easily add days, months, or years and convert back to human-readable format when necessary.

    - Memory Efficient:
        std::time_t is smaller in size (usually 64-bit) compared to a string that could use more memory. If you have a large set of dates, this could save memory.

* **Cons of Using `std::time_t`**

    Conversion Complexity:
        You would need to convert the YYYY-MM-DD date string from your input files into a std::time_t value when inserting data into the map. This requires extra logic and may introduce complexity.
        You'll need to work with std::tm to parse the date string and use mktime() to convert it to std::time_t.

		This introduces a layer of parsing and conversion you wouldn't need if you were using strings directly.

	Loss of Readability:

		Dates stored as std::time_t are no longer human-readable. While strings like "2023-04-25" are easily understood, a std::time_t integer might not make sense at a glance.
		You would have to convert std::time_t back into a readable format whenever you want to display it.

	Limited to Date Range of std::time_t:

		std::time_t is generally based on the number of seconds since the Unix epoch (January 1, 1970). Depending on the system and whether it uses a 32-bit or 64-bit representation for std::time_t, it may not cover the full range of historical dates (e.g., before 1970 or far into the future).

When to Stick with std::string

    Simplicity: If your dataset is small and you don’t need date arithmetic, using std::string is simpler and more intuitive.
    Readability: Strings are human-readable, so debugging and printing values from the map is much easier when dates are stored as std::string.
    Fewer conversions: With strings, you avoid the overhead and complexity of converting between formats. If the program’s primary task is comparing date strings from input files, using strings might be easier.

Conclusion

    For Small Projects or Simpler Code: Storing dates as std::string is easier to implement, more intuitive, and avoids the complexity of converting between date formats.
    For Performance-Intensive Applications: If you're dealing with a large number of dates and need efficient comparisons or date arithmetic, using std::time_t can be a better choice. However, this comes with the trade-off of added complexity for conversion and a loss of readability.

Since you're writing an educational exercise, the simplicity of using std::string might be more advantageous, but if you're up for handling the conversion complexity, std::time_t is an efficient and robust solution.

</details>

<details>
<summary><h3> Should date validation functions be member methods of the class or not? </h3></summary>
Since my date validation functions don't depend on the internal state of the BitcoinExchange class, and they're useful in a more general context, the cleaner and more flexible approach is to make them non-member functions. This approach:

- Keeps the class focused on its core purpose: handling bitcoin exchange logic.
- Allows easier reusability of date validation in other parts of the program.
- Keeps the class lighter and better aligned with the *Single Responsibility Principle* (SRP) [^1].

So I have decided to place the date validation functions in separate utility files, DateUtils.hpp and DateUtils.cpp, to decouple them from the BitcoinExchange class.

[^1]: The *Single Responsibility Principle* is one of the five SOLID principles of object-oriented design. It states that a class should have one and only one reason to change, meaning that it should focus on a single responsibility or function. In other words, **a class should be responsible for one thing**, and all of its methods should contribute to fulfilling that responsibility. In our case, BitcoinExchage's main purpose is to handle exchange logic, so its methods should focus on tasks related to this responsibility. Adding unrelated tasks, such as general date validation, dilutes the focus of the class.

</details>


<details>
<summary><h3>Common approaches to error handling in C++</h3></summary>

**1. Simple error reporting (C-style error handling)**

```
	if (validateDate(valueDate) == false) {
		std::cerr << "Error: bad input => " << valueDate << std::endl;
	}
```
- This approach is typical in C or for very simple C++ programs that don't require exception handling.
- It's low-overhead but doesn't integrate well into error management strategies where control flow needs to change based on the error.

**2. Generic exception**

```
	try {
		std::ostringstream oss;

		if (validateDate(valueDate) == false) {
			oss << "Error: bad input => " << valueDate;
			throw std::runtime_error(oss.str());
		}
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	} 
```
- Note that the thrown exception is not `std::exception` but `std::runtime_error`. This is because `std::exception` is very basic and doesn't support custom error messages directly. Instead, `std::runtime_error` does allow you to pass a custom error message with the oss.str().

**3. `std::runtime_error` exception**

```
	try {
		std::ostringstream oss;

		if (validateDate(valueDate) == false) {
			oss << "Error: bad input => " << valueDate;
			throw std::runtime_error(oss.str());
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	} 
```

- There is a **compact and clean way** to handle exceptions without needing an extra ostringstream:

```
	try {
		if (validateDate(valueDate) == false) {
			throw std::runtime_error("Error: bad input => " + valueDate);
		}
	} catch (const std::runtime_error & e) {
		std::cerr << e.what() << std::endl;
	} 
```

**4. Custom exception** (concatenating additional info -like a variable value- to error message)

- First we need to declare the custom exception class:

```
	class BadDateException : public std::exception {
		private:
			std::string _message;	// To store the full message

		public:
			// Constructor
			BadDateException(const std::string & date);

			// Override what() method
			virtual const char* what() const throw();
	};
```

- Next define it:

```
	#include "BadDateException.hpp"

	// Constructor definition
	BadDateException::BadDateException(const std::string& date) 
		: _message("Error: bad input => " + date) {}

	// what() method definition
	const char* BadDateException::what() const throw() {
		return _message.c_str();
	}

```

- And finally throw it in the try-catch block:

```
	try {
		if (validateDate(valueDate) == false) {
			throw BadDateException(valueDate);
		}
	} catch (const std::exception & e) {
		std::cerr << e.what() << std::endl;
	} 

```

- Using custom exceptions can feel over-engineered. If the complexity of your application doesn't justify it, simpler solutions like logging or using standard exceptions (std::runtime_error) may be more appropriate. Custom exceptions shine when your system needs more granular control over errors, clear and maintainable separation of concerns, and flexibility as your project scales.

**Conclusion**

If the project is small or medium-sized, better stick to simple error messages or standard exceptions. Move to custom exceptions only when your project grows in complexity and requires more refined error handling.

</details>