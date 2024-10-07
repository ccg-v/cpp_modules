# Exercise 01: Span
 ## Target
 Create a `Span` class that:
 * Stores a maximum of N integers
 * Implements the following member functions:
	- `addNumber()`: adds a single number to the Span each tieme it is called. If the `Span` is full (it already has N elements) the function must throw an exception.
	- `shortestSpan()` and `longestSpan()`: They must respectively find out the shortest span or the longest span (distance) between all the numbers stored, and return it. If there are no numbers stored, or only one, no span can be found. Thus, throw an exception.
	- A member function that adds many numbers to the Span in just one call, using a **range of iterators**. The idea is allow fillig the `Span` with a huge amount of numbers without having to make thousands of calls to `addNumber()`.

-----------------------------------------------------------------------------------------------------------------------------------

<details>
<summary><h3> Why create a new class to store integers if standard containers do the same job? </h3></summary>
The Span class will not only store integers but also implement logic for:

* Limiting the number of elements (N).
* Providing additional functionality like `shortestSpan()` and `longestSpan()`.
* Controlling the behaviour and throw proper exceptions if necessary

While the container can store integers, it doesn't inherently provide the logic to enforce a size limit or calculate spans. The Span class will encapsulate these behaviors into a single, reusable unit. This is an example of object-oriented design, where you create a class with both state (data) and behavior (methods).
</details>

<details>
<summary><h3> Why using a container instead of a C-style array? </h3></summary>

**1. Dynamic Sizing**

* C-Style Array: Fixed size once declared. You have to know the size at compile-time or allocate memory dynamically, which makes it inflexible if the size of the array could change or if it's based on runtime input.
* Container:  Containers are dynamically sized, meaning you can start with an empty container and add elements as needed. In the case of our Span class, we can add numbers dynamically, and the vector will automatically manage memory for us. This saves us from handling low-level memory management or reallocating arrays ourselves.

**2. Built-In Functionality**

* C-Style Array: C-style arrays are quite primitive and don’t provide many utilities. For instance, you’d need to manually track the number of elements and write your own code to resize or shift elements.
* Container: You get rich functionality out of the box:
	- Automatic resizing: You don’t need to manage memory manually.
	- Iterators: You can easily iterate over the elements using iterators, making it more compatible with the rest of the C++ Standard Library.

**3. Memory Management**

* C-Style Array: If you use a dynamic array (allocated with `new`), you'll need to manually manage memory allocation and deallocation. This introduces potential risks of memory leaks or buffer overflows if not done properly.
* Container: Handles all memory allocation and deallocation for you. When a container goes out of scope, it automatically frees the allocated memory. This makes your code cleaner and reduces the chances of memory errors.

**4. Exception Safety**

* C-Style Array: There's no built-in mechanism to handle errors, and if you access out-of-bounds elements, you're in undefined behavior territory.
* Container: Provides exception safety mechanisms and it throws exceptions when issues arise, allowing you to handle errors more gracefully.

**5. Standard Library Integration**

* C-Style Array: If you use a C-style array, you might find it harder to integrate with C++ standard algorithms (e.g., std::sort, std::min_element, std::max_element).
* Container: Is well integrated with C++ algorithms, so calculating things like spans (e.g., finding the minimum or maximum difference between elements) becomes much easier. 

</details>

<details>
<summary><h3> What is a range of iterators? </h3></summary>

A range of iterators is a way to refer to a sequence of elements between two iterators: a **beginning iterator** and an **ending iterator**. Many functions in the C++ Standard Library (including container member functions) allow you to specify a range of elements by providing these two iterators.

For example:

* The range `[vec.begin(), vec.end()]` represents all elements in a vector.
* The range `[vec.begin(), vec.begin() + 5]` would represent the first 5 elements of the vector.

C++ containers often have member functions that accept iterator ranges. For example, `std::vector` has an `insert()` function that can take a pair of iterators and insert all the elements in the range between those iterators.

```
std::vector<int> vec1 = {1, 2, 3, 4, 5};
std::vector<int> vec2;

// Insert elements from vec1 into vec2 using iterators
vec2.insert(vec2.begin(), vec1.begin(), vec1.end());
```

</details>