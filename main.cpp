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
        genbits("bbs_seeded", bbs_seeded)
        genbits("bbs_nested", bbs_nested)
        genbits("city", city)
        genbits("city_seeded", city_seeded)
        genbits("city_nested", city_nested)
        genbits("esgtsa", esgtsa)
        genbits("esgtsa_seeded", esgtsa_seeded)
        genbits("esgtsa_nested", esgtsa_nested)
        gen01("fast", fast)
        gen01("ign", ign)
        genbits("iqint1", iqint1)
        genbits("iqint1_seeded", iqint1_seeded)
        genbits("iqint1_nested", iqint1_nested)
        genbits("iqint2", iqint2)
        genbits("iqint2.x", iqint2x)
        genbits("iqint2.y", iqint2y)
        genbits("iqint2.z", iqint2z)
        genbits("iqint3", iqint3)
        genbits("jkiss32", jkiss32)
        genbits("lcg", lcg)
        genbits("lcg_seeded", lcg_seeded)
        genbits("lcg_nested", lcg_nested)
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
        genbits("ranlim32_seeded", ranlim32_seeded)
        genbits("ranlim32_nested", ranlim32_nested)
        genbits("superfast", superfast)
        genbits("superfast_seeded", superfast_seeded)
        genbits("superfast_nested", superfast_nested)
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
        genbits("wang_seeded", wang_seeded)
        genbits("wang_nested", wang_nested)
        genbits("xorshift128", xorshift128)            
        genbits("xorshift32", xorshift32)
        genbits("xorshift32_seeded", xorshift32_seeded)
        genbits("xorshift32_nested", xorshift32_nested)
        genbits("xxhash32", xxhash32)
        genbits("xxhash32_2", xxhash32_2)
        genbits("xxhash32_3", xxhash32_3)

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
        
        genbits("bbs_seed3", bbs_seed3)
        genbits("bbs_nested3", bbs_nested3)
        genbits("city_seed3", city_seed3)
        genbits("city_nested3", city_nested3)
        genbits("esgtsa_seed3", esgtsa_seed3)
        genbits("esgtsa_nested3", esgtsa_nested3)
        genbits("iqint1_seed3", iqint1_seed3)
        genbits("iqint1_nested3", iqint1_nested3)
        genbits("lcg_seed3", lcg_seed3)
        genbits("lcg_nested3", lcg_nested3)
        genbits("ranlim32_seed3", ranlim32_seed3)
        genbits("ranlim32_nested3", ranlim32_nested3)
        genbits("superfast_seed3", superfast_seed3)
        genbits("superfast_nested3", superfast_nested3)
        genbits("wang_seed3", wang_seed3)
        genbits("wang_nested3", wang_nested3)
        genbits("xorshift32_seed3", xorshift32_seed3)
        genbits("xorshift32_nested3", xorshift32_nested3)
        
        genbits("bbs_seed4", bbs_seed4)
        genbits("bbs_nested4", bbs_nested4)
        genbits("city_seed4", city_seed4)
        genbits("city_nested4", city_nested4)
        genbits("esgtsa_seed4", esgtsa_seed4)
        genbits("esgtsa_nested4", esgtsa_nested4)
        genbits("iqint1_seed4", iqint1_seed4)
        genbits("iqint1_nested4", iqint1_nested4)
        genbits("lcg_seed4", lcg_seed4)
        genbits("lcg_nested4", lcg_nested4)
        genbits("ranlim32_seed4", ranlim32_seed4)
        genbits("ranlim32_nested4", ranlim32_nested4)
        genbits("superfast_seed4", superfast_seed4)
        genbits("superfast_nested4", superfast_nested4)
        genbits("wang_seed4", wang_seed4)
        genbits("wang_nested4", wang_nested4)
        genbits("xorshift32_seed4", xorshift32_seed4)
        genbits("xorshift32_nested4", xorshift32_nested4)

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
