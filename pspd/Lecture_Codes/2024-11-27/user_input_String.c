// Online C compiler to run C program online
#include <stdio.h>

int main() {
   int count=0;
    printf("Enter a string: ");
    char str[100];
    scanf("%s",&str);
    for(int i=0;str[i]!='\0';i++){
        count++;
    }
    printf("The length of the string is: ");
    printf("%d",count);
    return 0;
}

//The input will be taken until a whitespace comes (since it's a null character)
