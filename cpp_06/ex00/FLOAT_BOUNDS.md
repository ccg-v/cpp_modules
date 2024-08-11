# Finding the floating point number bounds

This small program finds if the provided argument is within the bounds of floating point numbers:
```
#include <iostream>
#include <string>
#include <cfloat>
#include <cstdlib>

void	toFloat(const std::string & literal) {

    char* end;
    double d_value = std::strtod(literal.c_str(), &end);
	if (d_value > FLT_MAX)
		std::cout << d_value << " is greater than FLT_MAX" << std::endl;
	else if (d_value == FLT_MAX)
		std::cout << d_value << " is equal to FLT_MAX" << std::endl;
	else		
		std::cout << d_value << " is smaller than FLT_MAX" << std::endl;
}

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')" << std::endl;
        return 1;
    }
    toFloat(argv[1]);
    return 0;
}
```
FLT_MAX is 340282346638528859811704183484516925440.0000000000000000f
> ./convert 340282346638528859811704183484516925440.0000000000000000f
>
> 3.40282e+38 is equal to FLT_MAX

If we pass the first float value out of range, FLT_MAX + 1, the program will consider it as a valid float:
> ./convert 340282346638528859811704183484516925441.0000000000000000f
>
> 3.40282e+38 is equal to FLT_MAX

In fact, we will have to increment in 18889465931478580854784.0 units the FLOAT_MAX to find the first value that overflows the float range.
This is the 'real' FLT_MAX:
>./convert 340282346638528878701170114963097780224.0000000000000000f
>
>3.40282e+38 is equal to FLT_MAX

And this is the first value that overflows float range:
>./convert 340282346638528878701170114963097780225.0000000000000000f
>
>3.40282e+38 is greater than FLT_MAX
---
<details>
<summary><strong>Why this difference between 'theoretical' and 'real' FLOAT_MAX?</strong></summary>

The behavior is related to the precision limits of floating-point numbers and the way they are represented in memory.
<strong>Explanation</strong>

The core issue here is the precision of floating-point numbers, particularly the float type in C++, which typically follows the IEEE 754 standard for single-precision floating-point numbers.
Key Points:

* Single-Precision Floating-Point (IEEE 754):
    A single-precision float (also known as float in C++) is represented by 32 bits: 1 bit for the sign, 8 bits for the exponent, and 23 bits for the significand (mantissa).
    This format provides around 6-7 decimal digits of precision, meaning that not all decimal numbers can be exactly represented.

* Representation of Large Numbers:
    The largest representable value for a float (which is FLT_MAX) is approximately 3.4028235×10383.4028235×1038.
    However, because of the limited precision (23 bits for the significand), ***any number that is close to FLT_MAX might get rounded off to the nearest representable float value***. This is why numbers that should theoretically be distinct might be represented as the same float value.

* Precision Loss:
    When you try to represent a number slightly larger than FLT_MAX, due to the rounding behavior, it might still be represented as FLT_MAX.
	This is why a number like 340282346638528859811704183484516925441.0000000000000000f (which is larger than FLT_MAX) might still be recognized as FLT_MAX due to precision loss and rounding.

* The Threshold:
        ***The threshold at which the program finally recognizes the number as greater than FLT_MAX happens when the number is large enough that the rounding doesn't bring it back to FLT_MAX, but instead to a representable number greater than FLT_MAX.***
        The difference between the "theoretical" maximum and the "real" maximum observed (18889465931478580854784) is because of this rounding. The number provided has exceeded the range where it can still be rounded to FLT_MAX and is instead rounded to a different number.

<strong>Conclusion:</strong>

***The difference arises from the finite precision of the float type. Numbers near FLT_MAX are so close in value that they may be represented as the same float due to rounding. Only when the input number is large enough that it rounds to a representable value greater than FLT_MAX will the program correctly identify it as out of range. This behavior is inherent to how floating-point arithmetic works in computers.***
</details>

