/*
PROBLEM: Calculation of the power output of a hydroelectric dam based on the height of the dam and water flow rate.

ANALYSIS: To solve this problem, we need to gather the height of the dam and the flow rate of water in cubic meters per second. We will calculate the work done on the water by gravity using the formula \( w = mgh \), where \( m \) is the mass of water, \( g \) is the gravitational constant, and \( h \) is the height of the dam. The mass can be calculated from the volume of water since 1 cubic meter of water has a mass of 1000 kg. Finally, we will compute the power output in megawatts, considering that 90% of the work done is converted to electrical energy.

DATA REQUIREMENTS:
Problem Inputs:
double height; // To store the height of the dam in meters.
double flow_rate; // To store the flow rate in cubic meters per second.

Problem Outputs:
double power; // To store the calculated power output in megawatts.

DESIGN:
INITIAL ALGORITHM:
Step 1. Define constants for gravitational constant and efficiency.
Step 2. Prompt user for input on height of the dam.
Step 3. Prompt user for input on flow rate.
Step 4. Calculate mass of water flowing per second using flow rate.
Step 5. Calculate work done on water using the formula w = mgh.
Step 6. Calculate power output by considering efficiency and converting to megawatts.
Step 7. Display the results including power output.

IMPLEMENTATION:
*/
#include <stdio.h>

int main()
{
    double height, flow_rate, power;
    double g = 9.8; // gravitational constant
    double eff = 0.9; // efficiency

    // Step 2: Prompt user for input
    printf("Enter height of the dam in meters: ");  // Step 1
    scanf("%lf", &height);  // Step 2

    printf("Enter water flow rate in cubic meters per second: ");  // Step 3
    scanf("%lf", &flow_rate);  // Step 4

    // Step 5: Calculate mass of water flowing per second
    double mass = flow_rate * 1000;  // mass in kg (1 m³ of water = 1000 kg)

    // Step 6: Calculate work done on water
    double work = mass * g * height;  // work done in joules

    // Step 7: Calculate power output (in megawatts)
    power = (work * eff) / 1000000;  // converting watts to megawatts

    // Step 8: Display results
    printf("Power generated: %.2f MW\n", power);  // Output power

    return 0; // End program
}