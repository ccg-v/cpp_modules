# Exercise 00: Conversion of scalar types

<details>
<summary><h2> Scalar types </h2></summary>

Data types that hold a single value, as opposed to aggregate types like arrays, classes, or structures that can hold multiple values.
Main categories of scalar types:
1. Arithmetic Types
	1.1 Integer Types: Signed(short/int/long/long long) or Unsigned(unsigned short/unsigned int/unsigned long/unsigned long long)
	1.2 Floating-point Types: float/double/long double
2. Character Types
	2.1 Char: Signed char or Unsigned char
	2.2 wchar_t: used for wide characters(larger character sets like Unicode)
	2.3 char16_t and char32_t: used for Unicode characters in UTF-16 and UTF-32 encodings, respectively
3. Boolean Type: bool
4. Pointer Types
	2.1 int*, char*...: These are pointers to specific types
	2.2 void: A generic pointer that can hold the address of any data type
5. Enumerated types (enum)

</details>

## The function must take as a parameter "a string representation of a C++ literal"

When we talk about a "string representation of a C++ literal", we're talking about how literals of various types (integers, floats, characters, etc.) are expressed as strings in source code, rather than referring to string literals themselves (char* or std::string).
Let's consider a function that takes a string representation of a literal:

```void processLiteral(const std::string& literal);```

If you call this function, you're passing in a string that represents a literal, not necessarily a literal that is a string. For example:
```
processLiteral("123");       // Represents an integer literal
processLiteral("3.14");      // Represents a floating-point literal
processLiteral("'a'");       // Represents a character literal
processLiteral("\"hello\""); // Represents a string literal
processLiteral("true");      // Represents a boolean literal
```
## Pseudo Literals

In C++, pseudo literals are special values used to represent certain edge cases or special conditions in floating-point arithmetic. They are not numeric values in the usual sense but are part of the floating-point standard to handle cases that cannot be represented by finite floating-point numbers:

**1. Infinity** (`**+inf**` and `**-inf**`)

	* **Positive Infinity** ('**+inf**'): Represents a value that is larger than any finite number. This can result from operations like dividing a positive number by zero.
	* **Negative Infinity** ('**-inf**'): Represents a value that is more negative than any finite number. This can result from operations like dividing a negative number by zero.

	In C++, these are represented in floating-point types as:

	* For 'float': '+inff' and '-inff'
	* For 'double': '+inf' and '-inf'

**2. NaN** (**Not-a-Number**)

	Represents a value that is undefined or unrepresentable, especially in floating-point calculations. Operations like '0.0 / 0.0' or the square root of a negative number (in a context where complex numbers are not being used) can produce NaN.

	In C++, these are represented in floating-point types as:

	* For 'float': 'nanf'
	* For 'double': 'nan'

## Exercise's logic

**1. Attributes of the Class**

    Since the class ScalarConverter is designed to be non-instantiable and only needs to perform a conversion based on the provided string literal, it does not require any attributes. The conversion logic can be handled purely through static methods without any need for member variables.

**2. Constructor**

    The constructor should not receive any parameters. Given the class must be non-instantiable, the constructor should be private or protected to prevent instantiation. The string literal should be handled by a static method rather than through the constructor.

**3. Static Method for Conversion**

    The class should provide a static method (likely named convert) that takes the string literal as a parameter. This method will handle the detection of the literal type, conversion to the appropriate scalar types, and output the results.


