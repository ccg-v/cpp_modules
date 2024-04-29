# Exercise 01: Towards a more useful fixed-point number class

## Conversions
### Integer to fixed-point
*Find fixed-point value for int_value = 5, fractional_bits = 8*
```
	scale_factor = 2^fractional_bits = 2^8 = 256
	fp_value = int_value * scale_factor = 5 * 256 = 1280
```
<h4> Scaling up the integer (multiplying it by a scale factor) is indeed shifting its binary representation to the left, increasing its precision.</h4> 


### Integer to float-point
