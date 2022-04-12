#include "student.h"

void mainStruct()
{
    // struct defition
    struct TTStudent st1;
    TStudent *st2, group[SIZE];

//    st1 = input();
//    print(st1);

/*
    if ((st2 = (TStudent*)malloc(sizeof(TStudent)))==NULL){
        perror(NULL);
        return EXIT_FAILURE;
    }
    *st2 = input();
    print(*st2);

    free(st2);
*/
    inputGroup(group,3);
    printGroup(group,3);
    printf("Average Group Mark: %g\n",averageGroup(group,3));
}

int main()
{
//    mainStruct();
    exStruct1();
    return 0;
}
