/*
PROBLEM: Transformation of compass headings in degrees (0 to 360) to compass bearings.

ANALYSIS: To solve this problem, we need to gather a compass heading from the user and convert it into a compass bearing format. A compass bearing consists of a direction (north or south), an angle between 0 and 90 degrees, and a turning direction (east or west). We will validate the input to ensure it is within the acceptable range and then determine the corresponding bearing based on the heading.

DATA REQUIREMENTS:
Problem Inputs:
float heading; // To store the compass heading in degrees.

Problem Outputs:
The output will be a formatted string representing the compass bearing.

DESIGN:
INITIAL ALGORITHM:
Step 1. Prompt user for input on compass heading (in degrees).
Step 2. Check if the heading is valid (between 0 and 360 degrees).
Step 3. Determine the direction and angle based on the heading using a switch-case structure.
Step 4. Print the resulting bearing in the format "Direction Angle degrees Direction".

IMPLEMENTATION:
*/
#include <stdio.h>

void convert_heading_to_bearing(float heading) {
    // Step 2: Check if the heading is valid
    if (heading < 0 || heading >= 360) {
        printf("Invalid compass heading. Please enter a value between 0 and 360 degrees.\n");
        return;
    }

    char direction1, direction2;
    float angle;

    // Step 3: Determine the direction and angle using switch-case
    switch ((int)(heading / 90)) {
        case 0: // Heading between 0 and 90
            direction1 = 'N';
            direction2 = 'E';
            angle = heading;
            break;
        case 1: // Heading between 90 and 180
            direction1 = 'S';
            direction2 = 'E';
            angle = 180 - heading;
            break;
        case 2: // Heading between 180 and 270
            direction1 = 'S';
            direction2 = 'W';
            angle = heading - 180;
            break;
        case 3: // Heading between 270 and 360
            direction1 = 'N';
            direction2 = 'W';
            angle = 360 - heading;
            break;
        default:
            // This case should not occur due to prior validation
            printf("Invalid compass heading. Please enter a value between 0 and 360 degrees.\n");
            return;
    }

    // Step 4: Print the result
    printf("Bearing: %c %.1f degrees %c\n", direction1, angle, direction2);
}

int main() {
    float heading;

    // Step 1: Prompt user for input
    printf("Enter a compass heading (0 to 360 degrees): ");
    scanf("%f", &heading);

    // Convert and display the bearing
    convert_heading_to_bearing(heading);

    return 0; // End program
}