#include <unif01.h>
#include <bbattery.h>

// RNG definition meeting Test01 rules
uint32_t Ranhash() {
    uint64_t u = 2463534242U;
    uint64_t v = u * 3935559000370003845LL + 2691343689449507681LL;
    v ^= v >> 21; v ^= v << 37; v ^= v >> 4;
    v *= 4768777513237032717LL;
    v ^= v << 20; v ^= v >> 41; v ^= v << 5;
    return (uint32_t)(v & 0xffffffff);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("Ranhash", Ranhash);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
