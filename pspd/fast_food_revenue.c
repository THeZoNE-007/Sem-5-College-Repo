#include <stdio.h>
#include <math.h>

void fast_food_billions(int year){
   int diff=year-2005;
   double res=33.2+(16.8*diff);
   printf("US citizens will charge %lf billions of dollars for fast food in the year %d",res,year);
}

void main(){
   printf("Enter a year after 2005: ");
   int year;
   scanf("%d",&year);
   
   if(year<2005){
      printf("Invalid year entered!!");
     
   }
   else{
      fast_food_billions(year);
      
   }
}
