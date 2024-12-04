/*

Write a function deblank(input argument, output argument) that takes a stringoutput and a string input argument and returns a copy of the input argument with all blanks removed.
Input: Hello World
Output: HelloWorld

*/

#include<stdio.h>
#include<string.h>

void deblank(char str[]){
    for(int i=0;i<strlen(str)-1;i++){
       for(int j=i;j<strlen(str)-1;j++){
          if(str[j]==' '){
              char temp=str[j];
              str[j]=str[j+1];
              str[j+1]=temp;
          }
      }
    }
    printf("%s",str);
}

void main(){
   char str[100];
   printf("Enter a string: ");
   fgets(str,100,stdin);
   deblank(str);
 
}
