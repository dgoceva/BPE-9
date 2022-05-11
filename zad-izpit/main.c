#include "student.h"

int main()
{
    FILE *in = fopen("students.txt","r");

    if (in==NULL){
        perror("open file");
        exit(errno);
    }

    unsigned len = countStudent(in);
    TStudent *data = (TStudent*)malloc(len*sizeof(TStudent));

    if (data==NULL){
        perror("malloc error");
        fclose(in);
        exit(errno);
    }

    fclose(in);
    free(data);

    return 0;
}
