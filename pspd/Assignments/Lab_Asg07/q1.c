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

struct date_t { int day, month, year; };
struct tank_t { float capacity, current; };
struct auto_t {
    char make[50], model[50]; 
    int odometer;
    struct date_t manufacture, purchase; 
    struct tank_t gas_tank;
};

void print_auto(const struct auto_t *car) {
    printf("Maker: %s\nModel: %s\nOdometer: %d\nManufacture Date: %d-%d-%d\nPurchase Date: %d-%d-%d\nCapacity: %.2f\nCurrent fuel: %.2f\n",
           car->make, car->model, car->odometer,
           car->manufacture.day, car->manufacture.month, car->manufacture.year,
           car->purchase.day, car->purchase.month, car->purchase.year,
           car->gas_tank.capacity, car->gas_tank.current);
}

void scan_auto(struct auto_t *car) {
    printf("Enter the make: ");
    scanf("%s", car->make);
    
    printf("Enter the model: ");
    scanf("%s", car->model);
    
    printf("Enter the odometer reading: ");
    scanf("%d", &car->odometer);
    
    printf("Enter the manufacture day month year: ");
    scanf("%d %d %d", &car->manufacture.day, &car->manufacture.month, &car->manufacture.year);
    
    printf("Enter the purchase day month year: ");
    scanf("%d %d %d", &car->purchase.day, &car->purchase.month, &car->purchase.year);
    
    printf("Enter the capacity: ");
    scanf("%f", &car->gas_tank.capacity);
    
    printf("Enter the current fuel: ");
    scanf("%f", &car->gas_tank.current);
}

int main() {
    struct auto_t automobile;
    scan_auto(&automobile);
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
