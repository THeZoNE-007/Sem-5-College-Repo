#include <stdio.h>

void convert_heading_to_bearing(float heading) {
    // Check if the heading is valid
    if (heading < 0 || heading >= 360) {
        printf("Invalid compass heading. Please enter a value between 0 and 360 degrees.\n");
        return;
    }

    char direction1, direction2;
    float angle;

    // Determine the direction and angle using switch-case
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

    // Print the result
    printf("Bearing: %c %.1f degrees %c\n", direction1, angle, direction2);
}

int main() {
    float heading;

    // Prompt user for input
    printf("Enter a compass heading (0 to 360 degrees): ");
    scanf("%f", &heading);

    // Convert and display the bearing
    convert_heading_to_bearing(heading);

    return 0;
}