<details>
<summary><strong>Can a number be considered close to another number that is 18,889,465,931,478,580,854,783 units bigger?</strong></summary> 

The crux of the matter lies in how floating-point precision works, particularly for very large numbers.

<strong>>Understanding Floating-Point Precision Near FLT_MAX</strong>

Floating-point numbers are represented using a binary system, and the precision of these numbers depends on their magnitude. For numbers close to FLT_MAX, the precision is not measured in absolute terms (like the difference of 1 or 10), but rather in relative terms or ulps (units in the last place).

* Significance of ulps at FLT_MAX

    * Unit in the Last Place (ulp): The smallest difference between two consecutive floating-point numbers is called an "ulp." For numbers near FLT_MAX, this difference becomes very large in absolute terms.
    Relative Precision: As the magnitude of the number increases, the absolute precision (the smallest difference that can be represented) decreases. Near FLT_MAX, the spacing between representable numbers is on the order of 21042104, or around 10^{31} in decimal form.

* Quantifying the "Closeness"

    * ***The large difference of 18889465931478580854783 you observed is small relative to the magnitude of FLT_MAX***. While it seems enormous in absolute terms, it is a very small fraction of FLT_MAX.
    To put it in perspective, FLT_MAX is approximately 3.4028235×10383.4028235×1038. The difference you observed is on the order of 10191019, which is about 19 orders of magnitude smaller than FLT_MAX. This means that the difference is small enough that the floating-point representation can't distinguish between FLT_MAX and numbers close to it within this range.

* Practical Implications

    * In the context of floating-point arithmetic, the term "close" is relative. Near FLT_MAX, the floating-point representation can no longer resolve small differences, leading to the phenomenon you're observing.
    The precision of float in this range is such that many large numbers are indistinguishable from one another because they map to the same floating-point representation.

<strong>Conclusion</strong>

***The difference of 18889465931478580854783 may seem huge in absolute terms, but in the context of floating-point arithmetic near FLT_MAX, it is indeed "close." This is why the program doesn't recognize the number as distinct from FLT_MAX until it exceeds this threshold, at which point the number is no longer rounded to FLT_MAX but to a different, larger representable value.***
</details>

<details>
<summary><strong>Is that difference of  18889465931478580854784 constant or it depends on the system?</strong></summary>

The difference of 18,889,465,931,478,580,854,784 is related to the precision of the float data type and is tied to the IEEE 754 standard for single-precision floating-point representation. This difference is determined by the number of bits used for the exponent and the significand, which are consistent across systems that use IEEE 754 single-precision floats.

* Is the Difference Constant?

    ***The difference is constant across all systems that use the IEEE 754 standard for single-precision floating-point numbers***. This is because the spacing between representable floating-point numbers, especially at the extreme ends of the range (near FLT_MAX), is determined by the bitwise structure of the float.

* Why Is It Constant?

    IEEE 754 Standard: The IEEE 754 standard specifies how floating-point numbers are represented in memory. A single-precision float uses 32 bits, with 1 bit for the sign, 8 bits for the exponent, and 23 bits for the significand (mantissa).
    Exponent and Significand Relationship: As the value of the exponent increases, the representable numbers become more widely spaced. Near FLT_MAX, the difference between consecutive representable values (in terms of their significand) is governed by the highest exponent value, leading to large gaps between representable numbers.

* System Independence

    Hardware and Compiler Independence: Since the IEEE 754 standard is widely adopted, the difference between FLT_MAX and the next representable float is independent of the specific hardware or compiler, as long as they adhere to this standard.

<strong>Conclusion</strong>

***The difference of 18,889,465,931,478,580,854,784 is a fundamental characteristic of the IEEE 754 single-precision floating-point format and is therefore constant across different systems. It reflects the limitations of precision at the extreme upper end of the float range, and is not influenced by the specific system on which the code is run.***
</details>