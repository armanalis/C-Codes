#include <stdio.h>

void check_prime(int num) {
    int prime = 1;
    for (int i = 2; i <= num / 2; i++) {
        if (num % i == 0) {
            prime = 0;
            break;
        }
    }
    if (prime) {
        printf("%d is prime number.\n", num);
    }
    else {
        printf("%d is not prime number.\n", num);
    }

}

int main() {
    int num;
    printf("Enter the number:");
    scanf("%d", &num);
    check_prime(num);

    return 0;
}
