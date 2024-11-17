/*
PROBLEM: Determine if vehicle emissions exceed permitted levels based on pollutant type, grams emitted per mile, and odometer reading.

ANALYSIS: The program prompts the user to select a pollutant type and enter the grams emitted per mile and the odometer reading. Based on these inputs, the program checks if the emissions exceed the permitted levels defined in a table for two mileage ranges (first 50,000 miles and second 50,000 miles). If the odometer reading exceeds 100,000 miles, an error message is displayed.

DATA REQUIREMENTS:
Problem Inputs:
int pollutant_number; // To store the selected pollutant number (1 to 4).
double grams_per_mile; // To store grams emitted per mile.
int odometer_reading; // To store the odometer reading.

Problem Outputs:
double limit; // To store the permitted emission limit based on pollutant type and mileage.

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for pollutant number.
Step 2. Prompt user for grams emitted per mile.
Step 3. Prompt user for odometer reading.
Step 4. Determine the emission limit based on pollutant type and mileage.
Step 5. Compare grams emitted per mile with the limit.
Step 6. Display whether emissions exceed the permitted level or are within limits.

IMPLEMENTATION:
*/
#include <stdio.h>

int main() {
    int pollutant_number;
    double grams_per_mile;
    int odometer_reading;
    double limit;

    // Step 1: Prompt user for pollutant number
    printf("Enter pollutant number (1 to 4): \n");
    printf("(1) Carbon monoxide\n");
    printf("(2) Hydrocarbons\n");
    printf("(3) Nitrogen oxides\n");
    printf("(4) Nonmethane hydrocarbons\n");
    scanf("%d", &pollutant_number);

    // Step 2: Prompt user for grams emitted per mile
    printf("Enter grams emitted per mile: ");
    scanf("%lf", &grams_per_mile); // Corrected format specifier

    // Step 3: Prompt user for odometer reading
    printf("Enter odometer reading: ");
    scanf("%d", &odometer_reading);

    // Step 4: Determine emission limit based on odometer reading
    if (odometer_reading <= 50000) {
        limit = (pollutant_number == 1) ? 3.4 :
                (pollutant_number == 2) ? 0.31 :
                (pollutant_number == 3) ? 0.4 :
                (pollutant_number == 4) ? 0.25 : 0;
    } else if (odometer_reading <= 100000) {
        limit = (pollutant_number == 1) ? 4.2 :
                (pollutant_number == 2) ? 0.39 :
                (pollutant_number == 3) ? 0.5 :
                (pollutant_number == 4) ? 0.31 : 0;
    } else {
        printf("Exceeding allowable range (max of 100,000 miles)\n");
        return 1; // Exit with an error code
    }

    // Step 5: Compare emissions with limits
    if (grams_per_mile > limit) {
        printf("Emissions exceed permitted level of %.2f grams/mile.\n", limit);
    } else {
        printf("Within permitted level of %.2f grams/mile.\n", limit); // Corrected missing comma
    }

    return 0; // End program
}