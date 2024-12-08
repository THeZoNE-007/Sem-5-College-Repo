/*
Q5> The bubble sort is another technique for sorting an array. A bubble sort compares adjacent array elements and exchanges their values if they are out of order. In this way, the smaller values "bubble" to the top of the array (toward element 0), while the larger values sink to the bottom of the array. After the first pass of a bubble sort, the last array element is in the correct position; after the second pass, the last two elements are correct, and so on. Thus, after each pass, the unsorted portion of the array contains one less element. Write and test a function that implements this sorting method.
*/


/*
PROBLEM: Implement the bubble sort algorithm to sort an array of integers.

ANALYSIS: The program will define a function to perform bubble sort on an array and test it with a user-defined array. The user will be prompted to enter the elements of the array.

DATA REQUIREMENTS:
Problem Inputs:
int arr[]; // Array of integers to be sorted.
int n; // Number of elements in the array.

Problem Outputs:
Display the original and sorted arrays.

DESIGN:
INITIAL ALGORITHM:
1. Define a function bubbleSort that takes an array and its size as parameters.
2. Use nested loops to compare adjacent elements.
3. Swap elements if they are out of order.
4. Repeat the process until no swaps are needed, indicating the array is sorted.
5. In the main function, prompt for user input to define the array, call bubbleSort, and display results.

IMPLEMENTATION:
*/

#include <stdio.h>

// Function to perform bubble sort
void bubbleSort(int arr[], int n) {
    int temp; 
    int swapped;
    
    // Outer loop for each element
    for (int i = 0; i < n - 1; i++) {
        swapped = 0; // Reset swapped flag
        
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap if out of order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1; // Set swapped flag
            }
        }
        // If no two elements were swapped, break
        if (swapped == 0) {
            break;
        }
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]); // Corrected format specifier from "&d" to "%d"
    }
    printf("\n");
}

int main() {
    int n;
    
    // Prompt user for number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n); // Corrected format specifier from "&d" to "%d"
    
    int arr[n];
    
    // Input elements into the array
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]); // Corrected format specifier from "&d" to "%d"
    }
    
    // Print original array
    printf("Original Array: ");
    printArray(arr, n);
    
    // Perform bubble sort
    bubbleSort(arr, n);
    
    // Print sorted array
    printf("Sorted Array: ");
    printArray(arr, n);
    
    return 0; // Return statement indicating successful completion
}


/*
OUTPUT:-

Enter the number of elements: 5
Enter 5 elements:
64 34 25 12 22
Original Array: 64 34 25 12 22 
Sorted Array: 12 22 25 34 64 
*/
