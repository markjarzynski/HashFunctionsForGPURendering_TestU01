extern "C" {
    #include "TestU01.h"
}

#include "uint3.h"
#include "morton.h"

static uint32_t seed = 0U;
static uint32_t count = 0U;
static uint3 p, m;

uint3 Rand3DPCG( uint3 v ) {

    // Linear congruential step.
    v = v * 1664525u + 1013904223u;

    // swapping low and high bits makes all 32 bits pretty good
    v = v * (1u << 16u) + (v >> 16u);

    // final shuffle
    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;
    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;

    return v;
}

// RNG definition meeting Test01 rules
uint32_t test_Rand3DPCG() {

    if (count == 0) {
        m = morton3(seed);
        p = Rand3DPCG(m);

        count++;

        return p.x;
    } else if (count == 1) {
        count++;

        return p.y;
    } else {

        seed++;
        count = 0;

        return p.z;
    }
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits((char*) "Rand3DPCG", test_Rand3DPCG);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
