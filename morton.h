#ifndef MORTON_H
#define MORTON_H

#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "uint96.h"

#include <cstdint>

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

uint64_t morton (uint2 v)
{
    uint64_t m = 0;

    for (int i = 0; i < sizeof(v.x) * CHAR_BIT; i++)
    {
        m |= (v.x & 1U << i) << i | (v.y & 1U << i) << (i + 1);
    }

    return m;
}

uint2 morton2 (uint64_t m)
{
    uint2 v = uint2();

    for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1U << i) >> i;
        v.y |= (m & 1U << (i + 1)) >> i;
    }

    return v;
}

uint96_t morton (uint3 v)
{

    uint96_t m = 0u;
    w

    for (int i = 0; i < sizeof(v.x) * CHAR_BIT; i++)
    {
        m |= (v.x & 1U << i) << (2 * i) | (v.y & 1U << i) << (2 * i + 1) | (v.z & 1U << i) << (2 * i + 2);
    }

}

uint3 morton3 (uint96_t m)
{
    uint3 v = uint3();
    
    for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1U << (3 * i)) >> (2 * i);
        v.y |= (m & 1U << (3 * i + 1)) >> (2 * i + 1);
        v.z |= (m & 1U << (3 * i + 2)) >> (2 * i + 2);
    }
    
    return v;
}

uint128_t morton (uint4 v)
{
    uint128_t m = 0u;
    
    for (int i = 0; i < sizeof(v.x) * CHAR_BIT; i++)
    {
        m |= (v.x & 1u << i) << (3 * i) | (v.y & 1u << i) << (3 * i + 1) | (v.z & 1u << i) << (3 * i + 2) | (v.w & 1u << i) << (3 * i + 3);
    }

}

uint4 morton4 (uint128_t m)
{
    uint4 v = uint4();

    for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1u << (4 * i)) >> (3 * i);
        v.y |= (m & 1u << (4 * i + 1)) >> (3 * i + 1);
        v.z |= (m & 1u << (4 * i + 2)) >> (3 * i + 2);
        v.w |= (m & 1u << (4 * i + 3)) >> (3 * i + 3);
    }

    return v;
}

#endif
