#include "utils.h"

#define SIZE 10

int main()
{
    int data[SIZE];
    int i;
    unsigned n,base;
    char output[SIZE+1];
    char escape_chars[1000], input[] = "This is a sample\t\tHelp\n\n!";

    for (i=0;i<SIZE;++i){
        data[i] = rand()%50-25;
    }
    print(data,SIZE);

//    qsort(data,SIZE,sizeof(int),compare);
    my_sort(data,SIZE);
    print(data,SIZE);

    printf("Input n: ");
    scanf("%u",&n);
    printf("Input base: ");
    scanf("%u",&base);
    itob(n,output,base);
    printf("%u into base %u = %s\n",n,base,output);

    escape(escape_chars,input);
    puts(input);
    puts(escape_chars);

    return 0;
}


