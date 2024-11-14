/*
PROBLEM: Find the smallest, largest, and average values in a collection of N numbers.

ANALYSIS: The program will prompt the user to enter a number of values (N), read those values, and calculate:
- The smallest value
- The largest value
- The average value

DATA REQUIREMENTS:
Problem Inputs:
int N; // Number of values to be entered.
double value; // Each individual value in the collection.

Problem Outputs:
double smallest; // The smallest value in the collection.
double largest; // The largest value in the collection.
double avg; // The average value of the collection.

DESIGN:
INITIAL ALGORITHM:
1. Prompt user for input on number of values (N).
2. Validate N to ensure it is greater than zero.
3. Initialize variables for smallest, largest, and sum.
4. Loop through N iterations to read each value:
   - Update sum.
   - Check and update smallest and largest values.
5. Calculate average as sum divided by N.
6. Print smallest, largest, and average.
*/

#include <stdio.h>

int main() {
    int N;
    double value, sum = 0, smallest, largest, avg;

    printf("Enter the number of values (N): ");
    scanf("%d", &N);

    // Validate N
    if (N <= 0) {
        printf("Invalid number of values.\n");
        return 1;
    }

    smallest = 1e9; // Initialize to a large value
    largest = -1e9; // Initialize to a small value

    printf("Enter the values:\n");
    for (int i = 0; i < N; i++) {
        scanf("%lf", &value);
        sum += value;

        if (value < smallest) {
            smallest = value;
        }
        if (value > largest) {
            largest = value;
        }
    }

    avg = sum / N; // Calculate average

    printf("Smallest: %.2lf\n", smallest);
    printf("Largest: %.2lf\n", largest);
    printf("Average: %.2lf\n", avg);

    return 0;
}