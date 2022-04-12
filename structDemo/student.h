#ifndef STUDENT_H_INCLUDED
#define STUDENT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 50
#define SIZE 3

// struct declaration
struct TTStudent {
    unsigned fNom;
    char name[N];
    float avMark;
};

typedef struct TTStudent TStudent;

struct TTStudent input();
void print(TStudent st);
void inputGroup(TStudent *group, unsigned len);
void printGroup(TStudent *group, unsigned len);
float averageGroup(TStudent *group, unsigned len);
float my_round(float data, unsigned dec);

#endif // STUDENT_H_INCLUDED
