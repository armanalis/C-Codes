#include <stdio.h>
#include <stdlib.h>

int merge(int arr1[], int arr2[], int arr1size, int arr2size){

    int arr_resultsize = arr1size + arr2size;
    int c[arr_resultsize], i , j;

    for (i= 0; i<arr1size; i++){
        c[i]=arr1[i];
    }
    for (i=0, j = arr1size; j<arr_resultsize && i< arr2size; i++, j++){
        c[j] = arr2[i];
    }
    for ( int k = 0; k < arr_resultsize; k++) {
        printf("%d ", c[k]);
    }


}

int main() {
    int arr1[5], arr2[5];


    printf("Enter the first array:");
    for(int i=0; i<sizeof(arr1)/4; i++)
    {
        scanf("%d ", &arr1[i]);
    }
    printf("\nEnter the second array:");
    for(int i=0; i<sizeof(arr2)/4; i++)
    {
        scanf("%d ", &arr2[i]);
    }

    // in this line we are dividing the size of arrays by 4 because the sizeof function gives the array size multiplied by int(int*array size).
    merge(arr1, arr2, sizeof(arr1)/4, sizeof(arr2)/4);

    return 0;
}
