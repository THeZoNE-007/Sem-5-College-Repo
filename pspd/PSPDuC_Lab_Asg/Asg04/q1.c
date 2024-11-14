/*
PROBLEM: Create an automatic teller machine (ATM) program that dispenses money in the least number of bills.

ANALYSIS: The program will prompt the user to enter an amount (a multiple of 10 dollars) and will dispense this amount using the least number of bills. The available bills are $50, $20, and $10. A function will be defined to calculate how many of each type of bill to dispense.

DATA REQUIREMENTS:
Problem Inputs:
int amount; // The amount desired by the user (must be a multiple of 10).
int count50; // Count of $50 bills to dispense.
int count20; // Count of $20 bills to dispense.
int count10; // Count of $10 bills to dispense.

Problem Outputs:
Number of each type of bill dispensed.

DESIGN:
INITIAL ALGORITHM:
1. Prompt the user for input on the desired amount.
2. Validate that the amount is a multiple of 10.
3. Call a function `dispenseBills` that calculates the number of each type of bill needed.
4. Display the counts of each type of bill dispensed.
*/

#include <stdio.h>

// Function to determine how many bills to dispense
void dispenseBills(int amount, int *count50, int *count20, int *count10) {
    *count50 = amount / 50; // Calculate number of $50 bills
    amount %= 50;           // Update remaining amount
    *count20 = amount / 20; // Calculate number of $20 bills
    amount %= 20;           // Update remaining amount
    *count10 = amount / 10; // Calculate number of $10 bills
}

int main() {
    int amount, count50 = 0, count20 = 0, count10 = 0;
    
    printf("Enter amount (multiple of 10): ");
    scanf("%d", &amount);

    // Validate that the entered amount is a multiple of 10
    if (amount % 10 == 0 && amount > 0) {
        dispenseBills(amount, &count50, &count20, &count10);
        printf("50-dollar bills: %d\n", count50);
        printf("20-dollar bills: %d\n", count20);
        printf("10-dollar bills: %d\n", count10);
    } else {
        printf("Amount must be a positive multiple of 10\n");
    }

    return 0;
}