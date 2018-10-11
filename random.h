#pragma once

#include "uint.h"
#include "uint2.h"
#include "uint3.h"
#include "uint4.h"

#include "float2.h"
#include "float3.h"

#include "util.h"

// Commonly used constants
#define c1 0xcc9e2d51u
#define c2 0x1b873593u

// Helper Functions
uint rotl(uint x, uint r)
{
	return (x << r) | (x >> (32u - r));   
}

uint rotr(uint x, uint r)   
{
	return (x >> r) | (x << (32u - r));
}

uint fmix(uint h)
{
  h ^= h >> 16;
  h *= 0x85ebca6bu;
  h ^= h >> 13;
  h *= 0xc2b2ae35u;
  h ^= h >> 16;
  return h;
}

uint mur(uint a, uint h) {
  // Helper from Murmur3 for combining two 32-bit values.
  a *= c1;
  a = rotr(a, 17u);
  a *= c2;
  h ^= a;
  h = rotr(h, 19u);
  return h * 5u + 0xe6546b64u;
}

// convert 2D seed to 1D
uint seed(uint2 p) {
    return 19u * p.x + 47u * p.y + 101u;
}


// Hashes

// BBS-inspired hash
//  - Olano, Modified Noise for Evaluation on Graphics Hardware, GH 2005
uint bbs(uint v)
{
    v = v % 65521u;
    v = (v * v) % 65521u;
    v = (v * v) % 65521u;
    return v;
}

// CityHash32, adapted from Hash32Len0to4 in https://github.com/google/cityhash
uint city(uint s)
{
    uint len = 4u;
	uint b = 0u;
    uint c = 9u;
    
    for (uint i = 0u; i < len; i++) {
    	uint v = (s >> (i * 8u)) & 0xffu;
        b = b * c1 + v;
        c ^= b;
    }
    
    return fmix(mur(b, mur(len, c)));
}

// UE4 RandFast function
float fast(float2 v) {
    v = (1./4320.) * v + float2(0.25,0.);
    float state = frac( dot( v * v, float2(3571)));
    return frac( state * state * (3571. * 2.));
}

// Interleaved Gradient Noise
//  - Jimenez, Next Generation Post Processing in Call of Duty: Advanced Warfare
//    Advances in Real-time Rendering, SIGGRAPH 2014
float ign(float2 v)
{
    float3 magic = float3(0.06711056f, 0.00583715f, 52.9829189f);
    return frac(magic.z * frac(dot(v, float2(magic.x, magic.y))));//frac(magic.z * frac(dot(v, magic.xy)));
}

// Integer Hash - I
// - Inigo Quilez, Integer Hash - I, 2017
//   https://www.shadertoy.com/view/llGSzw
uint iqint1(uint n)
{
    // integer hash copied from Hugo Elias
	n = (n << 13U) ^ n;
    n = n * (n * n * 15731U + 789221U) + 1376312589U; 
    
    return n;
}

// Integer Hash - II
// - Inigo Quilez, Integer Hash - II, 2017
//   https://www.shadertoy.com/view/XlXcW4
uint3 iqint2(uint3 x)
{
    const uint k = 1103515245u;
    
    x = ((x>>8U)^uint3(x.y, x.z, x.x))*k;//((x>>8U)^x.yzx)*k;
    x = ((x>>8U)^uint3(x.y, x.z, x.x))*k;//((x>>8U)^x.yzx)*k;
    x = ((x>>8U)^uint3(x.y, x.z, x.x))*k;//((x>>8U)^x.yzx)*k;
    
    return x;
}

// Integer Hash - III
// - Inigo Quilez, Integer Hash - III, 2017
//   https://www.shadertoy.com/view/4tXyWN
uint iqint3(uint2 x)
{
    uint2 q = 1103515245U * ( (x>>1U) ^ (uint2(x.y, x.x)) );//1103515245U * ( (x>>1U) ^ (x.yx   ) );
    uint  n = 1103515245U * ( (q.x  ) ^ (q.y>>3U) );
    
    return n;
}

