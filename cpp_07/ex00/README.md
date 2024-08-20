# Exercise 00: Start with a few functions

## Templates

Templates in C++ are a powerful feature that allows you to write generic and reusable code. They enable you to define functions and classes that work with any data type, which is very useful when you want to write code that is independent of specific types. 

### Types of Templates in C++

**1. Function Templates**

* Function templates are used to create a single function that can operate on different data types. You define a template with one or more type parameters (e.g., 'T', 'U') that are used as placeholders for actual types.

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

* Class templates allow you to create classes that work with different data types. Like function templates, class templates use type parameters, enabling the class to be reused for different types.

### Function overloading vs. Templates

**1. Function overloading**

* Function overloading allows you to define multiple functions with the same name but with different parameter types or number of parameters. The compiler chooses the correct function based on the arguments provided

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
		std::cout << add(3, 4) << std::endl;          		// Calls the int version
		std::cout << add(3.5, 4.5) << std::endl;      		// Calls the double version
		std::cout << add("Hello", " World") << std::endl; 	// Calls the string version
	}
	```
	In the example we have written separate functions for each data type. This approach requires to manually write each version of the function, which can lead to duplicated code if the logic is similar for all types.


**2. Templates**

* Templates allow you to write a single function (or class) that works with any type. Unlike overloading, where you need to write separate functions for each data type even if the logic is identical, using a template you write the logic once, which is more concise and avoids code duplication. The compiler generates the appropriate function or class when it sees the type used at compile-time.

	Here's how the previous example can be refactored to use a template for the 'add()' function that can handle any type of data:

	```
	template <typename T>
	T add(T a, T b) {
		return a + b;
	}

	int main() {
		std::cout << add(3, 4) << std::endl;          						// Works with int
		std::cout << add(3.5, 4.5) << std::endl;      						// Works with double
		std::cout << add(string("Hello"), string(" World")) << std::endl; 	// Works with string
	}

	```

---

## The Scope Resolution Operator (`::`)

You would need the `::` in the following cases:

**1. Name conflicts:**
	If you have functions that share the name defined within different scopes, such as inside classes or namespaces, then you might need the `::` to disambiguate and explicitly call the global version

**2. Preventing ambiguities:**
	If you include libraries (like the C++ Standard Library) that have their own functions with the same name as yours, using `::` ensures that your custom functions are called instead of the library functions.

You might not need it if:
1. You have only one version of each of these functions defined in the global namespace[^1]
2. There are no conflicting functions from any other scopes

However, it is recommended to use it purely as a safeguard, anticipating that the code might be extended in the future and potentially introduce unexepected naming conflicts.
**Conflicts can also be avoided by not using `using namespace std;`, explicitly specifying namespaces, or giving our functions a different name.**

[^1]The **Global Namespace** is the top-level namespace in a C++ program where all identifiers (like variables, functions, and classes) that are not inside any specific namespace are placed by default. Any identifier that is not enclosed withi an custom
namespace or the `std` namespace will be considered part of the Global Namespace.