# Exercise 01: Reverse Polish Notation

## Target

Create a program that takes as an argument a mathematical expression written in Reverse Polish Notation, does the calculation and displays the result. 
- Operands in the expression must be digits (0-9) and operators are limited to '+ - * /". 
- Errors during the program execution must be displayed in the standard output.
- Brackets and decimal numbers don't have to be handled
- At least one container must be used to validate the exercise.

Example:
```
	$> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	42
```

> [!WARNING]
> The type of container(s) chosen for this exercise **must not be the one used in the previous exercise** and **will not be usable for the next one!**

## Reverse Polish Notation

**Polish Notation**, in which the operator comes before the operands, was invented in the 1920s by the Polish mathematician Jan Lucasiewicz.

In the late 1950s, Australian philosopher and computer scientist Charles L. Hamblin suggested placing the operator after the operands and hence created **Reverse Polish Notation**. Also known as **postfix notation**, contrasts with the **"infix notation"** of standard arithmetic expressions in which the operator symbol appears between the operands.

Reverse Polish Notation validation rules:

- Operands and Operators: In RPN, numbers (operands) appear before the operators that use them.
- Operator Requirements: Each binary operator (like *, +, -, /) needs two operands available in the container to apply the operation.
- Result: At the end of a valid RPN expression, there should be exactly one value left in the container (the result).

<details>
<summary><h3> Hint </h3></summary>

The RPN calculation relies heavily on a stack-like behavior (LIFO – last in, first out), where operands are pushed onto a container, and two operands are popped for each operator encountered.

RPN can be conveniently evaluated using a stack structure. Reading the expression from left to right, the following operations are performed:

1. If a value appears next in the expression, **push** this value on to the stack.

2. If an operator appears next, **pop** two items from the top of the stack and **push** the result of the operation on to the stack.

</details>

-----------------------------------
## Flow chart
<p align="center">
	<img src="assets/RPN.svg" />
</p>