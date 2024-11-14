/*
PROBLEM: Approximate the square root of a number using iterative calculations.

ANALYSIS: The program will use the formula NG = 0.5(LG + N/LG) to iteratively calculate the square root of a given number N. The initial guess (LG) will be set to 1.0. The process will continue until the difference between the last guess (LG) and the next guess (NG) is less than 0.005.

DATA REQUIREMENTS:
Problem Inputs:
double N; // The number for which the square root is to be calculated.

Problem Outputs:
double NG; // The approximate square root of the number.

DESIGN:
INITIAL ALGORITHM:
1. Define a function `sqrtApproximation` that takes a double N as input.
2. Initialize LG to 1.0 and declare NG.
3. Use a loop to calculate NG using the formula until the difference between NG and LG is less than 0.005.
4. Return the value of NG as the approximate square root.
5. In the main function, prompt the user for input and display the result.
*/

#include <stdio.h>
#include <math.h> // Include math.h for fabs function

// Function to approximate the square root
double sqrtApproximation(double N) {
    double LG = 1.0; // Last guess
    double NG;       // Next guess

    do {
        NG = 0.5 * (LG + N / LG); // Calculate next guess
        if (fabs(NG - LG) < 0.005) break; // Check if guesses are close enough
        LG = NG; // Update last guess
    } while (1);

    return NG; // Return the approximate square root
}

int main() {
    double N;
    printf("Enter a number to find the square root: ");
    scanf("%lf", &N);

    if (N < 0) {
        printf("Cannot compute square root of a negative number.\n");
    } else {
        printf("Approximate square root: %.5lf\n", sqrtApproximation(N));
    }

    return 0;
}