/* Write a C program to find out sum and average of 10 students using Array*/

#include<stdio.h>

void main(){
    int n=10;
    int age[n];
    int sum=0;
    for(int i=0;i<n;i++){
       printf("Enter a age: ");
       scanf("%d",&age[i]);
       sum+=age[i];
    }
    printf("%d",age);
    printf("The sum of ages: %d",sum);
    printf("\nThe avg of ages: %d",sum/n);

}
