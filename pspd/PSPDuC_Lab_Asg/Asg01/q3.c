/*
PROBLEM: Calculation of the acceleration and time for a jet fighter launched from an aircraft-carrier catapult.

ANALYSIS: To solve this problem, we need to gather the takeoff speed of the jet in kilometers per hour and the distance over which the catapult accelerates the jet. We will convert the takeoff speed to meters per second, then calculate the acceleration using the formula \( v^2 = 2as \) (where \( v \) is the final velocity, \( a \) is acceleration, and \( s \) is distance). After calculating acceleration, we will compute the time taken to reach takeoff speed using \( t = \frac{v}{a} \).

DATA REQUIREMENTS:
Problem Inputs:
double takeoff_speed_kmh; // To store takeoff speed in kilometers per hour.
double distance; // To store distance in meters.

Problem Outputs:
double acceleration; // To store calculated acceleration in m/s².
double time; // To store calculated time in seconds.

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for input on takeoff speed (in km/h).
Step 2. Convert takeoff speed from km/h to m/s.
Step 3. Prompt user for input on distance (in meters).
Step 4. Calculate acceleration using the formula \( a = \frac{v^2}{2s} \).
Step 5. Calculate time using the formula \( t = \frac{v}{a} \).
Step 6. Display results including acceleration and time.

IMPLEMENTATION:
*/
#include <stdio.h>

int main()
{
    double takeoff_speed_kmh, distance, acceleration, time;

    printf("JET FIGHTER ACCELERATION CALCULATOR\n");
    printf("Enter takeoff speed (in km/h): "); // Step 1
    scanf("%lf", &takeoff_speed_kmh); // Step 1

    double takeoff_speed_ms = takeoff_speed_kmh * 1000 / 3600; // Step 2: Convert to m/s

    printf("Enter distance (in meters): "); // Step 3
    scanf("%lf", &distance); // Step 4

    // Step 5: Calculate acceleration
    acceleration = (takeoff_speed_ms * takeoff_speed_ms) / (2 * distance); 

    // Step 6: Calculate time
    time = takeoff_speed_ms / acceleration; 

    // Step 7: Display results
    printf("Acceleration: %.2f m/s²\n", acceleration); // Output acceleration
    printf("Time: %.2f seconds\n", time); // Output time

    return 0; // End program
}