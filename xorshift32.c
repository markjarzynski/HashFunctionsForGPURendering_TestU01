#include <unif01.h>
#include <bbattery.h>

static unsigned int y = 2463534242U;

// RNG definition meeting Test01 rules
uint32_t xorshift32() {
    y ^= (y << 13);
    y ^= (y >> 17);
    return y ^= (y << 5);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("xorshift32", xorshift32);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
