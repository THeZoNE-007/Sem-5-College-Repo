#include<stdio.h>

void main()
{
	int a=10;
	char b='A';
	float c=1.1f;
	double d=6.9;
	
	int *pa = &a;
	char *pb = &b;
	float *pc = &c;
	double *pd = &d;
	
	printf("size of a: %d size of *pa: %d\n", sizeof(a), sizeof(pa));
	printf("size of b: %d size of *pb: %d\n", sizeof(b), sizeof(pb));
	printf("size of c: %d size of *pc: %d\n", sizeof(c), sizeof(pc));
	printf("size of d: %d size of *pd: %d\n", sizeof(d), sizeof(pd));
}
