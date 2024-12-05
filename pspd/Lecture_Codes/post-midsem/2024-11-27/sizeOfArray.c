/* Write a C program to find the length of a string */

#include <stdio.h>

int main() {
    char str[] = "Hello World"; // Define the string
    int c = 0; // Initialize counter

    // Loop through each character until we reach the null terminator
    for (int i = 0; str[i] != '\0'; i++) {
        c++; // Increment counter for each character
    }

    printf("Length of the given string = %d\n", c); // Print the length
    return 0; // Return success
}
