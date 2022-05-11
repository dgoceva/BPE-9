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

void changeMark(TStudent *student, char * subject, int mark)
{
    if (!strcmp("Mat",subject)) {
        for (int i=0;i<MARK_SIZE;++i)
            if (student->mat[i]==0){
                    student->mat[i] = mark;
                    return;
            }
    } else if (!strcmp("BG",subject)) {
           for (int i=0;i<MARK_SIZE;++i)
            if (student->bg[i]==0){
                    student->bg[i] = mark;
                    return;
            }
    } else if (!strcmp("IT",subject)) {
           for (int i=0;i<MARK_SIZE;++i)
            if (student->it[i]==0){
                    student->it[i] = mark;
                    return;
            }
    }
}

void addGrade(TStudent *data, char *command, unsigned size)
{
    char number[NUMBER_SIZE]+1;
    char subject[SUBJECT_SIZE]+1;
    int mark;

    memcpy(subject,command,SUBJECT_SIZE);
    subject[SUBJECT_SIZE]='\0';
    mark = command[SUBJECT_SIZE+1]-'0';
    memcpy(number,command+SUBJECT_SIZE+3,NUMBER_SIZE);
    number[NUMBER_SIZE]='\0';

    int index = findStudent(number,data,size);

    if (index==-1){
        return;
    }

    changeMark(data+index,subject,mark);
}

TAVMark calcAvMarkStudent(TStudent student)
{
    TAvMark avMark = {0,0,0};

    for (int i=0;student.mat[i];++i)
        avMark.mat += student.mat[i];

    avMark.mat = i ? avMark.mat/i : 0;

    for (int i=0;student.bg[i];++i)
        avMark.bg += student.bg[i];

    avMark.bg = i ? avMark.bg/i : 0;

    for (int i=0;student.it[i];++i)
        avMark.it += student.it[i];

    avMark.it = i ? avMark.it/i : 0;

    return avMark;
}

TAvMark calcAverage(TStudent *data, char *command, unsigned size)
{
    char class[CLASS_SIZE+1];
    TAvMark result = {0,0,0};
    TAvMark stRes;
    int count=0;

    memcpy(class,command,CLASS_SIZE);
    for (int i=0;i<size;++i){
        if (!memcmp(class,data[i].number,CLASS_SIZE)){
            count++;
            stRes = calcAvMarkStudent(data[i]);
            result.mat += stRes.mat;
            result.bg += stRes.bg;
            result.it += stRes.it;
        }
    }
    if (count){
        result.mat /= count;
        result.bg /= count;
        result.it /= count;
    } else {
        result.mat = result.bg = result.it = 0;
    }

    return result;
}

TStudent* addStudent(TStudent *data, char *command, unsigned *size)
{
    char number[NUMBER_SIZE+1];

    memcpy(number,command[strlen(command)-NUMBER_SIZE],NUMBER_SIZE);
    number[NUMBER_SIZE]='\0';

    if (findStudent(number,data,*size)!=-1)
        return data;

    data = (TStudent*) realloc(data,*size+sizeof(TStudent));
    if (data==NULL){
        perror("realloc");
        exit(errno);
    }
    initStudent(data[(*size)++],command,number);
    return data;
}

void initStudent(TStudent *student, char *command, char *number)
{
        strcpy(student->number,number);
        sscanf(command,"%s%s%s",student->first,student->second,student->last);

        for (int i=0;i<MARK_SIZE;++i){
            student->mat[i]=student->bg[i]=student->it[i]=0;
        }
}

void writeBin(char *out, TStudent *data, unsigned size)
{
    FILE *fout = fopen(out,"wb");

    if (fout!=NULL){
        perror("write error");
        free(data);
        exit(errno);
    }

    fwrite(data,size,sizeof(TStudent),fout);
    fclose(fout);
}
