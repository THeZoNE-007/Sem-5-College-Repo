/*
Write a function deblank(input argument, output argument) that takes a stringoutput and a string input argument and returns a copy of the input argument with all blanks removed.
Input: Hello World
Output: HelloWorld
*/

/*
PROBLEM: Remove all blank spaces from a given string.

ANALYSIS: The program will define a function that takes an input string and produces an output string with all spaces removed. It will prompt the user for input and display the modified string.

DATA REQUIREMENTS:
Problem Inputs:
char input[]; // Input string that may contain spaces.
char output[]; // Output string with spaces removed.

Problem Outputs: 
A deblanked string !!

DESIGN:
INITIAL ALGORITHM:
1. Define a function deblank that takes two string arguments (input and output).
2. Iterate through each character of the input string.
3. If the character is not a space, append it to the output string.
4. Terminate the output string properly.
5. In the main function, prompt for user input, call deblank, and display the result.
*/

#include <stdio.h>
#include <string.h>

void deblank(const char input[], char output[]) {
    int j = 0; // Index for output
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] != ' ') { // Check if the character is not a space
            output[j++] = input[i]; // Copy non-space character to output
        }
    }
    output[j] = '\0'; // Null-terminate the output string
}

int main() {
    char str[100], result[100];
    
    printf("Enter a string: ");
    fgets(str, 100, stdin);

    deblank(str, result); // Call deblank function
    printf("Output: %s\n", result); // Display result

    return 0;
}

/*
OUTPUT:- 

Enter a string: Hello to the World
Output: HellototheWorld
*/
