/*

Write a program n C that takes a list of nouns and generates their plural forms based on the following rules:

i) If a noun ends with y, replace y with ies
ii) If a nound ends with s, ch, or sh, append es
iii) For all other cases, append s.

The program shoudl print each noun along with its plural form.
Test the program with the following nons:

Chai, dairy, Boss, circus, fly, Dog, church, clue, dish

*/

#include <stdio.h>
#include <string.h>

void plural(char str[], char str2[], int n) {
    if (str[n - 1] == 'y') {
        int i = 0;
        for (i = 0; i < n - 1; i++) { // Use n-1 to exclude 'y'
            str2[i] = str[i];
        }
        str2[i] = 'i';
        str2[i + 1] = 'e';
        str2[i + 2] = 's';
        str2[i + 3] = '\0'; // Null terminate the plural form
    } else if ((str[n - 1] == 's') || (str[n - 2] == 'c' && str[n - 1] == 'h') || (str[n - 2] == 's' && str[n - 1] == 'h')) {
        strcpy(str2, str);
        strcat(str2, "es");
    } else {
        strcpy(str2, str);
        strcat(str2, "s");
    }

    printf("Plural: %s\n", str2); // Print result here
}

int main() {
    char str[100];
    char str2[100];
    printf("Enter a String: ");
    fgets(str, sizeof(str), stdin);
    
    // Remove newline character if present
    str[strcspn(str, "\n")] = '\0'; // This line removes the newline character

    plural(str, str2, strlen(str)); // Pass length of the string
    return 0;
}


