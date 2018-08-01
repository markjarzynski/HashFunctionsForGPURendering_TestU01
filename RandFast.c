#include <unif01.h>
#include <bbattery.h>
#include <math.h>
#include "morton.h"
#include "util.h"

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
double RandFast() {

    uint32_t x, y;

    vec2 v = unmorton2(seed);

    double Magic = 3571.0;

    x = (1.0 / 4320.0) * x + 0.25;
    y = (1.0 / 4320.0) * y;

    double Random = frac((x * x + y * y) * Magic);

    return frac(Random * Random * 2 * Magic);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("RandFast", RandFast);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
