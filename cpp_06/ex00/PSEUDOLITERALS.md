# PSEUDOLITERALS

The pseudoliterals +inf, -inf, +inff, -inff, nan, and nanf are often used in programming languages like C and C++ to represent special floating-point values.

1. **`+inf` and `-inf`**:

	* These represent positive infinity (+inf) and negative infinity (-inf).
	* They are typically the result of mathematical operations that exceed the representable range of a floating-point number.

    	- Example: Dividing a positive number by zero results in positive infinity (+inf).
    	- Example: Dividing a negative number by zero results in negative infinity (-inf).

2. **`+inff` and `-inff`**:

    * These are similar to +inf and -inf but are specifically for single-precision floating-point numbers (32-bit).
    * The extra f indicates that the literals are meant for floats rather than doubles (which are usually 64-bit).

3. **`nan`**:

    * nan stands for "Not a Number".
    * It is used to represent undefined or unrepresentable values, especially in cases of invalid mathematical operations like taking the square root of a negative number or dividing zero by zero.
    * nan is a special floating-point value defined by the IEEE 754 standard.

4. **`nanf`**:

    * Similar to nan, but specifically for single-precision (32-bit) floating-point numbers.

In C and C++, you might see these literals used when working with floating-point operations, especially when dealing with edge cases where operations could result in overflows or undefined results.

For example:
```
#include <iostream>
#include <cmath>

int main() {
    double positive_inf = 1.0 / 0.0;  // Results in +inf
    double negative_inf = -1.0 / 0.0; // Results in -inf
    double not_a_number = 0.0 / 0.0;  // Results in nan
    
    std::cout << "Positive infinity: " << positive_inf << std::endl;
    std::cout << "Negative infinity: " << negative_inf << std::endl;
    std::cout << "NaN: " << not_a_number << std::endl;
    
    return 0;
}
```
* The values of `+inf`, `-inf`, and `nan` are defined by the IEEE 754 standard for floating-point arithmetic, which ensures that these special values behave consistently across platforms.

	* Operations with `+inf` and `-inf`:
        Adding or multiplying by infinity follows intuitive rules (e.g., 1 + inf = inf, -inf * 2 = -inf).
	* Operations with `nan`:
        Any operation involving nan typically results in nan, as it indicates an indeterminate or invalid result.

## Summary:
* These literals are mainly used when working with floating-point operations to handle edge cases correctly and are a part of many modern programming languages.

>    * `+inf` and `-inf` represent infinite values.
>    * `+inff` and `-inff` are the same but for single-precision floats.
>    * `nan` represents "Not a Number", used for undefined results.
>    * `nanf` is the single-precision equivalent of nan.

