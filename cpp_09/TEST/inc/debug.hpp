#ifndef DEBUG_HPP
#define DEBUG_HPP

/* 
 *	This header defines a macro, DEBUG_PRINT(x), for general debugging purposes.
 *	 - If DEBUG_MODE is defined, x is executed; 
 *	 - Otherwise, it does nothing.
 * 
 *	'x' can be any statement (not just std::cout printing, also function calls):
 *		DEBUG_PRINT(std::cout << "Debugging enabled!" << std::endl);
 *		DEBUG_PRINT(printContainer()); 
 *
 *	When DEBUG_MODE is not defined, the 'do { } while (0)' ensures syntactic safety.
 *	For instance in an if-else structure:
 *
 *			if (condition)
 *				DEBUG_PRINT("Debug message");
 *			else
 *				doSomething();
 *
 *	If DEBUG_MODE is not defined, DEBUG_PRINT("Debug message"); expands to nothing.
 *	Though that would still be sintactcally correct, it could introduce logic bugs.
 *	To avoid that, we always expands into a single statement:
 *
 *			if (condition)
 *				do { } while (0);
 *			else
 *				doSomething();
 *
 *	The construct 'do { } while (0)' is a trick used in macros to ensure that the 
 *	macro expands into a single statement, regardless of its content. It executes
 *	the code inside { ... } exactly once. The condition while (0) is always false,
 *	so the loop never repeats.
 *
 *	If we are sure DEBUG_PRINT(x) is never going to be used inside an 'if-else'
 *	structure without braces, or in any other case that may potentially cause 
 *	syntax errors, a simpler version is:
 * 
 *			#ifdef DEBUG_MODE
 *				#define DEBUG_PRINT(x) x
 *			#else
 *				#define DEBUG_PRINT(x)
 *			#endif
 * 
 *	To enable the debugging mode, we can either
 *	 a) Define DEBUG_MODE at the top of one of the source files before including 
 *		 'debug.hpp', or
 *	 b) Define DEBUG_MODE at compile time using a compiler flag, -DDEBUG_MODE
 *		 (the first 'D' is a compiler option that tells the compiler to define a 
 *		 preprocessor macro.)
 */

 #ifdef DEBUG_MODE
  #define DEBUG_PRINT(x) do { x; } while (0)
 #else
  #define DEBUG_PRINT(x) do { } while (0)
 #endif

#endif