// JKiss32
// - David Jones, Good Practice in (Pseudo) Random Number Generation for 
//   Bioinformatics Applications, 2010
//   http://www0.cs.ucl.ac.uk/staff/d.jones/GoodPracticeRNG.pdf
uint jkiss32(uint2 p)
{
    uint x = p.x, y = p.y;
    
	uint z = 345678912u, w = 456789123u, c = 0u;
    int t;
    
    y ^= (y<<5u); y ^= (y>>7u); y ^= (y<<22u);
    t = int(z+w+c); 
    z = w; 
    c = uint(t < 0);
    w = uint(t&2147483647);
    x += 1411392427u;
    
    return x + y + w;
}

uint lcg(uint p)
{
	return p * 1664525u + 1013904223u;
}

// Adapted from MurmurHas3_x86_32 from https://github.com/aappleby/smhasher
uint murmur3(uint2 seed)
{
    uint h = seed.x;
    uint k = seed.y;
    
    k *= c1; 
    k = uint(rotl(k,15u));
    k *= c2;

    h ^= k;

    h = rotl(h,13u);	
    h = h*5u+0xe6546b64u;
    
    h ^= h >> 16u;
    h *= 0x85ebca6bu;
    h ^= h >> 13u;
    h *= 0xc2b2ae35u;
    h ^= h >> 16u;

    return h;
}

// UE4 RandPCG3D32
uint3 pcg3d(uint3 v)
{
	v = v * 1664525u + 1013904223u;   

    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;
    
    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;
    
    v = v ^ (v>>16u);
    
    return v;
}

// UE4 RandPCG3d16
uint3 pcg3d16(uint3 v)
{
    v = v * 12829u + 47989u;
    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;

    v.x += v.y*v.z;
    v.y += v.z*v.x;
    v.z += v.x*v.y;
    return v;
}

// UE4 PseudoRandom function
float pseudo(float2 v) {
    v = frac(v/128.)*128.f + float2(-64.340622f, -72.465622f);
    return frac(dot(float3(v.x, v.y, v.x) * float3(v.x, v.y, v.y), float3(20.390625f, 60.703125f, 2.4281209f)));//frac(dot(v.xyx * v.xyy, float3(20.390625f, 60.703125f, 2.4281209f)));
}

uint ranlim32(uint j)
{
    uint u, v, w1, w2, x, y;
    
    v = 2244614371U;
    w1 = 521288629U;
    w2 = 362436069U;

    u = j ^ v;

    u = u * 2891336453U + 1640531513U;
    v ^= v >> 13u; v ^= v << 17u; v ^= v >> 5u;
    w1 = 33378u * (w1 & 0xffffu) + (w1 >> 16u);
    w2 = 57225u * (w2 & 0xffffu) + (w2 >> 16u);

    v = u;

    u = u * 2891336453U + 1640531513U;
    v ^= v >> 13u; v ^= v << 17u; v ^= v >> 5u;
    w1 = 33378u * (w1 & 0xffffu) + (w1 >> 16u);
    w2 = 57225u * (w2 & 0xffffu) + (w2 >> 16u);

    x = u ^ (u << 9); x ^= x >> 17; x ^= x << 6;
    y = w1 ^ (w1 << 17); y ^= y >> 15; y ^= y << 5;

    return (x + v) ^ (y + w2);
}

// Hash from https://www.cs.ubc.ca/~rbridson/docs/schechter-sca08-turbulence.pdf
// - Schechter and Bridson, Evolving Sub-Grid Turbulence for Smoke Animation, 2008
uint sca08(uint s) {
    s = (s ^ 2747636419u) * 2654435769u;// % 4294967296u;
    s = (s ^ (s >> 16u)) * 2654435769u;// % 4294967296u;
    s = (s ^ (s >> 16u)) * 2654435769u;// % 4294967296u;
    return s;
}

