#include<stdio.h>
#include<math.h>

void separate(double num, char *sign, int *magnitude, double *fraction)
{
	*magnitude = (int)fabs(num);
	if(num >= 0)
	{
		*sign = '+';
	}
	else
	{
		*sign = '-';
	}
	*fraction = fabs(num) -*magnitude;
}

int main()
{
	double num = -10.205;
	int magnitude;
	char sign;
	double fraction;
	
	separate(num, &sign, &magnitude, &fraction);
	printf("Sign:%c\nMagnitude: %d\nFraction: %.3lf\n", sign, magnitude, fraction);
	
	return 0; 
}
