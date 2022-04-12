#include <stdio.h>

#define PR(format, value) printf(""#value" = %"#format"\t",(value))
#define NL putchar('\n')

#define PRINT1(f,x1) PR(f,x1), NL
#define PRINT2(f,x1,x2) PR(f,x1), PRINT1(f,x2)
#define PRINT3(f,x1,x2,x3) PR(f,x1), PRINT2(f,x2,x3)
#define PRINT4(f,x1,x2,x3,x4) PR(f,x1), PRINT3(f,x2,x3,x4)

void exStruct1()
{
     static struct S1 {
		char c[4],*s;
	 } s1 = { "abc", "def" };

	 static struct S2 {
		 char *cp;
		 struct S1 ss1;
	 } s2 = { "ghi", { "jkl", "mno" } };

	 PRINT2(c,s1.c[0],*s1.s);
	 PRINT2(s,s1.c,s1.s);

	 PRINT2(s,s2.cp,s2.ss1.s);
	 PRINT2(s,++s2.cp,++s2.ss1.s);
}

struct S1 {
	char *s;
	int i;
	struct S1 *sp1;
 };

 void exStruct2()
 {

	 static struct S1 a[] = {
		 { "abcd", 1, a+1 },
		 { "efgh", 2, a+2 },
		 { "ijkl", 3, a }
	 };
	 struct S1 *p = a;
	 int i;

	 PRINT3(s,a[0].s,p->s,a[2].sp1->s);

	 for (i=0;i<2;i++) {
		PR(d,--a[i].i);
		PRINT1(c,a[i].s[3]);
//		PR(c,++a[i].s[3]);
	 }
	 PRINT3(s,++(p->s),a[(++p)->i].s,a[--(p->sp1->i)].s);
 }
