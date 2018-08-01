#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t pcg3d() {

    uint32_t x, y, z;

    vec3 v = unmorton3(seed);
    x = v.x; y = v.y; z = v.z;

    seed++;

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
    
    // swap
    x ^= x >> 16u;
    y ^= y >> 16u;
    z ^= z >> 16u;
    
    // permute
    x += y*z;
    y += z*x;
    z += x*y;
    
    return z;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("pcg3d", pcg3d);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
