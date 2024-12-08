/*
Q3> A normalized vector X is defined as 

|------------------------------WRITE THIS QUESTION FROM BOOK QUESTION------------------------------|
|												   |	
|         x of i = (v of i/(summation of (v of i)^2 from i=1 to n)^0.5) ; i=1,2,...,n              |
|												   |
|--------------------------------------------------------------------------------------------------|

Each element of the normalized vector X is computed by dividing the corresponding element (vi) of the original vector by the square root of the sum of the squares of all the original vector's elements. Desgn and test a program that repeatedly scans and normalizes vectors of different lengths. Define functions scan_vector, normalize_vector, and print_vector.
*/


/*
PROBLEM: Normalize a vector based on the provided formula.

ANALYSIS: The program will repeatedly scan a vector from user input, normalize it, and display the normalized vector. The normalization is done by dividing each element of the vector by the suare root of the sum of the squares of all elements.

DATA REQUIREMENTS:
Problem Inputs:
int n; // Length of the vector
double v[n]; // Original vector
double x[n]; // Normalized vector

Problem Outputs:
Display the normalized vector.

DESIGN:
INITIAL ALGORITHM:
1. Define a functon to scan a vector from user input.
2. Define a fucntion to normalize the vector.
3. Define a function to print the normalized vector.
4. In the main function, use a loop to repeatedly scan, normalize, and print vectors until the user chooses to stop.
*/

#include<stdio.h>
#include<math.h>

void scan_vector(double v[], int n) {
	printf("Enter %d elements of the vector:\n", n);
	for (int i=0; i<n; i++) {
		scanf("%lf", &v[i]);
	}
}

void normalize_vector(double v[], double x[], int n) {
	double sum_of_squares = 0.0;
	
	//Calculate normalization factor
	for (int i=0; i<n; i++) {
		sum_of_squares += v[i] * v[i];
	}
	
	// Calculate normalization factor
	double norm_factor = sqrt(sum_of_squares);
	
	// Normalize the vector
	for (int i=0; i<n; i++) {
		x[i] = v[i] / norm_factor;
	}
}

void print_vector(double x[], int n) {
	printf("Nomalized vector:\n");
	for (int i=0; i<n; i++) {
		printf("%.4f ", x[i]);
	}
	printf("\n");
}

int main() {
	int n;
	
	while (1) {
		printf("Enter the no.of elements in the vector (or 0 to exit): ");
		scanf("%d", &n);
		
		if (n == 0) break;
		
		double v[n];
		double x[n];
		
		scan_vector(v, n);
		normalize_vector(v, x, n);
		print_vector(x, n);
	}
	return 0;
}

/*
OUTPUT:-

Enter the no.of elements in the vector (or 0 to exit): 2
Enter 2 elements of the vector:
1
2
Nomalized vector:
0.4472 0.8944 
Enter the no.of elements in the vector (or 0 to exit): 3           
Enter 3 elements of the vector:
3
4
5
Nomalized vector:
0.4243 0.5657 0.7071 
Enter the no.of elements in the vector (or 0 to exit): 0
*/
