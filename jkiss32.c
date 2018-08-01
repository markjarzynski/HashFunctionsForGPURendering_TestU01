#include <unif01.h>
#include <bbattery.h>

/* Implementation of a 32-bit KISS generator which uses no multiply instructions */
static unsigned int x=123456789,y=234567891,z=345678912,w=456789123,c=0;
unsigned int JKISS32()
{
    int t;
    y ^= (y<<5); y ^= (y>>7); y ^= (y<<22);
    t = z+w+c; z = w; c = t < 0; w = t&2147483647;
    x += 1411392427;
    return x + y + w;
}

// test harness
int main() {
    unif01_Gen *gen = unif01_CreateExternGenBits("JKISS32", JKISS32);
    bbattery_BigCrush(gen);
    unif01_DeleteExternGenBits(gen);
    return 0;
}
