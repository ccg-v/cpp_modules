#ifndef DEBUG_HPP
#define DEBUG_HPP

#ifdef DEBUG_MODE
#define DEBUG_PRINT(x) std::cout << x << std::endl;
#else
#define DEBUG_PRINT(x)
#endif

#endif
