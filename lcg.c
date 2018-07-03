#include <unif01.h>
#include <bbattery.h>

static uint32_t seed = 2463534242U; 

// RNG definition meeting Test01 rules
uint32_t lcg() {

    return seed * 1664525u + 1013904223u;

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("lcg", lcg);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
