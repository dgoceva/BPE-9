#include "array.h"

void generateArray(int array[],unsigned len)
{
        srand(time(NULL));

        for (int i=0;i<len;++i){
            array[i] = rand();
        }
}

void printArray(int array[],unsigned len)
{
        for (int i=0;i<len;++i){
            printf("%d ",array[i]);
        }
        printf("\n");
}

// 123: 123%10 = 3
// 123: 123/10 = 12%10 = 2
unsigned fillArray(int dest[],int src[],unsigned len)
{
        unsigned j=0;

        for (int i=0;i<len;++i){
            if (src[i]%10==src[i]/10%10){
                dest[j++] = src[i];
            }
        }
        return j;
}

unsigned fillArray1(int dest[],int src[],unsigned len)
{
        unsigned j=0;

        for (int i=0;i<len;++i){
            if (firstDigit(src[i])==lastDigit(src[i])){
                dest[j++] = src[i];
            }
        }
        return j;
}

int firstDigit(int a)
{
    a = abs(a);
    while (a/10!=0){
        a /= 10;
    }

    return a;
}

int lastDigit(int a)
{
    return abs(a)%10;
}
