/*
PROBLEM: Calculate and output the equation of the perpendicular bisector of the line segment between two points.

ANALYSIS: The program will prompt the user to input the coordinates of two points. It will then compute:
1. The slope of the line segment between the two points.
2. The coordinates of the midpoint of the line segment.
3. The slope of the perpendicular bisector as the negative reciprocal of the slope of the line segment.
4. The y-intercept of the perpendicular bisector using the midpoint and its slope.
5. Output the original points and the equation of the perpendicular bisector in y = mx + b format.

DATA REQUIREMENTS:
Problem Inputs:
double x1, y1; // Coordinates of the first point.
double x2, y2; // Coordinates of the second point.

Problem Outputs:
Equation of the perpendicular bisector in slope-intercept form.

DESIGN:
INITIAL ALGORITHM:
1. Define a function `find_perpendicular_bisector` that takes four double parameters (coordinates).
2. Calculate the midpoint coordinates.
3. Compute the slope of the line segment.
4. Calculate the slope of the perpendicular bisector.
5. Compute its y-intercept.
6. Print results including original points and equation.
*/

#include <stdio.h>

// Function to find and display the perpendicular bisector
void find_perpendicular_bisector(double x1, double y1, double x2, double y2) {
    double midpoint_x, midpoint_y;
    double slope, perp_slope, y_intercept;

    // Calculate the midpoint of the line segment
    midpoint_x = (x1 + x2) / 2.0;
    midpoint_y = (y1 + y2) / 2.0;

    // Calculate the slope of the line segment
    if (x2 - x1 != 0) {
        slope = (y2 - y1) / (x2 - x1);
        // Calculate the slope of the perpendicular bisector (negative reciprocal)
        perp_slope = -1 / slope;
    } else {
        // If x1 == x2, handle vertical line case
        perp_slope = 0; // The perpendicular bisector will be horizontal
    }

    // Calculate the y-intercept of the perpendicular bisector
    y_intercept = midpoint_y - (perp_slope * midpoint_x);

    // Display results
    printf("Original Points: (%.2f, %.2f) and (%.2f, %.2f)\n", x1, y1, x2, y2);
    printf("Midpoint: (%.2f, %.2f)\n", midpoint_x, midpoint_y);

    if (x2 - x1 != 0) {
        printf("Equation of the perpendicular bisector: y = %.2fx + %.2f\n", perp_slope, y_intercept);
    } else {
        // If vertical line segment, output horizontal line equation
        printf("Equation of the perpendicular bisector: y = %.2f\n", midpoint_y);
    }
}

int main() {
    double x1, y1, x2, y2;

    // Input coordinates of two points
    printf("Enter the coordinates of the first point (x1, y1): ");
    scanf("%lf %lf", &x1, &y1);

    printf("Enter the coordinates of the second point (x2, y2): ");
    scanf("%lf %lf", &x2, &y2);

    // Call function to find and display perpendicular bisector
    find_perpendicular_bisector(x1, y1, x2, y2);

    return 0;
}


/*
Output:

Enter the coordinates of the first point (x1, y1): 2 -4
Enter the coordinates of the second point (x2, y2): 7 -2
Original Points: (2.00, -4.00) and (7.00, -2.00)
Midpoint: (4.50, -3.00)
Equation of the perpendicular bisector: y = -2.50x + 8.25

*/
