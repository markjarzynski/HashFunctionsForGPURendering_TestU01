#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t lcg() {

    uint32_t v = seed;
    seed++;

    return v * 1664525u + 1013904223u;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("lcg", lcg);
    bbattery_Crush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
