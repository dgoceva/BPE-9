#include <stdio.h>
#include <stdlib.h>

#define PR(format, value) printf(""#value" = %"#format"\t",(value))
#define NL putchar('\n')

#define PRINT1(f,x1) PR(f,x1), NL
#define PRINT2(f,x1,x2) PR(f,x1), PRINT1(f,x2)
#define PRINT3(f,x1,x2,x3) PR(f,x1), PRINT2(f,x2,x3)
#define PRINT4(f,x1,x2,x3,x4) PR(f,x1), PRINT3(f,x2,x3,x4)

 void main1()
 {
        int a[]={0,1,2,3,4};
        int *p[]={a,a+1,a+2,a+3,a+4};
        int **pp=p;

        PRINT2(d,a,*a);
        PRINT3(d,p,*p,**p);
        PRINT3(d,pp,*pp,**pp);
        NL;
        pp++; PRINT3(d,pp-p,*pp-a,**pp);
        *pp++; PRINT3(d,pp-p,*pp-a,**pp);
        *++pp; PRINT3(d,pp-p,*pp-a,**pp);
        ++*pp; PRINT3(d,pp-p,*pp-a,**pp);
        NL;
        pp=p;
        **pp++; PRINT3(d,pp-p,*pp-a,**pp);
        *++*pp; PRINT3(d,pp-p,*pp-a,**pp);
        ++**pp; PRINT3(d,pp-p,*pp-a,**pp);
 }

 void main2()
 {
        int a[3][3] = {
            {1,2,3},
            {4,5,6},
            {7,8,9} };
        int *pa[3]={a[0],a[1],a[2]};
        int *p=a[0];
        int i;

        for (i=0;i<3;i++)
           PRINT3(d,a[i][2-i],*a[i],*(*(a+i)+i));
        NL;
        for (i=0;i<3;i++)
           PRINT2(d,*pa[i],p[i]);
 }

 int main()
 {
//     main1();
        main2();
        return EXIT_SUCCESS;
 }
