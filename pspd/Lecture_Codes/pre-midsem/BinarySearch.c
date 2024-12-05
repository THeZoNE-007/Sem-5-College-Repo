/*
Q2> Write a program to search an element in an array using Binary Search !!
---------------------------------------------------------------------------

PROBLEM: Search for an element in a sorted array using Binary Search.

ANALYSIS: The program will prompt the user to enter the number of elements, the elements themselves, and the target element to search. It will use the Binary Search algorithm to find the target element.

DATA REQUIREMENTS:
Problem Inputs:
int n; // Number of elements in the array.
int arr[n]; // Sorted array to be searched.
int target; // Element to be searched.

Problem Outputs:
Index of the target element if found, or a message indicating it is not found.
*/

#include <stdio.h>

// Function to perform Binary Search
int binarySearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid; // Element found, return index
        } else if (arr[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return -1; // Element not found
}

int main() {
    int n;

    // Prompt user for input on number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Prompt user for input on array elements (ensure array is sorted)
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user for target element
    int target;
    printf("Enter the element to search: ");
    scanf("%d", &target);

    // Perform Binary Search
    int result = binarySearch(arr, n, target);

    // Display result
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }

    return 0;
}
/*
------------------------------------------------------------------------------------------------------------------------------
#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    for (int left = 0, right = n - 1; left <= right;) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        left += arr[mid] < target; // Increment left if target is greater
        right -= arr[mid] > target; // Decrement right if target is smaller
    }
    return -1;
}

int main() {
    int n, target;
    printf("Enter the number of elements: "), scanf("%d", &n);
    
    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    
    printf("Enter the element to search: "), scanf("%d", &target);
    printf(binarySearch(arr, n, target) != -1 ? "Element found at index %d\n" : "Element not found\n", binarySearch(arr, n, target));
    
    return 0;
}
*/
