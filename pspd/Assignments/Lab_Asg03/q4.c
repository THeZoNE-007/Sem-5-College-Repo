/*
PROBLEM: Predict the billions of dollars of fast food charges based on a linear model.

ANALYSIS: The program will prompt the user to enter a year after 2005 and use the provided formula to calculate the predicted fast food charges for that year. The program will continue to prompt for years until a year before 2005 is entered.

DATA REQUIREMENTS:
Problem Inputs:
int year; // The year entered by the user.
double charges; // Predicted fast food charges in billions.

Problem Outputs:
Predicted fast food charges for the given year.

DESIGN:
INITIAL ALGORITHM:
1. Define a function `fast_food_billions` that takes an integer year as input and returns the predicted charges.
2. In the main function, initialize variables for year and charges.
3. Use a loop to repeatedly prompt the user for input:
   - If the entered year is before 2005, exit the loop.
   - Call `fast_food_billions` to calculate charges based on the entered year.
   - Display the predicted charges.
4. End the program when a year before 2005 is entered.
*/

#include <stdio.h>

// Function to calculate predicted fast food charges
double fast_food_billions(int year) {
    int t = year - 2005;  // Years since 2005
    return 33.2 + 16.8 * t;  // Formula for fast food charges
}

int main() {
    int year;
    double charges;

    while (1) {
        // Step 1: Get the year
        printf("Enter a year (before 2005 to stop): ");
        scanf("%d", &year);

        if (year < 2005) break;  // Stop if year is before 2005

        // Step 2: Calculate charges
        charges = fast_food_billions(year);

        // Step 3: Display the predicted charges
        printf("Predicted fast food charges in %d: $%.2lf billion\n", year, charges);
    }

    return 0;
}