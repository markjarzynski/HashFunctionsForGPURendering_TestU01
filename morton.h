#ifndef MORTON_H
#define MORTON_H

#include "uint2.h"
#include "uint3.h"
#include "uint4.h"
#include "uint96.h"

#include <climits>
#include <iostream>
#include <bitset>

typedef __int128 int128_t;
typedef unsigned __int128 uint128_t;

uint64_t morton (uint2 v)
{
    uint64_t m = 0u;

    for (int i = 0; i < 32; i++)
    {
        m |= (v.x & 1u << i) << i | (v.y & 1u << i) << (i + 1);
    }

    return m;
}

uint2 morton2 (uint64_t m)
{
    uint2 v = uint2();

    //for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    for (int i = 0; i < 32; i++)
    {
        v.x |= (m & (uint64_t(1u) << (2 * i))) >> i;
        v.y |= (m & (uint64_t(1u) << (2 * i + 1))) >> (i + 1);
    }

    return v;
}

//uint96_t morton (uint3 v)
uint64_t morton (uint3 v)
{
    uint64_t m = 0u;
    v = v & 0x1fffffu; // Only look at the first 21 bits.

    //for (uint i = 0; i < sizeof(v.x) * CHAR_BIT; i++)
    for (uint i = 0; i < 21; i++)
    {
        m |= (v.x & 1u << i) << (2u * i) | (v.y & 1u << i) << (2u * i + 1u) | (v.z & 1u << i) << (2u * i + 2u);
    }

    return m;
}

//uint3 morton3 (uint96_t m)
uint3 morton3 (uint64_t m)
{
    uint3 v = uint3();
    
    //for (int i = 0; i < sizeof(m) * CHAR_BIT; i++)
    for (int i = 0; i < 21; i++)
    {
        v.x |= (m & ( uint64_t(1u) << (3 * i))) >> (2 * i);
        v.y |= (m & (uint64_t(1u) << (3 * i + 1))) >> (2 * i + 1);
        v.z |= (m & (uint64_t(1u) << (3 * i + 2))) >> (2 * i + 2);
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

    return m;
}

uint4 morton4 (uint128_t m)
{
    uint4 v = uint4();

    for (uint i = 0; i < sizeof(m) * CHAR_BIT; i++)
    {
        v.x |= (m & 1u << (4u * i)) >> (3u * i);
        v.y |= (m & 1u << (4u * i + 1u)) >> (3u * i + 1u);
        v.z |= (m & 1u << (4u * i + 2u)) >> (3u * i + 2u);
        v.w |= (m & 1u << (4u * i + 3u)) >> (3u * i + 3u);
    }

    return v;
}

#endif
