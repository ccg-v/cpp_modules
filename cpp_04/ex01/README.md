# Exercise 01: I don't want to set the world on fire

## Deep copy vs. Shallow Copy
In C++, shallow copy and deep copy are two ways to create a copy of an object, but they differ in how they handle the object's data:

Shallow Copy:

    Copies the values of the member variables of the original object to the new object.
    If the member variables are basic data types (int, float, etc.), a new copy of the data is created for the new object.
    However, if the member variables are pointers or references, the shallow copy only copies the memory address they point to. Both the original and the copy object now refer to the same underlying data.

Deep Copy:

    Creates a completely independent copy of the original object.
    In addition to copying the values of member variables, it also copies the data pointed to by pointers and references.
    This means allocating new memory and copying the contents of the original data into the new memory for the copied object.

Here's a table summarizing the key differences:
| Feature | Shallow Copy | Deep Copy |
| --- | --- | --- |
| Member Variable Copying | Copies values| Copies values and pointed-to data |
| Data Independence	| No (shared data)| Yes (independent data) |
| Changes in Copy | Reflected in original object | Not reflected in original object |

Choosing Between Shallow and Deep Copy:

    Use shallow copy when you want multiple objects to share the same data (efficiency).
    Use deep copy when you need independent objects with isolated data (avoid unintended modifications).

Example:

Consider a class Person with a name (string) and a pointer to a Phone object.

    Shallow copy of Person would copy the name string but keep the same Phone pointer, meaning both objects point to the same phone data.
    Deep copy would not only copy the name but also create a new Phone object with its own copy of the phone data.

Understanding shallow vs. deep copy is crucial for working with objects in C++ to ensure proper data management and avoid unexpected behavior.