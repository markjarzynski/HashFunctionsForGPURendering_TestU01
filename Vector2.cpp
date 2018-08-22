#include <cstdint>
#include <iostream>

template <typename T>
class Vector2
{
private:
    template<int a, int b>
    class Swizzle
    {
    private:
        T v[2];
        
    public: 
        Vector2& operator = ( const Vector2& w )
        {
            v[a] = w.x;
            v[b] = w.y;
            return *( Vector2* )this;
        }
/*
        Vector2 operator + ( const Vector2& w ) const
        {
            return Vector2( v[a] + w.x, v[b] + w.y );
        }
*/
        operator Vector2()
        {
            return Vector2( v[a], v[b] );
        }

    };
public:
    union
    {
        T v[2];

        struct
        {
            T x;
            T y;
        };

        Swizzle<0,0> xx;
        Swizzle<0,1> xy;
        Swizzle<1,0> yx;
        Swizzle<1,1> yy;
    };

    Vector2 () : x( 0 ), y ( 0 ) {}

    Vector2 ( T a, T b ) : x ( a ), y ( b ) {}

    Vector2 ( T a ) : x ( a ), y ( a ) {}
    
    Vector2& operator - () const
    {
        return Vector2( -x, -y );
    }

    Vector2 operator + ( const T i ) const
    {
        return Vector2( x + i, y + i);
    }

    Vector2 operator + ( const Vector2& w ) const
    {
        return Vector2( x + w.x, y + w.y );
    }

    Vector2 operator - ( const Vector2& w ) const
    {
        return Vector2( x - w.x, y - w.y );
    }

    Vector2 operator * ( const Vector2& w ) const
    {
        return Vector2( x * w.x, y * w.y );
    }

    Vector2 operator / ( const Vector2& w ) const
    {
        return Vector2( x / w.x, y / w.y );
    }

    Vector2 operator & ( const Vector2& w ) const
    {
        return Vector2( x & w.x, y & w.y );
    }

    Vector2 operator | ( const Vector2& w ) const
    {
        return Vector2( x | w.x, y | w.y );
    }

    Vector2 operator ^ ( const Vector2& w ) const
    {
        return Vector2( x ^ w.x, y ^ w.y );
    }

    Vector2 operator ~ () const
    {
        return Vector2( ~x, ~y );
    }

    Vector2 operator << ( const unsigned int i ) const
    {
        return Vector2( x << i, y << i);
    }
    
    Vector2 operator >> ( const unsigned int i ) const
    {
        return Vector2( x >> i, y >> i);
    }

    Vector2& operator += ( const Vector2& w )
    {
        x += w.x;
        y += w.y;
        return *this;
    }

    Vector2& operator -= ( const Vector2& w )
    {
        x -= w.x;
        y -= w.y;
        return *this;
    }

    Vector2& operator *= ( const Vector2& w )
    {
        x *= w.x;
        y *= w.y;
        return *this;
    }
    
    Vector2& operator /= ( const Vector2& w )
    {
        x /= w.x;
        y /= w.y;
        return *this;
    }

    Vector2& operator &= ( const Vector2& w )
    {
        x &= w.x;
        y &= w.y;
        return *this;
    }

    Vector2& operator |= ( const Vector2& w )
    {
        x |= w.x;
        y |= w.y;
        return *this;
    }

    Vector2& operator ^= ( const Vector2& w )
    {
        x ^= w.x;
        y ^= w.y;
        return *this;
    }

    bool operator == ( const Vector2& w ) const
    {
        return x == w.x && y == w.y;
    }

    bool operator != ( const Vector2& w ) const
    {
        return x != w.x || y != w.y;
    }
};

template <typename S, typename T>
inline Vector2<T> operator + (const S a, const Vector2<T>& b)
{
    return Vector2<T>(a + b.x, a + b.y);
}

template <typename S, typename T>
inline Vector2<T> operator - (const S a, const Vector2<T> b)
{
    return Vector2<T>(a - b.x, a - b.y);
}

/*
template <typename S, typename T>
inline Vector2<T> operator * (const S a, const Vector2<T> b)
{
    return Vector2<T>(a * b.x, a * b.y);
}
*/

template <typename T>
inline T dot (const Vector2<T>& a, const Vector2<T>& b)
{
    return a.x * b.x + a.y * b.y;
}

std::ostream& operator << ( std::ostream& output, const Vector2<unsigned int>& v )
{
    return output << "(" << v.x << "," << v.y << ")";
}

typedef Vector2<unsigned int> uint2;

int main() 
{
    uint2 a = uint2(1,2);
    uint2 b = uint2(3,4);

    uint2 c = a.yx + b.xy;
    
    std::cout << "a" << a << std::endl << "b" << b << std::endl << "c" << c << std::endl;

    return 0;
}
