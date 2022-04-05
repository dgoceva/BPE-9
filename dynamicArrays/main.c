#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate(float *data,unsigned len)
{
    srand(time(NULL));

    for(int i=0;i<len;++i){
        data[i] = rand()%50/5.;
    }
}
void print(float *data,unsigned len)
{
    for (int i=0;i<len;++i){
        printf("%g\t",data[i]);
    }
    printf("\n");
}
void mainArray()
{
    float *data;

    data = (float*) malloc(5*sizeof(float));
    if (data==NULL){
        perror(NULL);
        exit(EXIT_FAILURE);
    }
    generate(data,5);
    print(data,5);
    free(data);
}

void generateMatrix(float**data,unsigned rows)
{
    srand(time(NULL));

    for (int i=0;i<rows;++i){
        for(int j=0;j<=i;++j){
            data[i][j] = rand()%50/5.;
        }
    }
}
void printMatrix(float**data,unsigned rows)
{
    for(int i=0;i<rows;++i){
        for(int j=0;j<=i;++j){
            printf("%g\t",data[i][j]);
        }
        printf("\n");
    }
}
void freeData(float *data[],unsigned len)
{
    for(int j=0;j<len;++j){
        free(data[j]);
        data[j]=NULL;
    }
    free(data);
}
void mainMatrix()
{
    float **data;

    data = (float**) malloc(5*sizeof(float*));
    if (data==NULL){
        perror("malloc data error:");
        exit(EXIT_FAILURE);
    }
    for (int i=0;i<5;++i){
        data[i] = (float*)calloc(i+1,sizeof(float));
        if (data[i]==NULL){
                /*
            for(int j=0;j<i;++j){
                free(data[j]);
                data[j]=NULL;
            }
            free(data);
            */
            freeData(data,i);
            perror("malloc row error:");
            exit(EXIT_FAILURE);
        }
    }

    generateMatrix(data,5);
    printMatrix(data,5);

    freeData(data,5);
    /*
    for(int j=0;j<5;++j){
        free(data[j]);
        data[j]=NULL;
    }
    free(data);
*/
}
int main()
{
//    mainArray();
    mainMatrix();
    return EXIT_SUCCESS;
}
