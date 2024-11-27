#include <stdio.h>
#include <stdlib.h>

void sorted(int arr[]){
    int new[5], j=0;
    for(int i=0; i<sizeof(arr)/4-1; i++){
        if(arr[i] != arr[i+1]){
            new[j++] == arr[i];
        }
    }
    new[j++] = arr[4];
    printf("New array is: {%d}", new);
    printf("\n New size of the array is: %d", sizeof(new)/4);
}

int main() {
    int arr[5];
    printf("Enter the array size of 5:");
    for (int i =0; i<sizeof(arr)/4; i++)
        scanf("%d", &arr[i]);
    sorted(arr);
    return 0;
}
