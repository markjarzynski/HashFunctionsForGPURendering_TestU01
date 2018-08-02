#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

static uint32_t seed = 0U;
static uint32_t count = 0U;

// RNG definition meeting Test01 rules
uint32_t Rand3DPCG() {

    uint32_t x, y, z;

    vec3 v = unmorton3(seed);
    x = v.x; y = v.y; z = v.z;

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

    if (count % 3 == 0) {
        ret = z;
    } else if (count % 3 == 1) {
        ret = y;
    } else {
        ret = x;
        seed++;
    } 
    count++;

    return ret;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("Rand3DPCG", Rand3DPCG);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
