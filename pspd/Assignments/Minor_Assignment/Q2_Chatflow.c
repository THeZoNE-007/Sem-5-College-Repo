/*
PROBLEM: Calculate the monthly bill for Chatflow Wireless customers based on their usage of weekday, night, and weekend minutes.

ANALYSIS: The program will prompt the user to enter the number of weekday minutes, night minutes, and weekend minutes used. It will then calculate:
1. The pretax bill based on the base rate and extra weekday minutes.
2. The tax amount based on the pretax bill.
3. The total bill including taxes.
4. The average cost per minute before taxes.

DATA REQUIREMENTS:
Problem Inputs:
int weekday_minutes; // Number of weekday minutes used.
int night_minutes; // Number of night minutes used.
int weekend_minutes; // Number of weekend minutes used.

Problem Outputs:
double pretax_bill; // Total bill before taxes.
double tax_amount; // Amount of tax applied.
double total_bill; // Total bill after taxes.
double avg_minute_cost; // Average cost per minute before taxes.

DESIGN:
INITIAL ALGORITHM:
1. Define constants for base rate, free minutes, extra minute cost, and tax rate.
2. Prompt user for input on weekday, night, and weekend minutes.
3. Calculate pretax bill based on weekday usage.
4. Calculate tax amount and total bill.
5. Calculate average cost per minute before taxes.
6. Display all relevant information in a formatted output.
*/

#include <stdio.h>

#define BASE_RATE 39.99
#define FREE_MINUTES 600
#define EXTRA_MINUTE_COST 0.40
#define TAX_RATE 0.0525

int main() 
{
    int weekday_minutes, night_minutes, weekend_minutes;
    double pretax_bill, tax_amount, total_bill, avg_minute_cost;
    
    // Prompt for user input
    printf("Enter the number of weekday minutes used: ");
    scanf("%d", &weekday_minutes);
    
    printf("Enter the number of night minutes used: ");
    scanf("%d", &night_minutes);
    
    printf("Enter the number of weekend minutes used: ");
    scanf("%d", &weekend_minutes);

    // Calculate pretax bill
    if (weekday_minutes > FREE_MINUTES) 
    {
        pretax_bill = BASE_RATE + (weekday_minutes - FREE_MINUTES) * EXTRA_MINUTE_COST;
    } 
    else 
    {
        pretax_bill = BASE_RATE;
    }

    // Calculate taxes and total bill
    tax_amount = pretax_bill * TAX_RATE;
    total_bill = pretax_bill + tax_amount;

    // Calculate average minute cost before taxes
    int total_minutes = weekday_minutes + night_minutes + weekend_minutes;
    
    // Avoid division by zero if no minutes are used
    if (total_minutes > 0) {
        avg_minute_cost = pretax_bill / total_minutes;
    } else {
        avg_minute_cost = 0; // Default to 0 if no minutes are used
    }

    // Display the results
    printf("\n--- Monthly Bill Summary ---\n");
    printf("Weekday minutes used: %d\n", weekday_minutes);
    printf("Night minutes used: %d\n", night_minutes);
    printf("Weekend minutes used: %d\n", weekend_minutes);
    printf("Pretax bill: $%.2f\n", pretax_bill);
    printf("Average cost per minute before taxes: $%.4f\n", avg_minute_cost);
    printf("Taxes: $%.2f\n", tax_amount);
    printf("Total bill: $%.2f\n", total_bill);

    return 0;
}

/*
Output:

Enter the number of weekday minutes used: 800
Enter the number of night minutes used: 500
Enter the number of weekend minutes used: 700

--- Monthly Bill Summary ---
Weekday minutes used: 800
Night minutes used: 500
Weekend minutes used: 700
Pretax bill: $119.99
Average cost per minute before taxes: $0.0600
Taxes: $6.30
Total bill: $126.29

*/
