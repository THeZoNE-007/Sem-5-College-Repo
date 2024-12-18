/*
Write a C program that uses a pointer to a structure to store
the dimensions of a rectangle and calculate its area and perimeter.

Define a structure Rectangle with the following members: length and width
The program should:
	Accept the length and width of a rectangle.
	Use a pointer to the structure to calculate the area and perimeter:
	Area = lrngth * width
	Perimetr = 2 * (length + width)
Print the dimensions, area, and perimeter
*/

#include<stdio.h>
struct rectangle{
   float length;
   float width;
};
void find_area(struct rectangle *r){
   
  float area=r->length*(r->width); 
  float perimeter=2.0*(r->length+r->width);
   
  printf("Length: %f\n",r->length);
  printf("Width: %f\n",r->width);
  printf("Area: %.2f\n",area);
  printf("Perimeter: %.2f\n",perimeter);
   
}
void initialise_rectangle(struct rectangle *r){
    printf("Enter the length of the rectangle: ");
    scanf("%f",&r->length);
    
    printf("Enter the width of the rectangle: ");
    scanf("%f",&r->width);
}

int main(){
   struct rectangle r;
   initialise_rectangle(&r);
    find_area(&r);
   return 0;
}

