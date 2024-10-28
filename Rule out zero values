#include <stdio.h>
#include <stdlib.h>

#define DIM 10

int eliminate(int A[DIM]){

    int i, temp[DIM], n=0;

    for(i=0; i<DIM; i++){
        if(A[i] != 0){
            temp[i] = A[i];
            printf("%d\n", temp[i]);
            n++;
        }
    }
    return temp[n];
}

int main(void){

    int A[6] = {0,1,2,0,3,4};//deneme

    /*
    int arr[DIM];
    printf("Enter the array:(Max 10 elements)");
    for(int i=0; i<DIM; i++)
        scanf("%d", &arr[i]);
    */

    printf("%d", eliminate(&A));

    return 0;
}
