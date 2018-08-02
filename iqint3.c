#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t iqint3() {

    uint32_t x, y;
    vec2 v = unmorton(seed); 
    x = v.x; y = v.y;
    seed++;

    uint32_t qx, qy, n;

    qx = 1103515245U * ((x >> 1U) ^ y);
    qy = 1103515245U * ((y>>1U) ^ x);

    n = 1103515245U * (x ^ (y >> 3U));

    return n;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("iqint3", iqint3);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
