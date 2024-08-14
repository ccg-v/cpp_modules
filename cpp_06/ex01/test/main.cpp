#include <stdint.h>
#include <stdio.h>

int main(void)
{
    uint64_t val = 0;
    uint8_t *p = (uint8_t *)&val;

    p[0] = 0xEF;
    p[1] = 0xBE;
    p[2] = 0xAD;
    p[3] = 0xDE;
    p[4] = 0xFE;
    p[5] = 0xCA;
    p[6] = 0xAF;
    p[7] = 0xDE;

    printf("%lX\n", val);
}
