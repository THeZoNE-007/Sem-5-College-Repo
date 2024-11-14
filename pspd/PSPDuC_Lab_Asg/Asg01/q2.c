/*
PROBLEM: Estimation of water savings and installation costs for replacing toilets with low-flush models in a community.

ANALYSIS: To solve this problem, we need to gather the population size of the community. We will calculate the number of toilets based on the population, estimate the daily water usage of existing toilets, and then calculate the water usage of new low-flush toilets. The difference will give us the amount of water saved per day. Additionally, we will calculate the total cost to install new toilets based on the number of toilets needed.

DATA REQUIREMENTS:
Problem Inputs:
int population; // To store the population size of the community.

Problem Outputs:
double water_saved; // To store the estimated water saved in liters per day.
double total_cost; // To store the total cost to install new toilets.

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for input on population size.
Step 2. Calculate the number of toilets based on population (1 toilet for every 3 persons).
Step 3. Calculate old water usage based on existing toilet specifications.
Step 4. Calculate new water usage based on low-flush toilet specifications.
Step 5. Calculate water saved by finding the difference between old and new water usage.
Step 6. Calculate total cost to install new toilets.
Step 7. Display results including water saved and total cost.

IMPLEMENTATION:
*/
#include <stdio.h>

int main()
{
    int population; // Step 1: Population size
    double water_saved, total_cost;

    printf("TOILET WATER CONSERVATION ESTIMATOR\n");
    printf("Enter population size: "); // Step 1
    scanf("%d", &population); // Step 2

    int num_toilets = population / 3; // Step 3: Calculate number of toilets

    double old_water_usage = num_toilets * 15 * 14; // Step 4: Old water usage (liters/day)
    double new_water_usage = num_toilets * 2 * 14; // Step 5: New water usage (liters/day)

    water_saved = old_water_usage - new_water_usage; // Step 6: Calculate water saved
    total_cost = num_toilets * 150; // Step 7: Calculate total installation cost

    // Step 8: Display results
    printf("Water saved: %.2f liters/day\n", water_saved); // Output water saved
    printf("Total cost: $%.2f\n", total_cost); // Output total cost

    return 0; // End program
}