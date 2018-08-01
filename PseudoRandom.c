#include <unif01.h>
#include <bbattery.h>
#include <math.h>
#include "util.h"

static uint32_t seed = 0;

// RNG definition meeting Test01 rules
double PseudoRandom() {
    double x = seed, y = seed;
    seed++;

    double i;

    x = frac(x / 128.0) * 128.0 - 64.340622;
    y = frac(y / 128.0) * 128.0 - 72.465622;

    return frac(x * x * 20.390625 + y * y * 60.703125 + x * y * 2.4281209);

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("PseudoRandom", PseudoRandom);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
