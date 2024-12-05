/*
Q> Write a C program to find the largest word from a given Sentence
*/
#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000 // Maximum length of the input sentence
#define MAX_WORD_LENGTH 100 // Maximum length of each word

int main() {
    char sentence[MAX_LENGTH], largestWord[MAX_WORD_LENGTH] = "";
    
    // Input: Read a sentence from the user
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    
    // Remove newline character if present
    sentence[strcspn(sentence, "\n")] = '\0';

    char *token = strtok(sentence, " ");
    
    // Find the largest word
    while (token != NULL) {
        if (strlen(token) > strlen(largestWord)) {
            strcpy(largestWord, token);
        }
        token = strtok(NULL, " ");
    }

    // Output: Print the largest word
    if (largestWord[0] != '\0') {
        printf("The largest word is: %s\n", largestWord);
    } else {
        printf("No words found in the input.\n");
    }

    return 0;
}
