//wap to check if a given string is palindrome or not
#include<stdio.h>
#include<string.h>

void main(){
  
   char str[20];
   printf("Enter a string: ");
   fgets(str,20,stdin);
   int count=0;
   int flag=0;
   for(int i=strlen(str)-2;i>=0;i--){
       if(str[i]==str[count]){
          flag=1;
       }
       else{
         flag=0;
         break;
       }
      count+=1;
   }
   if(flag==1){
      printf("Palindrome");
   }
   else{
      printf("Not palindrome");
   }
}
