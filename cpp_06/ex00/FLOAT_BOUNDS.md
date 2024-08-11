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
    However, because of the limited precision (23 bits for the significand), <strong>any number that is close to FLT_MAX might get rounded off to the nearest representable float value</strong>. This is why numbers that should theoretically be distinct might be represented as the same float value.

* Precision Loss:
    When you try to represent a number slightly larger than FLT_MAX, due to the rounding behavior, it might still be represented as FLT_MAX.
	This is why a number like 340282346638528859811704183484516925441.0000000000000000f (which is larger than FLT_MAX) might still be recognized as FLT_MAX due to precision loss and rounding.

* The Threshold:
        <strong>The threshold at which the program finally recognizes the number as greater than FLT_MAX happens when the number is large enough that the rounding doesn't bring it back to FLT_MAX, but instead to a representable number greater than FLT_MAX.</strong>
        The difference between the "theoretical" maximum and the "real" maximum observed (18889465931478580854784) is because of this rounding. The number provided has exceeded the range where it can still be rounded to FLT_MAX and is instead rounded to a different number.

<strong>Conclusion:</strong>

The difference arises from the finite precision of the float type. Numbers near FLT_MAX are so close in value that they may be represented as the same float due to rounding. Only when the input number is large enough that it rounds to a representable value greater than FLT_MAX will the program correctly identify it as out of range. This behavior is inherent to how floating-point arithmetic works in computers. 
</details>
.
---
<details>
<summary><strong>Second question?</strong></summary> 
Hidden content here 
</details>
---
<details>
<summary><strong>Third question?</strong></summary> 
Hidden content here 
</details>
---