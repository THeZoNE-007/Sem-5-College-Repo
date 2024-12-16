/*
Write a C program to find the employee with the highest salary from a list of employees. Define a structure Employee with the following members.

char name[50];
int id;
float salary;

Create a function that takes an array of Employee structures and returns the Employee with highest salary
*/

#include<stdio.h>
#include<math.h>
struct Employee{
     char name[50];
     int id;
     float salary;
};
struct Employee calculateSalary(struct Employee emp[],int n){
  float salary=0.0;
  struct Employee e;
  for(int i=0;i<n;i++){
      if(emp[i].salary>=salary){
          salary=emp[i].salary;
          e=emp[i];
      }     
  }
  return e;
}
int main(){
     int n;
     printf("Enter the number of employees: ");
     scanf("%d",&n);
     
     struct Employee emp[n];
     for(int i=0;i<n;i++){
        printf("Enter Name: ");
        scanf("%s",&emp[i].name);
        
        printf("\nEnter the ID: ");
        scanf("%d",&emp[i].id);
        
        printf("\nEnter the salary: ");
        scanf("%f",&emp[i].salary);
     }
     
    struct Employee e=calculateSalary(emp,n);
    printf("\nThe Employee with highest salary:");
    printf("\nName:%s",e.name);
    printf("\nID:%d",e.id);
    printf("\nSalary:%.2f",e.salary);
}
