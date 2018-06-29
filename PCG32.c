#include <unif01.h>
#include <bbattery.h>

// *Really* minimal PCG32 code / (c) 2014 M.E. O'Neill / pcg-random.org
// Licensed under Apache License 2.0 (NO WARRANTY, etc. see website)

typedef struct { uint64_t state;  uint64_t inc; } pcg32_random_t;

uint32_t pcg32_random_r(pcg32_random_t* rng)
{
    uint64_t oldstate = rng->state;
    // Advance internal state
    rng->state = oldstate * 6364136223846793005ULL + (rng->inc|1);
    // Calculate output function (XSH RR), uses old state for max ILP
    uint32_t xorshifted = ((oldstate >> 18u) ^ oldstate) >> 27u;
    uint32_t rot = oldstate >> 59u;
    return (xorshifted >> rot) | (xorshifted << ((-rot) & 31));
}

uint32_t PCG32() {
    pcg32_random_t rng;
    return pcg32_random_r(&rng);
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("PCG32", PCG32);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}

