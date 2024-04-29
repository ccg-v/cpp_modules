# Exercise 01: Towards a more useful fixed-point number class

## Conversions
### Integer to fixed-point
Involves scaling the integer by a scale factor, typically a power of 2, to represent fractional parts. For example, if you have an integer 'x' and you want to represent it with 'n' fractional bits, you multiply 'x' by '2^n' to get the fixed-point representation;

Ex: *Find fixed-point value for integer int_value = 5, fractional_bits = 8*
```
scale_factor = 2^fractional_bits = 2^8 = 256
fp_value = int_value * scale_factor = 5 * 256 = 1280
```
<h6>Indeed, scaling up the integer (multiplying it by a scale factor) is shifting its binary representation to the left, increasing its precision 

```
int_value 5 is binary 101
After shifting the 'fractional_bits' (8) to the left, int_value is 10100000000, in decimal 1280
```
</h6>

### Integer to float-point
*Find float-point value for integer int_value= 