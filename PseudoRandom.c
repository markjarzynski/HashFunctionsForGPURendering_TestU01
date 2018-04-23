#include <unif01.h>
#include <bbattery.h>
#include <math.h>

// RNG definition meeting Test01 rules
double PseudoRandom() {
    static double seed = 0;
    double x = seed, y = seed;
    ++seed;

    double i;

    x = modf(x / 128.0, &i) * 128.0 - 64.340622;
    y = modf(y / 128.0, &i) * 128.0 - 72.465622;

    return modf(x * x * 20.390625 + y * y * 60.703125 + x * y * 2.4281209, &i);

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGen01("PseudoRandom", PseudoRandom);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
