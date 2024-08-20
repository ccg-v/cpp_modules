# Exercise 01: Serialization

The exercise tests your understanding of how pointers, memory addresses, and type casting work in low-level programming, and how you can manipulate these concepts using serialization and deserialization techniques.

## SERIALIZATION AND DESERIALIZATION

* **Serialization**: This is the process of converting an object (or, in this case, a pointer to an object) into a format that can be easily stored, transmitted, or used in some other way. Here, the format is an integer (***`uintptr_t`***), which is a type specifically designed to hold a memory address as an unsigned integer.
* **Deserialization**: This is the reverse process of serialization. It involves taking the serialized format (in this case, the integer) and converting it back to the original object (or pointer to the object).

## REPRESENTATION OF MEMORY ADDRESS
* The ***memory address is typically represented as a binary number internally by the computer***. However, when displayed to programmers (e.g., in debugging or output), it's often shown in hexadecimal (base 16) format for readability. This is because hexadecimal is more compact than binary and aligns well with how memory is structured.
* In most programming languages, the pointers (i.e., the variables that store memory addresses) have a specific type that indicates what kind of data they point to. For example, a pointer to an _`int`_ might be of type _`int*`_, while a pointer to a _`float`_ would be of type _`float*`_. The type helps ensure that the pointer is used correctly, such as accessing the right amount of memory for the data type it points to.
* When you see a pointer's value (i.e., the memory address it stores), ***it's usually shown in hexadecimal form. This is just a convention for displaying the memory address to humans***. The computer itself uses the binary representation internally. Why hexadecimal? Because it is more compact and easier to read than binary. Each hexadecimal digit represents four binary digits, so a 64-bit address can be represented with just 16 hexadecimal digits.

## CASTING IN C++
In C++ there are four types of casting operators:
1. **`static_cast`**
	* It is used for standard type conversions, such as converting between numeric types (e.g., int to float), or for more complex conversions where the types are related, like upcasting or downcasting in a class hierarchy (e.g., casting a base class pointer to a derived class pointer).
	* Limitations: It performs compile-time checks and will not allow conversions between completely unrelated types (e.g., from a pointer to an integer).
2. **`const_cast`**
	* It is used to add or remove the const qualifier from a variable. It’s typically used when you need to pass a const object to a function that requires a non-const parameter.
3. **`reinterpret_cast`**
	* It is used for low-level casting where you want to convert one type to a completely unrelated type. This is often used for pointer conversions, such as converting a pointer to an integer type or vice versa. It doesn’t perform any type safety checks and is essentially a bitwise reinterpretation of the value.
	* Some common uses are:
		- Printing memory addresses for debugging purposes 
		- Creating hash values based on memory addresses
		- Performing calculations on memory addresses, etc. 
	* Why using unsigned integers instead of hexadecimal addresses? They can offer some specific advantages in certain scenarios:
		- Arithmetic operations: Easier with integers, more straightforward with hexadecimal
		- Compatibility with standard library: Many of the functions and data structures work with integers rather than hexadecimal
		- Bit manipulation: Easier to perform on integers than on hexadecimal representations
		- Performance: In some cases slightly faster in integer operations
		- Storage efficiency: Storing an integer typically uses less memory than storin a string representation of an hex address
	* `reinterpret_cast` is designed to handle conversions between types that have different underlying representations, like converting a pointer to an integer. Since a pointer is essentially a memory address, `reinterpret_cast` allows you to treat this memory address as an integer without changing the bit pattern—just interpreting it differently.
	* This is the most appropriate choice for converting a pointer to an integer (`uintptr_t`) because you’re explicitly telling the compiler to treat the pointer’s memory address as an unsigned integer.
4. **`dynamic_cast`**
	* It is used for safely downcasting pointers or references within an inheritance hierarchy. It checks at runtime if the cast is valid and returns nullptr if it isn’t. This is primarily used in polymorphic class hierarchies.