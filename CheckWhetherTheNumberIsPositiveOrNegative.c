#include <stdio.h>

void checknumber(int num){

    if (num==0)
        printf("The number is zero.");
    else if (num<0)
        printf("The number is negative.");
    else
        printf("The number is positive.");

}
int main() {

    int num;
    printf("Enter the number:");
    scanf("%d", &num);

    checknumber(num);

    return 0;
}
