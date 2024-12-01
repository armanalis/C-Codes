#include <stdio.h>
#include <stdlib.h>

#define DIM1 5
#define DIM2 2

int main(void){

    int v1[DIM1], v2[DIM2];
    int temp[DIM2];
    int count = 0;

    printf("Enter the first array: \n");

    for(int i=0; i<DIM1; i++)//first array initilaziton
        scanf("%d", &v1[i]);

    printf("Enter the second array: \n");

    for(int i=0; i<DIM2; i++)//second array initilaziton
        scanf("%d", &v2[i]);

    for(int i=0; i<DIM2; i++){
        for(int j=0; j<DIM1; j++){
            if(v1[j] == v2[i]){
                temp[i] = v2[i];
                count++;
            }
        }
    }
    if(count>=2){
        for(int k=0; k<DIM2; k++){
            printf("%d ", temp[k]);
        }
    }// count should be at least 2 fot the sub-sequence.

    return 0;
}
