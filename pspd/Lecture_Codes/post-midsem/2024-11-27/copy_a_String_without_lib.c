/* Write a C program for copying a string (without using library) */

#include <stdio.h>

int main() {
   int count=0;
    printf("Enter a string: ");
    char str[50];
    char s2[50];
    scanf("%s",&str);
    for(int i=0;str[i]!='\0';i++){
        count++;
        s2[i]=str[i];
    }
    printf("The length of the string is: ");
    printf("%d",count);
    printf("\nThe copied string is: %s",s2);
 
    return 0;
}
