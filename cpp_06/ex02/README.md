# Exercise 02: Identify real type

* **Objective**: 
	* Implement a base class with specific functionality and derive three empty classes from it. Use type identification techniques to determine the type of objects at runtime.

* **Constraints**:
	* Derived classes must be empty, meaning they do not contain any data members or additional methods beyond what’s required for inheritance.
    * The identification functions must handle the type checking without using the typeinfo header or modifying the derived classes.

* **Key points**:
	* Virtual Destructor: Ensures proper cleanup of derived class objects through base class pointers.
	* Dynamic Casting: Allows runtime type checking to determine the actual type of an object.
	* Empty Derived Classes: Maintain the constraint that derived classes are empty by not adding extra members or methods.

This exercise helps in understanding polymorphism, dynamic type identification, and adhering to specific constraints while designing classes in C++.

Read the subject [**here**](https://github.com/ccg-v/cpp_modules/blob/master/cpp_06/cpp06_subject.pdf)
***

## Questions:
<details>
<summary><strong>Why <i>`Base`</i> class must have a public virtual destructor? And why ONLY?</strong></summary>

* **The Purpose of the Destructor in this Context**

    * **Polymorphic Deletion**: The main reason for having a virtual destructor in a base class is to ensure that when you delete an object through a pointer of the base class type (Base*), the destructor of the derived class is called correctly. This prevents resource leaks, especially when derived classes manage resources like dynamic memory, file handles, or other system resources.

    * **Dynamic Casting and Type Identification**: The virtual destructor also establishes the class as polymorphic. When a class has a virtual function (like a virtual destructor), it automatically contains a `vtable (virtual table)`. This `vtable` is crucial for dynamic casting, without it dynamic casting wouldn’t work.

* **Lack of Constructor**

	* The presence of a destructor typically implies that objects of the class need special cleanup upon deletion. Without a constructor (or any other member functions), one might wonder what the destructor is actually managing.
	* In general, a class with a destructor should have a constructor, even if it’s just the default constructor.
    	* Constructors and destructors typically manage resources in tandem. Even if no resources are currently managed, it’s still a good design habit.
    	* A default constructor establishes how an object is initialized. Even if there’s no special initialization needed right now, you might add it later.
	* While the subject specifies that the Base class only needs a public virtual destructor, it’s unusual to have a destructor without a constructor. However, since the exercise explicitly allows you to avoid the Orthodox Canonical Form, it’s fine for this simplified context.

</details>

<details>
<summary><strong><i>`generate()`</i> and <i>`identify()`</i> must be member methods of Base class?</strong></summary>

No, in fact it’s more appropriate to implement them as non-member functions for the following reasons:

1. Design Separation:
    * The generate() function’s purpose is to randomly instantiate one of the derived classes (A, B, or C). Since it’s a utility function that deals with object creation and returns a pointer to Base, it doesn’t have to be tightly coupled with the Base class. It’s more of a utility related to the inheritance hierarchy rather than functionality specific to the Base class itself.
    The two identify() functions are also utilities that identify the type of an object derived from Base. These functions operate on objects of type Base, but they don’t need to be part of Base. They don’t change the state of Base objects, and they serve more as external tools that analyze the objects.

2. Simplicity and Clarity:
    * Making these functions non-member functions simplifies the Base class. The Base class can remain focused solely on being a polymorphic base class with a virtual destructor, as specified in the exercise.
    You’re not burdening the Base class with utility logic that’s unrelated to its core purpose.
</details>

<details>
<summary><strong>If derived classes are empty, how can we identify their types?</strong></summary>

The challenge here lies in identifying the actual type of an object when the derived classes are empty and don’t have any members or methods that differentiate them. This is where the power of polymorphism and runtime type identification (RTTI)[^1] in C++ come into play.

* **Identifying the Type Using a Pointer**

	* `dinamic_cast`: You can use dynamic casting to determine the actual type of the object at runtime. In C++, `dynamic_cast` allows you to safely cast a pointer from a base class to a derived class. 
		* If the cast is valid (i.e., the object is actually of the derived type), the cast succeeds.
		* If it’s not valid, it returns NULL (C++98) or nullptr (C++11 and later).

	* **Why This Works**: When you declare a class with a virtual function (like the virtual destructor in Base), the compiler generates a `vtable`(virtual table) for that class, allowing `dynamic_cast` to work. The `vtable` stores information about the actual type of the object, enabling runtime identification.

* **Identifying the Type Using a Reference**

	* In this case, you’re dealing with a reference, so you don’t have the option to use pointers or dynamic_cast directly. Instead, the best approach is to use try-catch exception handling combined with dynamic_cast.

    * When you use dynamic_cast with references, it will throw a `std::bad_cast` exception if the cast fails. This gives you a way to identify the type by attempting to cast to each derived type inside a try-catch block:
		- If the cast is successful, you can print the corresponding type.
    	- If the cast fails, catch the exception and continue with the next type.

	* The `std::bad_cast` exception is available in in the <typeinfo> header, but based on the exercise instructions, we are not allowed to include this header. Instead, we can use `std::exception`, which is a base class for all standard exceptions, to catch exceptions thrown by `dynamic_cast`
</details>

[^1] * RTTI allows a program to determine the type of an object during execution. This is useful for operations such as dynamic type checking, especially in cases where the actual type of an object needs to be known at runtime. It requires at least one virtual function in the base class (commonly a virtual destructor). This is because the virtual table (vtable) mechanism is used to store type information.
* RTTI is closely associated with polymorphism. When a base class declares a virtual destructor or virtual methods, RTTI information is available for objects of derived classes. This allows the program to identify and interact with derived types through base class pointers or references.
* Key RTTI Features:
    * `dynamic_cast`: This operator is used for safely downcasting (casting from a base class pointer/reference to a derived class pointer/reference). If the cast fails, dynamic_cast will return NULL for pointers or throw std::bad_cast for references. RTTI is used to check the actual type of the object at runtime.
    * `typeid`: This operator provides information about the type of an object or type information object. It returns a std::type_info object, which can be used to compare types or retrieve type names.