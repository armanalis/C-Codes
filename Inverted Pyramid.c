#include <stdio.h>
#include <stdlib.h>

void inv_pyramid(int num){
    int i, j, space;

    for (i = num; i >= 1; i--) {
        for (space = 0; space < num - i; space++)
            printf("  ");

        for (j = i; j <= 2 * i - 1; j++)
            printf("* ");

        for (j = 0; j < i - 1; j++)
            printf("* ");
        printf("\n");
    }
}

int main() {
    int num;
    printf("Enter the number of rows:");
    scanf("%d", &num);
    inv_pyramid(num);
    return 0;
}
