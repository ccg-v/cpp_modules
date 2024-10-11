# Exercise 02: Mutated abomination
## Target

`std::stack` is the only STL container that is not iterable. To repair this injustice, the exercise asks to write a **MutantStack class** that must be implemented in terms of a `std::stack`, offering all of its members plus **an additional feature: iterators**

------------------------------------------------------------------

## Concepts

### `std::stack`

In C++98, ``std::stack`` is part of the **container adapters** group, which provides a more specialized interface for certain use cases. `std::stack` is not a container itself, but rather an **adapter** that operates on an underlying container like `std::deque`, `std::vector`, or `std::list`.

* `std::stack` provides a Last-In-First-Out (LIFO) data structure, where the last element added is the first to be removed.
* It operates only on the top of the stack, providing limited access (no iteration or random access to other elements).
* The underlying container that std::stack uses to store its elements can be one of the standard sequence containers (like `deque`, `vector`, or `list`), but by default, it uses `std::deque`.

* **Key Operations**:

    - `push()`: Adds an element to the top of the stack.
    - `pop()`: Removes the element from the top of the stack.
    - `top()`: Accesses the top element of the stack without removing it.
    - `empty()`: Returns true if the stack is empty.
    - `size()`: Returns the number of elements in the stack.

* **Key Characteristics**:

    - **Underlying Container**: You can specify the underlying container type when creating a `std::stack`, but it must support `push_back()`, `pop_back()`, and `back()` operations. Common choices are `std::deque` (default), `std::vector`, or `std::list`.
	- **Restricted Access**: Unlike `std::vector` or `std::deque`, you can only interact with the top element of a `std::stack`. There's no way to access elements in the middle or iterate through them.
	- **LIFO (Last-In-First-Out)**: This makes `std::stack` suitable for algorithms where you need to process the most recently added element first (such as recursive algorithms or tracking states)

* **Conclusion**:

`std::stack` in C++98 is useful when you need a simple LIFO structure. It’s a container adapter, meaning it doesn’t have iterators or random access, and you can only interact with the most recently added element. If you need to iterate over or access elements elsewhere in the sequence, you should use the underlying container (like `std::deque` or `std::vector`) directly instead.

In C++98, in addition to `std::stack`, there are two other container adapters:

## `std::queue`

A `std::queue` is a FIFO structure, where elements are added to the back and removed from the front. It's useful for algorithms where the order of processing needs to follow the order of insertion.
* **Key Operations**:
	* `push()`: Adds an element to the back of the queue.
	* `pop()`: Removes the front element.
	* `front()`: Accesses the front element (without removing it).
	* `back()`: Accesses the back element (without removing it).
	* `empty()`: Returns true if the queue is empty.
	* `size()`: Returns the number of elements in the queue.

* **Underlying Container**: By default, `std::queue` uses `std::deque`, but you can also specify other containers like `std::list`. However, the container must support `push_back()` and `pop_front()` operations.

## `std::priority_queue`

`std::priority_queue` is a container adapter that provides a max-heap structure, where the largest element is always accessible at the front. It's a sorted structure where the highest-priority element (largest by default) is processed first.

* **Key Operations**:

	* `push()`: Inserts an element and maintains heap order.
	* `pop()`: Removes the largest element (front of the queue).
	* `top()`: Accesses the largest element without removing it.
	* `empty()`: Returns true if the queue is empty.
	* `size()`: Returns the number of elements in the queue.

* **Underlying Container**: By default, `std::priority_queue` uses `std::vector`, but you can also specify other containers like `std::deque`. The container must support random access iterators, like those provided by `std::vector`.

* **Custom Comparison**: You can customize the priority (i.e., sorting criteria) by providing a custom comparator function. By default, it uses ``std::less``, which makes the largest element the highest priority.

## Summary::

* `std::stack`: LIFO, processes the most recent element first.
* `std::queue`: FIFO, processes the oldest element first.
* `std::priority_queue`: Processes the highest-priority (largest by default) element first using a binary heap.

These adapters have restricted access compared to other containers but are tailored for specific use cases, and they rely on an underlying sequence container like `std::vector`, `std::deque`, or `std::list`.
