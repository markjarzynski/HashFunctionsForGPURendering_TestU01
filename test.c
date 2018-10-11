#include <stdio.h>
#include "uint96.h"
#include "morton.h"
#include <climits>

int main() {

    uint3 x = uint3(1u, 2u, 3u);

    uint96_t a = morton(x);
    printf("%x %x %x\n", a.x, a.y, a.z);


    return 0;
}
