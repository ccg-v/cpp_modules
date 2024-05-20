# Exercise 00: Polymorphism

## 1. Inheritance and Virtual Functions
### Non-virtual functions
In C++ inheritance, when you derive a class from a base class, the derived class inherits all the base class's members (both data members and member functions). Member functions in the base class are *non-virtual* by default, and the derived class inherits them just like it inherits data members.

When you call a *non-virtual* function on a derived class object through a base class pointer or reference, the function that gets called is the one defined in the base class, not the one in the derived class (if any). This is known as *static binding* or early binding.

### Virtual functions
However, when you declare a member function as *virtual* in the base class, it tells the compiler to perform *dynamic binding* (or late binding) for that function. This means the function call is resolved at runtime, allowing the derived class's overridden function to be called even when you use a base class pointer or reference.

## 2. Virtual Destructors
When you use polymorphism and dynamic binding (with virtual functions), it's crucial to *declare the base class destructor as virtual*. This ensures that the correct destructor for the derived class is called when an object is deleted through a base class pointer. If the base class is not virtual, only the base class destructor will be called, resulting in a resource leak because the derived class constructor has not been called. By making the destructor *virtual*, you ensure that the derived class's destructor is called first, followed by the base class's destructor.