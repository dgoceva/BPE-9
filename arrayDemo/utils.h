#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print(const int array[], unsigned len);
void my_sort(int array[], unsigned len);
int compare(const void* a,const void *b);
void itob(unsigned n, char *s, unsigned base);
void escape(char s[], const char *t);

#endif // UTILS_H_INCLUDED
