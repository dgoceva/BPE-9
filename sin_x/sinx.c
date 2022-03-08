#include "sinx.h"

double sinx0(double x)
{
    double sum = 0;
    double nom = x;
    double denom = 1;
    unsigned fact = 3;

    for (int i=1;i<1000;++i,fact+=2){
        sum += nom/denom;
        nom *= -x*x;
        denom *= (fact-1)*fact;
    }

    return sum;
}

double sinx(double x)
{
    double sum = 0;
    double member = x;
    unsigned fact = 3;

    for (int i=1;i<1000;++i,fact+=2){
        sum += member;
        member *= -x*x/((fact-1)*fact);
    }

    return sum;
}

// eps | memberN-memberN-1 | < eps
double sinxAE(double x)
{
    double sum = 0;
    double member = x;
    double member1 = 0;
    unsigned fact = 3;
    int cnt=0;

    while (fabs(member-member1)>=EPS) {
        sum += member;
        member1 = member;
        member *= -x*x/((fact-1)*fact);
        fact +=2;
        cnt++;
    }

    printf("counter: %d\n",cnt);
    return sum;
}

// delta | (memberN-memberN-1)/memberN | < delta
double sinxRE(double x)
{
    double sum = 0;
    double member = x;
    double member1 = 0;
    unsigned fact = 3;
    int cnt=0;

    while (fabs((member-member1)/member)>=DELTA) {
        sum += member;
        member1 = member;
        member *= -x*x/((fact-1)*fact);
        fact +=2;
        cnt++;
    }

    printf("counter: %d\n",cnt);
    return sum;
}
