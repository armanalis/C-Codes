#include <stdio.h>
void armstrong();

int main() {
    int num;
    printf("Enter the 3 digit number:");
    scanf("%d", &num);
    armstrong(num);
    return 0;
}

void armstrong(int num){

    int rem, temp = num, contr = 0;

    while(num>0){
        rem = num % 10;
        contr += (rem * rem * rem);
        num = num/10;
    }

    if (temp == contr) {
        printf("This is a armstrong number.");
    }
    else{
        printf("This is not a armstrong number.");
    }

}
