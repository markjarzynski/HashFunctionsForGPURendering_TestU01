/*
 * uint96.h
 *
 * An incomplete implementation of a 96-bit unsigned integer.
 * 
 * Mark Jarzynski <markj1@umbc.edu>
 *
 */
#ifndef UINT96_H
#define UINT96_H

#include <cstdint>

typedef uint32_t uint;

struct uint96
{
    union {
        uint i[3];
        struct {
            uint x, y, z;
        };
    };

    uint96 ()
    {
        i[0] = i[1] = i[2] = 0u;
    }
    
    uint96 ( uint i )
    {
        this->i[0] = 0u;
        this->i[1] = 0u;
        this->i[2] = i;
    }

    uint96 ( uint x, uint y, uint z )
    {
        i[0] = x; i[1] = y; i[2] = z;
    }

    uint96& operator = (const uint96 a)
    {
        i[0] = a.i[0];
        i[1] = a.i[1];
        i[2] = a.i[2];

        return *this;
    }

    uint96& operator = (const uint a)
    {
        i[0] = 0u;
        i[1] = 0u;
        i[2] = a;

        return *this;
    }
    
    uint96 operator ~ () const
    {
        return uint96(~x, ~y, ~z);
    }

    uint96 operator & (const uint96 a) const
    {
        return uint96(x & a.x, y & a.y, z & a.z);
    }
    
    uint96 operator &= (const uint96 a)
    {
        *this = *this & a;
        return *this;
    }

    uint96 operator & (const uint a) const
    {
        return uint96( x & 0u, y & 0u, z & a);
    }

    uint96 operator &= (const uint a) 
    {
        *this = *this & a;
        return *this;
    }
    
    uint96 operator | (const uint96 a) const
    {
        return uint96(x | a.x, y | a.y, z | a.z);
    }

    uint96& operator |= (const uint96 a)
    {
        *this = *this | a;
        return *this;
    }

    uint96 operator | (const uint a) const
    {
        return uint96(x | 0u, y | 0u, z | a);
    }

    uint96& operator |= (const uint a)
    {
        *this = *this | a;
        return *this;
    }

    uint96 operator ^ (const uint96 a) const
    {
        return uint96(x ^ a.x, y ^ a.y, z ^ a.z);
    }

    uint96& operator ^= (const uint96 a)
    {
        *this = *this ^ a;
        return *this;
    }

    uint96 operator ^ (const uint a) const
    {
        return uint96(x ^ 0u, y ^ 0u, z ^ a);
    }

    uint96& operator ^= (const uint a)
    {
        *this = *this ^ a;
        return *this;
    }
 
    uint96 operator + (const uint96 a) const
    {
        uint96 ret = 0u;


        ret.x = x + a.x;
        ret.y = y + a.y;
        ret.z = z + a.z;

        if (ret.x < x) {
            ret.y++;
        }

        if (ret.y < y) {
            ret.z++;
        }

        return ret;
    }

    uint96& operator += (const uint96 a)
    {
        *this = *this + a;
        return *this;
    }

    uint96 operator + (const uint a) const
    {
        uint96 ret = 0u;

        ret.x = x + a;
        
        if (ret.x < x) {
            ret.y++;
            if (ret.y < y) {
                ret.z++;
            }
        }

        return ret;
    }

    uint96& operator += (const uint a)
    {
        *this = *this + a;
        return *this;
    }


    uint96 operator - (const uint96 a) const
    {
        return this + ~a + 1u;
    }

    uint96 operator -= (const uint96 a)
    {
        *this = *this - a;
        return *this;
    }

    uint96 operator - (const uint a) const
    {
        return this + ~a + 1u;
    }

    uint96& operator -= (const uint a)
    {
        *this = *this - a;
        return *this;
    }
    
    uint96& operator ++ ()
    {
        *this = *this + 1u;
        return *this;
    }

    uint96 operator ++ (int)
    {
        uint96 temp = *this;
        ++*this;
        return temp;
    }

    uint96& operator -- ()
    {
        *this = *this - 1u;
        return *this;
    }

    uint96 operator -- (int)
    {
        uint96 temp = *this;
        --*this;
        return temp;
    }

    uint96 operator * (const uint96 a) const
    {

    }

    uint96& operator *= (const uint96 a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator * (const uint a) const
    {

    }

    uint96& operator *= (const uint a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator / (const uint96 a) const
    {

    }

    uint96& operator /= (const uint96 a)
    {
        *this = *this / a;
        return *this;
    }

    uint96 operator / (const uint a) const
    {

    }

    uint96& operator /= (const uint a)
    {
        *this = *this / a;
        return *this;
    }
};

typedef uint96 uint96_t;

#endif
