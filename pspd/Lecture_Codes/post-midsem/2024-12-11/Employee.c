#include <stdio.h>

struct Employee {
    int id;
    char Name[20];
    float Salary;
};

void displayEmployee(struct Employee *s) {
    printf("Employee details are as follows: \n");
    printf("Name: %s", s->Name); 
    printf("Roll: %d\n", s->id);
    float gross = s->Salary + s->Salary * 0.2 + s->Salary * 0.1;
    printf("Gross Salary: %f\n", gross);  
    printf("\n");
}

void getEmployee(struct Employee *s) {
   
    
    printf("Enter the Name: ");
    fgets(s->Name,20, stdin);  
    
    printf("Enter the Employee ID no: ");
    scanf("%d", &s->id);  
    
    printf("Enter the Salary: ");
    scanf("%f", &s->Salary);
    displayEmployee(s);
}

int main() {
    struct Employee ar[4];  
    for (int i = 0; i < 4; i++) {
        getEmployee(&ar[i]);
    }
    return 0;
}
