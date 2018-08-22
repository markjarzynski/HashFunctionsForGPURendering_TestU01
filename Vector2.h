#ifndef VECTOR2_H
#define VECTOR2_H

#include <cstdint>

template <typename T>
class Vector2
{
private:
    template<int a, int b>
    class Swizzle
    {
    public:
        Vector2& ref;
        
        Vector2& operator = ( const Vector2& v )
        {

            ref.x = v.x;
            ref.y = v.y;
            return ref;
        }

        Swizzle ( Vector2& v ) : ref ( v ) {}
    };
public:
    union
    {
        struct
        {
            T v[2];
        };

        struct // xyzw
        {
            T x;
            T y;
        };

        struct // rgba
        {
            T r;
            T g;
        };

        struct // stpq
        {
            T s;
            T t;
        };

    };

    Vector2& operator = ( const Swizzle<0,1> s )
    {
        x = s.ref.x;
        y = s.ref.y;
        return *this;
    }

    Vector2& operator = ( const Swizzle<1,0> s )
    {
        x = s.ref.y;
        y = s.ref.x;
        return *this;
    }

    Vector2& operator = ( const Swizzle<0,0> s )
    {
        x = s.ref.x;
        y = s.ref.x;
        return *this;
    }

    Vector2& operator = ( const Swizzle<1,1> s )
    {
        x = s.ref.y;
        y = s.ref.y;
        return *this;
    }

    Swizzle<0,0> xx;
    Swizzle<0,1> xy;
    Swizzle<1,0> yx;
    Swizzle<1,1> yy;
    /*
    Swizzle3<0,0,0> xxx;
    Swizzle3<0,0,1> xxy;
    Swizzle3<0,1,0> xyx;
    Swizzle3<0,1,1> xyy;
    Swizzle3<1,0,0> yxx;
    Swizzle3<1,0,1> yxy;
    Swizzle3<1,1,0> yyx;
    Swizzle3<1,1,1> yyy;
    */


    Vector2 ( T x, T y ) : xy ( Swizzle<0,1>( *this ) ), yx ( Swizzle<1,0>( *this ) ), xx ( Swizzle<0,0>( *this ) ), yy ( Swizzle<1,1>( *this ) )
    {
        this->x = x;
        this->y = y;
    }

    Vector2 ( T x ) : xy ( Swizzle<0,1>( *this ) ), yx ( Swizzle<1,0>( *this ) ), xx ( Swizzle<0,0>( *this ) ), yy ( Swizzle<1,1>( *this ) )
    {
        this->x = this->y = x;
    }

    Vector2 () : xy ( Swizzle<0,1>( *this ) ), yx ( Swizzle<1,0>( *this ) ), xx ( Swizzle<0,0>( *this ) ), yy ( Swizzle<1,1>( *this ) )
    {
        this->x = this->y = 0;
    }

};

typedef Vector2<int> int2;
typedef Vector2<unsigned int> uint2;
typedef Vector2<float> float2;
typedef Vector2<double> double2;

typedef Vector2<int> ivec2;
typedef Vector2<unsigned int> uvec2;
typedef Vector2<float> vec2;
typedef Vector2<double> dvec2;

#endif
