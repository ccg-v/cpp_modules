#ifndef DEBUG_HPP
#define DEBUG_HPP

// #ifdef DEBUG_MODE
// #define DEBUG_PRINT(x) std::cout << x << std::endl;
// #else
// #define DEBUG_PRINT(x)
// #endif

// #endif

// #ifdef DEBUG_MODE
// #define DEBUG_PRINT(x) do { std::cout << x << std::endl; } while (0)
// #else
// #define DEBUG_PRINT(x) do { } while (0)
// #endif

#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) do { x; } while (0)
#else
#define DEBUG_PRINT(x) do { } while (0)
#endif


#endif