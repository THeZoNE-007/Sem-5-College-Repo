#include<stdio.h>

void main()
{
	int a=511,b;
	char *p;
	p=&a;
	b=*p;
	printf("O/p 1\n");
	printf("%d%d%d\n",a,b,*p);
	*p=10;
	printf("O/p 2\n");
	printf("%d%d%d",a,b,*p);
}

/*

O/p should be like (possible on online C compiler) :

/tmp/LvBTLgBc0r.c: In function 'main':
/tmp/LvBTLgBc0r.c:7:10: warning: assignment to 'char *' from incompatible pointer type 'int *' [-Wincompatible-pointer-types]
    7 |         p=&a;
      |          ^
/tmp/LvBTLgBc0r.o
O/p 1
511-1-1
O/p 2
266-110

=== Code Exited With Errors ===
*/
