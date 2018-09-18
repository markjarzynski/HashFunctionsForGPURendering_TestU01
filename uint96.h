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

#include <stdint.h>

typedef uint32_t uint;

class uint96
{
public:
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

    uint96 ( uint *arr )
    {
        i[0] = arr[0];
        i[1] = arr[1];
        i[2] = arr[2];
    }

public:
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
   
    uint96& operator = (const uint a[3])
    {
        x = a[0];
        y = a[1];
        z = a[2];

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

    uint96 operator >> (const uint a) const
    {
        uint96 ret = 0u;

        ret.x = x >> a;
        ret.y = (x << (32u - a)) | (y >> a);
        ret.z = (y << (32u - a)) | (z >> a);

        return ret;
    }

    uint96& operator >>= (const uint a)
    {
        *this = *this >> a;
        return *this;
    }

    uint96 operator << (const uint a) const
    {
        uint96 ret = 0u;

        ret.x = (x << a) | (y >> (32u - a));
        ret.y = (y << a) | (z >> (32u - a));
        ret.z = (z << a);

        return ret;
    }

    uint96& operator <<= (const uint a)
    {
        *this = *this << a;
        return *this;
    }

    uint96 operator + (const uint96 a) const
    {
        uint96 ret = 0u;


        ret.x = x + a.x;
        ret.y = y + a.y;
        ret.z = z + a.z;

        if (ret.z < z) {
            ret.y++;
        }

        if (ret.y < y) {
            ret.x++;
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

        ret.x = x;
        ret.y = y;
        ret.z = z + a;
        
        if (ret.z < z) {
            ret.y++;
            if (ret.y < y) {
                ret.x++;
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
        return *this + ~a + 1u;
    }

    uint96& operator -= (const uint96 a)
    {
        *this = *this - a;
        return *this;
    }

    uint96 operator - (const uint a) const
    {
        uint96 ret = *this + ~a + 1u;
        
        return ret;
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
        return 0u;
    }

    uint96& operator *= (const uint96 a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator * (const uint a) const
    {
        return 0u;
    }

    uint96& operator *= (const uint a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator / (const uint96 a) const
    {
        return 0u;
    }

    uint96& operator /= (const uint96 a)
    {
        *this = *this / a;
        return *this;
    }

    uint96 operator / (const uint a) const
    {
        return 0u;
    }

    uint96& operator /= (const uint a)
    {
        *this = *this / a;
        return *this;
    }

    operator uint()
    {
        return z;
    }

};



typedef uint96 uint96_t;

#endif
