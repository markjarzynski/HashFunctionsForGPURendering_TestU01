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

#include <stdio.h>

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

        if ( 1u <= a && a < 32u ) {
            ret.x = x >> a;
            ret.y = (x << (32u - a)) | (y >> a);
            ret.z = (y << (32u - a)) | (z >> a); 
        } else if ( 32u <= a && a < 64u ) {
            ret.x = 0u;
            ret.y = x >> (a - 32u);
            ret.z = (x << (64u - a)) | (y >> (a - 32u));
        } else if ( 64u <= a && a < 96u ) {
            ret.x = 0u;
            ret.y = 0u;
            ret.z = x >> (a - 64u);
        } else {
            ret.x = x;
            ret.y = y;
            ret.z = z;
        }

        return ret;
    }

    uint96 operator >> (const int a) const
    {
        return *this >> uint(a);
    }

    uint96& operator >>= (const uint a)
    {
        *this = *this >> a;
        return *this;
    }

    uint96 operator << (const uint a) const
    {
        uint96 ret = 0u;

        if ( 1u <= a && a < 32u ) {
            ret.x = (x << a) | (y >> (32u - a));
            ret.y = (y << a) | (z >> (32u - a));
            ret.z = (z << a);
        } else if ( 32u <= a && a < 64u ) {
            ret.x = (y << (a - 32u)) | (z >> (64u - a));
            ret.y = z << (a - 32u);
            ret.z = 0u;
        } else if ( 64u <= a && a < 96u ) {
            ret.x = z << (a - 64u);
            ret.y = 0u;
            ret.z = 0u;
        } else {
            ret.x = x;
            ret.y = y;
            ret.z = z;
        }

        return ret;
    }

    uint96& operator <<= (const uint a)
    {
        *this = *this << a;
        return *this;
    }

    bool operator == (const uint a) const
    {
        return x == 0u && y == 0u && z == a;
    }

    bool operator == (const uint96 a) const
    {
        return x == a.x && y == a.y && z == a.z;
    }

    bool operator > (const uint a) const
    {
        return x > 1u || y > 1u || z > a;
    }
    
    bool operator >= (const uint a) const
    {
        return x > 1u || y > 1u || z >= a;
    }

    bool operator > (const uint96 a) const
    {
        if ( x > a.x) {
            return true;
        } else if ( x == a.x ) {
            if ( y > a.y ) {
                return true;
            } else if ( y == a.y ) {
                return z > a.z;
            }
        }

        return false;
    }

    bool operator >= (const uint96 a) const
    {
        if ( x > a.x ) {
            return true;
        } else if ( x == a.x ) {
            if ( y > a.y ) {
                return true;
            } else if (y == a.y) {
                return z >= a.z;
            }
        }

        return false;
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
        uint96 ret = 0u;

        for (uint i = 0; i < 96; i++) {
            if (((*this >> i) & 1u) == 1u) {
                ret += a << i;
            }
        }

        return ret;
    }

    uint96& operator *= (const uint96 a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator * (const uint a) const
    {
        return *this * uint96(a);
    }

    uint96& operator *= (const uint a)
    {
        *this = *this * a;
        return *this;
    }

    uint96 operator / (const uint96 d) const
    {
        if (d == 0u) {
            // error divide by zero
        }

        uint96 q = 0u;
        uint96 r = 0u;

        for (uint i = 96u; i > 0u; i--) {
            r = r << 1u;
            r = (r & ~uint96(1u)) | ((*this >> (i - 1u)) & 1u);
            if (r >= d) {
                r = r - d;
                q |= uint96(1u) << (i - 1u);
            }
        }
        return q; 
    }

    uint96& operator /= (const uint96 a)
    {
        *this = *this / a;
        return *this;
    }

    uint96 operator / (const uint a) const
    {
        return *this / uint96(a);
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