// SuperFastHash, adapated from http://www.azillionmonkeys.com/qed/hash.html
uint superfast(uint data)
{
	uint hash = 4u, tmp;
    
    hash += data & 0xffffu;
    tmp = (((data >> 16) & 0xffffu) << 11) ^ hash;
    hash = (hash << 16) ^ tmp;
    hash += hash >> 11;

    /* Force "avalanching" of final 127 bits */
    hash ^= hash << 3;
    hash += hash >> 5;
    hash ^= hash << 4;
    hash += hash >> 17;
    hash ^= hash << 25;
    hash += hash >> 6;
    
    return hash;

}

uint2 tea(int t, uint3 p)
{
    uint s = p.z;

    for( int i = 0; i < t; i++) {
        s += 0x9E3779B9u;
        p.x += (p.y<<4u)^(p.y+s)^(p.y>>5u);
        p.y += (p.x<<4u)^(p.x+s)^(p.x>>5u);
    }
    return uint2(p.x, p.y);//p.xy;
}

float trig(float2 p)
{
    return frac(43757.5453*sin(dot(p, float2(12.9898,78.233))));
}

// Wang hash, described on http://burtleburtle.net/bob/hash/integer.html
// original page by Thomas Wang 404
uint wang(uint v)
{
    v = (v ^ 61u) ^ (v >> 16u);
    v *= 9u;
    v ^= v >> 4u;
    v *= 0x27d4eb2du;
    v ^= v >> 15u;
    return v;
}

// 128-bit xorshift
//  - Marsaglia, Xorshift RNGs, Journal of Statistical Software, v8n14, 2003
uint4 xorshift128(uint4 v)
{
    v.w ^= v.w << 11u;
    v.w ^= v.w >> 8u;
    v = uint4(v.w, v.x, v.y, v.z); //v.wxyz;
    v.x ^= v.y;
    v.x ^= v.y >> 19u;
    return v;
}

// 32-bit xorshift
//  - Marsaglia, Xorshift RNGs, Journal of Statistical Software, v8n14, 2003
uint xorshift32(uint v) {
    v ^= v << 13u;
    v ^= v >> 17u;
    v ^= v << 5u;
    return v;
}

// xxhash (https://github.com/Cyan4973/xxHash)
//   From https://www.shadertoy.com/view/Xt3cDn
uint xxhash32(uint2 p)
{
    const uint PRIME32_2 = 2246822519U, PRIME32_3 = 3266489917U;
	const uint PRIME32_4 = 668265263U, PRIME32_5 = 374761393U;
    uint h32 = p.y + PRIME32_5 + p.x*PRIME32_3;
    h32 = PRIME32_4*((h32 << 17) | (h32 >> (32 - 17)));
    h32 = PRIME32_2*(h32^(h32 >> 15));
    h32 = PRIME32_3*(h32^(h32 >> 13));
    return h32^(h32 >> 16);
}

// Hash without Sine, https://www.shadertoy.com/view/4djSRW
float3 hashwithoutsine(float2 p)
{
	float3 p3 = frac(float3(p.x, p.y, p.x) * float3(.1031, .1030, .0973));//frac(float3(p.xyx) * float3(.1031, .1030, .0973));
    p3 = p3 + dot(p3, float3(p3.y, p3.x, p3.z) + 19.19);//dot(p3, p3.yxz+19.19);
    return frac((float3(p3.x, p3.x, p3.y) + float3(p3.y, p3.z, p3.z)) * float3(p3.z, p3.y, p3.x));//frac((p3.xxy+p3.yzz)*p3.zyx);
}

uint taus(uint z, int s1, int s2, int s3, uint m)
{
	uint b = (((z << s1) ^ z) >> s2);
    return (((z & m) << s3) ^ b);
}

// https://developer.nvidia.com/gpugems/GPUGems3/gpugems3_ch37.html
uint hybridtaus(uint4 z)
{
    for (int i = 0; i < 1; i++) {
        z.x = taus(z.x, 13, 19, 12, 4294967294u);
        z.y = taus(z.y, 2, 25, 4, 4294967288u);
        z.z = taus(z.z, 3, 11, 17, 4294967280u);
        z.w = z.w * 1664525u + 1013904223u;
    }
    
    return z.x ^ z.y ^ z.z ^ z.w;
}
