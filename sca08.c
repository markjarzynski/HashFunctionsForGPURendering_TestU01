#include <unif01.h>
#include <bbattery.h>

// RNG definition meeting Test01 rules
uint32_t sca08() {
    static uint32_t seed = 0;
    uint32_t s = seed;
    ++seed;

    s = (s ^ 2747636419) * 2654435769;// % 4294967296;
    s = (s ^ (s / 65536)) * 2654435769;// % 4294967296;
    s = (s ^ (s / 65536)) * 2654435769;// % 4294967296;

    return s;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("sca08", sca08);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
