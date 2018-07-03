#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 2463534242U; 

// RNG definition meeting Test01 rules
uint32_t wang() {

    uint32_t v = seed;

    v = (v ^ 61u) ^ (v >> 16u);
    v *= 9u;
    v ^= v >> 4u;
    v *= 0x27d4eb2du;
    v ^= v >> 15u;

    return v;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("wang", wang);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
