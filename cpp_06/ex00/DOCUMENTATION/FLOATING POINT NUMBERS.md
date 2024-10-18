# UNDERSTANDING FLOATING POINT NUMBERS

## The Trick: ific Notation

Scienfific notation is a way of writing very big or very small numbers more compactly. For example:

* 10000 can be written as 1 × 10⁴.
* 0.0001 can be written as 1 × 10⁻⁴.

Here, the "1" is called the "significant digit" (or "mantissa"), and the "4" (or "-4") is the "exponent." The exponent tells us how many places to move the decimal point.

## How Computers use this

Computers store floating point numbers in a similar way to scientific notation:

* **Significant Digit** (**Mantissa**): This is the main part of the number (like the "1" in our examples).
* **Exponent**: This tells the computer where to move the decimal point (like the "4" or "-4" in our examples).

For 10000:

* The computer would store "1" as the significant digit.
* It would store "4" as the exponent, meaning "move the decimal point 4 places to the right," giving us 10000.

For 0.0001:

* The computer would store "1" as the significant digit.
* It would store "-4" as the exponent, meaning "move the decimal point 4 places to the left," giving us 0.0001.

By using this method, the computer can handle both very large and very small numbers efficiently without needing a lot of space. It just keeps track of two things: the significant digit and the exponent. This way, instead of storing a bunch of zeros, it just stores a small, compact representation of the number.

## The structure of a floating point number

A floating point number in a computer is usually stored in a specific format. The most common format is based on the IEEE 754 standard. This standard defines how to represent floating point numbers in binary (the language of computers, using just 0s and 1s). Here’s the general structure:

* **Sign bit**: 1 bit
* **Exponent**: Several bits (depends on the precision)
* **Mantissa** (**Significant digit**): Several bits

For simplicity, let's talk about a common format: **32-bit single precision**.

### 1. The Sign bit

The sign bit is the simplest part. It’s just one bit (0 or 1):

* 0 means the number is positive.
* 1 means the number is negative.

Example: For +5.75, the sign bit would be 0; for -5.75, it would be 1.

### 2. The Exponent

The exponent part is what moves the decimal point. It’s stored in a special way called ***"biased exponent"***. Instead of storing the exponent as a positive or negative number directly, the computer adds a *bias* (a fixed number) to the exponent to make it easier to store in binary.

For single precision (32-bit):
* The exponent is 8 bits long.
* The bias for single precision is 127. This means if you have an exponent of +3, you actually store 3 + 127 = 130.

### 3. The Mantissa (Significant Digits)

The mantissa represents the actual digits of the number, but in binary (0s and 1s). In floating point representation, the mantissa assumes there is a leading "1." This is called the ***"implicit leading bit"***.

For single precision:
* The mantissa is 23 bits long.
* Example: The decimal number 5.75 has a binary mantissa of 1.011. In the computer, it’s stored as 011 (the leading 1 is implicit).

### 4. Putting it all together"

Let's store the number 5.75 in a 32-bit single precision floating point format.

* **Step 1: Convert 5.75 to binary**
    * 5 is 101 in binary.
    * 0.75 is 0.11 in binary (0.5 + 0.25 = 0.75).
    * So, 5.75 = **101.11** in binary.

* **Step 2: Normalize the binary number**
    * Normalize means to shift the binary point so it’s just after the first 1: **1.0111 × 2²**.
    * Here, the significant part is **1.0111** and the exponent is **2**.

* **Step 3: Fill in the floating point format**
    * **Sign bit**: Since 5.75 is positive, sign = **0**.
    * **Exponent**: The exponent is 2. In single precision, you add the bias (127) to this: 2 + 127 = **129**. In binary, 129 is **10000001**.
    * **Mantissa**: The mantissa stores the fraction part after the binary point, without the leading 1: **01110000000000000000000** (23 bits).

* **Final stored value**:
    * **Sign bit**: 0
    * **Exponent**: 10000001
    * **Mantissa**: 01110000000000000000000

So, the computer would store the number 5.75 as:

**0 10000001 01110000000000000000000**

## Summary

* Sign bit tells whether the number is positive or negative.
* Exponent shifts the decimal point to make the number larger or smaller.
* Mantissa stores the significant digits of the number in binary.

This is how the computer can store a wide range of numbers efficiently using floating point representation