# SERIALIZATION AND DESERIALIZATION
The exercise tests your understanding of how pointers, memory addresses, and type casting work in low-level programming, and how you can manipulate these concepts using serialization and deserialization techniques.
* **Serialization**: This is the process of converting an object (or, in this case, a pointer to an object) into a format that can be easily stored, transmitted, or used in some other way. Here, the format is an integer (`***uintptr_t***`), which is a type specifically designed to hold a memory address as an unsigned integer.
* **Deserialization**: This is the reverse process of serialization. It involves taking the serialized format (in this case, the integer) and converting it back to the original object (or pointer to the object).

# REPRESENTATION OF MEMORY ADDRESS
* The ***memory address is typically represented as a binary number internally by the computer***. However, when displayed to programmers (e.g., in debugging or output), it's often shown in hexadecimal (base 16) format for readability. This is because hexadecimal is more compact than binary and aligns well with how memory is structured.
* In most programming languages, the pointers (i.e., the variables that store memory addresses) have a specific type that indicates what kind of data they point to. For example, a pointer to an _int_ might be of type _int*_, while a pointer to a _float_ would be of type _float*_. The type helps ensure that the pointer is used correctly, such as accessing the right amount of memory for the data type it points to.
* When you see a pointer's value (i.e., the memory address it stores), ***it's usually shown in hexadecimal form. This is just a convention for displaying the memory address to humans***. The computer itself uses the binary representation internally. Why hexadecimal? Because it is more compact and easier to read than binary. Each hexadecimal digit represents four binary digits, so a 64-bit address can be represented with just 16 hexadecimal digits.

# CASTING IN C++
In C++ there are four types of casting operators:
1. `