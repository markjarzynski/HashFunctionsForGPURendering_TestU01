#ifndef MORTON_H
#define MORTON_H

#include "testu01.h"

typedef struct
{
    uint32_t x, y;
} vec2;

typedef struct
{
    uint32_t x, y, z;
} vec3;

uint32_t morton (uint32_t x, uint32_t y)
{
    uint32_t m = 0;

    for (int i = 0; i < sizeof(x) * CHAR_BIT; i++)
    {
        m |= (x & 1U << i) << i | (y & 1U << i) << (i + 1);
    }
    
    return m;
}

vec2 unmorton(uint32_t m)
{
    vec2 v = {0,0};

    for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1U << i) >> i;
        v.y |= (m & 1U << (i + 1)) >> i;
    }

    return v;

}

uint32_t morton2(uint32_t x, uint32_t y)
{
    return morton(x, y);
}

vec2 unmorton2(uint32_t m)
{
    return unmorton(m);
}

uint32_t morton3(uint32_t x, uint32_t y, uint32_t z) 
{
    uint32_t m = 0;

    for (int i = 0; i < sizeof(x) * CHAR_BIT; i++)
    {
        m |= (x & 1U << i) << (2 * i) | (y & 1U << i) << (2 * i + 1) | (z & 1U << i) << (2 * i + 2);
    }

    return m;
}

vec3 unmorton3(uint32_t m)
{
    vec3 v = {0,0,0};

    for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1U << (3 * i)) >> (2 * i);
        v.y |= (m & 1U << (3 * i + 1)) >> (2 * i + 1);
        v.z |= (m & 1U << (3 * i + 2)) >> (2 * i + 2);
    }

    return v;
}

#endif
