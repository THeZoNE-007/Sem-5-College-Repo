/*
PROBLEM: Process weekly employee time cards to calculate net pay for employees.

ANALYSIS: The program will prompt the user to enter the number of employees and then collect data for each employee, including their identification number, hourly wage rate, and hours worked. The program will calculate gross pay, apply overtime rates, deduct taxes, and compute net pay. Finally, it will display each employee's net pay, the total payroll, and the average amount paid.

DATA REQUIREMENTS:
Problem Inputs:
int num_employees; // Number of employees.
int emp_id; // Employee identification number.
double hourly_wage; // Hourly wage rate.
double hours_worked; // Hours worked during the week.

Problem Outputs:
double gross_pay; // Gross salary before tax deductions.
double net_pay; // Net salary after tax deductions.
double total_payroll; // Total payroll for all employees.
double avg_pay; // Average pay per employee.

DESIGN:
INITIAL ALGORITHM:
1. Prompt user for input on the number of employees (num_employees).
2. Initialize total_payroll to 0.
3. Loop through each employee:
   - Get employee ID, hourly wage, and hours worked.
   - Calculate gross pay based on hours worked (including overtime).
   - Deduct tax from gross pay to get net pay.
   - Accumulate net pay into total payroll.
   - Print employee ID and net pay.
4. Calculate average pay as total payroll divided by num_employees.
5. Print total payroll and average pay.
*/

#include <stdio.h>

int main() {
    int num_employees, emp_id;
    double hourly_wage, hours_worked;
    double gross_pay, net_pay, total_payroll = 0, avg_pay;

    printf("Enter the number of employees: ");
    scanf("%d", &num_employees);

    for (int i = 0; i < num_employees; i++) {
        printf("\nEnter employee ID: ");
        scanf("%d", &emp_id);
        printf("Enter hourly wage: ");
        scanf("%lf", &hourly_wage);
        printf("Enter hours worked: ");
        scanf("%lf", &hours_worked);

        // Calculate gross pay with overtime
        if (hours_worked > 40) {
            gross_pay = (40 * hourly_wage) + ((hours_worked - 40) * hourly_wage * 1.5);
        } else {
            gross_pay = hours_worked * hourly_wage;
        }

        // Calculate net pay after tax deduction
        net_pay = gross_pay - (gross_pay * 0.03625);
        total_payroll += net_pay;

        // Print employee ID and net pay
        printf("Employee ID: %d, Net Pay: %.2lf\n", emp_id, net_pay);
    }

    // Calculate average pay
    avg_pay = total_payroll / num_employees;

    // Print total payroll and average pay
    printf("\nTotal Payroll: %.2lf\n", total_payroll);
    printf("Average Pay: %.2lf\n", avg_pay);

    return 0;
}