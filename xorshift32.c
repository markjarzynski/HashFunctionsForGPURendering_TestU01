#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t xorshift32() {

    uint32_t y = seed;
    seed++;

    y ^= (y << 13);
    y ^= (yt >> 17);
    return y ^= (y << 5);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("xorshift32", xorshift32);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
