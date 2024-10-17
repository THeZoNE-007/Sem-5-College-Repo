#include <stdio.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void main ()
{
	//pointer initialization
	int a = 10, b = 20;
	printf("Before swap : ");
	printf("a= %d b= %d",a,b);
	swap(&a, &b);
	printf("After swapping: ");
	printf("a= %d b= %d",a,b);
}
