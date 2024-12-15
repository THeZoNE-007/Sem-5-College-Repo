/*
PROBLEM: Merge Two Sorted Arrays

ANALYSIS
To solve this problem, we need to merge two sorted arrays into a single sorted array while removing duplicates. 
Key points include using two pointers to traverse both arrays simultaneously and comparing current elements.

DATA REQUIREMENTS
    - Problem Inputs:   Two sorted arrays of type double (arr1 and arr2).
                        Their respective lengths (len1 and len2).
    - Problem Outputs:  A merged and sorted array (result) with no duplicates.

DESIGN
INITIAL ALGORITHM
1. Initialize pointers for both input arrays and an index for the result array.
2. While neither array has been fully traversed:
    - Compare current elements of both arrays.
    - Append the smaller value to the result array while ensuring no duplicates.
    - Increment the pointer of the array containing the smaller value.
3. Append any remaining elements from either array to the result array.
4. Return the merged array and its length through an output parameter.

IMPLEMENTATION
*/

#include <stdio.h>

// Function to merge two sorted arrays without duplicates
void merge_arrays(const double arr1[], int len1, const double arr2[], int len2, double result[], int *result_len) {
    int i = 0, j = 0, k = 0;

    // Traverse both arrays
    while (i < len1 && j < len2) {
        if (arr1[i] < arr2[j]) {
            // Add arr1[i] if it's not a duplicate
            if (k == 0 || result[k - 1] != arr1[i]) {
                result[k++] = arr1[i];
            }
            i++;
        } else if (arr1[i] > arr2[j]) {
            // Add arr2[j] if it's not a duplicate
            if (k == 0 || result[k - 1] != arr2[j]) {
                result[k++] = arr2[j];
            }
            j++;
        } else {
            // Skip duplicate values
            if (k == 0 || result[k - 1] != arr1[i]) {
                result[k++] = arr1[i];
            }
            i++;
            j++;
        }
    }

    // Add remaining elements from arr1
    while (i < len1) {
        if (k == 0 || result[k - 1] != arr1[i]) {
            result[k++] = arr1[i];
        }
        i++;
    }

    // Add remaining elements from arr2
    while (j < len2) {
        if (k == 0 || result[k - 1] != arr2[j]) {
            result[k++] = arr2[j];
        }
        j++;
    }

    // Set the result length
    *result_len = k;
}

// Test the function
int main() {
    double arr1[] = {1.1, 3.3, 5.5, 7.7};
    double arr2[] = {2.2, 3.3, 6.6, 8.8};
    int len1 = sizeof(arr1) / sizeof(arr1[0]), len2 = sizeof(arr2) / sizeof(arr2[0]);

    double result[100]; // Allocate enough space for the result
    int result_len;

    // Merge the arrays
    merge_arrays(arr1, len1, arr2, len2, result, &result_len);

    // Print the merged array
    printf("Merged Array: ");
    for (int i = 0; i < result_len; i++) {
        printf("%.1f ", result[i]);
    }
    printf("\n");

    return 0;
}

/*
OUTPUT:-

Merged Array: 1.1 2.2 3.3 5.5 6.6 7.7 8.8
*/