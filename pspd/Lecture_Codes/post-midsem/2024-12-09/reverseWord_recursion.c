/* Write a C prog to print a word in reverse order using Recursion ! */

#include<stdio.h>
#include<string.h>

void printword(char ch[], int size) {
  if(size<0) { return; }
  else {
    printf("%c", ch[size]);
    printword(ch, size-1);
  }
}

int main() {
  char ch[100];
  printf("Enter a string: ");
  fgets(ch,100,stdin);
  int size=strlen(ch)-1;
  printword(ch, size);
}
