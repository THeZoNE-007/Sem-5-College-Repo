/*
PROBLEM: Calculate the drag force experienced by a vehicle moving through the atmosphere.

ANALYSIS: The program will prompt the user to input the drag coefficient (CD) and the projected area (A) of the vehicle. It will then compute the drag force for a range of velocities from 0 m/s to 40 m/s in increments of 5 m/s using the formula:
F = (1/2) * CD * A * P * V^2
where P (rho) is the density of air at sea level (1.23 kg/m^3).

DATA REQUIREMENTS:
Problem Inputs:
double CD; // Drag coefficient.
double A; // Projected area in m^2.
double F; // Drag force in newtons.

Problem Outputs:
Table displaying velocity and corresponding drag force.

DESIGN:
INITIAL ALGORITHM:
1. Define a function `calculateDrag` that computes the drag force based on inputs.
2. In the main function, prompt the user for CD and A.
3. Use a loop to iterate over velocities from 0 to 40 m/s in increments of 5 m/s.
4. Call `calculateDrag` for each velocity and print the results in a formatted table.
*/

#include <stdio.h>

// Function to calculate drag force
void calculateDrag(double CD, double A, double rho, double V, double *F) {
    *F = 0.5 * CD * A * rho * V * V; // Calculate drag force
}

int main() {
    double CD, A, F;
    const double rho = 1.23; // Density of air at sea level

    // Step 1: Get user input for drag coefficient and projected area
    printf("Enter drag coefficient (CD): ");
    scanf("%lf", &CD);
    printf("Enter projected area (A in m^2): ");
    scanf("%lf", &A);

    // Step 2: Print header for output table
    printf("\n Velocity (m/s) | Drag Force (N) \n");
    printf("--------------------------------------------\n");

    // Step 3: Loop through velocities from 0 to 40 m/s
    for (int v = 0; v <= 40; v += 5) {
        calculateDrag(CD, A, rho, v, &F); // Calculate drag force
        printf("%12d | %12.2f \n", v, F); // Print velocity and drag force
    }

    return 0;
}