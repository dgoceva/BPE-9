#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define SIZE 1000
#define NAME_SIZE 15
#define MARK_SIZE 10
#define NUMBER_SIZE 5
#define SUBJECT_SIZE 3
#define CLASS_SIZE 3

typedef struct {
    char first[NAME_SIZE+1];
    char second[NAME_SIZE+1];
    char last[NAME_SIZE+1];
    char number[NUMBER_SIZE+1];
    unsigned short mat[MARK_SIZE];
    unsigned short bg[MARK_SIZE];
    unsigned short it[MARK_SIZE];
} TStudent;

typedef struct {
    float mat;
    float bg;
    float it;
} TAvMark;

unsigned countStudent(FILE *in);
void readFile(FILE *in, TStudent *data);
int findStudent(char *number, TStudent *data, unsigned size);
void addGrade(TStudent *data, char *command, unsigned size);
void changeMark(TStudent *student, char * subject, int mark);
TAvMark calcAverage(TStudent *data, char *command, unsigned size);
TAVMark calcAvMarkStudent(TStudent student);
TStudent* addStudent(TStudent *data, char *command, unsigned *size);
void initStudent(TStudent *student, char *command, char *number);
void writeBin(char *out, TStudent *data, unsigned size);

#endif // STUDENT_H_INCLUDED
