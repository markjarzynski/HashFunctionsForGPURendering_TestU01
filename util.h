#ifndef UTIL_H
#define UTIL_H

#include <math.h>

double frac( double m )
{
    double i;
    return modf(m, &i);
}

#endif
