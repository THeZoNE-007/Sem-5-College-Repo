#include<stdio.h>

int main()
{
	int *p,*q;
	int a=10,b;
	p=&a;
	printf("Output 1: \n");
	printf("%d\n%d\n%u\n%u\n",a,*p,&a,p);
	b=*p;
	q=p;
	*q=0;
	printf("Output 2: \n");
	printf("%d\n%d",a,b);
}
