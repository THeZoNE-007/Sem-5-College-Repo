/*
A barcode scanner for Universal Product Codes (UPCs) verifies the 12-digit code scanned by comparing the code’s last digit (called a check digit) to its own computation of the check digit from the first 11 digits as follows:
1. Calculate the sum of the digits in the odd-numbered positions (the first,third, ..., eleventh digits) and multiply this sum by 3.
2. Calculate the sum of the digits in the even-numbered positions (the second,fourth, ..., tenth digits) and add this to the previous result.
3. If the last digit of the result from step 2 is 0, then 0 is the check digit. Otherwise, subtract the last digit from 10 to calculate the check digit.
4. If the check digit matches the final digit of the 12-digit UPC, the UPC is assumed correct. 

Write a program that prompts the user to enter the 12 digits of a barcode separated by spaces. The program should store the digits in an integer array, calculate the check digit, and compare it to the final barcode digit. If the digits match, output the barcode with the message “validated.” If not, output the barcode with the message “error in barcode.” Also, output with labels the results from steps 1 and 2 of the check-digit calculations. Note that the “first” digit of the barcode will be stored in element 0 of the array. Try your program on the following barcodes, three of which are valid. For the first barcode, the result from step 2 is 79(0+9+0+8+4+0)*3+(7+4+0+0+5).

079400804501
024000162860
011110856807
051000138101
*/

#include<stdio.h>
int compare(int checkDigit, int arLast){
      if(checkDigit==arLast){
          printf("UPC is correct!!");
      }
      else{
          printf("UPC Is invalid!!");
      }
}
void main(){
   int ar[12];
   int res=0;
   printf("Enter the 12 digit upc code: ");
   for(int i=0;i<12;i++){
       printf("Enter the %d digit: ",i+1);
       scanf("%d",&ar[i]);

   }

   for(int i=0;i<11;i++){
      if(ar[i]%2!=0){
           res+=ar[i];
       }
   }
   res=res*3;
   for(int i=0;i<11;i++){
      if(ar[i]%2==0){
          res+=ar[i];
      }
   }
   int checkDigit=res%10;
   int arLast=ar[11];
   if(checkDigit==0){
       compare(checkDigit,arLast);
   }
   else{
      int check=10-checkDigit;
      compare(check,arLast);
     
   }
}

