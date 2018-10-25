#pragma once

#include <cstdint>
#include "uint3.h"
#include "morton.h"
#include "random.h"

#define test11(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(seed++);            \
}

#define test21(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton2(seed++));   \
}

#define test22(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    static uint32_t count = 0u;     \
    static uint2 m, p;              \
                                    \
    if (count == 0) {               \
        m = morton2(seed);          \
        p = HASH(m);                \
        count++;                    \
        return p.x;                 \
    } else {                        \
        seed++;                     \
        count = 0;                  \
        return p.y;                 \
    }                               \
}                                   \
                                    \
uint32_t test_##HASH##x()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton2(seed++)).x; \
}                                   \
                                    \
uint32_t test_##HASH##y()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton2(seed++)).y; \
}

#define test31(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton3(seed++));   \
}

#define test41(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton4(seed++));   \
}

#define test33(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    static uint32_t count = 0u;     \
    static uint3 p, m;              \
                                    \
    if (count == 0) {               \
        m = morton3(seed);          \
        p = HASH(m);                \
                                    \
        count++;                    \
                                    \
        return p.x;                 \
    } else if (count == 1) {        \
        count++;                    \
                                    \
        return p.y;                 \
    } else {                        \
                                    \
        seed++;                     \
        count = 0;                  \
                                    \
        return p.z;                 \
    }                               \
}                                   \
                                    \
uint32_t test_##HASH##x()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton3(seed++)).x; \
}                                   \
                                    \
uint32_t test_##HASH##y()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton3(seed++)).y; \
}                                   \
                                    \
uint32_t test_##HASH##z()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton3(seed++)).z; \
}

#define test44(HASH)                \
uint32_t test_##HASH()              \
{                                   \
    static uint32_t seed = 0u;      \
    static uint32_t count = 0u;     \
    static uint4 p, m;              \
                                    \
    if (count == 0) {               \
        m = morton4(seed);          \
        p = HASH(m);                \
                                    \
        count++;                    \
        return p.x;                 \
    } else if (count == 1) {        \
        count++;                    \
        return p.y;                 \
    } else if (count == 2) {        \
        count++;                    \
        return p.z;                 \
    } else {                        \
        seed++;                     \
        count = 0;                  \
        return p.w;                 \
    }                               \
}                                   \
                                    \
uint32_t test_##HASH##x()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton4(seed++)).x; \
}                                   \
                                    \
uint32_t test_##HASH##y()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton4(seed++)).y; \
}                                   \
                                    \
uint32_t test_##HASH##z()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton4(seed++)).z; \
}                                   \
                                    \
uint32_t test_##HASH##w()           \
{                                   \
    static uint32_t seed = 0u;      \
    return HASH(morton4(seed++)).w; \
}

#define ftest21(HASH)               \
double test_##HASH()                \
{                                   \
    static uint32_t seed = 0u;      \
    uint2 m = morton2(seed++);      \
    return HASH(float2(m.x, m.y));  \
}

#define ftest23(HASH)               \
double test_##HASH()                \
{                                   \
    static uint32_t seed = 0u;      \
    static uint32_t count = 0u;     \
    static float3 p;                \
    static uint2 m;                 \
                                    \
    if (count == 0) {               \
        m = morton2(seed);          \
        p = HASH(float2(m.x,m.y));  \
                                    \
        count++;                    \
        return p.x;                 \
    } else if (count == 1) {        \
        count++;                    \
        return p.y;                 \
    } else {                        \
        seed++;                     \
        count = 0;                  \
        return p.z;                 \
    }                               \
}                                   \
                                    \
uint32_t test_##HASH##x()           \
{                                   \
    static uint32_t seed = 0u;      \
    uint2 m = morton2(seed++);      \
    return HASH(float2(m.x,m.y)).x; \
}                                   \
                                    \
uint32_t test_##HASH##y()           \
{                                   \
    static uint32_t seed = 0u;      \
    uint2 m = morton2(seed++);      \
    return HASH(float2(m.x,m.y)).y; \
}                                   \
                                    \
uint32_t test_##HASH##z()           \
{                                   \
    static uint32_t seed = 0u;      \
    uint2 m = morton2(seed++);      \
    return HASH(float2(m.x,m.y)).z; \
}

#define MAKETEA(T)                  \
uint2 tea##T(uint2 p)               \
{                                   \
    return tea(T, p);               \
}

MAKETEA(2)
MAKETEA(3)
MAKETEA(4)
MAKETEA(5)
MAKETEA(6)

test11(bbs)
test11(city)
ftest21(fast)
ftest21(ign)
test11(iqint1)
test33(iqint2)
test21(iqint3)
test21(jkiss32)
test11(lcg)
test21(murmur3)
test33(pcg3d)
test33(pcg3d16)
ftest21(pseudo)
test11(ranlim32)
test11(sca08)
test11(superfast)
test22(tea2)
test22(tea3)
test22(tea4)
test22(tea5)
test22(tea6)
ftest21(trig)
test11(wang)
test44(xorshift128)
test11(xorshift32)
test21(xxhash32)
ftest23(hashwithoutsine)
test41(hybridtaus)
test33(Rand3DPCG32)
test44(Rand4DPCG32)
test22(pcg2d)
test44(pcg4d)
