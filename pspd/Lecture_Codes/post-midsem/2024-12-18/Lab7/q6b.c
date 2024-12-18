/*
Define a structure type element t to represent one element from the periodic table of elements.
Components should include the atomic number (an integer); the name, chemical symbol, and
class (strings); a numeric field for the atomic weight; and a seven-element array of integers
for the number of electrons in each shell. The following are the components of an element t
structure for sodium.

11 Sodium Na alkali_metal 22.9898 2 8 1 0 0 0 0
Define and test I/O functions scan_element and print_element.
*/

#include<stdio.h>

struct element_t{
   int atn;
   char name[20];
   char symbol[10];
   char class[20];
   float weight;
   int ar[7];
  
};
void print_data(struct element_t *element){
    printf("\n");
    printf("%d %s %s %s %f ",element->atn,element->name,element->symbol,element->class,element->weight);
    for(int i=0;i<7;i++){
      printf("%d ",element->ar[i]);
      
   }

}
void initialise_data(struct element_t *element){
   printf("Enter the atomic number,name,symbol,classname,weight: ");
   scanf("%d %s %s %s %f",&element->atn,&element->name,&element->symbol,&element->class,&element->weight);
   
   for(int i=0;i<7;i++){
      printf("Enter the number of electrons in orbit: %d\n",i);
      scanf("%d",&element->ar[i]);
   }
   print_data(element);
   
}
int main(){
   struct element_t element;
   initialise_data(&element);
}
