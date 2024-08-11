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
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
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
> [!NOTE]
> <details>
> <summary><strong>Why this difference between 'theoretical' and 'real' FLOAT_MAX?</strong></summary> 
Hidden content here 
> </details>
---