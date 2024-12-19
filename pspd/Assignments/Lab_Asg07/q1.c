/*
PROBLEM: Manage automobile details including make, model, odometer reading, manufacture and purchase dates, and gas tank information.

ANALYSIS: The program defines structures to represent an automobile, its manufacturing and purchase dates, and its gas tank. It includes functions to scan and print these details.

DATA REQUIREMENTS:
Problem Inputs:
- char make[50]; // Make of the automobile.
- char model[50]; // Model of the automobile.
- int odometer; // Odometer reading in miles.
- struct date_t manufacture; // Manufacture date.
- struct date_t purchase; // Purchase date.
- struct tank_t gas_tank; // Gas tank information.

Problem Outputs:
Formatted output showing all details of the automobile.

DESIGN:
INITIAL ALGORITHM:
1. Define structures for date, tank, and automobile.
2. Implement functions to scan and print details for each component (tank, date, automobile).
3. In the main function, gather user input for an automobile's details.
4. Print all gathered information in a structured format.

IMPLEMENTATION:
*/

#include <stdio.h>
#include <string.h>

// Structure definitions
struct date_t {
    int day;
    int month;
    int year;
};

struct tank_t {
    float capacity;
    float current;
};

struct auto_t {
    char make[50];
    char model[50];
    int odometer;
    struct date_t manufacture;
    struct date_t purchase;
    struct tank_t gas_tank;
};

// Function to print tank details
void print_tank(struct auto_t *automobile) {
    printf("Tank Capacity: %.2f gallons\n", automobile->gas_tank.capacity);
    printf("Current Fuel Level: %.2f gallons\n", automobile->gas_tank.current);
}

// Function to print date details
void print_date(struct auto_t *automobile) {
    printf("Manufacture Date: %02d-%02d-%d\n", automobile->manufacture.day, automobile->manufacture.month, automobile->manufacture.year);
    printf("Purchase Date: %02d-%02d-%d\n", automobile->purchase.day, automobile->purchase.month, automobile->purchase.year);
}

// Function to print automobile details
void print_auto(struct auto_t *automobile) {
    printf("Make: %s\n", automobile->make);
    printf("Model: %s\n", automobile->model);
    printf("Odometer Reading: %d miles\n", automobile->odometer);
    print_date(automobile);
    print_tank(automobile);
}

// Function to scan tank details
void scan_tank(struct tank_t *tank) {
    printf("Enter the tank capacity (gallons): ");
    scanf("%f", &tank->capacity);
    
    printf("Enter the current fuel level (gallons): ");
    scanf("%f", &tank->current);
}

// Function to scan date details
void scan_date(struct date_t *date) {
    printf("Enter the day, month, and year: ");
    scanf("%d %d %d", &date->day, &date->month, &date->year);
}

// Function to scan automobile details
void scan_auto(struct auto_t *automobile) {
    printf("Enter the make: ");
    scanf("%s", automobile->make);

    printf("Enter the model: ");
    scanf("%s", automobile->model);

    printf("Enter the odometer reading (miles): ");
    scanf("%d", &automobile->odometer);

    printf("Enter manufacture date:\n");
    scan_date(&automobile->manufacture);

    printf("Enter purchase date:\n");
    scan_date(&automobile->purchase);

    scan_tank(&automobile->gas_tank);
}

// Main function
int main() {
    struct auto_t automobile;

    // Scan and print the details of the automobile
    scan_auto(&automobile);
    
    // Print all details of the automobile
    printf("\nAutomobile Details:\n");
    print_auto(&automobile);

    return 0;
}

/*
OUTPUT:-

Enter the make: Mercury
Enter the model: Sable
Enter the odometer reading: 99842
Enter the manufacture day month year: 1 18 2001
Enter the purchase day month year: 5 30 1991
Enter the capacity: 16
Enter the current fuel: 12.5
Maker: Mercury
Model: Sable
Odometer: 99842
Manufacture Date: 1-18-2001
Purchase Date: 5-30-1991
Capacity: 16.00
Current fuel: 12.50
*/
