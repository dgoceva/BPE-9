#include "student.h"

int main()
{
    char command[SIZE];
    TAvMark average;
    FILE *in = fopen("students.txt","r");

    if (in==NULL){
        perror("open file");
        exit(errno);
    }

    unsigned len = countStudent(in);
    TStudent *data = (TStudent*)calloc(len, sizeof(TStudent));

    if (data==NULL){
        perror("malloc error");
        fclose(in);
        exit(errno);
    }

    readFile("students.txt",data);
    fclose(in);

    while (TRUE){
        if (fgets(command,SIZE,stdin)==NULL)
            break;
        if (!memcmp("ADD grade ",command,strlen("ADD grade "))){
            addGrade(data,command+strlen("ADD grade "),len);
        } else if (!memcmp("Calculate grades ",command,strlen("Calculate grades "))){
            average = calcAverage(data,command+strlen("Calculate grades "),len);
            printf("Average Mat: %g\tBG: %g\tIT: %g\n",average.mat,average.bg,average.it);
        } else if (!memcmp("ADD student ",command,strlen("ADD student "))){
            data = addStudent(data,command+strlen("ADD student "),&len);
        } else if(!strcmp("END",command)){
            writeBin("students.out",data,len);
        }
    }
    free(data);

    return 0;
}
