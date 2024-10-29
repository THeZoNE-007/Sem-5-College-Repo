// swap the first two elements of an array using pointers
#include<stdio.h>
void swap(int *a,int *b){
   *a=*a+*b;
   *b=*a-*b;
   *a=*a-*b;
}
void main(){
   int ar[5]={1,2,3,4,5};
   printf("Array before swapping: ");
   for(int i=0;i<5;i++){
      printf(", %d",ar[i]);
   }
   swap(&ar[0],&ar[1]);
   printf("\nArray After swapping: ");
   for(int i=0;i<5;i++){
      printf(", %d",ar[i]);
   }
   
}
