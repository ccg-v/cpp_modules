# Exercise 01: Iter

The subject asks to create the function `iter` as a general-purpose tool for iteration. It’s the responsibility of the user of iter to define what the operation is by providing the appropriate function. The function iter just needs to iterate over the array and apply that function to each element.

Therefore, the `iter` function doesn’t need to define a specific operation that works for every type. It just needs to be capable of accepting any operation (through the third parameter) and applying it to every element in the array, regardless of the type. This is why templates and function pointers are used—they allow the flexibility to handle any type of array and any operation.