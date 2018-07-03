#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 2463534242U;
static uint32_t x = 12345u;
static uint32_t y = 54321u;

// RNG definition meeting Test01 rules
uint32_t tea4() {

    uint32_t s = seed;
    seed++;

    for (int i = 0; i < 4; i++)
    {
        s += 0x9E3779B9u;
        x += (y << 4u) ^ (y + s) ^ (y >> 5u);
        y += (x << 4u) ^ (x + s) ^ (x >> 5u);
    }

    return y;

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("tea4", tea4);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
