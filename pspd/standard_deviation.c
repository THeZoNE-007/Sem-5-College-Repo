#include <stdio.h>
#include <math.h>
void main(){
   printf("Enter the value of N: ");
   double n;
   scanf("%lf",&n);
   
   int num;
   scanf("%d",&num);
   int count=1;
   int sum=num;
   int smallest=num;
   int largest=num;
   while(count!=n){
      count++;
      scanf("%d",&num);
      sum+=num;
      if(num>largest) largest=num;
      if(num<smallest) smallest=num;
      
   }
   printf("largest %d\n",largest);
   printf("smallest %d\n",smallest);
   printf("average %lf\n",sum/n);
   printf("sum %d\n",sum);
   
   double sd=sqrt((pow(sum,2)/n)-(pow(sum/n,2)));
   printf("the standard deviation is = %lf\n",sd);
   
}
