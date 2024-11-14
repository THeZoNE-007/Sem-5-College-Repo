/*
Write a program to take two numerical lists of the same length ended by a sentinel value and store the lists in arrays x and y, each of which has 20 elements. Let n be the actual number of data values in each list. Store the product of corresponding elements of x and y in a third array, z, also of size 20. Display the arrays x, y, and z in a three-column table. Then compute and display the square root of the sum of the items in z. Make up your own data, and be sure to test your program on at least one data set with number lists of exactly 20 items. One data set should have lists of 21 numbers, and one set should have significantly shorter lists.
*/

#include<stdio.h>
#include<math.h>
void main(){
   int ar1[20]={0};
   int ar2[20]={0};
   int ar3[20]={0};
   int sv=-1;
   for(int i=0;i<20;i++){
      printf("Enter value for %d element of ar1:",i+1);
      int num=0;
      scanf("%d",&num);
      if(num==sv){
         break;
      }
      ar1[i]=num;
   }
   for(int i=0;i<20;i++){
      printf("Enter value for %d element of ar2:",i+1);
      int num=0;
      scanf("%d",&num);
      if(num==sv){
         break;
      }
      ar2[i]=num;
   }
   for(int i=0;i<20;i++){
      ar3[i]=ar1[i]*ar2[i];
   }
   printf("x y z");
   for(int i=0;i<20;i++){
     printf("\n%d %d %d",ar1[i],ar2[i],ar3[i]);
   }
   double sum=0;
   int i=0;
   while(ar3[i]!=0){
       sum+=ar3[i];
       i+=1;
   }
   double sq=sqrt(sum);
   printf("\nThe square root of the sum of elements in z is %lf",sq);
  
}
