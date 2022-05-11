#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <mem.h>

#define SIZE 1000
#define NAME_SIZE 15
#define MARK_SIZE 10
#define NUMBER_SIZE 5

typedef struct {
    char first[NAME_SIZE+1];
    char second[NAME_SIZE+1];
    char last[NAME_SIZE+1];
    char number[NUMBER_SIZE+1];
    unsigned short mat[MARK_SIZE];
    unsigned short bg[MARK_SIZE];
    unsigned short it[MARK_SIZE];
} TStudent;

unsigned countStudent(FILE *in);
void readFile(FILE *in, TStudent *data);
int findStudent(char *number, TStudent *data, unsigned size);
#endif // STUDENT_H_INCLUDED
