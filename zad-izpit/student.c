#include "student.h"

unsigned countStudent(FILE *in)
{
    unsigned len=0;
    char buff[SIZE];

    while (fgets(buff,SIZE,in)!=NULL) {
        len++;
    }

    rewind(in);
    return len;
}

void readFile(FILE *in, TStudent *data)
{
// 17113: Ivan Ivanov Ivanov; Mat: 6 6 6 BG: 6 5 6 4 4 IT: 6 3
    char buff[SIZE];
    int i=0;
    int j;
    char *p;

    while (fgets(buff,SIZE,in)!=NULL) {
        p = buff;
        memcpy(data[i].number,p,NUMBER_SIZE);
        data[i].number[NUMBER_SIZE]='\0';
        p+=NUMBER_SIZE+2;

        sscanf(p,"%s%s%s",data[i].first,data[i].second,data[i].last);
        data[i].last[strlen(data[i].last)-1]='\0';
        p+=strlen(data[i].first)+strlen(data[i].second)+strlen(data[i].last)+6;

        j=0;
        while (*p>='2' && *p<='6'){
            data[i].mat[j++] = *p-'0';
            p+=2;
        }
        p+=4;

        j=0;
        while (*p>='2' && *p<='6'){
            data[i].bg[j++] = *p-'0';
            p+=2;
        }
        p+=4;
        j=0;
        while (*p>='2' && *p<='6'){
            data[i].it[j++] = *p-'0';
            p+=2;
        }
        i++;
    }
}

int findStudent(char *number, TStudent *data, unsigned size)
{
    for (int i=0;i<size;++i){
        if (!strcmp(data[i].number,number))
            return i;
    }
    return -1;
}
