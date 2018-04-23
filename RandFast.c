#include <unif01.h>
#include <bbattery.h>
#include <math.h>

// RNG definition meeting Test01 rules
double RandFast() {
    static double seed = 0;
    double x = seed, y = seed;
    ++seed;

    double i;

    double Magic = 3571.0;

    x = (1.0 / 4320.0) * x + 0.25;
    y = (1.0 / 4320.0) * y;

    double Random = modf((x * x + y * y) * Magic, &i);

    return modf(Random * Random * 2 * Magic, &i);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("RandFast", RandFast);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
