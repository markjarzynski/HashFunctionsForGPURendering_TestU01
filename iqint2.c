#include <unif01.h>
#include <bbattery.h>
#include "morton.h"

static uint32_t seed = 0U;

// RNG definition meeting Test01 rules
uint32_t iqint2() {

    uint32_t x, y, z;
    vec3 v = unmorton3(seed); 
    x = v.x; y = v.y; z = v.z;
    seed++;

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
    unif01_Gen *gen = unif01_CreateExternGenBits("iqint2", iqint2);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
