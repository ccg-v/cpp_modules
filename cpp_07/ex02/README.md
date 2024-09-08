# Exercise 02: Array

## Class templates

A class template in C++ is a blueprint for creating classes that can operate with any data type. It's similar to a function template, but it defines an entire class rather than just a single function. The idea is to write a class that can handle different data types while avoiding code duplication.

Here’s a simple example to illustrate:

```
template <typename T>
class MyClass {
public:
    MyClass(T value) : data(value) {}
    T getData() const { return data; }
private:
    T data;
};
```

- `template <typename T>` is the syntax used to define a class template.
- `T` is a placeholder for the data type that will be specified when an instance of the class is created.
- The class MyClass can now work with any type (like int, float, std::string, etc.) when instantiated.

Even though the class template can work with multiple types, it remains type-safe. You can't mix types unless explicitly allowed by the design.
lass templates are especially useful when you want to create data structures or algorithms that are not dependent on a specific type. For example, containers like `std::vector`, `std::list`, and `std::map` in the C++ Standard Library are implemented using class templates.

## Template Implementation File (.tpp)

 It's used to store the **template function/method definitions** when working with class templates, keeping the separation of declaration and definition that is usually required in C++ while still ensuring that template definitions are available to the compiler when needed.

> [!NOTE]
> The .tpp file must be included **at the end** of the header file

Template implementation files are not a source file. They are typically included in header files and should not be compiled directly into an object file (i.e., no .o should be generated from them). The inclusion of the .tpp file is handled by the .hpp file when you include it in the main.cpp file.