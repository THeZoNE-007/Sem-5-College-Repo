/*
PROBLEM: Compute and display both the range of values in the data collection and the standard deviation.

ANALYSIS: The program will prompt the user to enter a number of values (N), read those values, and calculate:
- The smallest value
- The largest value
- The average value
- The range (largest - smallest)
- The standard deviation

DATA REQUIREMENTS:
Problem Inputs:
int N; // Number of values to be entered.
double value; // Each individual value in the collection.

Problem Outputs:
double smallest; // The smallest value in the collection.
double largest; // The largest value in the collection.
double avg; // The average value of the collection.
double range; // The difference between the largest and smallest values.
double stdDev; // The standard deviation of the values.

DESIGN:
INITIAL ALGORITHM:
1. Prompt user for input on number of values (N).
2. Validate N to ensure it is greater than zero.
3. Initialize variables for smallest, largest, sum, and sum_squares.
4. Loop through N iterations to read each value:
   - Update sum and sum_squares.
   - Check and update smallest and largest values.
5. Calculate average as sum divided by N.
6. Calculate range as largest - smallest.
7. Calculate standard deviation using the formula provided.
8. Print smallest, largest, average, range, and standard deviation.
*/

#include <stdio.h>
#include <math.h>

int main() {
    int N;
    double value, sum = 0, sum_squares = 0, smallest, largest, range, avg, stdDev;

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
        sum_squares += value * value; // Accumulate sum of squares

        if (value < smallest) {
            smallest = value;
        }
        if (value > largest) {
            largest = value;
        }
    }

    avg = sum / N; // Calculate average
    range = largest - smallest; // Calculate range
    stdDev = sqrt((sum_squares / N) - (avg * avg)); // Calculate standard deviation

    printf("Smallest: %.2lf\n", smallest);
    printf("Largest: %.2lf\n", largest);
    printf("Average: %.2lf\n", avg);
    printf("Range: %.2lf\n", range);
    printf("Standard Deviation: %.2lf\n", stdDev);

    return 0;
}