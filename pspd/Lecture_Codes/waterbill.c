#include<stdio.h>

void calculate(double previous, double current, double unpaid){
	double demandCharge = 35.00;
	double perCharge = 1.10;
	double lateCharge = 2.00;
	
	if (unpaid == 0.00){
		double thisMonth = current - previous;
		double charge = demandCharge + (thisMonth*perCharge);
		printf("This Month's water ill is: %.2f", charge);
	}
	else{
		double thisMonth = current - previous;
		double charge = demandCharge + lateCharge + (thisMonth*perCharge);
		printf("This Month's water bill is: %.2f", charge);
	}
}

void main(){
	printf("Enter the previousConsumption & currentConsumption & unpaid bill if any: ");
	double previous,current,unpaidBill;
	
	scanf("%lf %lf %lf", &previous, &current, &unpaidBill);
	calculate(previous,current,unpaidBill);
}
