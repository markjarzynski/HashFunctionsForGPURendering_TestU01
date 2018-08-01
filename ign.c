#include <unif01.h>
#include <bbattery.h>
#include <math.h>
#include "util.h"

static unsigned int seed = 0U;

// RNG definition meeting Test01 rules
double ign() {
    double u, v, x, y, z;

    u = seed * 47 * 0.695f;
    v = seed * 17 * 0.695f;    

    seed++;

    x = 0.06711056f;
    y = 0.00583715f;
    z = 52.9829189f;

    return frac(z * frac(u*x + v*y));
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("ign", ign);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
