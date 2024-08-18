# FLOATING POINT LOSS OF PRECISION IN CONVERSION PROCESSES

Lets convert a number out of integer range to float type, for instance `(INT_MAX + 1)` = 2147483649

## Conversion of 2147483649 to Float

### 1. Representing in binary
* 2147483649 is represented in binary as 
	- ```10000000000000000000000000000001```
* This binary representation corresponds to `2^31 + 1`

### 2. Representing in float
* **Exponent Calculation**: In 'float', the exponent part is encoded with a `bias` of 127. For a number around 2^31, the exponent will be:
	- ```Exponent = 31 + 127 = 158```

* **Mantissa Calculation**: To convert the integer to float, it first needs to be expressed in a normalized scientific notation format. In binary scientific notation:
	- ```1.00000000000000000000001 × 2^31```
The integer '**2147483649**' in binary is '**1.00000000000000000000001**' when normalized.

### 3. Round to Fit Mantissa

* The 'float' type has a 23-bit mantissa. Therefore, the binary representation of '2147483649' needs to be rounded to fit into 23 bits.
The float representation will be approximated to
- **1.00000000000000000000001×2<sup>31</sup>**

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
* The value represented is:
	1 × 2^31 = 2147483648.0

