/*
PROBLEM: Manage inventory for a beer distributorship, tracking sales and purchases for different beer brands.

ANALYSIS: The program will prompt the user to enter the initial inventory for each beer brand and then process transactions that either increase (purchases) or decrease (sales) the inventory. The program will display the final inventory after processing all transactions.

DATA REQUIREMENTS:
Problem Inputs:
int inventory[4]; // Array to hold inventory for 4 beer brands.
int brand_id; // Brand ID number (1 to 4).
int transaction; // Amount purchased (positive) or sold (negative).

Problem Outputs:
Final inventory for each brand after processing transactions.

DESIGN:
INITIAL ALGORITHM:
1. Initialize an array to hold the inventory for each brand.
2. Prompt user for initial inventory values.
3. Process transactions in a loop until a termination condition is met.
   - Read brand ID and transaction amount.
   - Update the corresponding inventory based on the transaction.
4. Display the final inventory for each brand.
*/

#include <stdio.h>

int main() {
    int inventory[4];  // Array for 4 brands
    int brand_id, transaction;

    // Step 1: Input the initial inventory for each brand
    printf("Enter the starting inventory for Piels, Coors, Bud, Iron City:\n");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &inventory[i]);
    }

    // Step 2: Process transactions
    printf("Enter transactions (brand ID followed by transaction value, -999 to stop):\n");
    while (1) {
        scanf("%d", &brand_id);
        if (brand_id == -999) break;  // End input

        scanf("%d", &transaction);

        // Step 3: Update inventory
        inventory[brand_id - 1] += transaction;  // Update based on transaction
    }

    // Step 4: Display final inventory
    printf("\nFinal Inventory:\n");
    printf("Piels: %d\n", inventory[0]);
    printf("Coors: %d\n", inventory[1]);
    printf("Bud: %d\n", inventory[2]);
    printf("Iron City: %d\n", inventory[3]);

    return 0;
}