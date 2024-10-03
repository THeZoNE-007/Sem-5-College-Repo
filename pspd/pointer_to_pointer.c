#include<stdio.h>

int main() 
{
	int a;
	int *pa;
	int **ppa;
	int ***pppa;
	a=10;
	pa=&a;
	ppa=&pa;
	pppa=&ppa;
}
