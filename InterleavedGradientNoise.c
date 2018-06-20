#include <unif01.h>
#include <bbattery.h>
#include <math.h>

// RNG definition meeting Test01 rules
double InterleavedGradientNoise() {
    static double seed = 0;
    double u, v;
    double x = seed, y = seed, z = seed;
    ++seed;

    double i;

    u = seed * 47 * 0.695f;
    v = seed * 17 * 0.695f;    

    x = 0.06711056f;
    y = 0.00583715f;
    z = 52.9829189f;


    return modf(z * modf(u*x + v*y, &i), &i);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("InterleavedGradientNoise", InterleavedGradientNoise);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
