
#include <iostream>
#include <string>
#include <cfloat>
#include <cstdlib>
// #include <cerrno>
// #include <cmath>
// #include <cstring>

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

// bool isGreaterThanAbs(const char* str, const char* limit) {
//     // Skip leading whitespace and plus sign
//     while (*str == ' ' || *str == '+') str++;
//     while (*limit == ' ' || *limit == '+') limit++;
    
//     // Handle negative numbers
//     bool str_negative = (*str == '-');
//     bool limit_negative = (*limit == '-');
//     if (str_negative) str++;
//     if (limit_negative) limit++;
    
//     // Skip leading zeros
//     while (*str == '0') str++;
//     while (*limit == '0') limit++;
    
//     // Compare number of digits before the decimal point
//     const char* str_decimal = std::strchr(str, '.');
//     const char* limit_decimal = std::strchr(limit, '.');
//     size_t str_int_len = str_decimal ? (str_decimal - str) : std::strlen(str);
//     size_t limit_int_len = limit_decimal ? (limit_decimal - limit) : std::strlen(limit);
    
//     if (str_int_len != limit_int_len)
//         return str_int_len > limit_int_len;
    
//     // If same number of digits, compare lexicographically
//     int cmp = std::strncmp(str, limit, str_int_len);
//     if (cmp != 0)
//         return cmp > 0;
    
//     // If integer parts are equal, check decimal part
//     if (str_decimal && limit_decimal) {
//         str_decimal++;
//         limit_decimal++;
//         while (*str_decimal && *limit_decimal) {
//             if (*str_decimal != *limit_decimal)
//                 return *str_decimal > *limit_decimal;
//             str_decimal++;
//             limit_decimal++;
//         }
//         // If there are more non-zero digits, it's greater
//         while (*str_decimal) {
//             if (*str_decimal != '0' && *str_decimal != 'f' && *str_decimal != 'F')
//                 return true;
//             str_decimal++;
//         }
//     }
    
//     return false;  // Equal to limit is not greater than limit
// }

// void checkFloat(const char* literal) {
//     const char* flt_max = "340282346638528859811704183484516925440.0";
    
//     // Check if it's a special value
//     if (std::strcmp(literal, "inf") == 0 || std::strcmp(literal, "+inf") == 0 ||
//         std::strcmp(literal, "infinity") == 0 || std::strcmp(literal, "+infinity") == 0) {
//         std::cout << literal << " is greater than FLT_MAX" << std::endl;
//         return;
//     }
//     if (std::strcmp(literal, "-inf") == 0 || std::strcmp(literal, "-infinity") == 0) {
//         std::cout << literal << " is less than -FLT_MAX" << std::endl;
//         return;
//     }
    
//     bool is_negative = (literal[0] == '-');
//     const char* abs_literal = is_negative ? literal + 1 : literal;
    
//     if (isGreaterThanAbs(abs_literal, flt_max)) {
//         std::cout << literal << (is_negative ? " is less than -FLT_MAX" : " is greater than FLT_MAX") << std::endl;
//     } else {
//         char* end;
//         errno = 0;
//         float f_value = std::strtof(literal, &end);
//         if (errno == ERANGE) {
//             if (f_value == HUGE_VALF) {
//                 std::cout << literal << " overflows float (too large)" << std::endl;
//             } else if (f_value == -HUGE_VALF) {
//                 std::cout << literal << " overflows float (too small)" << std::endl;
//             } else if (f_value == 0) {
//                 std::cout << literal << " underflows float" << std::endl;
//             }
//         } else if (end == literal) {
//             std::cout << literal << " is not a valid float" << std::endl;
//         } else {
//             std::cout << f_value << " is within float range" << std::endl;
//         }
//     }
// }

int main(int argc, char **argv) {

    if (argc != 2) {
        std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
				  << std::endl;
        return 1;
    }
    toFloat(argv[1]);

    return 0;
}

// int main(int argc, char **argv) {

//     if (argc != 2) {
//         std::cerr << "Invalid arguments (usage: './convert.out <parameter>')"
// 				  << std::endl;
//         return 1;
//     }
//     checkFloat(argv[1]);

//     return 0;
// }