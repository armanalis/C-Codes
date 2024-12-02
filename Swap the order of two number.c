#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int main(void) {

    int a,b;
    
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);

    swap(&a,&b);

    printf("New order is %d %d ",a,b);

    return 0;
}
