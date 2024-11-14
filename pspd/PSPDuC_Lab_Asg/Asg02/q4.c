/*
PROBLEM: Determine the day number (1 to 366) in a year for a given date.

ANALYSIS: The program accepts a date (day, month, year) as input and calculates which day of the year it corresponds to. It accounts for leap years when calculating the total number of days. A year is a leap year if it is divisible by 4, but not if it is divisible by 100 unless it is also divisible by 400.

DATA REQUIREMENTS:
Problem Inputs:
int d; // Day of the month.
int m; // Month of the year.
int y; // Year.

Problem Outputs:
int n_days; // The day number in the year (1 to 366).

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for input on day, month, and year.
Step 2. Validate month and day input.
Step 3. Calculate the total number of days up to the given date using a switch-case structure.
Step 4. Adjust for leap years when calculating days in February.
Step 5. Display the total number of days.

IMPLEMENTATION:
*/
#include <stdio.h>

int leap(int year) {
    // Determine if the given year is a leap year
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1; // Leap year
    } else {
        return 0; // Not a leap year
    }
}

int main() {
    int d, m, y;
    printf("Enter the value of date, month & year: ");
    scanf("%d%d%d", &d, &m, &y);
    
    // Step 2: Validate month and day
    if (m < 1 || m > 12 || d < 1 || d > 31) {
        printf("Invalid date\n");
        return 1;
    }

    // Days in each month
    int n_days = d;

    switch (m) {
        case 12: n_days += 30; // December has 31 days
        case 11: n_days += 31; // November has 30 days
        case 10: n_days += 30; // October has 31 days
        case 9: n_days += 31; // September has 30 days
        case 8: n_days += 31; // August has 31 days
        case 7: n_days += 30; // July has 31 days
        case 6: n_days += 31; // June has 30 days
        case 5: n_days += 30; // May has 31 days
        case 4: n_days += 31; // April has 30 days
        case 3:
            if (leap(y)) {
                n_days += 29; // Leap year February
            } else {
                n_days += 28; // Non-leap year February
            }
            break; // Important to break here to avoid falling through
        case 2: 
            n_days += 31; // January has 31 days
            break;
        case 1: 
            break; // No need to add anything for January since it's already included in n_days
        default:
            printf("Invalid month\n");
            return 1;
    }

    printf("Total days = %d\n", n_days);
    return 0;
}