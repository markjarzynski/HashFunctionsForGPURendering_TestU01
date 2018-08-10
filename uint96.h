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
    uint i[3];

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

    bool operator > (const uint a)
    {
        if (i[2] > a or i[1] > 0 or i[0] > 0)
        {
            return true;
        }

        return false;
    }

    uint96 operator + (const uint a) const
    {
        uint96 ret = 0u;

        if ((ret.i[2] = i[2] + a) < i[2]) {
            if ((ret.i[1] = i[1] + 1) < i[1]) {
                ret.i[0] = i[0] + 1;
            }
        }

        return ret;
    }

    uint96& operator += (const uint a)
    {
        *this = *this + a;
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
};

typedef uint96 uint96_t;

/*
class uint96
{
public:
    uint i[3];

public:
    uint96 () 
    {
        i[0] = i[1] = i[2] = 0;        
    }

    uint96 (uint32_t i)
    {
        this->i[0] = this->i[1] = 0;
        this->i[2] = i;
    }



};

inline uint96 operator ++ (const uint96 &a)
{
    if (i[2]++ == 0)
    {
        if (i[1]++ == 0)
        {
            i[0]++;
        }
    }
}
*/
#endif
