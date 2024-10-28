//write a program in c to find square sum of first 5 elements using call by value
#include<stdio.h>

int square(int num){
   return num*num;
}
void main(){
   int ar[10]={1,2,3,4,5,6,7,8,9,10};
   int sum=0;
   for(int i=0;i<5;i++){
      sum+=square(ar[i]);
   }
   printf("The square sum: %d",sum);
}
