/*
Q1> Write a program to sort the elements of an array using Bubble sort !!
-------------------------------------------------------------------------

PROBLEM: Sort the elements of an array using Bubble Sort.

ANALYSIS: The program will prompt the user to enter the number of elements and then the elements themselves. It will use the Bubble Sort algorithm to sort the array in ascending order.

DATA REQUIREMENTS:
Problem Inputs:
int n; // Number of elements in the array.
int arr[n]; // Array to be sorted.

Problem Outputs:
Sorted array in ascending order.
*/

#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    // Prompt user for input on number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Prompt user for input on array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Perform Bubble Sort
    bubbleSort(arr, n);

    // Display sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
