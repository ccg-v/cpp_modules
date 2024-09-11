# Exercise 01: Iter

The subject asks to create the function `iter` as a general-purpose tool for iteration. It must take three parameters:

* The address of an array
* The length of the array
* A function that will be called on every element of the array

It’s the responsibility of the user of `iter` to define what the operation is by providing the appropriate function. The function `iter` just needs to iterate over the array and apply that function to each element.

Therefore, the `iter` function doesn’t need to define a specific operation that works for every type. It just needs to be capable of accepting any operation (through the third parameter) and applying it to every element in the array, regardless of the type. This is why templates and function pointers are used, because they allow the flexibility to handle any type of array and any operation.

> [!NOTE]
> Templates must be defined in the header files

--------------------------------------------------------------------

## Function templates

The subject suggests a deeper use of templates, implying that we may need to create a specific function template as well. The idea is that we can leverage function templates to create a generic function that can be used with different data types. This way, iter can accept not just regular functions, but also function templates that have been instantiated for specific types.

* **What is a Function Template?**

A function template is a blueprint for creating functions that can operate on different types. It allows you to define a function where the data types of its parameters are not fixed, and can be determined when the template is instantiated (i.e., when you use it).

```
template <typename T>
void printElement(const T& element) {
    std::cout << element << std::endl;
}
```
In the previous example, `printElement` is a function template. You can instantiate this template for different types by calling it with, say, int, double, or std::string arguments. The ability to pass instantiated function templates allows you to:

- Write generic operations: You can create a single function template (like printElement) that works for all types, then instantiate it for specific types when needed.
- Keep iter flexible: Since iter is itself a function template, you can pass different instantiated function templates for different types, making your code more reusable.

--------------------------------------------------------------------

## Primary templates and specializations

Specialization is a mechanism used in templates to provide a different implementation of a primary template ***for a specific type or condition***.

 - **Primary template**: A general, unspecialized template that works for all types (like T*). For example:
	```
	template <typename T>
	void incrementElement(T& element) {
		element++;
	}
	```
 
 - **Full specialization** (`template <>`): It is used when you are providing a specific implementation for a particular type. This is a full specialization of the previous template, specifically for Point struct:
	```
	template <>
	void incrementElement(Point & p) {
		p.x ++;
		p.y ++;
	}
	```

 - **Partial specialization** (`template <typename T>`): It is used when you're still using a template parameter but restricting the template to handle a particular case (e.g., arrays of pointers) while keeping flexibility in the specific type. This is a partial specialization of incrementElement() template:
	```
	template <typename T>
	void incrementElement(T* &ptr) {
		if (ptr)
			(*ptr)++;
	}
	```
	The function receives a pointer to a T, which is a template parameter; thus, the specialization is partial, not full.

--------------------------------------------------------------------

<details>
<summary><h2> Exercise questions and hints </h2></summary>

<details>
<summary><h2> Options for `iter()`'s function parameter </h2></summary>

1. **Function locked to a specific function pointer type `void (*f)(T&)`**

	```
	template <typename T>`
	void iter(T* array, size_t length, void (*f)(T &));
	```

	This signature requires that the function passed as the third argument strictly takes a reference (`T &`) to non-constant elements of the array. 
	Limitations:

	* You can't pass functions that accept a constant reference (`const T &`). If you want to allow functions that do not modify the array elements (e.g. `void 		printElement(const T& element)`) you need to overload iter() to handle `const` cases:

		`void iter(T* array, size_t length, void (*f)(const T &);`

	* You also lose the ability to pass functions that take array elements by value. Again, we would need to overload iter():

		`void iter(T* array, size_t length, void (*f)(T))`

	Read in next section, ["The function parameter: Why passing by reference and not by value?"](https://github.com/ccg-v/cpp_modules/tree/master/cpp_07/ex01#-the-function-parameter-why-passing-by-reference-and-not-by-value-) why this is not the best choice.

* Also, if for instance we want to handle arrays of pointers (e.g., `int*`), we need to provide a different function signature where the first parameter accepts an array of pointers. This is because the T* in the original function signature is meant for arrays of T, not T*:

	`void iter(T** array, size_t length, void (*f)(T*))`

In short, this signature it's too limiting in terms of flexibility. You end up needing more repetitive code, and that doesn't align well with the concept of templates where flexibility is the key.

The subject says that the third parameter ***"can be an instantiated function template"***, suggesting a second and more flexible approach:

2. **Using a template parameter for the function**

	```
	template <typename T, typename F>
	void iter (T* array, size_t length, F f);
	```

This version of iter accepts a function object or a function pointer as the third argument (F f). It doesn't require a specific function signature, which means it can handle both:

- Functions that modify elements of the array (void (*f)(T&))
- Functions that don't modify elements (void (*f)(T const&))
- Functions for arrays of pointers (void (*f)(T*))

This is because F is a generic callable[^1], and C++'s template system will automatically deduce the correct type for F based on how you invoke the iter function. As a result, you don't need explicit overloads for specific cases.

--------------------------------------------------------------------
</details>

<details>
<summary><h2> The function parameter: Why passing by reference and not by value? </h2></summary>

### Passing by Value is Fine for Basic Types (Scalars)

For simple, scalar types like int, float, or char, copying is inexpensive:

- These types are small in size (typically 4 or 8 bytes).
- Copying them is very fast because they involve just moving a few bytes.
- The overhead of copying is negligible.

This is why passing by value works well for such basic types. Even though each element is copied, the cost is minimal.

### Passing by Value is Less Ideal for Complex Types

What happens when T is a more complex type, such as:

- std::string: Contains dynamically allocated memory.
- User-defined classes: Could include multiple members, dynamically allocated resources, or complex constructors/destructors.

When you pass a complex type by value, the copy operation involves:

- Copying all internal data: For something like a std::string, this may include copying dynamically allocated memory.
- Potentially invoking copy constructors: For user-defined classes, copying may involve running a copy constructor, which could be expensive if it involves deep copying internal resources.

In such cases:

- Performance overhead: Copying complex objects can be much slower, especially in loops where many copies are made.
- Unnecessary resource use: Creating temporary copies can lead to unnecessary memory usage and potential slowdowns.

### Conclusion

Passing by value works for basic types because copying them is cheap and straightforward. For complex types, copying is more expensive and potentially problematic, which is why passing by const T& is preferred—it’s more efficient and avoids unnecessary deep copies.

Passing by `const T&`:

- Avoids copying by passing a reference, which is just a pointer under the hood.
- Ensures that the function operates directly on the original object without creating unnecessary copies.
- Maintains immutability (const) so that the function cannot accidentally modify the original elements.

--------------------------------------------------------------------
</details>

</details>

[^1]: n C++ terminology, a callable is any object that can be called using the function call operator ().