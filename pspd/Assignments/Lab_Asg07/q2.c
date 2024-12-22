/*
PROBLEM: Represent an element from the periodic table with its properties and provide functions to input and output these properties.

ANALYSIS: The program defines a structure to represent an element, including its atomic number, name, chemical symbol, class, atomic weight, and the number of electrons in each shell. It includes functions to scan and print these details.

DATA REQUIREMENTS:
Problem Inputs:
- int atn; // Atomic number of the element.
- char name[20]; // Name of the element.
- char symbol[10]; // Chemical symbol of the element.
- char class[20]; // Class of the element (e.g., metal, non-metal).
- float weight; // Atomic weight of the element.
- int ar[7]; // Number of electrons in each shell (array of 7 integers).

Problem Outputs:
Formatted output showing all details of the element.

DESIGN:
INITIAL ALGORITHM:
1. Define a structure for an element with appropriate components.
2. Implement functions to scan and print details for the element.
3. In the main function, gather user input for an element's details.
4. Print all gathered information in a structured format.

IMPLEMENTATION:
*/

#include <stdio.h>

struct element_t {
    int atn;
    char name[20], symbol[10], class[20];
    float weight;
    int ar[7];
};

void print_data(const struct element_t *element) {
    printf("\n%d %s %s %s %.2f ", element->atn, element->name, element->symbol, element->class, element->weight);
    for (int i = 0; i < 7; i++) {
        printf("%d ", element->ar[i]);
    }
}

void initialise_data(struct element_t *element) {
    printf("Enter atomic number, name, symbol, class, weight: ");
    scanf("%d %19s %9s %19s %f", &element->atn, element->name, element->symbol, element->class, &element->weight); 
    //Limit to prevent buffer overflows if the input exceeds the size of the destination array 
    
    for (int i = 0; i < 7; i++) {
        printf("Enter number of electrons in orbit %d: ", i);
        scanf("%d", &element->ar[i]);
    }
    
    print_data(element);
}

int main() {
    struct element_t element;
    initialise_data(&element);
    return 0;
}

/*
OUTPUT:-

Enter the atomic number,name,symbol,classname,weight: 11 Sodium Na alkali_metal 22.9898
Enter the number of electrons in orbit 0: 2
Enter the number of electrons in orbit 1: 8
Enter the number of electrons in orbit 2: 1
Enter the number of electrons in orbit 3: 0
Enter the number of electrons in orbit 4: 0
Enter the number of electrons in orbit 5: 0
Enter the number of electrons in orbit 6: 0

11 Sodium Na alkali_metal 22.989799 2 8 1 0 0 0 0
*/
