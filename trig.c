#include <unif01.h>
#include <bbattery.h>
#include <math.h>

static uint32_t seed = 12345u;

// RNG definition meeting Test01 rules
uint32_t trig() {

    uint32_t x = seed, y = seed;
    seed++;

    double i;

    return modf(43757.5453 * sinf(x * 12.9898 + y * 78.233), &i);

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("trig", trig);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
