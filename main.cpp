extern "C" {
    #include "TestU01.h"
}

#include <functional>
#include <map>
#include <string>
#include <iostream>

#include "random.h"
#include "test.h"

using namespace std;

int main ( int argc, char** argv )
{
    unif01_Gen *gen;
   

    if (argc > 1)
    {
        for (int i = 1; i < argc; i++) 
        {
            /*
            if ( strcmp(argv[i], "pcg3d") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "pcg3d", test_pcg3d);
            }
            else if ( strcmp(argv[i], "pcg3dx") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "pcg3d.x", test_pcg3dx);
            }
            else if ( strcmp(argv[i], "pcg3dy") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "pcg3d.y", test_pcg3dy);
            }
            else if ( strcmp(argv[i], "pcg3dz") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "pcg3d.z", test_pcg3dz);
            }
            else if ( strcmp(argv[i], "bbs") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "bbs", test_bbs);
            }
            else if ( strcmp(argv[i], "city") == 0 ) 
            {
                gen = unif01_CreateExternGenBits((char*) "city", test_city);
            }
            else if ( strcmp(argv[i], "fast") == 0 ) 
            {
                gen = unif01_CreateExternGen01((char*) "fast", test_fast);
            }
            else if ( strcmp(argv[i], "ign") == 0 ) 
            {
                gen = unif01_CreateExternGen01((char*) "ign", test_ign);
            }
            */
            
            if ( false ) { }

#define genbits(NAME, HASH)                                                     \
            else if ( strcmp(argv[i], NAME) == 0 )                              \
            {                                                                   \
                gen = unif01_CreateExternGenBits((char*) NAME, test_##HASH);    \
            }

#define gen01(NAME, HASH)                                                       \
            else if ( strcmp(argv[i], NAME) == 0 )                              \
            {                                                                   \
                gen = unif01_CreateExternGen01((char*) NAME, test_##HASH);      \
            }

            genbits("bbs", bbs)
            genbits("city", city)
            gen01("fast", fast)
            gen01("ign", ign)
            genbits("iqint1", iqint1)
            genbits("iqint2", iqint2)
            genbits("iqint2.x", iqint2x)
            genbits("iqint2.y", iqint2y)
            genbits("iqint2.z", iqint2z)
            genbits("iqint3", iqint3)
            genbits("jkiss32", jkiss32)
            genbits("lcg", lcg)
            genbits("murmur3", murmur3)
            genbits("pcg3d", pcg3d)
            genbits("pcg3d.x", pcg3dx)
            genbits("pcg3d.y", pcg3dy)
            genbits("pcg3d.z", pcg3dz)
            gen01("pseudo", pseudo)
            genbits("ranlim32", ranlim32)
            genbits("sca08", sca08)
            genbits("superfast", superfast)
            genbits("tea2", tea2)
            genbits("tea2.x", tea2x)
            genbits("tea2.y", tea2y)
            genbits("tea3", tea3)
            genbits("tea3.x", tea3x)
            genbits("tea3.y", tea3y)
            genbits("tea4", tea4)
            genbits("tea4.x", tea4x)
            genbits("tea4.y", tea4y)
            genbits("tea5", tea5)
            genbits("tea5.x", tea5x)
            genbits("tea5.y", tea5y)
            genbits("tea6", tea6)
            genbits("tea6.x", tea6x)
            genbits("tea6.y", tea6y)
            gen01("trig", trig)
            genbits("wang", wang)
            genbits("xorshift128", xorshift128)            
            genbits("xorshift32", xorshift32)
            genbits("xxhash32", xxhash32)
            gen01("hashwithoutsine", hashwithoutsine)
            genbits("hybridtaus", hybridtaus)

            else
            {
                continue;
            }

#undef genbits
#undef gen01

            bbattery_BigCrush(gen);
            unif01_DeleteExternGenBits(gen);
        }
    }
    else 
    {

    }

    return 0;
}
