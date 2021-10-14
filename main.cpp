extern "C" {
    #include "TestU01.h"
}

#include <mpi.h>

#include <cstring>
#include <functional>
#include <iostream>
//#include <map>
#include <string>

#include "random.h"
#include "test.h"

#define NDIM 200
#define SMALLCRUSH_NUM 10
#define CRUSH_NUM 96
#define BIGCRUSH_NUM 106
#define RABBIT_NUM 26
#define ALPHABIT_NUM 9

using namespace std;

int main ( int argc, char** argv )
{
    int id, np, Rep[1 + NDIM] = {0};
    unif01_Gen *gen;
    bool output_to_file = false;
    string outfile = "", hash = "", test = "";
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &np);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    
    // Set the test to the ID of the task. The tests start at 1.
    Rep[id + 1] = 1;
    test = to_string(id);

    // Find the output file from the CLI arguments.
    for (int i = 1; i < argc; i++)
    {
        if (strncmp(argv[i], "--output=", 9) == 0)
        {
            output_to_file = true;

            int len = strlen(argv[i]) - 8;
            char temp[len];
            strncpy(temp, argv[i] + 9, len);

            outfile = temp;
        }
    }
   
    // Find the hash name.
    for (int i = 1; i < argc; i++) 
    {
        if ( false ) { }

#define genbits(NAME, HASH)                                                     \
        else if ( strcmp(argv[i], NAME) == 0 )                              \
        {                                                                   \
            hash = NAME;                                                    \
            gen = unif01_CreateExternGenBits((char*) NAME, test_##HASH);    \
        }

#define gen01(NAME, HASH)                                                       \
        else if ( strcmp(argv[i], NAME) == 0 )                              \
        {                                                                   \
            hash = NAME;                                                    \
            gen = unif01_CreateExternGen01((char*) NAME, test_##HASH);      \
        }

        genbits("bbs", bbs)
        genbits("bbs_linear2", bbs_linear2)
        genbits("bbs_nested2", bbs_nested2)
        genbits("city", city)
        genbits("city_linear2", city_linear2)
        genbits("city_nested2", city_nested2)
        genbits("esgtsa", esgtsa)
        genbits("esgtsa_linear2", esgtsa_linear2)
        genbits("esgtsa_nested2", esgtsa_nested2)
        gen01("fast", fast)
        gen01("ign", ign)
        genbits("iqint1", iqint1)
        genbits("iqint1_linear2", iqint1_linear2)
        genbits("iqint1_nested2", iqint1_nested2)
        genbits("iqint2", iqint2)
        genbits("iqint2.x", iqint2x)
        genbits("iqint2.y", iqint2y)
        genbits("iqint2.z", iqint2z)
        genbits("iqint3", iqint3)
        genbits("iqint3_1", iqint3_1)
        genbits("jkiss32", jkiss32)
        genbits("lcg", lcg)
        genbits("lcg_linear2", lcg_linear2)
        genbits("lcg_nested2", lcg_nested2)
        genbits("murmur3", murmur3)
        genbits("pcg3d", pcg3d)
        genbits("pcg3d.x", pcg3dx)
        genbits("pcg3d.y", pcg3dy)
        genbits("pcg3d.z", pcg3dz)
        genbits("pcg3d16", pcg3d16)
        genbits("pcg3d16.x", pcg3d16x)
        genbits("pcg3d16.y", pcg3d16y)
        genbits("pcg3d16.z", pcg3d16z)
        gen01("pseudo", pseudo)
        genbits("ranlim32", ranlim32)
        genbits("ranlim32_linear2", ranlim32_linear2)
        genbits("ranlim32_nested2", ranlim32_nested2)
        genbits("superfast", superfast)
        genbits("superfast_linear2", superfast_linear2)
        genbits("superfast_nested2", superfast_nested2)
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
        genbits("wang_linear2", wang_linear2)
        genbits("wang_nested2", wang_nested2)
        genbits("xorshift128", xorshift128)            
        genbits("xorshift32", xorshift32)
        genbits("xorshift32_linear2", xorshift32_linear2)
        genbits("xorshift32_nested2", xorshift32_nested2)
        genbits("xxhash32", xxhash32)
        genbits("xxhash32_2", xxhash32_2)
        genbits("xxhash32_3", xxhash32_3)
        genbits("xxhash32_4", xxhash32_4)
        genbits("xxhash32_linear2", xxhash32_linear2)
        genbits("xxhash32_linear3", xxhash32_linear3)
        genbits("xxhash32_linear4", xxhash32_linear4)
        genbits("xxhash32_nested2", xxhash32_nested2)
        genbits("xxhash32_nested3", xxhash32_nested3)
        genbits("xxhash32_nested4", xxhash32_nested4)

        gen01("hashwithoutsine11", hashwithoutsine11)
        gen01("hashwithoutsine12", hashwithoutsine12)
        gen01("hashwithoutsine13", hashwithoutsine13)
        gen01("hashwithoutsine21", hashwithoutsine21)
        gen01("hashwithoutsine22", hashwithoutsine22)
        gen01("hashwithoutsine23", hashwithoutsine23)
        gen01("hashwithoutsine31", hashwithoutsine31)
        gen01("hashwithoutsine32", hashwithoutsine32)
        gen01("hashwithoutsine33", hashwithoutsine33)
        gen01("hashwithoutsine41", hashwithoutsine41)
        gen01("hashwithoutsine42", hashwithoutsine42)
        gen01("hashwithoutsine43", hashwithoutsine43)
        gen01("hashwithoutsine44", hashwithoutsine44)

        genbits("hybridtaus", hybridtaus)
        genbits("Rand3DPCG32", Rand3DPCG32)
        genbits("Rand4DPCG32", Rand3DPCG32)
        genbits("pcg2d", pcg2d)
        genbits("pcg2d.x", pcg2dx)
        genbits("pcg2d.y", pcg2dy)
        genbits("pcg4d", pcg4d)
        genbits("pcg4d.x", pcg4dx)
        genbits("pcg4d.y", pcg4dy)
        genbits("pcg4d.z", pcg4dz)
        genbits("pcg4d.w", pcg4dw)
        
        genbits("bbs_linear3", bbs_linear3)
        genbits("bbs_nested3", bbs_nested3)
        genbits("city_linear3", city_linear3)
        genbits("city_nested3", city_nested3)
        genbits("esgtsa_linear3", esgtsa_linear3)
        genbits("esgtsa_nested3", esgtsa_nested3)
        genbits("iqint1_linear3", iqint1_linear3)
        genbits("iqint1_nested3", iqint1_nested3)
        genbits("lcg_linear3", lcg_linear3)
        genbits("lcg_nested3", lcg_nested3)
        genbits("ranlim32_linear3", ranlim32_linear3)
        genbits("ranlim32_nested3", ranlim32_nested3)
        genbits("superfast_linear3", superfast_linear3)
        genbits("superfast_nested3", superfast_nested3)
        genbits("wang_linear3", wang_linear3)
        genbits("wang_nested3", wang_nested3)
        genbits("xorshift32_linear3", xorshift32_linear3)
        genbits("xorshift32_nested3", xorshift32_nested3)
        
        genbits("bbs_linear4", bbs_linear4)
        genbits("bbs_nested4", bbs_nested4)
        genbits("city_linear4", city_linear4)
        genbits("city_nested4", city_nested4)
        genbits("esgtsa_linear4", esgtsa_linear4)
        genbits("esgtsa_nested4", esgtsa_nested4)
        genbits("iqint1_linear4", iqint1_linear4)
        genbits("iqint1_nested4", iqint1_nested4)
        genbits("lcg_linear4", lcg_linear4)
        genbits("lcg_nested4", lcg_nested4)
        genbits("ranlim32_linear4", ranlim32_linear4)
        genbits("ranlim32_nested4", ranlim32_nested4)
        genbits("superfast_linear4", superfast_linear4)
        genbits("superfast_nested4", superfast_nested4)
        genbits("wang_linear4", wang_linear4)
        genbits("wang_nested4", wang_nested4)
        genbits("xorshift32_linear4", xorshift32_linear4)
        genbits("xorshift32_nested4", xorshift32_nested4)

        /*
        genbits("hashadd", hashadd)
        genbits("hashmul", hashmul)

        genbits("bbs_2", bbs_2)
        genbits("bbs_3", bbs_3)
        genbits("bbs_4", bbs_4)
        genbits("city_2", city_2)
        genbits("city_3", city_3)
        genbits("city_4", city_4)
        genbits("esgtsa_2", esgtsa_2)
        genbits("esgtsa_3", esgtsa_3)
        genbits("esgtsa_4", esgtsa_4)
        genbits("iqint1_2", iqint1_2)
        genbits("iqint1_3", iqint1_3)
        genbits("iqint1_4", iqint1_4)
        genbits("lcg_2", lcg_2)
        genbits("lcg_3", lcg_3)
        genbits("lcg_4", lcg_4)
        genbits("ranlim32_2", ranlim32_2)
        genbits("ranlim32_3", ranlim32_3)
        genbits("ranlim32_4", ranlim32_4)
        genbits("superfast_2", superfast_2)
        genbits("superfast_3", superfast_3)
        genbits("superfast_4", superfast_4)
        genbits("wang_2", wang_2)
        genbits("wang_3", wang_3)
        genbits("wang_4", wang_4)
        genbits("xorshift32_2", xorshift32_2)
        genbits("xorshift32_3", xorshift32_3)
        genbits("xorshift32_4", xorshift32_4)
        
        genbits("bbs_xor2", bbs_xor2)
        genbits("bbs_xor3", bbs_xor3)
        genbits("bbs_xor4", bbs_xor4)
        genbits("city_xor2", city_xor2)
        genbits("city_xor3", city_xor3)
        genbits("city_xor4", city_xor4)
        genbits("esgtsa_xor2", esgtsa_xor2)
        genbits("esgtsa_xor3", esgtsa_xor3)
        genbits("esgtsa_xor4", esgtsa_xor4)
        genbits("iqint1_xor2", iqint1_xor2)
        genbits("iqint1_xor3", iqint1_xor3)
        genbits("iqint1_xor4", iqint1_xor4)
        genbits("lcg_xor2", lcg_xor2)
        genbits("lcg_xor3", lcg_xor3)
        genbits("lcg_xor4", lcg_xor4)
        genbits("ranlim32_xor2", ranlim32_xor2)
        genbits("ranlim32_xor3", ranlim32_xor3)
        genbits("ranlim32_xor4", ranlim32_xor4)
        genbits("superfast_xor2", superfast_xor2)
        genbits("superfast_xor3", superfast_xor3)
        genbits("superfast_xor4", superfast_xor4)
        genbits("wang_xor2", wang_xor2)
        genbits("wang_xor3", wang_xor3)
        genbits("wang_xor4", wang_xor4)
        genbits("xorshift32_xor2", xorshift32_xor2)
        genbits("xorshift32_xor3", xorshift32_xor3)
        genbits("xorshift32_xor4", xorshift32_xor4)
*/
        genbits("pcg", pcg)
        genbits("pcg_linear2", pcg_linear2)
        genbits("pcg_linear3", pcg_linear3)
        genbits("pcg_linear4", pcg_linear4)
        genbits("pcg_nested2", pcg_nested2)
        genbits("pcg_nested3", pcg_nested3)
        genbits("pcg_nested4", pcg_nested4)

        genbits("city_2", city_2)
        genbits("city_3", city_3)
        genbits("city_4", city_4)

        genbits("murmur3_2", murmur3_2)
        genbits("murmur3_3", murmur3_3)
        genbits("murmur3_4", murmur3_4)
    
        genbits("superfast_2", superfast_2)
        genbits("superfast_3", superfast_3)
        genbits("superfast_4", superfast_4)

        genbits("murmur3_linear2", murmur3_linear2)
        genbits("murmur3_linear3", murmur3_linear3)
        genbits("murmur3_linear4", murmur3_linear4)
        genbits("murmur3_nested2", murmur3_nested2)
        genbits("murmur3_nested3", murmur3_nested3)
        genbits("murmur3_nested4", murmur3_nested4)

        genbits("md5_1", md5_1)
        genbits("md5_2", md5_2)
        genbits("md5_3", md5_3)
        genbits("md5", md5)

        genbits("test", test)
        genbits("pcg3d_31", pcg3d_31)
        genbits("pcg3d_21", pcg3d_21)

        else
        {
            continue;
        }

#undef genbits
#undef gen01
    }

    if (output_to_file) 
    {
        outfile += "/" + hash + "-" + test + ".txt";
        freopen(outfile.c_str(), "w", stdout);
        //setvbuf(stdout, NULL, _IONBF, 0);
    }

    // Find out which battery of tests we are doing then do them.    
    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "--small") == 0)
        {
            bbattery_RepeatSmallCrush(gen, Rep);
            break;
        } 
        else if (strcmp(argv[i], "--crush") == 0)
        {
            bbattery_RepeatCrush(gen, Rep);
        }
        else if (strcmp(argv[i], "--big") == 0)
        {
            bbattery_RepeatBigCrush(gen, Rep);
            break;
        }
        else if (strcmp(argv[i], "--rabbit") == 0)
        {
            //Rabbit(gen, NULL, nb, Rep);
            break;
        }
        else if (strcmp(argv[i], "--alphabit") == 0)
        {
            //Alphabit(gen, NULL, nb, r, s, FALSE, 0, Rep);
            break;
        }
    }

    unif01_DeleteExternGenBits(gen);

    if (output_to_file)
    {
        fclose(stdout);
    }

    return 0;
}
