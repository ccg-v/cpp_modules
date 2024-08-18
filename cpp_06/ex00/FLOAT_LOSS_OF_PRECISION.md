# FLOATING POINT LOSS OF PRECISION IN CONVERSION PROCESSES

## Floating-Point Representation Overview

Both float (single-precision) and double (double-precision) follow the IEEE 754 standard:

* '**float**' (**single-precision**): 32 bits
	* 1 bit for the sign
	* 8 bits for the exponent
	* 23 bits for the mantissa (fraction)
* '**double**' (**double-precision**): 64 bits
	* 1 bit for the sign
	* 11 bits for the exponent
	* 52 bits for the mantissa (fraction)

A floating-point number is represented as:	   **value= <sup>(−1)</sup> sign × (1+mantissa) × 2<sup>exponent−bias</sup>**

---
## Conversion of 2147483649 to Float

Lets convert a number out of integer range to float type, for instance `(INT_MAX + 1)` = 2147483649

### 1. Representing in binary
* 2147483649 is represented in binary as ```10000000000000000000000000000001```
* This binary representation corresponds to `2^31 + 1`

### 2. Representing in float
* **Exponent Calculation**: In 'float', the exponent part is encoded with a `bias` of 127. For a number around 2^31, the exponent will be: ```Exponent = 31 + 127 = 158```

* **Mantissa Calculation**: To convert the integer to float, it first needs to be expressed in a normalized scientific notation format. In binary scientific notation: ```1.00000000000000000000001 × 2^31```

* The integer '**2147483649**' in binary is '**1.00000000000000000000001**' when normalized.

### 3. Round to Fit Mantissa

* The 'float' type has a 23-bit mantissa. Therefore, the binary representation of '2147483649' needs to be rounded to fit into 23 bits.
The float representation will be approximated to **1.00000000000000000000001×2<sup>31</sup>**

Here, the mantissa is truncated after the 23rd bit.

### 4. Binary Floating-Point Representation in Float

* **Exponent**: The exponent in binary for '**158**' is '**10011110**'.
* **Mantissa**: The mantissa (after truncation) is '**00000000000000000000000**'.

So, the float representation is:

* **Sign bit**: '**0**' (positive)
* **Exponent**: '**10011110**'
* **Mantissa**: '**00000000000000000000000**'

In IEEE 754 float format is ```0 10011110 00000000000000000000000```

### 5. Value of Float Representation

Convert this float representation back to decimal:
* The exponent 10011110 (binary) corresponds to 158 in decimal.
* The value represented is:  1 × 2<sup>31</sup> = 2147483648.0

---

## Conversion of double 2147483649.0 to Float

Now let's convert the same number but in double format, 2147483649.0, to float.

### Step 1: 'double' representation of '2147483649.0'

### 1. Binary representation
* 2147483649 is represented in binary as ```10000000000000000000000000000001```
* This binary representation corresponds to `2^31 + 1`

### 2. Exponent calculation
* **Exponent Calculation**: The position of the most significant bit is at position 31 (from right to left, starting at 0), so the exponent for this value is '**31**'.

### 3. Mantissa
* In 'double' , ***the mantissa can store up to 52 bits***. Here, the mantissa is:  ``1.00000000000000000000000000000001 (binary)```
* The leading 1 is implicit in the IEEE 754 format, so only the fractional part after the binary point is stored: ```0000000000000000000000000000000000000000000000000001```

### 4. Double representation
* **Sign bit**: 0 (positive number)
* **Exponent**: 31 + 1023 (bias[^1]) = 1054 (in binary: 10000011110)
* **Mantissa**: 0000000000000000000000000000000000000000000000000001
* So, the double value for 2147483649.0 is:  ```0 10000011110 0000000000000000000000000000000000000000000000000001```

### Step 2: Converting to 'float'

When converting to 'float', only 23 bits are available for the mantissa, which means significant precision is lost.

### 1. Truncation of Mantissa**: ***The original double mantissa has 52 bits, but float can only store 23 bits***. The truncated mantissa looks like this:  ```00000000000000000000000```. Notice that the last significant 1 in the double mantissa is lost because it falls beyond the 23-bit limit of float.

### 2. Float Representation:

* **Sign bit**: 0
* **Exponent**: '**31 + 127 (bias[^1]) = 158**' (in binary: '**10011110**')'
* **Mantissa**: '**00000000000000000000000**'

The float value now represents:  ```0 10011110 00000000000000000000000```

### 3. Resulting Value:

The float value corresponds to:  **1×2<sup>31</sup>=2147483648.0**

### Step 3: Analyzing the precision loss

* The original double value was '**2147483649.0**', but after converting to float, it is represented as '**2147483648.0**'.
* Why the Loss?: The least significant bit that differentiates '**2147483649.0**' from '**2147483648.0**' is lost because float doesn't have enough precision to store it. The mantissa in float is too small to capture that difference.

[^1]: The reason the ***bias*** is different is because of the difference in the number of bits allocated to the exponent. 'float' has 8 bits for the exponent, so a bias of 127 (which is 2<sup>7</sup> −1) is used. 'double' has 11 bits for the exponent, so a bias of 1023 (which is 2<sup>10</sup> − 1) is used.