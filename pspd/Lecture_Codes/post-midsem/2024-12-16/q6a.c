#include<stdio.h>
struct Auto_t{
     char make[50];
     char model[50];
     int odometer;
     struct date_t manufacture;
     struct date_t purchase;
     struct tank_t capacity;
     struct tank_t currentFuel;
     
};
struct date_t{
     int day;
     int month;
     int year;
};
struct tank_t{
     float value;
};
void scan_date(struct auto_t automobile){
   struct date_t manufacture;
   struct date_t purchase;
   printf("Enter the manufacture day:")
   scanf("%d",&manufacture.day);
}
void scan_auto(struct auto_t automobile){
   printf("Enter the make: ");
   scanf("%s",automobile.make);
   
   printf("Enter the model: ");
   scanf("%s",automobile.model);
   
   printf("Enter the odometer reading: ");
   scanf("%s",automobile.odometer);
   
   scan_date(automobile);
   
}


int main(){
  
}
