#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 2463534242U;

// RNG definition meeting Test01 rules
uint32_t ranlim32() {
    uint32_t u, v, w1, w2, x, y;
    uint32_t j = seed;

    v = 2244614371U;
    w1 = 521288629U;
    w2 = 362436069U;

    u = j ^ v;

    u = u * 2891336453U + 1640531513U;
    v ^= v >> 13; v ^= v << 17; v ^= v >> 5;
    w1 = 33378 * (w1 & 0xffff) + (w1 >> 16);
    w2 = 57225 * (w2 & 0xffff) + (w2 >> 16);

    v = u;

    u = u * 2891336453U + 1640531513U;
    v ^= v >> 13; v ^= v << 17; v ^= v >> 5;
    w1 = 33378 * (w1 & 0xffff) + (w1 >> 16);
    w2 = 57225 * (w2 & 0xffff) + (w2 >> 16);

    x = u ^ (u << 9); x ^= x >> 17; x ^= x << 6;
    y = w1 ^ (w1 << 17); y ^= y >> 15; y ^= y << 5;

    return (x + v) ^ (y + w2);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("ranlim32", ranlim32);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
