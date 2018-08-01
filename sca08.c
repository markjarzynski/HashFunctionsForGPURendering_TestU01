#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t sca08() {
    uint32_t s = seed;
    seed++;

    s = (s ^ 2747636419) * 2654435769;// % 4294967296;
    s = (s ^ (s / 65536)) * 2654435769;// % 4294967296;
    s = (s ^ (s / 65536)) * 2654435769;// % 4294967296;
    //s = (s ^ (s >> 16u)) * 2654435769;// % 4294967296;
    //s = (s ^ (s >> 16u)) * 2654435769;// % 4294967296;

    return s;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("sca08", sca08);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
