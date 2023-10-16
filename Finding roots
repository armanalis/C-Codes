#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void find_roots(int a, int b, int c){
    double r1, r2;
    int D;
    D = b*b - 4*a*c;
    if (a ==0){
        printf("Invalid.");
        exit(0);
    }
    if(D>0){
        r1 = (double)(-b+sqrt(D))/(2*a);
        r2 = (double)(-b-sqrt(D))/(2*a);
        printf("Root 1: %f\n", r1);
        printf("Root 2: %f", r2);
    }
    else if(D==0){
        r2 = (double) -b/(2*a);
        r1 =r2;
        printf("Root 1: %f\n", r1);
        printf("Root 2: %f", r2);
    }
    else
        printf("The roots are complex.");

}

int main() {
    int a, b, c;
    printf("Enter the coefficients of function:");
    scanf("%d %d %d", &a, &b, &c);
    find_roots(a, b, c);
    return 0;
}
