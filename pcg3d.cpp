extern "C" {
    #include "TestU01.h"
}

#include "uint3.h"
#include "morton.h"

static uint32_t seed = 0u;
static uint32_t count = 0u;
static uint3 p, m;

uint3 pcg3d(uint3 v) {

    // LCG
    uint32_t a = 1664525u;
    uint32_t c = 1013904223u;
    v = v * a + c;

    // permute
    v.x += v.y * v.z;
    v.y += v.z * v.x;
    v.z += v.x * v.y;

    // swap
    v.x ^= v.x >> 16u;
    v.y ^= v.y >> 16u;
    v.z ^= v.z >> 16u;

    // permute
    v.x += v.y * v.z;
    v.y += v.z * v.x;
    v.z += v.x * v.y;

    return v;
}

// RNG definition meeting Test01 rules
uint32_t test_pcg3d() {

    if (count == 0) {
        m = morton3(seed);
        p = pcg3d(m);

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
    unif01_Gen *gen = unif01_CreateExternGenBits((char*) "pcg3d", test_pcg3d);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
