/* 
char str1 = "Hello";
char str2 = "world" 

Concatenate or merge the above strings without using lib */

#include <stdio.h>

int main() {
   int count=0;
    printf("Enter a string1: ");
    char str[50];
    scanf("%s",&str);
    printf("Enter a string2: ");
    char s2[50];
    scanf("%s",&s2);
    int point=0;
    char s3[100];
    for(int i=0;str[i]!='\0';i++){
        s3[i]=str[i];
        point=i;
    }
    point=point+1;
    s3[point]=32;
    printf("point: %d",point);
    point++;
    for(int i=0;i<s2[i]!='\0';i++){
        s3[point]=s2[i];
        point++;
    }
    printf("Concatenated string is: %s",s3);
 
    return 0;
}


