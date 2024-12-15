/*
PROBLEM: Identifying Substances by Boiling Point

ANALYSIS
To identify a substance based on its observed boiling point, we compare the observed value to known boiling points within a 5% tolerance. 
We will use a function called within_x_percent to determine if the observed boiling point matches a known value.

DATA REQUIREMENTS
    - Problem Inputs:   double observed; // The observed boiling point.
    - Predefined boiling points:
        Water (100°C)
        Mercury (357°C)
        Copper (1187°C)
        Silver (2193°C)
        Gold (2660°C)
    - Problem Outputs:  Identified substance or "Substance Unknown".

DESIGN
INITIAL ALGORITHM
1. Define boiling points for substances.
2. Read the observed boiling point from the user.
3. Loop through predefined boiling points:
    - Use within_x_percent to check if the observed value is within 5% of any boiling point.
    - If matched, print the substance name and exit.
4. If no match is found, print "Substance Unknown".

IMPLEMENTATION
*/

#include <stdio.h>
#include <math.h>

// Function to check if the data is within x percent of the reference
int within_x_percent(double ref, double data, double x) {
    double tolerance = (x / 100) * ref;
    return (data >= ref - tolerance) && (data <= ref + tolerance);
}

// Main function
int main() {
    double observed;
    const double boiling_points[] = {100, 357, 1187, 2193, 2660};
    const char *substances[] = {"Water", "Mercury", "Copper", "Silver", "Gold"};
    int num_substances = 5;
    int found = 0;

    printf("Enter the observed boiling point in degree Celsius: ");
    scanf("%lf", &observed);

    for (int i = 0; i < num_substances; i++) {
        if (within_x_percent(boiling_points[i], observed, 5.0)) {
            printf("The substance is %s.\n", substances[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Substance Unknown.\n");
    }

    return 0;
}

/*
OUTPUT:-

Enter the observed boiling point in degree Celsius: 100
The substance is Water.
Enter the observed boiling point in degree Celsius: 300
Substance Unknown.
*/