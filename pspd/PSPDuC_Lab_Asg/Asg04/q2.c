  /*
PROBLEM: Determine if a given positive integer is a multiple of 7, 11, or 13; check if the sum of its digits is odd or even; and determine if it is a prime number.

ANALYSIS: The program will prompt the user to enter positive integers and will analyze each number based on three criteria:
a. Whether it is a multiple of 7, 11, or 13.
b. Whether the sum of its digits is odd or even.
c. Whether it is a prime number.

DATA REQUIREMENTS:
Problem Inputs:
int number; // The positive integer entered by the user.

Problem Outputs:
int isMultiple; // Indicates if the number is a multiple of 7, 11, or 13.
int isSumodd; // Indicates if the sum of digits is odd (1) or even (0).
int isPrime; // Indicates if the number is prime (1) or not (0).

DESIGN:
INITIAL ALGORITHM:
1. Define a function `analyzeInteger` that takes an integer and three pointers as arguments.
2. Inside the function:
   - Check if the number is a multiple of 7, 11, or 13.
   - Calculate the sum of its digits and check if it is odd or even.
   - Check if the number is prime.
3. In the main function, repeatedly prompt the user for input until they choose to stop.
4. Call `analyzeInteger` for each input and display the results.
*/

#include <stdio.h>

// Function to analyze the integer
void analyzeInteger(int number, int *isMultiple, int *isSumodd, int *isPrime) {
    // Check for multiples
    *isMultiple = (number % 7 == 0 || number % 11 == 0 || number % 13 == 0);
    
    // Calculate sum of digits
    int sum = 0, temp = number;
    while (temp > 0) {
        sum += temp % 10;
        temp /= 10;
    }
    *isSumodd = (sum % 2 != 0); // Odd if sum % 2 != 0

    // Check for prime
    *isPrime = 1; // Assume it is prime
    if (number < 2) {
        *isPrime = 0; // Numbers less than 2 are not prime
        return;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            *isPrime = 0; // Not prime if divisible by any i
            break;
        }
    }
}

int main() {
    int number, isMultiple, isSumodd, isPrime;
    char choice;

    do {
        printf("Enter a positive integer: ");
        scanf("%d", &number);

        analyzeInteger(number, &isMultiple, &isSumodd, &isPrime);

        printf("Number: %d\n", number);
        printf("Multiple of 7, 11, or 13: %d\n", isMultiple);
        printf("The sum of digits is odd: %d\n", isSumodd);
        printf("Prime number: %d\n", isPrime);
        
        printf("Would you like to enter another number? (y/n): ");
        scanf(" %c", &choice); // Added space before %c to consume any newline character
    } while (choice == 'y' || choice == 'Y');

    return 0;
}