# Exercise 00: Start with a few functions

## Templates

Templates in C++ are a powerful feature that allows you to write generic and reusable code. They enable you to define functions and classes that work with any data type, which is very useful when you want to write code that is independent of specific types. 

### Types of Templates in C++

**1. Function Templates**
Function templates are used to create a single function that can operate on different data types. You define a template with one or more type parameters (e.g., 'T', 'U') that are used as placeholders for actual types.

In the following example, the same 'findMax()' function works with integers, doubles and chars. The template automatically adatps to the data type passed when the function is called.

```
// Function template for finding the maximum of two values
template <typename T>
T findMax(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << findMax(10, 20) << endl;          // Works with integers
    cout << findMax(5.5, 2.3) << endl;        // Works with doubles
    cout << findMax('a', 'z') << endl;        // Works with characters
}
```

**2. Class Templates**
Class templates allow you to create classes that work with different data types. Like function templates, class templates use type parameters, enabling the class to be reused for different types.

### Function overloading vs. Templates

**1. Function overloading**

Function overloading allows you to define multiple functions with the same name but with different parameter types or number of parameters. The compiler chooses the correct function based on the arguments provided

```
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}

string add(string a, string b) {
    return a + b;
}

int main() {
    cout << add(3, 4) << endl;          // Calls the int version
    cout << add(3.5, 4.5) << endl;      // Calls the double version
    cout << add("Hello", " World") << endl; // Calls the string version
}
```
In the example we have written separate functions for each data type. This approach requires to manually write each version of the function, which can lead to duplicated code if the logic is similar for all types.


**2. Templates**

As we have seen in the first example, templates allow you to write a single function (or class) that works with any type. The compiler generates the appropriate function or class when it sees the type used at compile-time.
