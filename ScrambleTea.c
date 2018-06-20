#include <unif01.h>
#include <bbattery.h>

typedef unsigned int uint;

// RNG definition meeting Test01 rules
uint ScrambleTEA() {
    static uint seed = 0;
    uint y = seed, z = seed;
    ++seed;

    uint IterationCount = 3;

    uint k[4] = { 0xA341316Cu , 0xC8013EA4u , 0xAD90777Du , 0x7E95761Eu };
    uint sum = 0;

    for (uint i = 0; i < IterationCount; ++i)
    {
        sum += 0x9e3779b9;
        y += ((z << 4u) + k[0]) ^ (z + sum) ^ ((z >> 5u) + k[1]);
        z += ((y << 4u) + k[2]) ^ (y + sum) ^ ((y >> 5u) + k[3]);
    }

    return z;

}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("ScrambleTEA", ScrambleTEA);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
