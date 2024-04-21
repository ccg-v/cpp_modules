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
This is what the OCF entails:
* **Default constructor:** A constructor that initializes an object with default values if no arguments are provided.
* 