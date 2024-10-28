#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main(void){

    int classes[SIZE], flag, val;
    int i, j;

    for(i=0; i<SIZE; i++)
        classes[i] = 0;

    printf("Input sequence: ");
    flag = 1;
    do{
        printf("Value =");
        scanf("%d", &val);

        if (val < 0 || val > SIZE * SIZE) {
            flag = 0;
        }
        else{
            classes[val/SIZE]++;
        }

    }while(flag == 1);

    for(i=0; i<SIZE; i++){
        printf("[%2d-%2d]", i*SIZE, (i+1)*SIZE-1);
        for(j=0; j<classes[i]; j++) {
            printf("#");
        }
        printf("\n");
    }
    return 0;
}
