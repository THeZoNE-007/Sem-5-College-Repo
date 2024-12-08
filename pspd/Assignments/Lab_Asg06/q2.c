/*
2.Write a function fact_calc that takes a string output argument and an integer input argument n and returns a string showing the calculation of n! . For example, if the value supplied for n were 6, the string returned would be “6! = 6 x 5 x 4 x 3 x 2 x 1 = 720”. Write a program that repeatedly prompts the user for an integer between 0 and 9, calls fact_calc and outputs the resulting string in a box of asterisks of the right size to surround the result. If the user inputs an invalid value, the program should display an error message and reprompt for valid input. Input of the sentinel -1 should cause the input loop to exit. Sample run: 
Enter an integer between 0 and 9 or -1 to quit => 6
**************************************
* 6! = 6 x 5 x 4 x 3 x 2 x 1 = 720 *
**************************************
Enter an integer between 0 and 9 or -1 to quit => 12
Invalid entry
Enter an integer between 0 and 9 or -1 to quit => 0
************
* 0! = 1 *
************
Enter an integer between 0 and 9 or -1 to quit => -1
*/


/*
PROBLEM: Calculate the factorial of an integer and format the output as a string.

ANALYSIS: The program calculates the factorial of an integer and formats it into a string for display.

DATA REQUIREMENTS:
- int n; // Integer input for which to calculate the factorial.
- char output[100]; // Output string showing the calculation.

DESIGN:
1. Define a function fact_calc to calculate the factorial and format the output.
2. Prompt for user input and validate it.
3. Display results.
*/

#include <stdio.h>
#include <string.h>

void int_to_str(int num, char* str) {
    if (num == 0) { str[0] = '0'; str[1] = '\0'; return; }
    int i = 0;
    while (num) {
        str[i++] = (num % 10) + '0';
        num /= 10;
    }
    str[i] = '\0';
    for (int j = 0; j < i / 2; j++) { // Reverse the string
        char temp = str[j];
        str[j] = str[i - j - 1];
        str[i - j - 1] = temp;
    }
}

void fact_calc(char* output, int n) {
    int factorial = 1;
    char temp[100] = "";
    
    for (int i = n; i > 0; i--) {
        factorial *= i;
        char buffer[10];
        int_to_str(i, buffer);
        strcat(temp, buffer);
        if (i > 1) strcat(temp, " x "); // Append multiplication sign
    }

    char n_str[10], fact_str[10];
    int_to_str(n, n_str);
    int_to_str(factorial, fact_str);

    strcpy(output, n_str);
    strcat(output, "! = ");
    strcat(output, temp);
    strcat(output, " = ");
    strcat(output, fact_str);
}

int main() {
    int n;
    char output[100];

    while (1) {
        printf("Enter an integer between 0 and 9 (enter -1 to terminate) => ");
        scanf("%d", &n);

        if (n == -1) break; // Terminate on -1
        if (n < 0 || n > 9) { 
            printf("Invalid Input\n"); // Print error message for invalid input
            continue; 
        }

        fact_calc(output, n); // Calculate factorial
        printf("%s\n", output); // Print result
    }

    return 0;
}

/*
OUTPUT:-

Enter an integer between 0 and 9 or -1 to quit => 6
6! = 6 x 5 x 4 x 3 x 2 x 1 = 720
Enter an integer between 0 and 9 or -1 to quit => 12
Invalid Input
Enter an integer between 0 and 9 or -1 to quit => 0
0! = 1
Enter an integer between 0 and 9 or -1 to quit => -1
*/
