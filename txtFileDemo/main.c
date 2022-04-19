#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef enum {False, True} TBoolean;

void copyFile(char *src, char *dest)
{
    char c;

    // 1
    FILE *in, *out;

    //2
    in = fopen(src,"r");
    if (in==NULL){
        perror("open source file:");
        exit(EXIT_FAILURE);
    }
    if ((out=fopen(dest,"w"))==NULL){
        perror("open source file:");
        exit(EXIT_FAILURE);
    }

    //3
    while ((c=fgetc(in))!=EOF){
        fputc(c,out);
    }

    //4
    fclose(in);
    fclose(out);
}

void catFile(char *src, char *dest)
{
    FILE *in, *out;
    char buf[BUFSIZ];

    if ((in=fopen(src,"r"))==NULL){
        perror(NULL);
        exit(errno);
    }

     if ((out=fopen(dest,"a"))==NULL){
        perror(NULL);
        exit(errno);
    }

    while((fgets(buf,BUFSIZ,in))!=NULL){
        fputs(buf,out);
        puts(buf);
    }

    fclose(in);
    fclose(out);
}
int readTemp(char *fname, double temperatures[])
{
    FILE *in;
    int len=0;

    if ((in=fopen(fname,"r"))==NULL){
        perror(NULL);
        exit(errno);
    }

    while (True){
        if (fscanf(in,"%lf",&temperatures[len])!=1){
            if (feof(in)){
                fclose(in);
                return len;
            } else {
                perror(NULL);
                fclose(in);
                exit(errno);
            }
        }
        len = (len+1)%MAXSIZE;
    }
    fclose(in);
}
void print(double *temperatures, int len)
{
    for (int i=0;i<len;++i){
        printf("%g\t", temperatures[i]);
    }
    printf("\n");
}

int main()
{
    double tempData[MAXSIZE];
    int len;
//    copyFile("lipsum.txt","lipsum.out.txt");
//    catFile("lipsum.txt","lipsum.dat.txt");
    len = readTemp("temperatures.txt",tempData);
    print(tempData,len);

    return 0;
}
