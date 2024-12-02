/*
Q> Write a C program to find all the substrings of a given string

For example:- 
	Input : hello
	Output : h,e,l,l,o,he,el,ll,lo,hel,ell,llo,hell,ello,hello 
*/

#include <stdio.h>
#include <string.h>

int main() {
    char str[100]; // Input string
    printf("Enter a string: ");
    scanf("%s", str); // Read input string

    int length = strlen(str);

    // Loop to find all substrings
    printf("Sub-strings: ");
    for (int start = 0; start < length; start++) {
        for (int end = start + 1; end <= length; end++) {
            // Print the substring from start to end
            for (int k = start; k < end; k++) {
                printf("%c", str[k]);
            }
            printf(", "); // Separate substrings with a comma
        }
    }
    return 0;
}
