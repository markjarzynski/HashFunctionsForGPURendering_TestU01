#include <unif01.h>
#include <bbattery.h>


static uint32_t a = 12345u;
static uint32_t b = 98765u;
static uint32_t seed = 2463534242U;

// RNG definition meeting Test01 rules
uint32_t tea6() {

    uint32_t x = a, y = b, s = seed;

    for (int i = 0; i < 6; i++)
    {
        s += 0x9E3779B9u;
        x += (y << 4u) ^ (y + s) ^ (y >> 5u);
        y += (x << 4u) ^ (x + s) ^ (x >> 5u);
    }

    return y;

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("tea6", tea6);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
