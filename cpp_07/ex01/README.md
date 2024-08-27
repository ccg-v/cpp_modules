# Exercise 01: Iter

The subject asks to create the function `iter` as a general-purpose tool for iteration. It must take three parameters:

* The address of an array
* The length of the array
* A function that will be called on every element of the array

It’s the responsibility of the user of `iter` to define what the operation is by providing the appropriate function. The function `iter` just needs to iterate over the array and apply that function to each element.

Therefore, the `iter` function doesn’t need to define a specific operation that works for every type. It just needs to be capable of accepting any operation (through the third parameter) and applying it to every element in the array, regardless of the type. This is why templates and function pointers are used, because they allow the flexibility to handle any type of array and any operation.

> [!NOTE]
> Templates must be defined in the header files

### Function templates ###

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

<details>
<summary><h3> The function parameter: Why passing by reference and not by value?** </h3></summary>

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

</details>

<details>
<summary><h3> Other options for `iter()`'s third parameter ** </h3></summary>

The subject says hat the third parameter ***"can be an instantiated function template"***, suggesting that there are other options. These are the alternatives:

1. **A Regular Function (Non-Template Function)**:

The third parameter can simply be a standard, non-template function that takes a specific type. For instance, if you’re working with an array of `int`, you could pass a function like this:

```
void increment(int& x) {
    x++;
}
```

You can pass this function directly to `iter` when iterating over an int array. The function is specific to `int` and is not a template, but it will still work.

Example usage:

```
int arr[] = {1, 2, 3, 4};
iter(arr, 4, increment);
```

2. **A Lambda Function**:

Lambda functions are a convenient way to define small, inline functions without having to declare them separately.

```
iter(arr, 4, [](int& x) { x *= 2; });  // Doubles each element
```

Here, the lambda captures each element by reference and modifies it directly.

3. **A Function Object (Functor)**:

You can define a class or struct that overloads the `operator()`, turning it into a callable object. This is known as a **functor**

```
struct MultiplyByTwo {
    void operator()(int& x) const {
        x *= 2;
    }
};

iter(arr, 4, MultiplyByTwo());
```

This approach provides even more flexibility, allowing you to store state or define more complex behavior.

</details>