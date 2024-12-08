/*
Q4> The binary search algorithm that follows may be used to search an array when the elements are in order. This algorithm is analogous to the following approach for finding a name in a telephone book.
1. Open the book in the middle, and look at the middle name on the page.
2. If the middle name isn’t the one you’re looking for, decide whether it comes before or after the name you want.
3. Take the appropriate half of the section of the book you were looking in and repeat these steps until you land on the name.

ALGORITHM FOR BINARY SEARCH:
1. Let bottom be the subscript of the initial array element.
2. Let top be the subscript of the last array element.
3. Let found be false.
4. Repeat as long as bottom isn’t greater than top and the target has not been found
   5. Let middle be the subscript of the element halfway between bottom and top.
   6. If the element at middle is the target
        7. Set found to true and index to middle.
   else if the element at middle is larger than the target
        8. Let top be middle – 1.
   else
        9. Let bottom be middle + 1.

Write and test a function binary_srch that implements this algorithm for an array of integers. When there is a large number of array elements, which function do you think is faster: binary_srch or the linear search function?
*/


/*
PROBLEM: Implement a binary search algorithm to find an element in a sorted array of integers.

ANALYSIS: The program will define a function to perform binary search and test it with a user-defined sorted array. The user will be prompted to enter the target value to search for in the array.

DATA REQUIREMENTS:
Problem Inputs:
int arr[]; // Sorted array of integers.
int n; // Number of elements in the array.
int target; // Element to search for.

Problem Outputs:
Index of the target element if found, or a message indicating it is not found.

DESIGN:
INITIAL ALGORITHM:
1. Define a function binarySearch that takes an array, number of elements, and target as parameters.
2. Use a loop to repeat until the left index is greater than the right index.
3. Calculate the middle index.
4. If the middle element matches the target, return the middle index.
5. If the middle element is greater than the target, adjust the right index.
6. If the middle element is less than the target, adjust the left index.
7. If the target is not found, return –1.
8. In the main function, prompt for user input to define the sorted array and target value, then call binarySearch and display results.


IMPLEMENTATION:
*/

#include <stdio.h>

int binarySearch(int arr[], int n, int target) {
    for (int left = 0, right = n - 1; left <= right;) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid;
        left = arr[mid] < target; // Increment left if target is greater
        right -= arr[mid] > target; // Decrement right if target is smaller
    }
    return -1; // Target not found
}

int main() {
    int n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

    printf("Enter the element to search: ");
    scanf("%d", &target);
    printf(binarySearch(arr, n, target) != -1 ? "Element found at index %d\n" : "Element not found\n", binarySearch(arr, n, target));

    return 0;
}

/*
OUTPUT:-
Enter the number of elements: 5
Enter 5 sorted elements:
1 3 5 7 9
Enter the element to search: 5
Element found at index 2
*/
