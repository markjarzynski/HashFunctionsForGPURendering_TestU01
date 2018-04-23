#include <unif01.h>
#include <bbattery.h>

typedef unsigned int uint;

// RNG definition meeting Test01 rules
uint Rand3DPCG() {
    static uint seed = 0;
    uint x = seed, y = seed, z = seed;
    ++seed;

    // LCG
    uint a = 1664525u;
    unsigned long c = 10139042223u;
    x = x * a + c;
    y = y * a + c;
    z = z * a + c;

    // permute
    x += y*z;
    y += z*x;
    z += x*y;

    // swap
    x = (x<<16u) + (x>>16u);
    y = (y<<16u) + (y>>16u);
    z = (z<<16u) + (z>>16u);

    // permute
    x += y*z;
    y += z*x;
    z += x*y;

    return z;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("Rand3DPCG", Rand3DPCG);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
