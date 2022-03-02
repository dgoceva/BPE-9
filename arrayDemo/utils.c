#include "utils.h"

void my_sort(int data[], unsigned len)
{
    int i,j;
    int temp;

    for (i=len-1;i>=0;--i){
        for (j=0;j<i;++j){
            if (data[j]>data[j+1]){
               temp = data[j];
               data[j]=data[j+1];
               data[j+1] = temp;
            }
        }
    }
}

void print(const int array[],unsigned len)
{
    int i;

    for (i=0;i<len;++i){
        printf("%d ",array[i]);
    }
    printf("\n");
}

int compare(const void* a,const void *b){
    int a1 = *(int*)a;
    int b1 = *(int*)b;
    return a1-b1;
//    int *a1 = (int*)a;
//    int *b1 = (int*)b;
//    return *a1-*b1;
//    return *b1-*a1;
}

void itob(unsigned n, char *s, unsigned base)
{
    const unsigned LEN=10;
    char d;
    int i=LEN-1;

    memset(s,' ',LEN);
    s[LEN] = '\0';

    if (n==0){
        s[i] = '0';
        return;
    }
    while(n>0){
        if (n%base>9){
            d = n%base + '7';
        }else {
            d = n%base + '0';
        }
        s[i--] = d;
        n /= base;
    }
}

void escape(char s[], const char *t)
{
    // '\n' => "\n"
    // '\t' => "\t"

    int i,j;

    for (i=j=0;i<strlen(t);++i){
        switch(t[i]){
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
           default:
                s[j++] = t[i];
        }
    }
    s[j] = '\0';
}
