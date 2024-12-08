/*
Q2> A barcode scanner for Universal Product Codes (UPCs) verifies the 12-digit code scanned by comparing the code's last digit (called a check digit) to its own computation of the check digit from the first 11 digits as follows:

1. Calculate the sum of the digits in the odd-numbered positions (the first, third,... eleventh digits) and multiply this sum by 3.
2. Calculate the sum of the digits in the even-numbered positions (the second, fourth,..., tenth digits) and add this to the previous result.
3. If the last digit of the result from step 2 is 0, then 0 is the check digit. Otherwise, subtract the last digit from 10 to calculate the check digit.
4. If the check digit matches the final digit of the 12-digit UPC, the UPC is assumed correct.

Write a program that prompts the user to enter the 12 digits of a barcode separated by spaces. The program should store the digits in an integer array, calculate the check digit, and compare it to 
the final barcode digit. If the digits match, output the barcode with the message "validated". If not, output the barcode with the message "error in barcode". Also, output with labels the results from 
steps 1 and 2 of the check-digit calculations. Note that the "first" digit of the barcode will be stored in element 0 of the array. Try your program on the following barcodes, three of which are valid. For the first barcode, the result from step 2 is 79 (0+9+0+8+4+0)*3 + (7+4+0+0+5)

079400804501
024000162860
011110856807
051000138101
*/


/*
PROBLEM: Validate a 12-digit Universal Product Code (UPC) by calculating the check digit.

ANALYSIS: The program will prompt the user to enter a 12-digit UPC code, calculate the check digit 
from the first 11 digits, and compare it to the last digit. It will display results of calculations 
and indicate whether UPC is valid or invalid.

DATA REQUIREMENTS:
Problem Inputs:
int ar[12]; // Array to store the 12 digits of UPC.

Problem Outputs:
Display results of steps 1 and 2 of check-digit calculations. Indicate whether UPC is validated or has an error.

DESIGN:
INITIAL ALGORITHM:
1. Initialize an integer array of size 12 to store UPC digits.
2. Prompt user to enter 12 digits of UPC code.
3. Calculate sum of digits in odd-numbered positions and multiply by 3.
4. Calculate sum of digits in even-numbered positions and add to step 3 result.
5. Determine check digit based on step 4 result.
6. Compare calculated check digit with last digit of UPC.
7. Display results from steps 3 and 4, and indicate if UPC is validated or has an error.

IMPLEMENTATION:
*/

#include <stdio.h>

// Function to compare calculated check digit with last digit
void compare(int checkDigit, int arLast) {
    if (checkDigit == arLast) {
        printf("UPC is validated!\n");
    } else {
        printf("Error in barcode!\n");
    }
}

int main() {
    int ar[12]; // Array to store UPC digits
    int res = 0; // Variable to store intermediate results

    // Step 2: Input for UPC code
    printf("Enter the 12-digit UPC Code separated by spaces: ");
    for (int i = 0; i < 12; i++) {
        scanf("%d", &ar[i]);
    }

    // Step 3: Calculate sum of odd-positioned digits
    for (int i = 0; i < 11; i += 2) {
        res += ar[i];
    }
    res *= 3;

    // Step 4: Calculate sum of even-positioned digits
    for (int i = 1; i < 11; i += 2) { // Corrected index for even positions
        res += ar[i];
    }

    // Display results from step 3 and step 4
    printf("Sum from odd positions (multiplied by 3): %d\n", res);
    
    // Determine check digit
    int checkDigit = res % 10;
    if (checkDigit != 0) {
        checkDigit = 10 - checkDigit;
    }

    // Compare calculated check digit with last digit
    int arLast = ar[11];
    compare(checkDigit, arLast);

    return 0; // Return statement indicating successful completion
}

/*
OUTPUT:-

Enter the 12-digit UPC Code separated by spaces: 0 7 9 4 0 0 8 0 4 5 0 1
Sum from odd positions (multiplied by 3): 79
UPC is validated!
*/
