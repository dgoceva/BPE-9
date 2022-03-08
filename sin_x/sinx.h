#ifndef SINX_H_INCLUDED
#define SINX_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define _USE_MATH_DEFINES
#include <math.h>

#define EPS 1e-6
#define DELTA 0.01

double sinx0(double x);
double sinx(double x);
double sinxAE(double x);
double sinxRE(double x);

#endif // SINX_H_INCLUDED
