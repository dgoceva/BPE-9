#include <stdio.h>
#include <stdlib.h>

#define BOOLEAN int
#define FALSE 0

void mainCounting(int *nc,int *nw, int *nl)
{
    char c;
    BOOLEAN isInside=FALSE;

    *nc=*nw=*nl=0;
    while((c=getchar())!=EOF){ // ^Z===EOF
        (*nc)++;
        if (c=='\n'){
            ++*nl;
        }
        if (c=='\n' || c==' ' || c=='\t'){
            isInside = FALSE;
        }
        else if(!isInside){
            isInside = !isInside;
            (*nw)++;
        }

    }
 }

void inputOptionDetect(int argc, char *argv[],BOOLEAN *c, BOOLEAN *m, BOOLEAN *l)
{
    for (int i=1;i<argc;++i){
        if (!strcmp(argv[i],"-c") || !strcmp(argv[i],"--bytes"))
            *c=!FALSE;
        if (!strcmp(argv[i],"-m") || !strcmp(argv[i],"--chars"))
            *m=!FALSE;
        if (!strcmp(argv[i],"-l") || !strcmp(argv[i],"--lines"))
            *l=!FALSE;
    }
}
int main(int argc, char *argv[])
 {
     int nc,nw,nl;
     BOOLEAN print_c=FALSE,print_m=FALSE,print_L=FALSE;

     mainCounting(&nc,&nw,&nl);

     printf("%d\t%d\t%d\n",nl,nw,nc);

     return 0;
 }
