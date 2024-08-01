In this version I tried unsuccessfully to move the try-catch blocks out from the main. I put just one within the parameterized constructor, but:

 * that forced me to modify the insertion operator overload, otherwise when the object is not created the insertion operator overload still displays its message with a huge random number as the grade value (because it has not been initialized)
 * the increment and decrement functions don't work.
 
According to the AI, the try-catch block in the constructor is catching and handling the exceptions locally, which prevents them from propagating to the calling code 

So I finally gave up and left the try-catch blocks in the main.