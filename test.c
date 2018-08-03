#include <stdio.h>
#include "morton.h"

#define PATTERN "%c%c%c%c%c%c%c%c"
#define BINARY(byte) \
        (byte & 0x80 ? '1' : '0'), \
        (byte & 0x40 ? '1' : '0'), \
        (byte & 0x20 ? '1' : '0'), \
        (byte & 0x10 ? '1' : '0'), \
        (byte & 0x08 ? '1' : '0'), \
        (byte & 0x04 ? '1' : '0'), \
        (byte & 0x02 ? '1' : '0'), \
        (byte & 0x01 ? '1' : '0')

int main() {

    uint32_t x = 1;
    uint32_t y = 2;
    uint32_t z = 3;
    uint128_t m = morton3(x,y,z); // set m to be the morton3 of xyz
    
    printf("%u %u %u %llu\n", x, y, z, (unsigned long long) m);
    printf(""PATTERN" "PATTERN" "PATTERN" "PATTERN"\n", BINARY(x), BINARY(y), BINARY(z), BINARY(m));

    // reset xyz and get their values from unmorton3(m)
    x = y = z = 0;

    vec3 v = unmorton3(m);
    x = v.x; y = v.y; z = v.z;

    printf("%u %u %u %llu\n", x, y, z, (unsigned long long) m);
    printf(""PATTERN" "PATTERN" "PATTERN" "PATTERN"\n", BINARY(x), BINARY(y), BINARY(z), BINARY(m));

    /*
    for (int i = 0; i < sizeof(x) * CHAR_BIT; i++)
    {
        //z |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
        m |= (x & 1U << i) << (2 * i) | (y & 1U << i) << (2 * i + 1) | (z & 1U << i) << (2 * i + 2);
    }

    printf("%d %d %d %d\n", x, y, z, m);
    printf(""PATTERN" "PATTERN" "PATTERN" "PATTERN"\n", BINARY(x), BINARY(y), BINARY(z), BINARY(m));

    x = 0;
    y = 0;
    z = 0;

    for (int i = 0; i < sizeof(z) * CHAR_BIT; i++)
    {
        x |= (m & 1U << (3 * i)) >> (2 * i);
        y |= (m & 1U << (3 * i + 1)) >> (2 * i + 1);
        z |= (m & 1U << (3 * i + 2)) >> (2 * i + 2);
    }
    
    printf("%d %d %d %d\n", x, y, z, m);
    printf(""PATTERN" "PATTERN" "PATTERN" "PATTERN"\n", BINARY(x), BINARY(y), BINARY(z), BINARY(m));
    */

    return 0;
}
