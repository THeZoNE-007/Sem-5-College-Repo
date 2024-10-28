// write a c program to find mean and standard deviation of an array containing 10 elements
#include <stdio.h>
#include <math.h>
int main() {
    int n = 10;
    int num[n];
    double sum = 0.0, mean, sd = 0.0;
    for (int i = 0; i < n; i++) {
        printf("Enter NUM %d: ", i + 1);
        scanf("%d", &num[i]);
        sum += num[i];
    }
    mean=sum/n;
    for (int i=0;i<n;i++) {
        sd+=pow(num[i]-mean,2);
    }
    sd=sqrt(sd/n);
    printf("The mean is: %.2lf\n", mean);
    printf("The standard deviation is: %.2lf\n", sd);

    return 0;
}
