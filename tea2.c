#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

#define TEA 2

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t tea() {

    uint32_t x, y, s = 0U;
    vec2 v = unmorton(seed);
    x = v.x; y = v.y;
    seed++;

    for (int i = 0; i < TEA; i++)
    {
        s += 0x9E3779B9u;
        x += (y << 4u) ^ (y + s) ^ (y >> 5u);
        y += (x << 4u) ^ (x + s) ^ (x >> 5u);
    }

    return y;

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("tea2", tea);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
