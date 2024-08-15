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
___
The challenge here lies in identifying the actual type of an object when the derived classes are empty and don’t have any members or methods that differentiate them. This is where the power of polymorphism and runtime type identification (RTTI) in C++ come into play
***
## Questions:
<details>
<summary><strong>Why `Base` class must have a public virtual destructor? And why ONLY?</strong></summary>

* **The Purpose of the Destructor in this Context**

    * **Polymorphic Deletion**: The main reason for having a virtual destructor in a base class is to ensure that when you delete an object through a pointer of the base class type (Base*), the destructor of the derived class is called correctly. This prevents resource leaks, especially when derived classes manage resources like dynamic memory, file handles, or other system resources.

    * **Dynamic Casting and Type Identification**: The virtual destructor also establishes the class as polymorphic. When a class has a virtual function (like a virtual destructor), it automatically contains a `vtable (virtual table)`. This `vtable` is crucial for dynamic casting, without it dynamic casting wouldn’t work.

* **Absence of a Constructor**

	* The presence of a destructor typically implies that objects of the class need special cleanup upon deletion. Without a constructor (or any other member functions), one might wonder what the destructor is actually managing.
	* In general, a class with a destructor should have a constructor, even if it’s just the default constructor.
    	* Constructors and destructors typically manage resources in tandem. Even if no resources are currently managed, it’s still a good design habit.
    	* A default constructor establishes how an object is initialized. Even if there’s no special initialization needed right now, you might add it later.
	* While the subject specifies that the Base class only needs a public virtual destructor, it’s unusual to have a destructor without a constructor. However, since the exercise explicitly allows you to avoid the Orthodox Canonical Form, it’s fine for this simplified context.

</details>


