# Exercise 01: Iter

The subject asks to create the function `iter` as a general-purpose tool for iteration. It must take three parameters:

* The address of an array
* The length of the array
* A function that will be called on every element of the array

It’s the responsibility of the user of iter to define what the operation is by providing the appropriate function. The function iter just needs to iterate over the array and apply that function to each element.

Therefore, the `iter` function doesn’t need to define a specific operation that works for every type. It just needs to be capable of accepting any operation (through the third parameter) and applying it to every element in the array, regardless of the type. This is why templates and function pointers are used, because they allow the flexibility to handle any type of array and any operation.

<details>
<summary><h3> The function parameter: Why passing by reference and not by value? </h3></summary>

## Passing by Value is Fine for Basic Types (Scalars)

For simple, scalar types like int, float, or char, copying is inexpensive:

- These types are small in size (typically 4 or 8 bytes).
- Copying them is very fast because they involve just moving a few bytes.
- The overhead of copying is negligible.

This is why passing by value works well for such basic types. Even though each element is copied, the cost is minimal.

## Passing by Value is Less Ideal for Complex Types

What happens when T is a more complex type, such as:

- std::string: Contains dynamically allocated memory.
- User-defined classes: Could include multiple members, dynamically allocated resources, or complex constructors/destructors.

When you pass a complex type by value, the copy operation involves:

- Copying all internal data: For something like a std::string, this may include copying dynamically allocated memory.
- Potentially invoking copy constructors: For user-defined classes, copying may involve running a copy constructor, which could be expensive if it involves deep copying internal resources.

In such cases:

- Performance overhead: Copying complex objects can be much slower, especially in loops where many copies are made.
- Unnecessary resource use: Creating temporary copies can lead to unnecessary memory usage and potential slowdowns.

## Conclusion

Passing by value works for basic types because copying them is cheap and straightforward. For complex types, copying is more expensive and potentially problematic, which is why passing by const T& is preferred—it’s more efficient and avoids unnecessary deep copies.

Passing by `const T&`:

> Avoids copying by passing a reference, which is just a pointer under the hood.
> Ensures that the function operates directly on the original object without creating unnecessary copies.
> Maintains immutability (const) so that the function cannot accidentally modify the original elements.

</details>