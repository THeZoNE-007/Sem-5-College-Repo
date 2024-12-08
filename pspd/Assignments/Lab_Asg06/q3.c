/*
Write a function hydroxide in C that checks if a given string ends with the substring OH. The function should return 1 if the string ends with OH and 0 otherwise.

Test the function with the following strings:
- KOH
- H2O2
- NaCl
- NaOH
- C9H8O4
- MgOH
*/


/*
PROBLEM: Check if a given string ends with the substring "OH".

ANALYSIS: The program will define a function that checks if the last two characters of a string are "OH". It will print the result indicating whether the string ends with "OH".

DATA REQUIREMENTS:
Problem Inputs:
char str[]; // Input string to check.

Problem Outputs:
Return 1 if the string ends with "OH", otherwise return 0.

DESIGN:
INITIAL ALGORITHM:
1. Define a function hydroxide that takes a string as input.
2. Compare the last two characters of the string with "O" and "H".
3. Return 1 if they match, otherwise return 0.
4. In the main function, prompt for user input, call hydroxide, and display the result.
*/

#include <stdio.h>
#include <string.h>

int hydroxide(char str[]) {
    char secondlast = str[strlen(str) - 3];
    char last = str[strlen(str) - 2];
    if (secondlast == 'O' && last == 'H') {
        return 1;
    } else {
        return 0;
    }
}

void main() {
    char str[100];
    printf("Enter a chemical compound: ");
    fgets(str, 100, stdin);
    int res = hydroxide(str);
    printf("%d", res);
}

/*
OUTPUT:-

Enter a chemical compound: NaOH
1
*/
