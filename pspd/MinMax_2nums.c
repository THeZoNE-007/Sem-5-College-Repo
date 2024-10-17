#include <stdio.h>

void minMax(int a, int b, int *max, int *min)
{
	if (a>b)
	{
		*max=a;
		*min=b;
	}
	else if(b>a)
	{
		*max=b;
		*min=a;
	}
	else
	{
		printf("Both are same numbers !!");
		*min=*max=a;
	}
}

void main()
{
	int a=10, b=20;
	printf("Numbers entered: %d %d", a,b);
	printf("");
	int min,max;
	minMax(a,b,&max,&min);
	printf("Max number = %d and Min number = %d", max,min);
}
