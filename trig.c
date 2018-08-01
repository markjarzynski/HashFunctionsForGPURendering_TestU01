#include <unif01.h>
#include <bbattery.h>
#include <math.h>
#include "morton.h"
#include "util.h"
#include <stdio.h>

static uint32_t seed = 0u;

// RNG definition meeting Test01 rules
double trig() {

    uint32_t x, y;
    vec2 v = unmorton(seed);
    x = v.x; y = v.y;

    seed++;

	double s = x * 12.9898 + y * 78.233;

    return frac(43757.5453 * s);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("trig", trig);
    bbattery_Crush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
