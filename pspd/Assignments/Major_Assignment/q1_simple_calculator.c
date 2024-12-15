/*
PROBLEM: Simple Calculator

ANALYSIS
To solve this problem, we need to process arithmetic operations on an accumulator. 
The program uses an initial accumulator value of 0, applies the specified operation, and displays the result after each operation. 
Two functions are required:
    - scan_data: Reads the operator and operand.
    - do_next_op: Applies the operation to the accumulator.

DATA REQUIREMENTS
    - Problem Inputs:   char operator; // The operations to perform (+, -, *, /, ^, q).
                        double operand; // The operand for the operation.
    - Problem Outputs:  double accumulator; // Updated result after applying the operation.

DESIGN
INITIAL ALGORITHM

1. Initialize accumulator to 0.
2. Loop until the quit command (q) is encountered:
    - Read operator and operand using scan_data.
    - Apply operation using do_next_op.
    - Print the updated accumulator.
3. Print the final accumulator value.

IMPLEMENTATION
*/

#include <stdio.h>
#include <math.h>

// Function to scan the operator and operand
void scan_data(char *operator, double *operand) {
    printf("Enter operation and operand (e.g., + 5.0 or q 0): ");
    scanf(" %c %lf", operator, operand);
}

// Function to perform the operation
void do_next_op(char operator, double operand, double *accumulator) {
    switch (operator) {
        case '+':
            *accumulator += operand;
            break;
        case '-':
            *accumulator -= operand;
            break;
        case '*':
            *accumulator *= operand;
            break;
        case '/':
            if (operand != 0) {
                *accumulator /= operand;
            } else {
                printf("Error: Division by zero is not allowed.\n");
            }
            break;
        case '^':
            *accumulator = pow(*accumulator, operand);
            break;
        case 'q':
            break;
        default:
            printf("Invalid operator.\n");
    }
}

// Main function
int main() {
    char operator;
    double operand, accumulator = 0.0;

    printf("Simple Calculator\n");
    do {
        scan_data(&operator, &operand);
        if (operator == 'q') {
            printf("Final result is %.2lf\n", accumulator);
            break;
        }
        do_next_op(operator, operand, &accumulator);
        printf("Result so far is %.2lf\n", accumulator);
    } while (operator != 'q');

    return 0;
}

/*
OUTPUT:-

Simple Calculator
Enter operation and operand (e.g., + 5.0 or q 0): + 5
Result so far is 5.00
Enter operation and operand (e.g., + 5.0 or q 0): + 12
Result so far is 17.00
Enter operation and operand (e.g., + 5.0 or q 0): +13
Result so far is 30.00
Enter operation and operand (e.g., + 5.0 or q 0): q 0
Final result is 30.00
*/