#include <stdio.h>
#include <stdlib.h>

#define PR(format, value) printf(""#value" = %"#format"\t",(value))
#define NL printf("\n")

int a[]={0,1,2,3,4};

void no_swap(int x, int y)
{
    int temp = x;
    x = y;
    y = temp;
    printf("x=%d,y=%d\n",x,y);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
    printf("x=%d,y=%d\n",*x,*y);
}

void pointer2()
 {
        int i,*p;
        for (i=0; i<=4; i++) PR(d,a[i]);
        NL;
        for (p=&a[0]; p<=&a[4]; p++)
           PR(d,*p);
        NL; NL;
        for (p=&a[0],i=1; i<=5; i++)
           PR(d,p[i]);
        NL;
        for (p=a,i=0; p+i<=a+4; p++,i++)
           PR(d,*(p+i));
        NL; NL;
        for (p=a+4; p>=a; p--) PR(d,*p);
        NL;
        for (p=a+4,i=0; i<=4; i++) PR(d,p[-i]);
        NL;
        for (p=a+4; p>=a; p--) PR(d,a[p-a]);
        NL;
}

void pointer()
{
    int x=1, y=2,z[]={0,1,2,3,4,5,6,7,8,9};
    int *ip;

    printf("1: %p %d\n",ip,*ip);
    printf("1: %p\n",ip);
    ip = &x;
    printf("2: %p %d\n",ip,*ip);

    *ip = *ip+2;
    printf("3: %p %d %d\n",ip,*ip, x);

    ip = z;
    printf("4: %p %d\n",ip,*ip);  //z[0]
    y += *ip++;
    printf("5: %p %d %d\n",ip,*ip,y);
    (*ip)++;
    printf("6: %p %d\n",ip,*ip);
    ++*ip;
    printf("7: %p %d\n",ip,*ip);
    *++ip;
    printf("8: %p %d\n",ip,*ip);

    for (int i=0;i<10;++i)
        printf("%d ",z[i]);
    NL;

    for(ip=z;ip-z<10;++ip)
        printf("%d ",*ip);
    NL;

    no_swap(x,y);
    printf("x=%d,y=%d\n",x,y);
    swap(&x,&y);
    printf("x=%d,y=%d\n",x,y);
}

int main(int argc,char *argv[])
{
  //  pointer();
//    pointer2();
    printf("%d\n",argc);
    for (int i=0;i<argc;++i){
        printf("%s\n",argv[i]);
    }

    return EXIT_SUCCESS;
}
