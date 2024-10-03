#include<stdio.h>

int main() 
{
	int a = 10;
	printf("value = %d and address = %x\n", a,&a);
	printf("value = %d and address = %u\n", a,&a);
	printf("value = %d and address = %lu\n", a,&a);
	printf("value = %d and address = %p\n", a,&a);
	printf("value = %d and address = %lp\n", a,&a);
}
