#include "student.h"

struct TTStudent input()
{
    struct TTStudent st;

    printf("Faculty Number: ");
    scanf("%u",&st.fNom);
    printf("Name: ");
    scanf("%s",st.name);
    printf("Average Mark: ");
    scanf("%f",&st.avMark);

    return st;
}

void print(TStudent st)
{
    printf("%u, %s, %g\n",st.fNom,st.name,st.avMark);
}

void inputGroup(TStudent *group, unsigned len)
{
    for (int i=0;i<len;++i)
        group[i] = input();
}

void printGroup(TStudent *group, unsigned len)
{
    for (int i=0;i<len;++i)
        print(group[i]);
}

float my_round(float data, unsigned dec)
{
        float nom = pow(10,dec);
        return ((int)(data*nom+0.5))/nom;
}
float averageGroup(TStudent *group, unsigned len)
{
    float sum=0;

    for (int i=0;i<len;++i){
        sum += group[i].avMark;
    }

    return (!len) ? 0 : my_round(sum/len,2);
}
