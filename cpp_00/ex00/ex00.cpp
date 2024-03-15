#include <iostream>

int main(int argc, char **argv) {
    int i = 1;
    int j;
    char c;

    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        while (i < argc) {
            j = 0;
            while (argv[i][j] != '\0') {
                c = argv[i][j];
                if (c >= 'a' && c <= 'z')
                    c = c - 32;
                std::cout << c;
                j++;
            }
            i++;
        }
    }
    return 0;
}

