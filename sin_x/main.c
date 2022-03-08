#include "sinx.h"

int main()
{
    double x, xrad;

    printf("x=");
    scanf("%lf",&x);
    xrad = x/180*M_PI;

    printf("sin0(%g)=%lf\n",x,sinx0(xrad));
    printf("sin(%g)=%lf\n",x,sinx(xrad));
    printf("sinAE(%g)=%lf\n",x,sinxAE(xrad));
    printf("sinRE(%g)=%lf\n",x,sinxRE(xrad));
    printf("from math: %lf\n",sin(xrad));

    return 0;
}
