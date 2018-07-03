#include <unif01.h>
#include <bbattery.h>

static uint32_t state[4] = {2463534242U, 1664525U, 22695477U, 12345U};

/* The state array must be initialized to not be all zero */
uint32_t xorshift128()
{
	/* Algorithm "xor128" from p. 5 of Marsaglia, "Xorshift RNGs" */
	uint32_t s, t = state[3];
	t ^= t << 11;
	t ^= t >> 8;
	state[3] = state[2]; state[2] = state[1]; state[1] = s = state[0];
	t ^= s;
	t ^= s >> 19;	
	state[0] = t;
	return t;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("xorshift128", xorshift128);
    bbattery_SmallCrush(gen);
    unif01_DeleteExternGen01(gen);
    return 0;
}
