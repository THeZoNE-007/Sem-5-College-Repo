/* 
Q1> Write a program to take two numerical lists of the same length ended by a sentinel value and store the lists in arrays x and y, each of which has 20 elements. Let n be the actual number of data values in each list. Store the product of corresponding elements of x and y in a third array, z, also of size 20. Display the arrays x, y, and z in a three-column table. Then compute and display the square root of the sum of the items in z. Make up your own data, and be sure to test your program on at least one data set with number lists of exactly 20 items. One data set should have lists of 21 numbers, and one set should have significantly shorter lists.
*/


/* 
PROBLEM: Take two numerical lists of the same length, compute the product of corresponding elements, and display the results.

ANALYSIS: The program will prompt the user to enter two lists of numbers, store them in arrays, and calculate the product of corresponding elements. It will then display the arrays and compute 
the square root of the sum of the products.

DATA REQUIREMENTS:
Problem Inputs:
int ar1[20]; // First array.
int ar2[20]; // Second array.
int ar3[20]; // Array to store products.
int n; // Actual number of data values entered.

Problem Outputs:
Display arrays ar1, ar2, and ar3 in a three-column table.
Display the square root of the sum of elements in ar3.

DESIGN:
INITIAL ALGORITHM:
1. Initialize three arrays of size 20 for input and output.
2. Prompt the user to enter values for the first array until a sentinel value (-1) is entered or 20 values are reached.
3. Prompt the user to enter values for the second array using the same method.
4. Calculate the product of corresponding elements from both arrays and store them in a third array.
5. Display all three arrays in a formatted table.
6. Compute and display the square root of the sum of elements in the product array.

IMPLEMENTATION:
*/

#include <stdio.h>
#include <math.h>

int main() { // Step 1
    int ar1[20] = {0};
    int ar2[20] = {0};
    int ar3[20] = {0}; 
    int n = 0; 
    int sv = -1;

    // Step 2
    for (int i = 0; i < 20; i++) {
        printf("Enter value for element %d of ar1 (or -1 to stop): ", i + 1);
        int num = 0;
        scanf("%d", &num);
        if (num == sv) {
            break;
        }
        ar1[n] = num;
        n++;
    }

    // Step 3
    for (int i = 0; i < n; i++) {
        printf("Enter value for element %d of ar2 (or -1 to stop): ", i + 1);
        int num = 0;
        scanf("%d", &num);
        if (num == sv) {
            break;
        }
        ar2[i] = num;
    }

    // Step 4
    for (int i = 0; i < n; i++) {
        ar3[i] = ar1[i] * ar2[i];
    }

    // Step 5
    printf("\n x \t y \t z\n");
    printf("-------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d \t %d\n", ar1[i], ar2[i], ar3[i]);
    }

    // Step 6
    double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ar3[i];
    }

    double sq = sqrt(sum);
    printf("\nThe square root of the sum of elements in z is %.2lf\n", sq);

    return 0;
}

/*
OUTPUT:-

Enter value for element 1 of ar1 (or -1 to stop): 2
Enter value for element 2 of ar1 (or -1 to stop): 3
Enter value for element 3 of ar1 (or -1 to stop): 4
Enter value for element 4 of ar1 (or -1 to stop): -1
Enter value for element 1 of ar2 (or -1 to stop): 5
Enter value for element 2 of ar2 (or -1 to stop): 6
Enter value for element 3 of ar2 (or -1 to stop): 7

 x       y       z
-------------------
2        5       10
3        6       18
4        7       28

The square root of the sum of elements in z is 7.48
*/
