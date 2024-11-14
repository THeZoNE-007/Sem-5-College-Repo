/*
PROBLEM: Control of a bread machine to manage baking processes based on user input.

ANALYSIS: The program allows the user to select the type of bread (White or Sweet), specify if the loaf size is double, and indicate if baking is manual. Based on these inputs, the program calculates the total baking time using predefined times for each step in the bread-making process. If the loaf size is double, baking times are adjusted accordingly. If baking is manual, the program instructs the user to remove the dough after shaping.

DATA REQUIREMENTS:
Problem Inputs:
char bread_type; // To store the type of bread ('w' for White, 's' for Sweet).
int is_double; // To indicate if the loaf size is double (0 for No, 1 for Yes).
int is_manual; // To indicate if baking is manual (0 for No, 1 for Yes).

Problem Outputs:
int total_time; // To store the total baking time in minutes.

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for input on bread type.
Step 2. Prompt user for input on loaf size (double or not).
Step 3. Prompt user for input on whether baking is manual.
Step 4. Calculate total time based on predefined times for each step.
Step 5. Adjust baking time if loaf size is double.
Step 6. If baking is manual, instruct user to remove dough and adjust total time.
Step 7. Display total baking time.

IMPLEMENTATION:
*/
#include <stdio.h>

int get_baking_time(char bread_type, int is_double) {
    int baking;
    if (bread_type == 'w') {
        baking = 45; // Baking time for White bread
    } else {
        baking = 35; // Baking time for Sweet bread
    }
    if (is_double) {
        baking = (int)(baking * 1.5); // Increase by 50% if loaf size is double
    }
    return baking;
}

int main() {
    char bread_type;
    int is_double, is_manual;
    int total_time = 0;

    // Step 1: Prompt user for input
    printf("Enter the bread type (w for white, s for sweet): ");
    scanf(" %c", &bread_type); // Note: Added space before %c to consume any newline characters

    printf("Is the loaf size double? (0 for No, 1 for Yes): ");
    scanf("%d", &is_double); // Step 2

    printf("Is baking manual? (0 for No, 1 for Yes): ");
    scanf("%d", &is_manual); // Step 3

    // Step 4: Calculate total time based on predefined times
    total_time += 15; // Primary kneading
    total_time += 60; // Primary rising
    total_time += (bread_type == 'w') ? 18 : 33; // Secondary kneading
    total_time += 20; // Secondary rising
    total_time += 2;   // Loaf shaping
    total_time += 75; // Final rising
    total_time += get_baking_time(bread_type, is_double); // Baking time

    if (is_manual) {
        printf("Remove dough for manual baking.\n"); // Step 6
        total_time -= get_baking_time(bread_type, is_double); // Adjust total time
    }

    // Step 7: Display total baking time
    printf("Total baking time: %d minutes\n", total_time);
    
    return 0; // End program
}