#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 2463534242U; 

// RNG definition meeting Test01 rules
uint32_t bbs() {

    uint32_t v = seed;

    v = v % 65521u;
    v = (v * v) % 65521u;
    v = (v * v) % 65521u;

    return v;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("bbs", bbs);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
