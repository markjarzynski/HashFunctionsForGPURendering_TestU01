#include <stdio.h>
#include "uint96.h"
#include "morton.h"
#include <climits>

int main() {


    uint x = 1u;
    uint y = 2u;
    uint z = 3u;

    uint96_t a = uint96_t(0xffffffff, 0xffffffff, 0xffffffff);

    printf("%lu\n", sizeof(a) * CHAR_BIT);

    uint96_t b;

    b = (a & 1u << 3u) >> 2u;

    /*
    for (uint i = 0; i < sizeof(a) * CHAR_BIT; i++)
    {
        b |= (a & 1u << (3u * i)) >> (2u * i);
    }
    */

    


    printf("%08x %08x %08x\n", b.x, b.y, b.z);

    

    /*
    uint x = 1u;
    uint y = 2u;
    uint z = 3u;

    uint96_t m = morton(uint3(x,y,z));

    printf("%08x %08x %08x\n", x, y, z);
    printf("%08x %08x %08x\n", m.x, m.y, m.z);

    x = y = z = 0u;
    uint3 v = morton3(m);
    x = v.x; y = v.y; z = v.z;

    printf("%08x %08x %08x\n", x, y, z);
    printf("%08x %08x %08x\n", m.x, m.y, m.z);
    */

    return 0;
}
