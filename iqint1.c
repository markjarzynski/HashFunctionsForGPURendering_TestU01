#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

static uint32_t seed = 0U;

// From https://www.shadertoy.com/view/llGSzw
uint32_t iqint1() {

    uint32_t n = seed;
    seed++;

    n = (n << 13U) ^ n;
    n = n * (n * n * 15731U + 789221U) + 1376312589U;

    return n;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("iqint1", iqint1);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
