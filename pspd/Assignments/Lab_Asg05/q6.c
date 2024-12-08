/*
Q6> A C program can represent a real polynomial p (x) of degree n as an array of the real coefficients: 
a subscript 0, a subscript 1, ..., a subscript n ( a subscript n != 0).

p(x) = a subscript 0 + (a subscript 1 * x) + (a subscript 2 * x superscript 2) +...+ (a subscript n * x superscript n)

Write a program that inputs a polynomial of maximum degree 8 and then evaluates the polynomial at various values of x. 
Include a function get_poly that fills the array of coefficients and sets the degree of the polynomial, 
and a function eval_poly that evaluates a polynomial at a given value of x. Use these function prototypes:

void get_poly(double coeff[], int* degreep);
double eval_poly(const double coeff[], int degree, double x);
*/


/*
PROBLEM: Represent and evaluate a polynomial of degree up to 8.

ANALYSIS: The program will input the coefficients of a polynomial, store them in an array, and evaluate 
the polynomial at various values of \( x \). It will use two functions: one to get the polynomial coefficients 
and another to evaluate the polynomial.

DATA REQUIREMENTS:
Problem Inputs:
double coeff[9]; // Array to store coefficients for a polynomial of degree up to 8. 
int degree; // Degree of the polynomial.

Problem Outputs:
Display the evaluated result of the polynomial for given values of \( x \).

DESIGN:
INITIAL ALGORITHM:
1. Define a function get_poly that fills the array of coefficients and sets the degree of the polynomial.
2. Define a function eval_poly that evaluates the polynomial at a given value of \( x \).
3. In the main function, call get_poly to input coefficients and degree.
4. Prompt the user for values of \( x \) to evaluate the polynomial.
5. Call eval_poly for each value of \( x \) and display results.

IMPLEMENTATION:
*/

#include <stdio.h>
#include <math.h> // Include math.h for pow function

// Function prototypes
void get_poly(double coeff[], int* degreep);
double eval_poly(const double coeff[], int degree, double x);

int main() {
    double coeff[9]; // Coefficients for a polynomial of degree up to 8
    int degree;
    
    // Get polynomial coefficients and degree
    get_poly(coeff, &degree);
    
    // Evaluate the polynomial at various values of x
    double x;
    char choice;
    
    do {
        printf("Enter a value for x: ");
        scanf("%lf", &x);
        double result = eval_poly(coeff, degree, x);
        printf("p(%.2f) = %.2f\n", x, result);
        
        printf("Do you want to evaluate another value? (y/n): ");
        scanf(" %c", &choice); // Space before % to consume any newline character
    } while (choice == 'y' || choice == 'Y'); // Fixed logical condition
    
    return 0; // Return statement indicating successful completion
}

// Function to get polynomial coefficients and degree
void get_poly(double coeff[], int* degreep) { // Fixed parameter from coeffll to coeff[]
    printf("Enter the degree of the polynomial (0-8): ");
    scanf("%d", degreep);
    
    // Ensure degree is within valid range
    if (*degreep < 0 || *degreep > 8) {
        printf("Invalid degree. Setting degree to 0.\n");
        *degreep = 0;
    }
    
    // Input coefficients
    for (int i = 0; i <= *degreep; i++) {
        printf("Enter coefficient a[%d]: ", i);
        scanf("%lf", &coeff[i]);
    }
}

// Function to evaluate the polynomial at given value x
double eval_poly(const double coeff[], int degree, double x) {
    double result = 0.0;
    
    for (int i = 0; i <= degree; i++) {
        result += coeff[i] * pow(x, i); // Use pow function to calculate powers
    }
    
    return result;
}


/*
OUTPUT:-

Enter the degree of the polynomial (0-8): 2
Enter coefficient a[0]: 1
Enter coefficient a[1]: -3
Enter coefficient a[2]: 2
Enter a value for x: 1
p(1.00) = 0.00
Do you want to evaluate another value? (y/n): y
Enter a value for x: 2
p(2.00) = 3.00
Do you want to evaluate another value? (y/n): n
*/
