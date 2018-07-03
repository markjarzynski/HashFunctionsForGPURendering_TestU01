#include <unif01.h>
#include <bbattery.h>

static uint32_t x = 2463534242U;
static uint32_t y = 12345U;
static uint32_t z = 9876543U;

// RNG definition meeting Test01 rules
uint32_t iqint() {

    x = ((x>>8u)^y)*1103515245u;
    y = ((y>>8u)^z)*1103515245u;
    z = ((z>>8u)^x)*1103515245u;

    x = ((x>>8u)^y)*1103515245u;
    y = ((y>>8u)^z)*1103515245u;
    z = ((z>>8u)^x)*1103515245u;

    x = ((x>>8u)^y)*1103515245u;
    y = ((y>>8u)^z)*1103515245u;
    z = ((z>>8u)^x)*1103515245u;

    return z;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("iqint", iqint);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
