#include<stdio.h>

void main(){
   int n=0;
   printf("Enter the size of the array: ");
   scanf("%d",&n);
   
   int ar[n];
   for(int i=0;i<n;i++){
       printf("Enter array element: %d",i+1);
       scanf("%d",&ar[i]);
   }
   for(int i=0;i<n;i++){
       for(int j=i;j<n;j++){
          if(ar[i]>ar[j]){
             int temp=ar[i];
             ar[i]=ar[j];
             ar[j]=temp;
          }
       }
   }
   printf("Sorted Array:\n");
   for(int i=0;i<n;i++){
      printf("%d\t",ar[i]);
   }
   int mid=n/2;
   
   printf("Enter a element to search: ");
   int num;
   scanf("%d",&num);
   int present=0;
   if(num>ar[mid]){
      for(int i=mid+1;i<n;i++){
         if(ar[i]==num){
            present=1;
         }
      }
   }else{
     for(int i=0;i<mid;i++){
         if(ar[i]==num){
            present=1;
         }
      }
   }
   present==1?printf("Is the number %d present in the sorted array: Yes"):printf("Is the number %d present in the sorted array: false");
   
}
