#include <unif01.h>
#include <bbattery.h>

static unsigned int x = 2463534242U;
static unsigned int y = 2463534242U;
static unsigned int z = 2463534242U;

// RNG definition meeting Test01 rules
uint32_t Rand3DPCG() {

    // LCG
    uint32_t a = 1664525u;
    uint32_t c = 1013904223u;
    x = x * a + c;
    y = y * a + c;
    z = z * a + c;

    // permute
    x += y*z;
    y += z*x;
    z += x*y;
     
    // permute
    x += y*z;
    y += z*x;
    z += x*y;
    
    // swap
    x ^= x >> 16u;
    y ^= y >> 16u;
    z ^= z >> 16u;

    return z;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("Rand3DPCG", Rand3DPCG);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
