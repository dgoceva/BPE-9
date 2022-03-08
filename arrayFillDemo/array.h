#ifndef ARRAY_H_INCLUDED
#define ARRAY_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateArray(int array[],unsigned len);
void printArray(int array[],unsigned len);
unsigned fillArray(int dest[],int src[],unsigned len);
int firstDigit(int a);
int lastDigit(int a);
unsigned fillArray1(int dest[],int src[],unsigned len);

#endif // ARRAY_H_INCLUDED
