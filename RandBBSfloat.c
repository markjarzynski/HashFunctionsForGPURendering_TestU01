#include <unif01.h>
#include <bbattery.h>
#include <math.h>

#define BBS_PRIME24 4093

static double seed = 3.14159265;

// RNG definition meeting Test01 rules
double RandBBSfloat() {
    double s = seed;
    ++seed;

    double i;

    s = modf(s / BBS_PRIME24, &i);
    s = modf(s * s * BBS_PRIME24, &i);
    s = modf(s * s * BBS_PRIME24, &i);

    return s;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("RandBBSfloat", RandBBSfloat);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
