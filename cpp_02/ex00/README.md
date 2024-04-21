# Exercise 00: My First Class in Orthodox Canonical Form

## Target
Learn about the Orthodox Canonical Form for classes, and the fixed-point numbers.

## Subject
Create a class in Orthodox Canonical Form that represents a fixed-point number:

* Private members:
  * An integer to store the fixed-point number value.
  * A static constant integer to store the number of fractional bits. Its value will always be the integer literal 8.
* Public members:
  * A default constructor that initializes the fixed-point number value to 0.
  * A copy constructor.
  * A copy assignment operator overload.
  * A destructor.
  * A member function int getRawBits( void ) const; that returns the raw value of the fixed-point value.
  * A member function void setRawBits( int const raw ); that sets the raw value of the fixed-point number.

## Theory
The Ortodox Canonical Form (OCF) is a set of guidelines for defining well-behaved and predictable classes in C++. It ensures the class will be easily used and integrated in other code. 
The standard C++98 and before OCF consists of four member functions:
* **Default constructor:** A constructor that initializes an object with default values if no arguments are provided.
* **Copy Constructor:** Creates a new object that is a copy of an existing object.
* **Copy Assignment Operator:** Assigns the value of one object to another existing object.
* **Destructor:** Called when an object is destroyed to clean up any resource it holds.

C++11 and later include two additional member functions, a Move Constructor and a Move Assignement Operator, but we are focusing on C++98 standard for now.

Here's an example of OCF:
```
class Person {
private:
    std::string name; // name of the person
    int age; // age of the person
public:
    // default constructor
    Person() : name(""), age(0) {}

    // copy constructor
    Person(const Person& source) : name(source.name), age(source.age) {}

    // copy assignment operator
    Person& operator=(const Person& other) {
        if (this != &other) { // avoid self-assignment
            name = other.name;
            age = other.age;
        }
        return *this;
    }
```
- The Default Constructor ensures private members are initialized with default values.
- The Copy Constructor provides a mechanism to create a new 'Person' instance as a copy of an existing one ('source'), maintaining data integrity and separation between objects.
```
Person p1("Alice", 30);
Person p2 = p1;	// Copy Constructor is called here to create p2 as a copy of p1
```
- The Copy Assignment Operator modifies an existing object to become a copy of another object of the same class.
```
Person p1("Alice", 30);
Person p2;
p2 = p1;	// Copy assignment operator is called here to assign p1's data to p2
```
The difference is that _the copy constructor creates a new copy, while the copy assignment operator modifies an existing object_. 
The provided code example defines a custom copy assignment operator because calling it explicitly is not needed. However, an explicit call would be:
```
Person p1("Alice", 30);
Person p2;

// Explicit call to copy assignment operator using member function syntax
p2 = p1.operator=(p1);
```