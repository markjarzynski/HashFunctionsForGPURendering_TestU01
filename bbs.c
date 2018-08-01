#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t bbs() {

    uint32_t v = seed;
    seed++;

    v = v % 65521u;
    v = (v * v) % 65521u;
    v = (v * v) % 65521u;

    return v;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("bbs", bbs);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
