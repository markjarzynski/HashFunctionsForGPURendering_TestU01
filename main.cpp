extern "C" {
    #include "TestU01.h"
}

#include <cstring>
#include <functional>
#include <iostream>
//#include <map>
#include <string>

#include "random.h"
#include "test.h"

#define SMALLCRUSH_NUM 10
#define CRUSH_NUM 96
#define BIGCRUSH_NUM 106
#define RABBIT_NUM 26
#define ALPHABIT_NUM 9

using namespace std;

int main ( int argc, char** argv )
{
    unif01_Gen *gen;

    int size = 0;
    int* Rep;
    int Rep_len = 0;

    Rep = new int[Rep_len + 1];

    bool output_to_file = false;

    string outfile = "", hash = "", test = "";

    if (argc > 1)
    {
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

        for (int i = 1; i < argc; i++)
        {
            if (strcmp(argv[i], "--small") == 0)
            {
                size = 0;
                Rep_len = SMALLCRUSH_NUM;
                Rep = new int[Rep_len + 1];
                break;
            } 
            else if (strcmp(argv[i], "--crush") == 0)
            {
                size = 1;
                Rep_len = CRUSH_NUM;
                Rep = new int[Rep_len + 1];
                break;
            }
            else if (strcmp(argv[i], "--big") == 0)
            {
                size = 2;
                Rep_len = BIGCRUSH_NUM;
                Rep = new int[Rep_len + 1];
                break;
            }
            else if (strcmp(argv[i], "--rabbit") == 0)
            {
                size = 3;
                Rep_len = RABBIT_NUM;
                Rep = new int[Rep_len + 1];
                break;
            }
            else if (strcmp(argv[i], "--alphabit") == 0)
            {
                size = 4;
                Rep_len = ALPHABIT_NUM;
                Rep = new int[Rep_len + 1];
                break;
            }
        }

        bool flag_test = false;

        for (int i = 1; i < argc; i++)
        {
            if (strncmp(argv[i], "--test=", 7) == 0)
            {
                flag_test = true;
                break;
            }
        }
       
        if (flag_test) 
        {
            for (int i = 1; i < Rep_len; i++)
            {
                Rep[i] = 0;
            }
            for (int i = 1; i < argc; i++)
            {
                if ( strncmp(argv[i], "--test=", 7) == 0 )
                {
                    int len = strlen(argv[i]) - 6;
                    char temp[len];
                    strncpy(temp, argv[i] + 7, len);
                    cout << temp << endl;
                    test = temp;
                    cout << test << endl;
                    
                    int i = atoi(temp);
                    Rep[i] = 1;
                }
            }
        } 
        else 
        {
            for (int i = 0; i < Rep_len; i++)
            {
                Rep[i] = 1;
            }
        }

        /*
        cout << "Rep: ";
        for (int i = 0; i < Rep_len; i++)
        {
            cout << Rep[i];
        }
        cout << endl;
        */

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
            gen01("hashwithoutsine", hashwithoutsine)
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

            genbits("hashadd", hashadd)
            genbits("hashmul", hashmul)

            else
            {
                continue;
            }

#undef genbits
#undef gen01

            if (output_to_file) 
            {
                outfile += "/" + hash + "-" + test + ".txt";
                freopen(outfile.c_str(), "w", stdout);
                //setvbuf(stdout, NULL, _IONBF, 0);
            }

            if (size == 0)
            {
                bbattery_RepeatSmallCrush(gen, Rep);
            }
            else if (size == 1)
            {
                bbattery_RepeatCrush(gen, Rep);
            }
            else if (size == 2)
            {
                bbattery_RepeatBigCrush(gen, Rep);
            }
            else if (size == 3)
            { 
                //Rabbit(gen, NULL, nb, Rep);
            }
            else if (size == 4)
            {
                //Alphabit(gen, NULL, nb, r, s, FALSE, 0, Rep);
            }

            unif01_DeleteExternGenBits(gen);

            if (output_to_file)
            {
                fclose(stdout);
            }
        }
    }
    else 
    {

    }

    return 0;
}
